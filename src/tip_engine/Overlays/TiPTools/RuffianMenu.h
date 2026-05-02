#pragma once

#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include <rex/cvar.h>

REXCVAR_DECLARE(bool, disable_ruffians);

class RuffianMenuPage : public TipToolsPage {
public:
    RuffianMenuPage() {
        name = "Ruffian Settings";
        description = "Ruffian related options";
        color = ImColor(200, 80, 80);
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

    // Local state mirroring CVars
    bool disable_ruffians_ = false;
};
