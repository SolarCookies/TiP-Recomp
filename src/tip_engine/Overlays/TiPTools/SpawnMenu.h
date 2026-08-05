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
* The core goal of ReTiP is not only to get the software running, but to 
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

#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include "src/tip_engine/Types/VivaTags.h"

class SpawnMenuPage : public TipToolsPage {
public:
    SpawnMenuPage() {
        name = "Spawn Menu";
        description = "Spawn Pinata and Items in the World";
        color = ImColor(100, 149, 237);
    }

    void OnOpen() override {
        categoryFocusIndex = 0;
        selectedCategory = -1;
        categoryScrollToFocus = true;
        itemFocusIndex = 0;
        selectedItemIndex = -1;
        itemScrollToFocus = false;
        optionsFocusIndex = 0;
        memset(searchBuffer, 0, sizeof(searchBuffer));
    }

    void OnDraw() override;

    void OnClose() override {
        selectedItemIndex = -1;
        selectedCategory = -1;
    }

    int categoryFocusIndex = 0;
    int selectedCategory = -1;
    bool categoryScrollToFocus = false;

    int itemFocusIndex = 0;
    int selectedItemIndex = -1;
    bool itemScrollToFocus = false;
    char searchBuffer[64] = {};

    int optionsFocusIndex = 0;
    int variantIndex = 0;
    int wildcardIndex = 0;
    bool Wild = false;
    bool isResident = false;
    float sizeScale = 1.0f;

    TiPWidgets::AccelState vertAccel;
    TiPWidgets::AccelState sliderAccel;
    int prevPanel = -1;

    float inputTimer = 0.0f;
};
