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
