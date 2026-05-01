#include "Globals.h"
#include "Log.h"
#include "tip_engine/hooks.h"

#include <cstdint>
#include <cmath>
#include <cstring>
#include <rex/ui/imgui_dialog.h>
#include "Overlays/Fps.h"
#include "imgui.h"

#include <rex/cvar.h>
#include "tip_engine/rex_macros.h"
#include <rex/graphics/flags.h>
#include <rex/system/kernel_state.h>
#include "tip_engine/Log.h"
#include "tip_engine/D3DTypes.h"
#include "Overlays/DebugInfo.h"

#include "rex_macros.h"
#include <fstream>
#include "tip_engine/Types/CommonTypes.h"
#include <SDL3/SDL.h>
#include <thread>
#include <atomic>
#include "tip_engine/Globals.h"

REXCVAR_DEFINE_DOUBLE(tip_mouse_y_sensitivity, 0.05, "_Trouble in Paradise/Input", "Mouse Y sensitivity (deg per pixel)").range(0.01, 5.0);
REXCVAR_DEFINE_DOUBLE(tip_mouse_x_sensitivity, 0.05, "_Trouble in Paradise/Input", "Mouse X sensitivity (deg per pixel)").range(0.01, 5.0);
REXCVAR_DEFINE_BOOL(tip_mouse_invert_y, false, "_Trouble in Paradise/Input", "Invert mouse Y");
REXCVAR_DEFINE_BOOL(tip_mouse_invert_x, false, "_Trouble in Paradise/Input", "Invert mouse X");
REXCVAR_DEFINE_DOUBLE(tip_mouse_zoom_step, 100.0, "_Trouble in Paradise/Input", "Zoom units per wheel detent").range(10.0, 500.0);
REXCVAR_DEFINE_BOOL(rgb_cursor, false, "_Trouble in Paradise", "Enables the Gursor"); // rainbow cursor

//Forward decl - defined alongside the (gated) zoom hook below.
static void ApplyMouseZoom(uint32_t camera);


//rex_meCursorCamCalculateYaw_822C1B18
REX_PPC_EXTERN_IMPORT(meCursorCamCalculateYaw_822C1B18);
int meCursorCamCalculateYaw_822C1B18_Hook(int camera, int controls) {
    float* YawPtr = reinterpret_cast<float*>(0x100000000ull + camera + 40);
    float yawBefore = to_byteswapped_float(*YawPtr);

    int result = rex::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculateYaw_822C1B18, camera, controls);

    int32_t dx = 0;
    if (g_raw_mouse) dx = g_raw_mouse->ConsumeDx();
    else if (g_mouse_listener) dx = g_mouse_listener->ConsumeDx();

    if (dx != 0) {
        float sensitivity = static_cast<float>(REXCVAR_GET(tip_mouse_x_sensitivity));
        float sign = REXCVAR_GET(tip_mouse_invert_x) ? -1.0f : 1.0f;
        float yawDelta = static_cast<float>(dx) * sensitivity * sign;

        float targetYaw = std::fmod(yawBefore + yawDelta, 360.0f);
        if (targetYaw < 0.0f) targetYaw += 360.0f;

        YawPtr[0] = to_byteswapped_float(targetYaw); //Stored yaw

        //Propagated render-yaw - native sub_8239FE50 skips it on zero-delta path
        uint32_t inner = std::byteswap(*reinterpret_cast<uint32_t*>(0x100000000ull + camera + 0));
        if (inner) {
            uint32_t derived = std::byteswap(*reinterpret_cast<uint32_t*>(0x100000000ull + inner + 2416));
            if (derived) {
                float* renderYawPtr = reinterpret_cast<float*>(0x100000000ull + derived + 1704);
                renderYawPtr[0] = to_byteswapped_float(targetYaw);
            }
        }
    }

    return result;
}
REX_PPC_HOOK(meCursorCamCalculateYaw_822C1B18)


//rex_meCursorCamCalculatePitch_822C1C00
REX_PPC_EXTERN_IMPORT(meCursorCamCalculatePitch_822C1C00);
int meCursorCamCalculatePitch_822C1C00_Hook(int camera, int controls) {
    float* PitchPtr = reinterpret_cast<float*>(0x100000000ull + camera + 32);
    float pitchBefore = to_byteswapped_float(*PitchPtr);

    int result = rex::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculatePitch_822C1C00, camera, controls);

    int32_t dy = 0;
    if (g_raw_mouse) dy = g_raw_mouse->ConsumeDy();
    else if (g_mouse_listener) dy = g_mouse_listener->ConsumeDy();

    if (dy != 0) {
        float sensitivity = static_cast<float>(REXCVAR_GET(tip_mouse_y_sensitivity));
        float sign = REXCVAR_GET(tip_mouse_invert_y) ? 1.0f : -1.0f;
        float pitchDelta = static_cast<float>(dy) * sensitivity * sign;

        constexpr float kMaxPerFrameDeg = 30.0f;
        if (pitchDelta > kMaxPerFrameDeg) pitchDelta = kMaxPerFrameDeg;
        if (pitchDelta < -kMaxPerFrameDeg) pitchDelta = -kMaxPerFrameDeg;

        float targetPitch = pitchBefore + pitchDelta;
        float pitchMin = to_byteswapped_float(*reinterpret_cast<float*>(0x100000000ull + camera + 52));
        float pitchMax = to_byteswapped_float(*reinterpret_cast<float*>(0x100000000ull + camera + 60));
        if (targetPitch > pitchMax) targetPitch = pitchMax;
        if (targetPitch < pitchMin) targetPitch = pitchMin;

        PitchPtr[0] = to_byteswapped_float(targetPitch);
    }

    return result;
}
REX_PPC_HOOK(meCursorCamCalculatePitch_822C1C00)


REX_PPC_EXTERN_IMPORT(meCursorCamCalculateZoom_822C1CE0);
void meCursorCamCalculateZoom_822C1CE0_Hook(int camera, int controls) {

    rex::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculateZoom_822C1CE0, camera, controls);

    // Sets the max and min values for zoom and pitch and also checks the memory to make sure that its valid before writing to it.
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    float* ZoomOutPtr = reinterpret_cast<float*>(0x100000000ull + camera + 84);
    float zoomOut = to_byteswapped_float(*ZoomOutPtr);
    if(zoomOut < 126.0f && zoomOut > 124.0f) {
        if (g_IsPlacingBuilding) {
            ZoomOutPtr[0] = to_byteswapped_float(300.0f);
        } else {
            ZoomOutPtr[0] = to_byteswapped_float(1000.0f);
        }
    }

    float* PitchMaxPtr = reinterpret_cast<float*>(0x100000000ull + static_cast<uint32_t>(camera) + 60);
    float pitchmax = to_byteswapped_float(*PitchMaxPtr);
    if(pitchmax < 61.0f && pitchmax > 59.0f) {
        PitchMaxPtr[0] = to_byteswapped_float(89.0f);
    }

    float* PitchMinPtr = reinterpret_cast<float*>(0x100000000ull + static_cast<uint32_t>(camera) + 52);
    float pitchmin = to_byteswapped_float(*PitchMinPtr);
    if(pitchmin < -59.0f && pitchmin > -61.0f) {
        PitchMinPtr[0] = to_byteswapped_float(-89.0f);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
}
REX_PPC_HOOK(meCursorCamCalculateZoom_822C1CE0)


//rex_CXuiModule__ProcessInput_8229A968
REX_PPC_EXTERN_IMPORT(CXuiModule__ProcessInput_8229A968);
int CXuiModule__ProcessInput_8229A968_Hook(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    if(g_LockGameInput) {
        return 0; // Block game input when the menu is open
    }
    int result = rex::GuestToHostFunction<int>(__imp__rex_CXuiModule__ProcessInput_8229A968, a1, a2, a3, a4, a5, a6, a7, a8);
    return result;
}
REX_PPC_HOOK(CXuiModule__ProcessInput_8229A968)

//rex_XInputGetKeystroke_82B0A740
REX_PPC_EXTERN_IMPORT(XInputGetKeystroke_82B0A740);
int XInputGetKeystroke_82B0A740_Hook(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10,int a11,int a12)
{
    if(g_LockGameInput) {
        return 0; // Block game input when the menu is open
    }
    int result = rex::GuestToHostFunction<int>(__imp__rex_XInputGetKeystroke_82B0A740, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    return result;
}
REX_PPC_HOOK(XInputGetKeystroke_82B0A740);

//int rex_XuiProcessInput_826B2DE0(unsigned __int16 *a1)
REX_PPC_EXTERN_IMPORT(XuiProcessInput_826B2DE0);
int XuiProcessInput_826B2DE0_Hook(unsigned __int16 *a1) {
    Log(LogLevel::Info, "XuiProcessInput Hook Hit");
    if(g_LockGameInput) {
        Log(LogLevel::Info, "Game input is locked, blocking input in XuiProcessInput");
        return 0; // Block game input when the menu is open
    }
    int result = rex::GuestToHostFunction<int>(__imp__rex_XuiProcessInput_826B2DE0, a1);
    Log(LogLevel::Info, "XuiProcessInput Hook Finished");
    return result;
}
REX_PPC_HOOK(XuiProcessInput_826B2DE0);


uint32_t HI(const std::string& hexColor) {
    if (hexColor.size() != 9 || hexColor[0] != '#') {
        return 0xFFFFFFFF; // Default to white if invalid format
    }
    uint32_t r = std::stoul(hexColor.substr(1, 2), nullptr, 16);
    uint32_t g = std::stoul(hexColor.substr(3, 2), nullptr, 16);
    uint32_t b = std::stoul(hexColor.substr(5, 2), nullptr, 16);
    uint32_t a = std::stoul(hexColor.substr(7, 2), nullptr, 16);
    return (r << 24) | (g << 16) | (b << 8) | a;
}

// Classify a host-endian RGBA color as red or yellow
static bool isRedColor(uint32_t rgba) {
    uint8_t r = (rgba >> 24) & 0xFF;
    uint8_t g = (rgba >> 16) & 0xFF;
    uint8_t b = (rgba >>  8) & 0xFF;
    return r > 180 && g < 80 && b < 80;
}

static bool isYellowColor(uint32_t rgba) {
    uint8_t r = (rgba >> 24) & 0xFF;
    uint8_t g = (rgba >> 16) & 0xFF;
    uint8_t b = (rgba >>  8) & 0xFF;
    return r > 180 && g > 180 && b < 80;
}

// Triangle tracking arrays (8 red, 8 yellow)
static constexpr int MAX_TRIANGLES = 8;
static uint32_t redPtrs[MAX_TRIANGLES] = {};
static uint32_t yellowPtrs[MAX_TRIANGLES] = {};
static uint32_t redLastKnown[MAX_TRIANGLES] = {};   // value at offset 0 when captured
static uint32_t yellowLastKnown[MAX_TRIANGLES] = {};
static int redCount = 0;
static int yellowCount = 0;

void CursorColor_hook(PPCRegister& r31, PPCRegister& r27)
{
    Log(LogLevel::Info, "Cursor Color Hook Hit");
  if(!REXCVAR_GET(rgb_cursor)) {
    Log(LogLevel::Info, "rgb_cursor cvar is disabled, skipping color modification");
    return;
  }

    // Resolve color pointer (guest memory is big-endian)
    uint32_t* colorPtr = reinterpret_cast<uint32_t*>(0x100000000ull + r31.u32 + 24);
    uint32_t rawColor = std::byteswap(*colorPtr); // host-endian RGBA

    // Read a stable field (offset 0) for sanity checking — we never modify this
    uint32_t baseValue = *reinterpret_cast<uint32_t*>(0x100000000ull + r31.u32);

    // Sanity check: if any stored entry's base value changed, memory was reallocated
    bool invalidated = false;
    for (int i = 0; i < redCount && !invalidated; i++) {
        uint32_t cur = *reinterpret_cast<uint32_t*>(0x100000000ull + redPtrs[i]);
        if (cur != redLastKnown[i]) invalidated = true;
    }
    for (int i = 0; i < yellowCount && !invalidated; i++) {
        uint32_t cur = *reinterpret_cast<uint32_t*>(0x100000000ull + yellowPtrs[i]);
        if (cur != yellowLastKnown[i]) invalidated = true;
    }
    if (invalidated) {
        redCount = 0;
        yellowCount = 0;
        memset(redPtrs, 0, sizeof(redPtrs));
        memset(yellowPtrs, 0, sizeof(yellowPtrs));
        memset(redLastKnown, 0, sizeof(redLastKnown));
        memset(yellowLastKnown, 0, sizeof(yellowLastKnown));
    }

    // Check if this pointer is already tracked
    bool isTracked = false;
    for (int i = 0; i < redCount; i++) {
        if (redPtrs[i] == r31.u32) { isTracked = true; break; }
    }
    if (!isTracked) {
        for (int i = 0; i < yellowCount; i++) {
            if (yellowPtrs[i] == r31.u32) { isTracked = true; break; }
        }
    }

    // If not tracked yet, classify by original color and add
    if (!isTracked) {
        if (isRedColor(rawColor) && redCount < MAX_TRIANGLES) {
            redPtrs[redCount] = r31.u32;
            redLastKnown[redCount] = baseValue;
            redCount++;
            isTracked = true;
        } else if (isYellowColor(rawColor) && yellowCount < MAX_TRIANGLES) {
            yellowPtrs[yellowCount] = r31.u32;
            yellowLastKnown[yellowCount] = baseValue;
            yellowCount++;
            isTracked = true;
        }
    }

    // Only apply rainbow to tracked (red/yellow) triangles
    if (!isTracked) return;

    // Determine if this is a red triangle (for hue offset)
    bool isRed = false;
    for (int i = 0; i < redCount; i++) {
        if (redPtrs[i] == r31.u32) { isRed = true; break; }
    }

    // Time-based hue cycling: full rainbow every 3 seconds
    auto now = std::chrono::steady_clock::now();
    static auto start = now;
    double elapsed = std::chrono::duration<double>(now - start).count();
    double hueD = fmod(elapsed * 120.0 + (isRed ? 180.0 : 0.0), 360.0); // red offset by 180°
    float hue = static_cast<float>(hueD);

    // HSV to RGB with full saturation and value
    float h = hue / 60.0f;
    int sector = static_cast<int>(h) % 6;
    float f = h - static_cast<int>(h);
    float q = 1.0f - f;

    float r, g, b;
    switch (sector) {
        case 0: r = 1; g = f; b = 0; break;
        case 1: r = q; g = 1; b = 0; break;
        case 2: r = 0; g = 1; b = f; break;
        case 3: r = 0; g = q; b = 1; break;
        case 4: r = f; g = 0; b = 1; break;
        default: r = 1; g = 0; b = q; break;
    }

    uint32_t ri = static_cast<uint32_t>(r * 255.0f);
    uint32_t gi = static_cast<uint32_t>(g * 255.0f);
    uint32_t bi = static_cast<uint32_t>(b * 255.0f);
    uint32_t rgba = (ri << 24) | (gi << 16) | (bi << 8) | 0xFF;

    // Apply cycling color, byte-swapped for PPC
    *colorPtr = std::byteswap(rgba);
    Log(LogLevel::Info, "Modified cursor triangle color to rainbow");
}