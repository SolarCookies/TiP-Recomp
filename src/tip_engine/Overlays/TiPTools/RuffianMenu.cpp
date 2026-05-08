#include "RuffianMenu.h"
#include <rex/cvar.h>
#include "src/tip_engine/rex_macros.h"
#include "src/tip_engine/Log.h"
#include <imgui.h>

REXCVAR_DEFINE_BOOL(disable_ruffians, false, "_Trouble in Paradise/Ruffian Settings", "Prevents ruffians from spawning");

//int rex_meCreateRuffianActor_823F89E0(int ruffiansWS, int ruffianNode)
REX_PPC_EXTERN_IMPORT(meCreateRuffianActor_823F89E0);
int meCreateRuffianActor_823F89E0_Hook(int ruffiansWS, int ruffianNode) {
    Log(LogLevel::Info, "meCreateRuffianActor Hook Hit");
    if (REXCVAR_GET(disable_ruffians)) {
        Log(LogLevel::Info, "Ruffian spawn blocked");
        return 0;
    }
    int result = rex::ppc::GuestToHostFunction<int>(__imp__rex_meCreateRuffianActor_823F89E0, ruffiansWS, ruffianNode);
    Log(LogLevel::Info, "meCreateRuffianActor Hook Finished");
    return result;
};
REX_PPC_HOOK(meCreateRuffianActor_823F89E0);

void RuffianMenuPage::SyncFromCVars() {
    disable_ruffians_ = REXCVAR_GET(disable_ruffians);
}

void RuffianMenuPage::SyncToCVars() {
    REXCVAR_SET(disable_ruffians, disable_ruffians_);
}

void RuffianMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
        return;
    }

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
    TiPWidgets::Toggle("Disable Ruffian Spawning", disable_ruffians_, focusIndex == 0, width, input);
    TiPWidgets::PopListStyle();

    SyncToCVars();
}
