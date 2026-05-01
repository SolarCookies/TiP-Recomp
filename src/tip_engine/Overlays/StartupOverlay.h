#pragma once
#include <rex/ui/imgui_dialog.h>
#include <rex/cvar.h>
#include <chrono>
#include <cmath>
#include "imgui.h"

REXCVAR_DECLARE(bool, ShowStartupOverlay);

class StartupOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit StartupOverlayDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer),
          startTime_(std::chrono::steady_clock::now()) {}

    void OnDraw(ImGuiIO& io) override {
        if (!REXCVAR_GET(ShowStartupOverlay) || finished_)
            return;

        auto now = std::chrono::steady_clock::now();
        float elapsed = std::chrono::duration<float>(now - startTime_).count();

        constexpr float kDuration = 10.0f;
        constexpr float kFadeOutStart = 7.0f;
        constexpr float kPulseSpeed = 3.0f;

        if (elapsed >= kDuration) {
            finished_ = true;
            return;
        }

        float baseAlpha = 1.0f;
        if (elapsed > kFadeOutStart) {
            baseAlpha = 1.0f - (elapsed - kFadeOutStart) / (kDuration - kFadeOutStart);
        }

        float pulse = 0.7f + 0.3f * std::sin(elapsed * kPulseSpeed);
        float alpha = baseAlpha * pulse;

        ImVec2 displaySize = io.DisplaySize;
        float windowWidth = 500.0f;
        float windowHeight = 40.0f;
        ImGui::SetNextWindowPos(ImVec2((displaySize.x - windowWidth) * 0.5f, 10.0f), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(windowWidth, windowHeight));
        ImGui::SetNextWindowBgAlpha(0.6f * alpha);

        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::Begin("##StartupOverlay", nullptr,
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_NoInputs |
            ImGuiWindowFlags_NoNav |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_AlwaysAutoResize);

        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, alpha));
        const char* text = "ReTiP 1.10 - Press F4 to open up the recomp settings";
        float textWidth = ImGui::CalcTextSize(text).x;
        ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
        ImGui::SetCursorPosY((windowHeight - ImGui::GetTextLineHeight()) * 0.5f);
        ImGui::Text("%s", text);
        ImGui::PopStyleColor();

        ImGui::End();
        ImGui::PopStyleVar(2);
    }

private:
    std::chrono::steady_clock::time_point startTime_;
    bool finished_ = false;
};
