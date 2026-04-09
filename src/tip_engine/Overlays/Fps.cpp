#include "Fps.h"
#include <tip_engine/hooks.h>

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