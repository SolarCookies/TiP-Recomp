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

REXCVAR_DECLARE(bool, lock_fps);
REXCVAR_DECLARE(bool, show_fps);
REXCVAR_DECLARE(bool, ShowStartupOverlay);
REXCVAR_DECLARE(bool, rgb_cursor);
REXCVAR_DECLARE(bool, SolarRendererPreview);
REXCVAR_DECLARE(bool, OverlaySolarRenderer);

class SettingsMenuPage : public TipToolsPage {
public:
    SettingsMenuPage() {
        name = "Settings";
        description = "General settings";
        color = ImColor(255, 200, 50);
        cvarCategory = "TiP/Fps";
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

    bool lockFps = false;
    bool showFps = false;
    bool showStartupOverlay = true;
};
