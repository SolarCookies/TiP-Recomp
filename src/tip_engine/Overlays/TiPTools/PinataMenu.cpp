#include "PinataMenu.h"
#include <rex/cvar.h>
#include "src/tip_engine/rex_macros.h"
#include <imgui.h>

REXCVAR_DEFINE_BOOL(disableSurfacePreferences, false, "TiP/Pinata", "Disable Surface Preferences for Pinatas");

REX_PPC_EXTERN_IMPORT(supportPinataActorIsOnSurfaceWithPreference_82558D28);
REX_HOOK_RAW(supportPinataActorIsOnSurfaceWithPreference_82558D28_Hook) {
    if (REXCVAR_GET(disableSurfacePreferences)) {
        ctx.r3.u32 = 0;
    } else {
        __imp__rex_supportPinataActorIsOnSurfaceWithPreference_82558D28(ctx, base);
    }
};

void PinataMenuPage::SyncFromCVars() {
    disableSurfacePreferences_ = REXCVAR_GET(disableSurfacePreferences);
}

void PinataMenuPage::SyncToCVars() {
    REXCVAR_SET(disableSurfacePreferences, disableSurfacePreferences_);
}

void PinataMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
        return;
    }

    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN, ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    if (focusIndex < 0) focusIndex = 0;
    if (focusIndex > 0) focusIndex = 0;

    if (focusIndex != prevFocusIndex) {
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Disable Surface Preferences for Pinatas", disableSurfacePreferences_, focusIndex == 0, width, input);
    TiPWidgets::PopListStyle();

    SyncToCVars();
}
