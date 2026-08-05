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

#pragma once
#include <rex/ui/imgui_dialog.h>
#include <rex/cvar.h>
#include <chrono>
#include <cmath>
#include "imgui.h"

REXCVAR_DECLARE(bool, ShowStartupOverlay);

class StartupOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit StartupOverlayDialog(rex::ui::ImGuiDrawer* drawer) : rex::ui::ImGuiDialog(drawer), startTime_(std::chrono::steady_clock::now()) {}

    void OnDraw(ImGuiIO& io) override {
        if (!REXCVAR_GET(ShowStartupOverlay) || finished_) return;

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

        ImGui::Begin("##StartupOverlay", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize);

        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, alpha));
        const char* text = std::string("ReTiP " + retipversion).c_str();
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
