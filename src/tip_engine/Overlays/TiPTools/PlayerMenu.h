#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include "src/tip_engine/Types/VivaTags.h"

class PlayerMenuPage : public TipToolsPage {
public:
    PlayerMenuPage() {
        name = "Player Menu";
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
    int level = 0;
};