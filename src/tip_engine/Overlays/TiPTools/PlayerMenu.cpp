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

#include "PlayerMenu.h"
#include "../TiPTools.h"
#include "src/tip_engine/Types/VivaTags.h"
#include "src/tip_engine/rex_macros.h"

inline int pendingcoins = 0;
inline int pendingexp = 0;
inline int pendinglevel = 0;
inline int playerMainPtr = 0;

REX_PPC_EXTERN_IMPORT(player_playerMainUpdateHighestAndLowestCredits_8252EDA0);
int player_playerMainUpdateHighestAndLowestCredits_8252EDA0_Hook(int playerMain) {
    int result = GuestToHostFunction<int>(__imp__rex_player_playerMainUpdateHighestAndLowestCredits_8252EDA0, playerMain);

    playerMainPtr = playerMain;

    return result;
}
REX_PPC_HOOK(player_playerMainUpdateHighestAndLowestCredits_8252EDA0);

void PlayerMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
    }

    static constexpr int kOptionCount = 3;

    if(playerMainPtr <= 0) {
         return;
    }

    coins = std::byteswap(*reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 4));
    experience = std::byteswap(*reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 16));
    int level = std::byteswap(*reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 20));

    // Accelerated up/down navigation
    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN,
                                          ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    TiPWidgets::WrapIndex(focusIndex, kOptionCount);

    // Reset slider acceleration on focus change
    if (focusIndex != prevFocusIndex) {
        sliderAccel.Reset();
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    TiPWidgets::PushListStyle();
    TiPWidgets::IntSlider("Coins", coins, 0, 999999, focusIndex == 0, width, sliderAccel);
    TiPWidgets::IntSlider("Experience", experience, 0, 15000, focusIndex == 1, width, sliderAccel);
    TiPWidgets::PopListStyle();

    *reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 4) = std::byteswap(coins);
    *reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 16) = std::byteswap(experience);

}
