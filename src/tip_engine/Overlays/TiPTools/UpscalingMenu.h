#pragma once
#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include <rex/cvar.h>

class UpscalingMenuPage : public TipToolsPage {
public:
    UpscalingMenuPage() {
        name = "Upscaling";
        description = "FidelityFX upscaling and sharpening";
        color = ImColor(255, 60, 60);
    }

    void OnOpen() override {
        focusIndex = 0;
        SyncFromCVars();
    }

    void OnDraw() override;

    void OnClose() override {}

    void SyncFromCVars();

    float inputTimer = 0.0f;
    int focusIndex = 0;
    TiPWidgets::AccelState vertAccel;
    int prevFocusIndex = -1;

    int effectIndex = 0;
    int qualityIndex = 0;
    float fsrSharpnessReduction = 0.2f;
    float casAdditionalSharpness = 0.0f;
    bool dither = false;
    bool frameGeneration = false;

    float sliderHoldTime = 0.0f;
    float sliderAccumulator = 0.0f;
};
