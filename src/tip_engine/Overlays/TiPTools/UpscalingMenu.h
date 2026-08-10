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
