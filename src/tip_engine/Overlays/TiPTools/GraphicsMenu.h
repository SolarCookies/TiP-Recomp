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

#ifdef DEBUG_BUILD
REXCVAR_DECLARE(bool, PreviewDrawVerticesUP);
REXCVAR_DECLARE(bool, PreviewBeginIndexedVertices);
REXCVAR_DECLARE(bool, PreviewXuiDraw);
REXCVAR_DECLARE(bool, PreviewDrawColoredQuad);
REXCVAR_DECLARE(bool, PreviewDrawQuad2D);
REXCVAR_DECLARE(bool, PreviewDrawTexturedQuad);
#endif

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

    // Local state mirroring CVars
    bool disableFur = false;
    bool disableMainDraw = false;
    bool disableUIDraw = false;
    bool useAspectRatio = false;
    float aspectRatio = 1.7777778f;
    bool skipIntros = false;

    #ifdef DEBUG_BUILD
    bool previewDrawVerticesUP = false;
    bool previewBeginIndexedVertices = false;
    bool previewXuiDraw = false;
    bool previewDrawColoredQuad = false;
    bool previewDrawQuad2D = false;
    bool previewDrawTexturedQuad = false;
    #endif

    float sliderHoldTime = 0.0f;
    float sliderAccumulator = 0.0f;
};
