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
*
* DISCLAIMER: This software is provided "as-is" without warranty of any kind. 
* This project is an unofficial fan translation layer and does NOT provide, 
* distribute, or package any copyrighted game assets, binaries, or media belonging 
* to Microsoft or Rare. Users must provide their own legally obtained game assets. 
* This software must not be used in any manner that violates Microsoft's copyrights.
* DO NOT REDISTRIBUTE GAME ASSETS OR PROMOTE PIRACY.
*
* AI USE GUIDELINES:
* This project is built with minimal AI usage. We may utilize basic inline code 
* suggestions or rely on AI assistance for debugging, but the vast majority of 
* this codebase is written by hand. We manually decompile functions,
* reverse engineer structs, and write hooks to ensure accuracy and maintainability.
*
* The core goal of ReTiP is not only to get the game running, but to 
* research, document, and learn exactly how the game operates under the hood so that 
* we can provide modding support. We do not support using AI for creative 
* task or problem solving. i.e asking an AI agent to "find a way to 
* make freecam work". Instead, AI should only be used for small, boilerplate tasks or
* parsing a 1000 line crash log to isolate an error. We actively encourage all project 
* contributors to avoid the use of AI agents entirely when writing code or decompiling functions.
*
* The truth of the matter is that AI when used currectly by people who understand the output
* can be incredibly useful just like intelisense, being able to press Tab to autocomplete a
* for loop can save time. However, AI is not a replacement for human understanding and
* should not be used to replace the process of learning and understanding how the game works.
*
* We strongly prefer the use of local models that do not harm the environment and 
* can run entirely on your own local hardware over cloud based AI services. Ultimately, 
* all pull requests and code contributions will be strictly reviewed by people who 
* understand the codebase and the game. If you list Claude or any other AI as a coauthor 
* or contributor, your PR will be rejected regardless of whether it works.
******************************************************************************
*/

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
        cvarCategory = "TiP/Graphics";
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
