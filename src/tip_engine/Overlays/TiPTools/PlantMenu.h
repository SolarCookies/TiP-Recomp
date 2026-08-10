/**
******************************************************************************
* ReTiP: Viva Pinata Recompiled                                              *
******************************************************************************
* Copyright (c) 2026 SolarCookies. Licensed under custom noncommercial terms.
*
* This software is licensed for non-commercial, private, and educational use 
* only. You may modify, rewrite, and optimize this code provided that full 
* attribution is given to the original authors listed on the project repository. 
* Commercial use is prohibited.
******************************************************************************
*/

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
        cvarCategory = "TiP/Plants";
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
