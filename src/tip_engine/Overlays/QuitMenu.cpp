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
