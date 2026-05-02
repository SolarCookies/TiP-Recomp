#include "PlantMenu.h"
#include <rex/cvar.h>
#include "src/tip_engine/rex_macros.h"
#include "src/tip_engine/Log.h"
#include "src/tip_engine/Globals.h"
#include "src/tip_engine/Types/CommonTypes.h"
#include <imgui.h>

// Option: Plants will always have optimal water levels
REXCVAR_DEFINE_BOOL(disable_water, false, "_Trouble in Paradise", "Plants will always have optimal water levels");

// int __fastcall rex_bifWatermeterSetLevel_822BEB40(int result, double a2)
//
// `result` is the watermeter object (guest VA). The original caller computes
// the requested level relative to a parent struct as:
//   rex_bifWatermeterSetLevel_822BEB40(
//       (int)(parent + 1000),
//       (max - min) * 0.5f + min);
// where min/max live at parent[1008] / parent[1009] (floats). Relative to the
// watermeter pointer (parent + 1000 ints == parent + 4000 bytes), min/max are
// at float offsets +8 / +9. When `disable_water` is enabled we override the
// incoming a2 with the optimal midpoint so plants always sit at the ideal
// water level instead of fully blocking the call.
REX_PPC_EXTERN_IMPORT(bifWatermeterSetLevel_822BEB40);
int bifWatermeterSetLevel_822BEB40_Hook(int result, double a2) {
    Log(LogLevel::Info, "bifWatermeterSetLevel Hook Hit");
    if (REXCVAR_GET(disable_water)) {
        const float* watermeter = reinterpret_cast<const float*>(0x100000000ull + static_cast<uint32_t>(result));
        float minLevel = to_byteswapped_float(watermeter[8]);
        float maxLevel = to_byteswapped_float(watermeter[9]);
        double optimal = static_cast<double>((maxLevel - minLevel) * 0.5f + minLevel);
        Log(LogLevel::Info,
            "Water level overridden from " + std::to_string(a2) +
            " to optimal " + std::to_string(optimal));
        return rex::GuestToHostFunction<int>(__imp__rex_bifWatermeterSetLevel_822BEB40, result, optimal);
    }
    return rex::GuestToHostFunction<int>(__imp__rex_bifWatermeterSetLevel_822BEB40, result, a2);
};
REX_PPC_HOOK(bifWatermeterSetLevel_822BEB40);

void PlantMenuPage::SyncFromCVars() {
    disable_water_ = REXCVAR_GET(disable_water);
}

void PlantMenuPage::SyncToCVars() {
    REXCVAR_SET(disable_water, disable_water_);
}

void PlantMenuPage::OnDraw() {
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
    TiPWidgets::Toggle("Optimal Water Levels", disable_water_, focusIndex == 0, width, input);
    TiPWidgets::PopListStyle();

    SyncToCVars();
}
