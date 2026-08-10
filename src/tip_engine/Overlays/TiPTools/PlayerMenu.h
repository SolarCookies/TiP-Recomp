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

#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include "src/tip_engine/Types/VivaTags.h"

class PlayerMenuPage : public TipToolsPage {
public:
    PlayerMenuPage() {
        name = "Player Settings";
        description = "Manage player settings";
        color = ImColor(255, 0, 0); // Red
    }

    void OnOpen() override {
    }

    void OnDraw() override;

    void OnClose() override {
    }

    float inputTimer = 0.0f;
    int focusIndex = 0;
    TiPWidgets::AccelState vertAccel;
    TiPWidgets::AccelState sliderAccel;
    int prevFocusIndex = -1;
    int coins = 0;
    int experience = 0;
};
