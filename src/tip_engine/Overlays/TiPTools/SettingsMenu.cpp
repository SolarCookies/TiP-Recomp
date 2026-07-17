#include "SettingsMenu.h"
#include "../TiPWidgets.h"

static constexpr int kOptionCount = 3;

void SettingsMenuPage::SyncFromCVars() {
    lockFps = REXCVAR_GET(lock_fps);
    showFps = REXCVAR_GET(show_fps);
    showStartupOverlay = REXCVAR_GET(ShowStartupOverlay);
}

void SettingsMenuPage::SyncToCVars() {
    REXCVAR_SET(lock_fps, lockFps);
    REXCVAR_SET(show_fps, showFps);
    REXCVAR_SET(ShowStartupOverlay, showStartupOverlay);
}

void SettingsMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
        return;
    }

    // Accelerated up/down navigation
    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN, ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    TiPWidgets::WrapIndex(focusIndex, kOptionCount);

    if (focusIndex != prevFocusIndex) {
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    ImGui::TextColored(ImVec4(1.0f, 0.85f, 0.3f, 1.0f), "Performance");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Lock FPS (30)", lockFps, focusIndex == 0, width, input);
    TiPWidgets::Toggle("Show FPS Overlay", showFps, focusIndex == 1, width, input);
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1.0f, 0.85f, 0.3f, 1.0f), "UI");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Show Startup Overlay", showStartupOverlay, focusIndex == 2, width, input);
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    SyncToCVars();
}
