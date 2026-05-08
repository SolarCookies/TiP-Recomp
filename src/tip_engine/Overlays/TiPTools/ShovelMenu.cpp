#include "ShovelMenu.h"
#include "src/tip_engine/rex_macros.h"
#include "src/tip_engine/Types/VivaTags.h"
#include <bit>
#include <cstdint>
#include <imgui.h>
#include <limits>

static constexpr int kOptionCount = 4;

REXCVAR_DEFINE_BOOL(shovel_qol_enabled, false, "_Trouble in Paradise/Shovel", "Apply extra shovel hits per swing");
REXCVAR_DEFINE_INT32(shovel_qol_hits, 1, "_Trouble in Paradise/Shovel", "Shovel hits applied per swing").range(1, 10);
REXCVAR_DEFINE_BOOL(shovel_qol_protect_pinatas, true, "_Trouble in Paradise/Shovel", "Keep shovel QoL from affecting Pinatas");
REXCVAR_DEFINE_BOOL(shovel_qol_protect_pinata_houses, true, "_Trouble in Paradise/Shovel", "Keep shovel QoL from affecting Pinata houses");

static int ShovelQolHits() {
    int hits = REXCVAR_GET(shovel_qol_hits);
    if (hits < 1) return 1;
    if (hits > 10) return 10;
    return hits;
}

static bool ShovelQolAffectsPinatas() {
    return REXCVAR_GET(shovel_qol_enabled) && !REXCVAR_GET(shovel_qol_protect_pinatas);
}

static uint32_t ReadGuestU32(uint32_t addr) {
    auto* value = reinterpret_cast<const uint32_t*>(0x100000000ull + addr);
    return std::byteswap(*value);
}

PPC_EXTERN_IMPORT(sub_825A0818);
PPC_EXTERN_IMPORT(__imp__sub_82512AC0);

static int ActorTagClass(int actor) {
    if (actor == 0) return supportPinataTag_Class_UNKNOWN;

    uint32_t tag = ReadGuestU32(static_cast<uint32_t>(actor) + 132);
    return rex::GuestToHostFunction<int>(sub_825A0818, tag);
}

static bool IsHitMeterCaller(uint32_t caller) {
    switch (caller) {
    case 0x8230D030:
    case 0x82318E24:
    case 0x82337754:
    case 0x82341FF8:
    case 0x8237992C:
    case 0x8251289C:
    case 0x8256ACBC:
        return true;
    default:
        return false;
    }
}

static int ScaleHitMeterDamage(int actor, int amount) {
    if (!REXCVAR_GET(shovel_qol_enabled) || amount <= 0) return amount;

    int hits = ShovelQolHits();
    if (hits <= 1) return amount;

    int tagClass = ActorTagClass(actor);
    if (!ShovelQolAffectsPinatas() && tagClass == supportPinataTag_Class_Animal) return amount;
    if (REXCVAR_GET(shovel_qol_protect_pinata_houses) &&
        (tagClass == supportPinataTag_Class_Home || tagClass == supportPinataTag_Class_HouseBlock)) {
        return amount;
    }

    int64_t scaled = static_cast<int64_t>(amount) * hits;
    if (scaled > std::numeric_limits<int>::max()) return std::numeric_limits<int>::max();
    return static_cast<int>(scaled);
}

int sub_82512AC0_Hook(int actor, int amount, int update) {
    if (IsHitMeterCaller(rex::GetGuestCallerAddress())) {
        amount = ScaleHitMeterDamage(actor, amount);
    }

    return rex::GuestToHostFunction<int>(__imp__sub_82512AC0, actor, amount, update);
}
PPC_HOOK(sub_82512AC0, sub_82512AC0_Hook);

void ShovelMenuPage::SyncFromCVars() {
    enabled = REXCVAR_GET(shovel_qol_enabled);
    hits = ShovelQolHits();
    protectPinatas = REXCVAR_GET(shovel_qol_protect_pinatas);
    protectPinataHouses = REXCVAR_GET(shovel_qol_protect_pinata_houses);
}

void ShovelMenuPage::SyncToCVars() {
    REXCVAR_SET(shovel_qol_enabled, enabled);
    REXCVAR_SET(shovel_qol_hits, hits);
    REXCVAR_SET(shovel_qol_protect_pinatas, protectPinatas);
    REXCVAR_SET(shovel_qol_protect_pinata_houses, protectPinataHouses);
}

void ShovelMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
        return;
    }

    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN,
                                         ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    TiPWidgets::WrapIndex(focusIndex, kOptionCount);

    if (focusIndex != prevFocusIndex) {
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Enable Shovel QoL", enabled, focusIndex == 0, width, input);
    TiPWidgets::Toggle("Protect Pinatas", protectPinatas, focusIndex == 1, width, input);
    TiPWidgets::Toggle("Protect Pinata Houses", protectPinataHouses, focusIndex == 2, width, input);
    TiPWidgets::IntSlider("Hits Per Swing", hits, 1, 10, focusIndex == 3, width, hitsAccel);
    TiPWidgets::PopListStyle();

    SyncToCVars();
}
