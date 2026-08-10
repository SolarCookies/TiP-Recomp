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
******************************************************************************
*/

#pragma once
#include <rex/cvar.h>
#include <rex/ui/imgui_dialog.h>
#include "imgui.h"
#include <chrono>
#include <memory>
#include <vector>
#include <string>

inline double cpuMS;
inline double gpuMS;
inline int flock;

double GetHostProcessMemoryMB();

struct StatUnitSample {
    float hostFps = 0.0f;
    float generatedFps = 0.0f;
    float rhitMs = 0.0f;
    float rhitStallMs = 0.0f;
    float inputMs = 0.0f;
    float draws = 0.0f;
    float tris = 0.0f;
    int guestW = 0;
    int guestH = 0;
    int hostW = 0;
    int hostH = 0;
    float memMB = 0.0f;
};

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

        bool statUnit = rex::cvar::Query<bool>("stat_unit");
        if (statUnit) {
            auto now = std::chrono::steady_clock::now();
            if (lastStatSample.time_since_epoch().count() == 0 ||
                std::chrono::duration<float>(now - lastStatSample).count() >= 0.25f) {
                lastStatSample = now;
                stats.hostFps = static_cast<float>(rex::cvar::Query<double>("present_host_fps"));
                stats.generatedFps =
                    static_cast<float>(rex::cvar::Query<double>("present_fsr3_generated_fps"));
                stats.rhitMs = static_cast<float>(rex::cvar::Query<double>("gpu_stat_cp_busy_ms"));
                stats.rhitStallMs =
                    static_cast<float>(rex::cvar::Query<double>("gpu_stat_cp_stall_ms"));
                stats.inputMs = static_cast<float>(rex::cvar::Query<double>("input_stat_poll_ms"));
                stats.draws = static_cast<float>(rex::cvar::Query<double>("gpu_stat_frame_draws"));
                stats.tris =
                    static_cast<float>(rex::cvar::Query<double>("gpu_stat_frame_triangles"));
                stats.guestW = rex::cvar::Query<int32_t>("present_guest_width");
                stats.guestH = rex::cvar::Query<int32_t>("present_guest_height");
                stats.hostW = rex::cvar::Query<int32_t>("present_host_width");
                stats.hostH = rex::cvar::Query<int32_t>("present_host_height");
                stats.memMB = static_cast<float>(GetHostProcessMemoryMB());
            }
        }

        for (auto& counter : fpsManager->counters) {
            float fps = counter->averageFps;
            ImVec4 color;
            if (fps < 30.0f) color = ImVec4(1.0f, 0.15f, 0.15f, 1.0f);
            else if (fps < 60.0f) color = ImVec4(1.0f, 0.9f, 0.0f, 1.0f);
            else if (fps <= 70.0f) color = ImVec4(0.2f, 1.0f, 0.2f, 1.0f);
            else color = ImVec4(0.2f, 0.6f, 1.0f, 1.0f);

            ImGui::TextColored(color, "%.0f FPS", fps);
            if (statUnit) {
                ImGui::TextColored(color, "cpu:   %.1fms", cpuMS);
                ImGui::TextColored(color, "draw:  %.1fms", gpuMS);
                ImGui::TextColored(color, "rhit:  %.1fms (wait %.1fms)", stats.rhitMs,
                                   stats.rhitStallMs);
                ImGui::TextColored(color, "input: %.2fms", stats.inputMs);
            }
        }

        if (statUnit) {
            if (stats.hostFps > 0.5f) {
                ImGui::TextColored(ImVec4(0.65f, 0.4f, 1.0f, 1.0f), "%.0f FPS (host)", stats.hostFps);
            }
            if (stats.generatedFps > 0.5f) {
                ImGui::TextColored(ImVec4(1.0f, 0.45f, 0.85f, 1.0f), "%.0f FPS (generated)", stats.generatedFps);
            }

            const ImVec4 statColor(0.85f, 0.85f, 0.85f, 1.0f);
            ImGui::TextColored(statColor, "draws: %.0f", stats.draws);
            if (stats.tris >= 1000000.0f) {
                ImGui::TextColored(statColor, "tris:  %.2fM", stats.tris / 1000000.0f);
            } else if (stats.tris >= 1000.0f) {
                ImGui::TextColored(statColor, "tris:  %.1fK", stats.tris / 1000.0f);
            } else {
                ImGui::TextColored(statColor, "tris:  %.0f", stats.tris);
            }
            ImGui::TextColored(statColor, "mem:   %.0fMB", stats.memMB);

            if (stats.guestW > 0 && stats.guestH > 0) {
                ImGui::TextColored(statColor, "guest: %dx%d", stats.guestW, stats.guestH);
            }
            if (stats.hostW > 0 && stats.hostH > 0) {
                if (stats.guestH > 0) {
                    ImGui::TextColored(statColor, "host:  %dx%d (%.0f%%)", stats.hostW, stats.hostH, 100.0f * float(stats.hostH) / float(stats.guestH));
                } else {
                    ImGui::TextColored(statColor, "host:  %dx%d", stats.hostW, stats.hostH);
                }
            }
        }

        ImGui::End();
    }

private:
    StatUnitSample stats;
    std::chrono::steady_clock::time_point lastStatSample{};
};
