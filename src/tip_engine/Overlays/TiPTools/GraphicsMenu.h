#pragma once
#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include <rex/cvar.h>

REXCVAR_DECLARE(bool, DisableFur);
REXCVAR_DECLARE(bool, DisableMainDraw);
REXCVAR_DECLARE(bool, DisableUIDraw);
REXCVAR_DECLARE(bool, UseAspectRatioFromConfig);
REXCVAR_DECLARE(double, AspectRatio);
REXCVAR_DECLARE(bool, SkipIntros);
REXCVAR_DECLARE(bool, EnableShadows);
REXCVAR_DECLARE(bool, EnableReflections);
REXCVAR_DECLARE(bool, EnableOcclusions);
REXCVAR_DECLARE(bool, EnableTransparency);
REXCVAR_DECLARE(bool, EnableModels);
REXCVAR_DECLARE(bool, EnableSceneEffects);
REXCVAR_DECLARE(bool, EnableBloom);

class GraphicsMenuPage : public TipToolsPage {
public:
    GraphicsMenuPage() {
        name = "Graphics";
        description = "Graphics and rendering settings";
        color = ImColor(80, 200, 255);
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

    bool disableFur = false;
    bool disableMainDraw = false;
    bool disableUIDraw = false;
    bool useAspectRatio = false;
    float aspectRatio = 1.7777778f;
    bool skipIntros = false;
    bool enableShadows = true;
    bool enableReflections = true;
    bool enableOcclusions = true;
    bool enableTransparency = true;
    bool enableModels = true;
    bool enableSceneEffects = true;
    bool enableBloom = true;

    float sliderHoldTime = 0.0f;
    float sliderAccumulator = 0.0f;
};
