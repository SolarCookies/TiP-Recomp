#include "SettingsMenu.h"
#include "../TiPWidgets.h"

static constexpr int kOptionCount = 6;

void SettingsMenuPage::SyncFromCVars() {
    lockFps = REXCVAR_GET(lock_fps);
    showFps = REXCVAR_GET(show_fps);
    showStartupOverlay = REXCVAR_GET(ShowStartupOverlay);
    rgbCursor = REXCVAR_GET(rgb_cursor);
    //solarRendererPreview = REXCVAR_GET(SolarRendererPreview);
    //overlaySolarRenderer = REXCVAR_GET(OverlaySolarRenderer);
}

void SettingsMenuPage::SyncToCVars() {
    REXCVAR_SET(lock_fps, lockFps);
    REXCVAR_SET(show_fps, showFps);
    REXCVAR_SET(ShowStartupOverlay, showStartupOverlay);
    REXCVAR_SET(rgb_cursor, rgbCursor);
    // SolarRendererPreview and OverlaySolarRenderer require restart - don't sync
}

void SettingsMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
        return;
    }

    // Accelerated up/down navigation
    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN,
                                          ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    TiPWidgets::WrapIndex(focusIndex, kOptionCount);

    if (focusIndex != prevFocusIndex) {
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    // Section: Performance
    ImGui::TextColored(ImVec4(1.0f, 0.85f, 0.3f, 1.0f), "Performance");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Lock FPS (30)", lockFps, focusIndex == 0, width, input);
    TiPWidgets::Toggle("Show FPS Overlay", showFps, focusIndex == 1, width, input);
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    // Section: UI
    ImGui::TextColored(ImVec4(1.0f, 0.85f, 0.3f, 1.0f), "UI");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Show Startup Overlay", showStartupOverlay, focusIndex == 2, width, input);
    TiPWidgets::Toggle("RGB Cursor", rgbCursor, focusIndex == 3, width, input);
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    // Section: Solar Renderer (requires restart)
    ImGui::TextColored(ImVec4(1.0f, 0.85f, 0.3f, 1.0f), "Solar Renderer (Restart Required)");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    // Show current state but grey them out to indicate restart required
    ImGui::BeginDisabled();
    bool solarCopy = solarRendererPreview;
    bool overlayCopy = overlaySolarRenderer;
    TiPWidgets::Toggle("Solar Renderer", solarCopy, focusIndex == 4, width, input);
    TiPWidgets::Toggle("Overlay Solar Renderer", overlayCopy, focusIndex == 5, width, input);
    ImGui::EndDisabled();
    TiPWidgets::PopListStyle();

    if (focusIndex == 4 || focusIndex == 5) {
        ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Change in retip.toml (requires restart)");
    }

    // Write toggleable changes back to CVars
    SyncToCVars();
}
