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
