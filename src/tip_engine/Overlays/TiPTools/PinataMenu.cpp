#include "PinataMenu.h"
#include <rex/cvar.h>
#include "src/tip_engine/rex_macros.h"
#include <imgui.h>

// Option: Disable Surface Preferences for Pinatas
REXCVAR_DEFINE_BOOL(disableSurfacePreferences, false, "_Trouble in Paradise", "Disable Surface Preferences for Pinatas");
// BOOL __fastcall rex_supportPinataActorIsOnSurfaceWithPreference_82558D28(int a1, int wantedPreference)
REX_PPC_EXTERN_IMPORT(supportPinataActorIsOnSurfaceWithPreference_82558D28);
int supportPinataActorIsOnSurfaceWithPreference_82558D28_Hook(int a1, int wantedPreference) {
    Log(LogLevel::Info, "supportPinataActorIsOnSurfaceWithPreference Hook Hit");
    if (REXCVAR_GET(disableSurfacePreferences)) {
        Log(LogLevel::Info, "Surface preferences for pinatas are disabled, forcing preferred surface check to pass");
        return 0;
    } else {
        Log(LogLevel::Info, "Surface preferences for pinatas are enabled, performing normal check");
        int result = rex::ppc::GuestToHostFunction<int>(__imp__rex_supportPinataActorIsOnSurfaceWithPreference_82558D28, a1, wantedPreference);
        Log(LogLevel::Info, "supportPinataActorIsOnSurfaceWithPreference Hook Finished");
        return result;
    }
};
REX_PPC_HOOK(supportPinataActorIsOnSurfaceWithPreference_82558D28);

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

    // Navigation (only one option for now)
    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN,
                                         ImGuiKey_UpArrow, ImGuiKey_DownArrow);
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

    // Write changes back to CVar
    SyncToCVars();
}
