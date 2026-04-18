#include "PlayerMenu.h"
#include "../TiPTools.h"
#include "src/tip_engine/Types/VivaTags.h"


void PlayerMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
    }

    static constexpr int kOptionCount = 3;

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
    TiPWidgets::IntSlider("Experience", experience, 0, 999999, focusIndex == 1, width, sliderAccel);
    TiPWidgets::IntSlider("Level", level, 0, 196, focusIndex == 2, width, sliderAccel);
    TiPWidgets::PopListStyle();
}
