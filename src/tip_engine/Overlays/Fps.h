#pragma once
#include <rex/ui/imgui_dialog.h>
#include "imgui.h"
#include <chrono>
#include <memory>
#include <vector>
#include <string>

inline double cpuMS;
inline double gpuMS;
inline int flock;

class FPSCounter {
public:
    std::string name;
    void Tick();
    int AverageCount = 100;
    std::vector<float> frameTimes;
    float averageFps = 0.0f;
    float averageMs = 0.0f;
    std::chrono::steady_clock::time_point lastTick = std::chrono::steady_clock::now();
};

class FPSManager {
public:
    std::vector<std::unique_ptr<FPSCounter>> counters;
    bool showFPS = false;

    FPSCounter* GetCreateCounter(const std::string& name) {
        for (auto& counter : counters) {
            if (counter->name == name) return counter.get();
        }
        auto newCounter = std::make_unique<FPSCounter>();
        newCounter->name = name;
        FPSCounter* ptr = newCounter.get();
        counters.push_back(std::move(newCounter));
        return ptr;
    }
};

class FpsOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit FpsOverlayDialog(rex::ui::ImGuiDrawer* drawer) : rex::ui::ImGuiDialog(drawer) {}

    FPSManager* fpsManager = nullptr;

    void OnDraw(ImGuiIO& io) override {

        //Limit draw to every 10 frames
        if(flock > 120){ flock = 0;}
        else{ flock++; }

        if (!fpsManager || !fpsManager->showFPS) return;

        const ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoDecoration;

        ImGui::SetNextWindowPos(ImVec2(10.0f, 10.0f), ImGuiCond_Always);
        ImGui::SetNextWindowBgAlpha(0.55f);
        ImGui::Begin("##FPSOverlay", nullptr, flags);

        for (auto& counter : fpsManager->counters) {
            float fps = counter->averageFps;
            ImVec4 color;
            if (fps < 30.0f) color = ImVec4(1.0f, 0.15f, 0.15f, 1.0f);
            else if (fps < 60.0f) color = ImVec4(1.0f, 0.9f, 0.0f, 1.0f);
            else if (fps <= 70.0f) color = ImVec4(0.2f, 1.0f, 0.2f, 1.0f);
            else color = ImVec4(0.2f, 0.6f, 1.0f, 1.0f);

            ImGui::TextColored(color, "%.0f FPS", fps);
            ImGui::TextColored(color,"cpu: %.1fms", cpuMS);
            ImGui::TextColored(color,"gpu: %.1fms", gpuMS);
        }

        ImGui::End();
    }
};
