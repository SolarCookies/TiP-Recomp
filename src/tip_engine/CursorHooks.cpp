/** 
******************************************************************************
* ReTiP: Viva Pinata Recompiled                                              *
******************************************************************************
* Copyright (c) 2026 SolarCookies. Licensed under custom noncommercial terms.
*
* This software is licensed for non-commercial, private, and educational use 
* only. You may modify, rewrite, and optimize this code provided that full 
* attribution is given to the original authors listed on the project repository. 
* Commercial use is prohibited.
*
* DISCLAIMER: This software is provided "as-is" without warranty of any kind. 
* This project is an unofficial fan translation layer and does NOT provide, 
* distribute, or package any copyrighted game assets, binaries, or media belonging 
* to Microsoft or Rare. Users must provide their own legally obtained game assets. 
* This software must not be used in any manner that violates Microsoft's copyrights.
* DO NOT REDISTRIBUTE GAME ASSETS OR PROMOTE PIRACY.
*
* AI USE GUIDELINES:
* This project is built with minimal AI usage. We may utilize basic inline code 
* suggestions or rely on AI assistance for debugging, but the vast majority of 
* this codebase is written by hand. We manually decompile functions,
* reverse engineer structs, and write hooks to ensure accuracy and maintainability.
*
* The core goal of ReTiP is not only to get the game running, but to 
* research, document, and learn exactly how the game operates under the hood so that 
* we can provide modding support. We do not support using AI for creative 
* task or problem solving. i.e asking an AI agent to "find a way to 
* make freecam work". Instead, AI should only be used for small, boilerplate tasks or
* parsing a 1000 line crash log to isolate an error. We actively encourage all project 
* contributors to avoid the use of AI agents entirely when writing code or decompiling functions.
*
* The truth of the matter is that AI when used currectly by people who understand the output
* can be incredibly useful just like intelisense, being able to press Tab to autocomplete a
* for loop can save time. However, AI is not a replacement for human understanding and
* should not be used to replace the process of learning and understanding how the game works.
*
* We strongly prefer the use of local models that do not harm the environment and 
* can run entirely on your own local hardware over cloud based AI services. Ultimately, 
* all pull requests and code contributions will be strictly reviewed by people who 
* understand the codebase and the game. If you list Claude or any other AI as a coauthor 
* or contributor, your PR will be rejected regardless of whether it works.
******************************************************************************
*/

#include "Globals.h"
#include "Log.h"
#include <cstdint>
#include <cmath>
#include <cstring>
#include <rex/cvar.h>
#include "tip_engine/rex_macros.h"
#include <rex/graphics/flags.h>
#include <rex/system/kernel_state.h>
#include "rex_macros.h"
#include <fstream>
#include "tip_engine/Types/CommonTypes.h"
#include <SDL3/SDL.h>
#include <thread>
#include <atomic>

REXCVAR_DEFINE_DOUBLE(tip_mouse_y_sensitivity, 0.05, "TiP/Input", "Mouse Y sensitivity").range(0.01, 5.0);
REXCVAR_DEFINE_DOUBLE(tip_mouse_x_sensitivity, 0.05, "TiP/Input", "Mouse X sensitivity").range(0.01, 5.0);
REXCVAR_DEFINE_BOOL(tip_mouse_invert_y, false, "TiP/Input", "Invert mouse Y");
REXCVAR_DEFINE_BOOL(tip_mouse_invert_x, false, "TiP/Input", "Invert mouse X");
REXCVAR_DEFINE_DOUBLE(tip_mouse_zoom_step, 100.0, "TiP/Input", "").range(10.0, 500.0);
REXCVAR_DEFINE_DOUBLE(tip_mouse_zoom_max, 125.0, "TiP/Input", "Maximum mouse zoom-out distance").range(125.0, 1000.0);

REX_PPC_EXTERN_IMPORT(meCursorCamCalculateYaw_822C1B18);
int meCursorCamCalculateYaw_822C1B18_Hook(int camera, int controls) {
    float* YawPtr = reinterpret_cast<float*>(0x100000000ull + camera + 40);
    float yawBefore = to_byteswapped_float(*YawPtr);

    int result = rex::ppc::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculateYaw_822C1B18, camera, controls);

    int32_t dx = 0;
    if (!g_FreeCamActive) {
        if (g_raw_mouse) dx = g_raw_mouse->ConsumeDx();
        else if (g_mouse_listener) dx = g_mouse_listener->ConsumeDx();
        if (!IsRetipGameInputActive()) dx = 0;
    }

    if (dx != 0) {
        float sensitivity = static_cast<float>(REXCVAR_GET(tip_mouse_x_sensitivity));
        float sign = REXCVAR_GET(tip_mouse_invert_x) ? -1.0f : 1.0f;
        float yawDelta = static_cast<float>(dx) * sensitivity * sign;

        float targetYaw = std::fmod(yawBefore + yawDelta, 360.0f);
        if (targetYaw < 0.0f) targetYaw += 360.0f;

        YawPtr[0] = to_byteswapped_float(targetYaw); //Stored yaw

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

REX_PPC_EXTERN_IMPORT(meCursorCamCalculatePitch_822C1C00);
int meCursorCamCalculatePitch_822C1C00_Hook(int camera, int controls) {
    float* PitchPtr = reinterpret_cast<float*>(0x100000000ull + camera + 32);
    float pitchBefore = to_byteswapped_float(*PitchPtr);

    int result = rex::ppc::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculatePitch_822C1C00, camera, controls);

    int32_t dy = 0;
    if (!g_FreeCamActive) {
        if (g_raw_mouse) dy = g_raw_mouse->ConsumeDy();
        else if (g_mouse_listener) dy = g_mouse_listener->ConsumeDy();
        if (!IsRetipGameInputActive()) dy = 0;
    }

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

REX_PPC_EXTERN_IMPORT(cursorCameraTick_822C1E88);
int cursorCameraTick_822C1E88_Hook(int camera, int controls, int pos, int rot) {
    if (pos) {
        playerPos = pos;
    }
    if (rot) {
        playerRot = rot;
    }
    if (camera) {
        g_cameraAddr = static_cast<uint32_t>(camera);
    }
    return rex::ppc::GuestToHostFunction<int>(__imp__rex_cursorCameraTick_822C1E88, camera, controls, pos, rot);
}
REX_PPC_HOOK(cursorCameraTick_822C1E88)

REX_PPC_EXTERN_IMPORT(meCursorCamCalculateZoom_822C1CE0);
void meCursorCamCalculateZoom_822C1CE0_Hook(int camera, int controls) {

    rex::ppc::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculateZoom_822C1CE0, camera, controls);
    // Sets the max and min values for zoom and pitch and also checks the memory to make sure that its valid before writing to it.
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    constexpr float kVanillaZoomOut = 125.0f;
    constexpr float kWheelDeltaPerDetent = 120.0f;

    float* ZoomCurrentPtr = reinterpret_cast<float*>(0x100000000ull + camera + 36);
    float* ZoomInPtr = reinterpret_cast<float*>(0x100000000ull + camera + 76);
    float* ZoomOutPtr = reinterpret_cast<float*>(0x100000000ull + camera + 84);
    float zoomCurrent = to_byteswapped_float(*ZoomCurrentPtr);
    float zoomIn = to_byteswapped_float(*ZoomInPtr);
    float zoomOut = to_byteswapped_float(*ZoomOutPtr);

    int32_t wheel = 0;
    if (!g_FreeCamActive) {
        if (g_raw_mouse) wheel = g_raw_mouse->ConsumeWheel();
        else if (g_mouse_listener) wheel = g_mouse_listener->ConsumeWheel();
        if (!IsRetipGameInputActive()) wheel = 0;
    }

    if (wheel != 0) {
        float detents = static_cast<float>(wheel) / kWheelDeltaPerDetent;
        float step = static_cast<float>(REXCVAR_GET(tip_mouse_zoom_step));
        float mouseZoomOut = static_cast<float>(REXCVAR_GET(tip_mouse_zoom_max));
        float zoomMax = g_IsPlacingBuilding ? 300.0f : mouseZoomOut;
        float zoomMin = zoomIn;
        if (zoomMin <= 0.0f || zoomMin > kVanillaZoomOut) {
            zoomMin = kVanillaZoomOut;
        }

        float targetZoom = std::clamp(zoomCurrent - (detents * step), zoomMin, zoomMax);
        if ((zoomCurrent < kVanillaZoomOut && targetZoom > kVanillaZoomOut) ||
            (zoomCurrent > kVanillaZoomOut && targetZoom < kVanillaZoomOut)) {
            targetZoom = kVanillaZoomOut;
        }

        ZoomOutPtr[0] = to_byteswapped_float(zoomMax);
        ZoomCurrentPtr[0] = to_byteswapped_float(targetZoom);
    } else if (g_IsPlacingBuilding && zoomOut < 126.0f && zoomOut > 124.0f) {
        ZoomOutPtr[0] = to_byteswapped_float(300.0f);
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

REX_EXTERN(__imp__rex_CXuiModule__ProcessInput_8229A968);
REX_HOOK_RAW(rex_CXuiModule__ProcessInput_8229A968) {
    if (g_LockGameInput) {
        //ctx.r3.u64 = 0; // Block game input when the menu is open
        return;
    }
    __imp__rex_CXuiModule__ProcessInput_8229A968(ctx, base);
}

REX_EXTERN(__imp__rex_XInputGetKeystroke_82B0A740);
REX_HOOK_RAW(rex_XInputGetKeystroke_82B0A740) {
    if (g_LockGameInput) {
        //ctx.r3.u64 = 0; // Block game input when the menu is open
        return;
    }
    __imp__rex_XInputGetKeystroke_82B0A740(ctx, base);
}

REX_EXTERN(__imp__rex_XuiProcessInput_826B2DE0);
REX_HOOK_RAW(rex_XuiProcessInput_826B2DE0) {
    if (g_LockGameInput) {
        //ctx.r3.u64 = 0; // Block game input when the menu is open
        return;
    }
    __imp__rex_XuiProcessInput_826B2DE0(ctx, base);
}
