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
#include "imgui.h"

inline ImVec4 ToVec4(const ImColor& color) {
    return ImVec4(color.Value.x, color.Value.y, color.Value.z, color.Value.w);
}

inline ImVec4 Brighten(const ImVec4& col, float factor) {
    return ImVec4(
        col.x + (1.0f - col.x) * factor,
        col.y + (1.0f - col.y) * factor,
        col.z + (1.0f - col.z) * factor,
        col.w
    );
}

inline ImVec4 Darken(const ImVec4& col, float factor) {
    return ImVec4(col.x * (1.0f - factor), col.y * (1.0f - factor), col.z * (1.0f - factor), col.w);
}

inline ImVec4 WithAlpha(const ImVec4& col, float alpha) {
    return ImVec4(col.x, col.y, col.z, alpha);
}

constexpr int kColorCount = 57;

inline void SetUIColor(const ImColor& color) {
    ImVec4 base = ToVec4(color);

    ImVec4 bright = Brighten(base, 0.15f);
    ImVec4 brighter = Brighten(base, 0.30f);
    ImVec4 dim = Darken(base, 0.20f);
    ImVec4 dark = Darken(base, 0.45f);
    ImVec4 darker = Darken(base, 0.65f);
    ImVec4 darkest = Darken(base, 0.85f);
    ImVec4 veryDark = Darken(base, 0.92f);

    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.00f, 1.00f, 1.00f, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TextDisabled, ImVec4(0.50f, 0.50f, 0.50f, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_WindowBg, WithAlpha(veryDark, 0.50f));
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.00f, 0.00f, 0.00f, 0.50f));
    ImGui::PushStyleColor(ImGuiCol_PopupBg, WithAlpha(darkest, 0.94f));

    ImGui::PushStyleColor(ImGuiCol_Border, WithAlpha(base, 0.50f));
    ImGui::PushStyleColor(ImGuiCol_BorderShadow, ImVec4(0.04f, 0.00f, 0.03f, 0.00f));

    ImGui::PushStyleColor(ImGuiCol_FrameBg,  WithAlpha(dark, 0.54f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, WithAlpha(base, 0.40f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, WithAlpha(bright, 0.67f));

    ImGui::PushStyleColor(ImGuiCol_TitleBg, WithAlpha(darkest, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed, ImVec4(0.00f, 0.00f, 0.00f, 0.51f));

    ImGui::PushStyleColor(ImGuiCol_MenuBarBg, WithAlpha(darkest, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, WithAlpha(veryDark, 0.53f));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab, WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered, WithAlpha(bright, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive, WithAlpha(brighter, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_CheckMark, WithAlpha(base, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, WithAlpha(base, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, WithAlpha(dim, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_Button, WithAlpha(base, 0.40f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, WithAlpha(dim, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, WithAlpha(bright, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_Header, WithAlpha(dim, 0.31f));
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, WithAlpha(base, 0.80f));
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, WithAlpha(bright, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_Separator, WithAlpha(dark, 0.50f));
    ImGui::PushStyleColor(ImGuiCol_SeparatorHovered, WithAlpha(dim, 0.78f));
    ImGui::PushStyleColor(ImGuiCol_SeparatorActive, WithAlpha(base, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_ResizeGrip, WithAlpha(base, 0.20f));
    ImGui::PushStyleColor(ImGuiCol_ResizeGripHovered, WithAlpha(bright, 0.67f));
    ImGui::PushStyleColor(ImGuiCol_ResizeGripActive, WithAlpha(brighter, 0.95f));

    ImGui::PushStyleColor(ImGuiCol_InputTextCursor, ImVec4(1.00f, 1.00f, 1.00f, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_TabHovered, WithAlpha(base, 0.80f));
    ImGui::PushStyleColor(ImGuiCol_Tab, WithAlpha(dark, 0.86f));
    ImGui::PushStyleColor(ImGuiCol_TabSelected, WithAlpha(dim, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TabSelectedOverline, WithAlpha(base, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TabDimmed, WithAlpha(darkest, 0.97f));
    ImGui::PushStyleColor(ImGuiCol_TabDimmedSelected, WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TabDimmedSelectedOverline, WithAlpha(dark, 0.00f));

    ImGui::PushStyleColor(ImGuiCol_PlotLines, WithAlpha(brighter, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_PlotLinesHovered, ImVec4(1.00f, 0.43f, 0.35f, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.90f, 0.70f, 0.00f, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_PlotHistogramHovered, ImVec4(1.00f, 0.60f, 0.00f, 1.00f));

    ImGui::PushStyleColor(ImGuiCol_TableHeaderBg, WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TableBorderStrong, WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TableBorderLight, WithAlpha(darkest, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TableRowBg, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
    ImGui::PushStyleColor(ImGuiCol_TableRowBgAlt, ImVec4(1.00f, 1.00f, 1.00f, 0.06f));

    ImGui::PushStyleColor(ImGuiCol_TextLink, WithAlpha(dim, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, WithAlpha(base, 0.35f));
    ImGui::PushStyleColor(ImGuiCol_DragDropTarget, ImVec4(1.00f, 1.00f, 0.00f, 0.90f));
    ImGui::PushStyleColor(ImGuiCol_NavCursor, WithAlpha(dim, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_NavWindowingHighlight, ImVec4(1.00f, 1.00f, 1.00f, 0.70f));
    ImGui::PushStyleColor(ImGuiCol_NavWindowingDimBg, ImVec4(0.80f, 0.80f, 0.80f, 0.20f));
    ImGui::PushStyleColor(ImGuiCol_ModalWindowDimBg, ImVec4(0.80f, 0.80f, 0.80f, 0.35f));
}

inline void PopUIColor() {
    ImGui::PopStyleColor(kColorCount);
}
