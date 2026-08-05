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

#include "Fps.h"
#include <tip_engine/hooks.h>
#include <tip_engine/Timer.h>
#include <tip_engine/Globals.h>
#include <tip_engine/Types/CommonTypes.h>
#include <rex/hook.h>
#include <rex/graphics/mod_shader_params.h>
#include <chrono>
#include <thread>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define PSAPI_VERSION 2
#include <windows.h>
#include <psapi.h>

REXCVAR_DEFINE_BOOL(stat_unit, false, "TiP/Fps", "Show the detailed stats in the FPS overlay");

REXCVAR_DECLARE(bool, lock_fps);

namespace {

constexpr auto kLockedFramePeriod =
    std::chrono::duration_cast<std::chrono::steady_clock::duration>(
        std::chrono::duration<double>(1.0 / 30.0));

void PaceTo30Hz(std::chrono::steady_clock::time_point& nextAllowed) {
    if (!REXCVAR_GET(lock_fps)) {
        nextAllowed = {};
        return;
    }

    const auto now = std::chrono::steady_clock::now();
    if (nextAllowed.time_since_epoch().count() == 0 ||
        now - nextAllowed > kLockedFramePeriod) {
        nextAllowed = now + kLockedFramePeriod;
        return;
    }

    constexpr auto kSpinMargin = std::chrono::milliseconds(2);
    if (nextAllowed - now > kSpinMargin) {
        std::this_thread::sleep_for((nextAllowed - now) - kSpinMargin);
    }
    while (std::chrono::steady_clock::now() < nextAllowed) {
        std::this_thread::yield();
    }

    nextAllowed += kLockedFramePeriod;
}

}

double GetHostProcessMemoryMB() {
    PROCESS_MEMORY_COUNTERS_EX info{};
    info.cb = sizeof(info);
    if (!GetProcessMemoryInfo(GetCurrentProcess(), reinterpret_cast<PROCESS_MEMORY_COUNTERS*>(&info), sizeof(info))) {
        return 0.0;
    }
    return double(info.WorkingSetSize) / (1024.0 * 1024.0);
}

REX_EXTERN(__imp__rex_appMainTickPreDraw_821C91C0);
REX_HOOK_RAW(rex_appMainTickPreDraw_821C91C0){
    static std::chrono::steady_clock::time_point s_tickDeadline{};
    PaceTo30Hz(s_tickDeadline);

    Timer timer;
    timer.start();
    __imp__rex_appMainTickPreDraw_821C91C0(ctx, base);
    timer.stop();
    cpuMS = timer.elapsedMilliseconds();
}

REX_EXTERN(__imp__rex_appMainDraw_821C8E78);
REX_HOOK_RAW(rex_appMainDraw_821C8E78){
    static std::chrono::steady_clock::time_point s_drawDeadline{};
    PaceTo30Hz(s_drawDeadline);

    static const auto s_modClockStart = std::chrono::steady_clock::now();
    const float seconds = std::chrono::duration<float>(
                              std::chrono::steady_clock::now() - s_modClockStart).count();
    rex::gpu::SetModShaderParam(0, seconds);

    auto* cam = reinterpret_cast<camMainWorkspace_s*>(0x100000000ull + 0x82C34D48);
    rex::gpu::SetModShaderParam(1, to_byteswapped_float(cam->visCamToWorldMtx[2][0]));
    rex::gpu::SetModShaderParam(2, to_byteswapped_float(cam->visCamToWorldMtx[2][1]));
    rex::gpu::SetModShaderParam(3, to_byteswapped_float(cam->visCamToWorldMtx[2][2]));
    rex::gpu::SetModShaderParam(4, to_byteswapped_float(cam->visCamToWorldMtx[0][0]));
    rex::gpu::SetModShaderParam(5, to_byteswapped_float(cam->visCamToWorldMtx[0][1]));
    rex::gpu::SetModShaderParam(6, to_byteswapped_float(cam->visCamToWorldMtx[0][2]));
    rex::gpu::SetModShaderParam(7, to_byteswapped_float(cam->fovY));
    rex::gpu::SetModShaderParam(8,  to_byteswapped_float(cam->visCamToWorldMtx[1][0]));
    rex::gpu::SetModShaderParam(9,  to_byteswapped_float(cam->visCamToWorldMtx[1][1]));
    rex::gpu::SetModShaderParam(10, to_byteswapped_float(cam->visCamToWorldMtx[1][2]));

    auto* lightWs = reinterpret_cast<lightMainWorkspace_s*>(0x100000000ull + 0x82C3C010);
    rex::gpu::SetModShaderParam(12, to_byteswapped_float(lightWs->dirLight.dir.x));
    rex::gpu::SetModShaderParam(13, to_byteswapped_float(lightWs->dirLight.dir.y));
    rex::gpu::SetModShaderParam(14, to_byteswapped_float(lightWs->dirLight.dir.z));
    rex::gpu::SetModShaderParam(16, to_byteswapped_float(lightWs->dirLight.col.x));
    rex::gpu::SetModShaderParam(17, to_byteswapped_float(lightWs->dirLight.col.y));
    rex::gpu::SetModShaderParam(18, to_byteswapped_float(lightWs->dirLight.col.z));

    Timer timer;
    timer.start();
    __imp__rex_appMainDraw_821C8E78(ctx, base);
    timer.stop();
    gpuMS = timer.elapsedMilliseconds();
}

void FPSCounter::Tick(){
    auto Time = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> delta = Time - lastTick;
    lastTick = Time;
    float ms = static_cast<float>(delta.count());
    frameTimes.push_back(ms);
    if (frameTimes.size() > AverageCount) {
        frameTimes.erase(frameTimes.begin());
    }
    float total = 0.0f;
    for (float f : frameTimes) {
        total += f;
    }
    averageMs = total / frameTimes.size();
    averageFps = 1000.0f / averageMs;
}
