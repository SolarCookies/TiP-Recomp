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

// Number of style colors pushed by SetUIColor
constexpr int kColorCount = 57;

inline void SetUIColor(const ImColor& color) {
    ImVec4 base = ToVec4(color);

    // Derived shades
    ImVec4 bright       = Brighten(base, 0.15f);
    ImVec4 brighter     = Brighten(base, 0.30f);
    ImVec4 dim          = Darken(base, 0.20f);
    ImVec4 dark         = Darken(base, 0.45f);
    ImVec4 darker       = Darken(base, 0.65f);
    ImVec4 darkest      = Darken(base, 0.85f);
    ImVec4 veryDark     = Darken(base, 0.92f);

    // Text
    ImGui::PushStyleColor(ImGuiCol_Text,                    ImVec4(1.00f, 1.00f, 1.00f, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TextDisabled,            ImVec4(0.50f, 0.50f, 0.50f, 1.00f));

    // Backgrounds
    ImGui::PushStyleColor(ImGuiCol_WindowBg,                WithAlpha(veryDark, 0.50f));
    ImGui::PushStyleColor(ImGuiCol_ChildBg,                 ImVec4(0.00f, 0.00f, 0.00f, 0.50f));
    ImGui::PushStyleColor(ImGuiCol_PopupBg,                 WithAlpha(darkest, 0.94f));

    // Borders
    ImGui::PushStyleColor(ImGuiCol_Border,                  WithAlpha(base, 0.50f));
    ImGui::PushStyleColor(ImGuiCol_BorderShadow,            ImVec4(0.04f, 0.00f, 0.03f, 0.00f));

    // Frame
    ImGui::PushStyleColor(ImGuiCol_FrameBg,                 WithAlpha(dark, 0.54f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered,          WithAlpha(base, 0.40f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive,           WithAlpha(bright, 0.67f));

    // Title
    ImGui::PushStyleColor(ImGuiCol_TitleBg,                 WithAlpha(darkest, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive,           WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed,        ImVec4(0.00f, 0.00f, 0.00f, 0.51f));

    // Menu
    ImGui::PushStyleColor(ImGuiCol_MenuBarBg,               WithAlpha(darkest, 1.00f));

    // Scrollbar
    ImGui::PushStyleColor(ImGuiCol_ScrollbarBg,             WithAlpha(veryDark, 0.53f));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrab,           WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabHovered,    WithAlpha(bright, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarGrabActive,     WithAlpha(brighter, 1.00f));

    // Widgets
    ImGui::PushStyleColor(ImGuiCol_CheckMark,               WithAlpha(base, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab,              WithAlpha(base, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive,        WithAlpha(dim, 1.00f));

    // Buttons
    ImGui::PushStyleColor(ImGuiCol_Button,                  WithAlpha(base, 0.40f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered,           WithAlpha(dim, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive,            WithAlpha(bright, 1.00f));

    // Headers
    ImGui::PushStyleColor(ImGuiCol_Header,                  WithAlpha(dim, 0.31f));
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered,           WithAlpha(base, 0.80f));
    ImGui::PushStyleColor(ImGuiCol_HeaderActive,            WithAlpha(bright, 1.00f));

    // Separators
    ImGui::PushStyleColor(ImGuiCol_Separator,               WithAlpha(dark, 0.50f));
    ImGui::PushStyleColor(ImGuiCol_SeparatorHovered,        WithAlpha(dim, 0.78f));
    ImGui::PushStyleColor(ImGuiCol_SeparatorActive,         WithAlpha(base, 1.00f));

    // Resize grip
    ImGui::PushStyleColor(ImGuiCol_ResizeGrip,              WithAlpha(base, 0.20f));
    ImGui::PushStyleColor(ImGuiCol_ResizeGripHovered,       WithAlpha(bright, 0.67f));
    ImGui::PushStyleColor(ImGuiCol_ResizeGripActive,        WithAlpha(brighter, 0.95f));

    // Cursor
    ImGui::PushStyleColor(ImGuiCol_InputTextCursor,         ImVec4(1.00f, 1.00f, 1.00f, 1.00f));

    // Tabs
    ImGui::PushStyleColor(ImGuiCol_TabHovered,              WithAlpha(base, 0.80f));
    ImGui::PushStyleColor(ImGuiCol_Tab,                     WithAlpha(dark, 0.86f));
    ImGui::PushStyleColor(ImGuiCol_TabSelected,             WithAlpha(dim, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TabSelectedOverline,     WithAlpha(base, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TabDimmed,               WithAlpha(darkest, 0.97f));
    ImGui::PushStyleColor(ImGuiCol_TabDimmedSelected,       WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TabDimmedSelectedOverline, WithAlpha(dark, 0.00f));

    // Plot
    ImGui::PushStyleColor(ImGuiCol_PlotLines,               WithAlpha(brighter, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_PlotLinesHovered,        ImVec4(1.00f, 0.43f, 0.35f, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_PlotHistogram,           ImVec4(0.90f, 0.70f, 0.00f, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_PlotHistogramHovered,    ImVec4(1.00f, 0.60f, 0.00f, 1.00f));

    // Tables
    ImGui::PushStyleColor(ImGuiCol_TableHeaderBg,           WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TableBorderStrong,       WithAlpha(darker, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TableBorderLight,        WithAlpha(darkest, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TableRowBg,              ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
    ImGui::PushStyleColor(ImGuiCol_TableRowBgAlt,           ImVec4(1.00f, 1.00f, 1.00f, 0.06f));

    // Misc
    ImGui::PushStyleColor(ImGuiCol_TextLink,                WithAlpha(dim, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_TextSelectedBg,          WithAlpha(base, 0.35f));
    ImGui::PushStyleColor(ImGuiCol_DragDropTarget,          ImVec4(1.00f, 1.00f, 0.00f, 0.90f));
    ImGui::PushStyleColor(ImGuiCol_NavCursor,               WithAlpha(dim, 1.00f));
    ImGui::PushStyleColor(ImGuiCol_NavWindowingHighlight,   ImVec4(1.00f, 1.00f, 1.00f, 0.70f));
    ImGui::PushStyleColor(ImGuiCol_NavWindowingDimBg,       ImVec4(0.80f, 0.80f, 0.80f, 0.20f));
    ImGui::PushStyleColor(ImGuiCol_ModalWindowDimBg,        ImVec4(0.80f, 0.80f, 0.80f, 0.35f));
}

inline void PopUIColor() {
    ImGui::PopStyleColor(kColorCount);
}
