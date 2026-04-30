#include "Globals.h"
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
#include <rex/ppc/types.h>
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

//rex_inputPitchState_822C1C00
REX_PPC_EXTERN_IMPORT(inputPitchState_822C1C00);
int inputPitchState_822C1C00_Hook(int camera, int controls) {
    float* PitchPtr = reinterpret_cast<float*>(0x100000000ull + camera + 32);
    float pitchBefore = to_byteswapped_float(*PitchPtr);

    int result = rex::GuestToHostFunction<int>(__imp__rex_inputPitchState_822C1C00, camera, controls);

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
REX_PPC_HOOK(inputPitchState_822C1C00)
//rex_meCursorCamCalculateZoom_822C1CE0
inline float g_zoom_target = 1150.0f; //Persisted between calls; mouse wheel adjusts
REX_PPC_EXTERN_IMPORT(meCursorCamCalculateZoom_822C1CE0);
void meCursorCamCalculateZoom_822C1CE0_Hook(int camera, int controls) {

    float* ZoomOutPtr = reinterpret_cast<float*>(0x100000000ull + camera + 84);
    if(g_IsPlacingBuilding) {
        ZoomOutPtr[0] = to_byteswapped_float(300.0f); //Zoom in when placing building
    }else{
        int32_t wheel = 0;
        if (g_raw_mouse) wheel = g_raw_mouse->ConsumeWheel();
        else if (g_mouse_listener) wheel = g_mouse_listener->ConsumeWheel();
        if (wheel != 0) {
            float step = static_cast<float>(REXCVAR_GET(tip_mouse_zoom_step));
            float detents = static_cast<float>(wheel) / 120.0f; //WHEEL_DELTA per detent
            g_zoom_target -= detents * step; //Wheel up = zoom in = ZoomOut shrinks
            if (g_zoom_target < 200.0f) g_zoom_target = 200.0f;
            if (g_zoom_target > 2000.0f) g_zoom_target = 2000.0f;
        }
        ZoomOutPtr[0] = to_byteswapped_float(g_zoom_target);
    }
    float* PitchMaxPtr = reinterpret_cast<float*>(0x100000000ull + camera + 60);
    PitchMaxPtr[0] = to_byteswapped_float(89.0f); //Increase pitch max
    float* PitchMinPtr = reinterpret_cast<float*>(0x100000000ull + camera + 52);
    PitchMinPtr[0] = to_byteswapped_float(-89.0f); //Decrease pitch min


    rex::GuestToHostFunction<void>(__imp__rex_meCursorCamCalculateZoom_822C1CE0, camera, controls);
}
REX_PPC_HOOK(meCursorCamCalculateZoom_822C1CE0)

