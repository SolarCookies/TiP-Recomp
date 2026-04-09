#pragma once
#include <rex/ui/imgui_dialog.h>
#include "imgui.h"
#include <memory>
#include <vector>
#include "ImPlot/implot.h"

inline bool ShowPlot = false;

class FPSCounter {
public:
    std::string name;
    void Tick();
    int AverageCount = 100; // Number of frames to average over
    std::vector<float> frameTimes;
    float averageFps = 0.0f;
    float averageMs = 0.0f;
    std::chrono::steady_clock::time_point lastTick = std::chrono::steady_clock::now();
};

class FPSManager {
public:
    std::vector<std::unique_ptr<FPSCounter>> counters;
    bool showFPS = false;

    FPSCounter* GetCreateCounter(const std::string& name){
        for (std::unique_ptr<FPSCounter>& counter : counters) {
            if (counter->name == name) {
                return counter.get();
            }
        }
        // If not found, create a new counter
        auto newCounter = std::make_unique<FPSCounter>();
        newCounter->name = name;
        FPSCounter* ptr = newCounter.get();
        counters.push_back(std::move(newCounter));
        return ptr;
    }

};

inline int   bar_data[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
inline float x_data[1000] = { 0 };
inline float y_data[1000] = { 0 };

class FpsOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit FpsOverlayDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer) {}

    FPSManager* fpsManager;

    void OnDraw(ImGuiIO& io) override {
        if(!fpsManager->showFPS) return;
        ImGui::Begin("FPS Overlay", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
        for (auto& counter : fpsManager->counters) {
            ImGui::Text("%s: %.1f FPS (%.2f ms)", counter->name.c_str(), counter->averageFps, counter->averageMs);
        }
        ImGui::Checkbox("Show Plot", &ShowPlot);
        if(ShowPlot) {
            if (ImPlot::BeginPlot("FPS Plot", ImVec2(-1, 0))) {
                ImPlot::SetupAxesLimits(0, 100, 0, 200, ImPlotCond_Always);
                for (auto& counter : fpsManager->counters) {
                    if (counter->frameTimes.size() >= 2) {
                        int count = static_cast<int>(counter->frameTimes.size());
                        int offset = count > 100 ? count - 100 : 0;
                        int plotCount = count > 100 ? 100 : count;
                        std::vector<float> fpsValues(plotCount);
                        for (int i = 0; i < plotCount; i++) {
                            float ms = counter->frameTimes[offset + i];
                            fpsValues[i] = ms > 0.0f ? 1000.0f / ms : 0.0f;
                        }
                        ImPlot::PlotLine(counter->name.c_str(), fpsValues.data(), plotCount);
                    }
                }
                ImPlot::EndPlot();
            }
        }
        ImGui::End();
    }
};