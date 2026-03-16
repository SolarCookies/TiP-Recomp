#pragma once

#include <cstdint>
#include <atomic>
#include <chrono>
#include <thread>
#include <rex/ui/imgui_dialog.h>
#include "imgui.h"

#include <rex/cvar.h>
#include <rex/ppc/types.h>
#include <rex/system/kernel_state.h>

inline double fpsCount;
inline bool showfps;

class FpsOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit FpsOverlayDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer) {}

    void OnDraw(ImGuiIO& io) override {
        if (!showfps) {
            return; // Don't draw the overlay if it's disabled
		}
        const double fps = fpsCount;

        ImGui::SetNextWindowPos(ImVec2(10.0f, 10.0f));
            //ImGuiCond_Always, ImVec2(1.0f, 0.0f));
        ImGui::SetNextWindowBgAlpha(0.0f);
        ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0, 0, 0, 0));
        ImGui::SetNextWindowSize(ImVec2(120.0f, 0.0f));

        ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_NoInputs |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoBringToFrontOnFocus;

        if (ImGui::Begin("##fps_overlay", nullptr, flags)) {
            ImVec4 color;
            if (fps >= 59.0)       color = ImVec4(0.2f, 1.0f, 1.0f, 1.0f);   // blue
            else if (fps >= 30.0)  color = ImVec4(0.2f, 1.0f, 0.2f, 1.0f);   // green
            else if (fps <= 20.0)  color = ImVec4(1.0f, 0.2f, 0.2f, 1.0f);   // red
            else                   color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);   // yellow (21-29)

            ImGui::TextColored(color, "FPS: %.1f", fps);
        }
        ImGui::End();
        ImGui::PopStyleColor();
    }
};