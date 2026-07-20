#include "Fps.h"
#include <tip_engine/hooks.h>
#include <tip_engine/Timer.h>
#include <rex/hook.h>

REX_EXTERN(__imp__rex_appMainTickPreDraw_821C91C0);
REX_HOOK_RAW(rex_appMainTickPreDraw_821C91C0){
    Timer timer;
    timer.start();
    __imp__rex_appMainTickPreDraw_821C91C0(ctx, base);
    timer.stop();
    cpuMS = timer.elapsedMilliseconds();
}

REX_EXTERN(__imp__rex_appMainDraw_821C8E78);
REX_HOOK_RAW(rex_appMainDraw_821C8E78){
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
