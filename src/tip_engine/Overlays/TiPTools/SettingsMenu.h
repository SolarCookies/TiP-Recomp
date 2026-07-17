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
