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

#include "PlantMenu.h"
#include <rex/cvar.h>
#include "src/tip_engine/rex_macros.h"
#include "src/tip_engine/Log.h"
#include "src/tip_engine/Globals.h"
#include "src/tip_engine/Types/CommonTypes.h"
#include <imgui.h>

// Option: Plants will always have optimal water levels
REXCVAR_DEFINE_BOOL(disable_water, false, "TiP/Plants", "Plants will always have optimal water levels");

REX_PPC_EXTERN_IMPORT(bifWatermeterSetLevel_822BEB40);
int bifWatermeterSetLevel_822BEB40_Hook(int result, double a2) {
    if (REXCVAR_GET(disable_water)) {
        const float* watermeter = reinterpret_cast<const float*>(0x100000000ull + static_cast<uint32_t>(result));
        float minLevel = to_byteswapped_float(watermeter[8]);
        float maxLevel = to_byteswapped_float(watermeter[9]);
        double optimal = static_cast<double>((maxLevel - minLevel) * 0.5f + minLevel);
        
        return GuestToHostFunction<int>(__imp__rex_bifWatermeterSetLevel_822BEB40, result, optimal);
    }
    return GuestToHostFunction<int>(__imp__rex_bifWatermeterSetLevel_822BEB40, result, a2);
};
REX_PPC_HOOK(bifWatermeterSetLevel_822BEB40);

void PlantMenuPage::SyncFromCVars() {
    disable_water_ = REXCVAR_GET(disable_water);
}

void PlantMenuPage::SyncToCVars() {
    REXCVAR_SET(disable_water, disable_water_);
}

void PlantMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
        return;
    }

    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN, ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    if (focusIndex < 0) focusIndex = 0;
    if (focusIndex > 0) focusIndex = 0;

    if (focusIndex != prevFocusIndex) {
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Optimal Water Levels", disable_water_, focusIndex == 0, width, input);
    TiPWidgets::PopListStyle();

    SyncToCVars();
}
