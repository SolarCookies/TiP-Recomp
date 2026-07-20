#pragma once

#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include <rex/cvar.h>

REXCVAR_DECLARE(bool, disable_water);

class PlantMenuPage : public TipToolsPage {
public:
    PlantMenuPage() {
        name = "Plant Settings";
        description = "Plant related options";
        color = ImColor(120, 200, 80);
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
    int prevFocusIndex = -1;

    bool disable_water_ = false;
};
