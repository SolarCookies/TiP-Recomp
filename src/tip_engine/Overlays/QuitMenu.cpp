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
* The core goal of ReTiP is not only to get the software running, but to 
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

#include "QuitMenu.h"
#include "tip_engine/Globals.h"

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

static bool KeyPressedEdge(int vk, bool& wasDown) {
    bool down = (GetAsyncKeyState(vk) & 0x8000) != 0;
    bool pressed = down && !wasDown;
    wasDown = down;
    return pressed;
}
#endif

void QuitMenuDialog::OnDraw(ImGuiIO& io) {
#ifdef _WIN32
    bool shift = (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
    bool escEdge = KeyPressedEdge(VK_ESCAPE, escWasDown_);
    bool endEdge = KeyPressedEdge(VK_END, endWasDown_);
#else
    bool shift = io.KeyShift;
    bool escEdge = ImGui::IsKeyPressed(ImGuiKey_Escape, false);
    bool endEdge = ImGui::IsKeyPressed(ImGuiKey_End, false);
#endif

    if (!showConfirm_ && ((shift && escEdge) || endEdge)) {
        showConfirm_ = true;
        FlushRetipMouseInput();
    }

    g_QuitConfirmActive = showConfirm_;

    if (!showConfirm_) return;
    DrawConfirm(io);
}

void QuitMenuDialog::DrawConfirm(ImGuiIO& io) {
    const ImVec2 screen = io.DisplaySize;

    ImGui::GetBackgroundDrawList()->AddRectFilled(
        ImVec2(0.0f, 0.0f), screen, ImColor(0, 0, 0, 160));

    constexpr float kWidth = 420.0f;
    ImGui::SetNextWindowPos(ImVec2(screen.x * 0.5f, screen.y * 0.5f), ImGuiCond_Always,
                            ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(kWidth, 0.0f), ImGuiCond_Always);

    const ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(20.0f, 18.0f));
    ImGui::Begin("###RetipQuitConfirm", nullptr, flags);

    ImGui::PushTextWrapPos(kWidth - 40.0f);
    ImGui::TextUnformatted("Are you sure you want to quit?");
    ImGui::Spacing();
    ImGui::TextWrapped("Any unsaved progress will be lost.");
    ImGui::PopTextWrapPos();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    const float fullW = ImGui::GetContentRegionAvail().x;
    const float btnW = (fullW - ImGui::GetStyle().ItemSpacing.x) * 0.5f;

    if (ImGui::Button("Quit", ImVec2(btnW, 34.0f))) {
        showConfirm_ = false;
        g_QuitConfirmActive = false;
        if (window_) window_->RequestClose();
    }
    ImGui::SameLine();
    if (ImGui::Button("Cancel", ImVec2(btnW, 34.0f))) {
        showConfirm_ = false;
        g_QuitConfirmActive = false;
    }

    ImGui::End();
    ImGui::PopStyleVar();
}
