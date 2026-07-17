#pragma once

#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include <cstdint>
#include <rex/cvar.h>

REXCVAR_DECLARE(bool, shovel_qol_enabled);
REXCVAR_DECLARE(int32_t, shovel_qol_hits);
REXCVAR_DECLARE(bool, shovel_qol_protect_pinatas);
REXCVAR_DECLARE(bool, shovel_qol_protect_pinata_houses);

class ShovelMenuPage : public TipToolsPage {
public:
    ShovelMenuPage() {
        name = "Shovel Settings";
        description = "Shovel related options";
        color = ImColor(210, 180, 90);
    }

    void OnOpen() override {
        focusIndex = 0;
        SyncFromCVars();
    }

    void OnDraw() override;

    void OnClose() override {}

    void SyncFromCVars();
    void SyncToCVars();

    float inputTimer = 0.0f;
    int focusIndex = 0;
    TiPWidgets::AccelState vertAccel;
    TiPWidgets::AccelState hitsAccel;
    int prevFocusIndex = -1;

    bool enabled = false;
    int hits = 1;
    bool protectPinatas = true;
    bool protectPinataHouses = true;
};
