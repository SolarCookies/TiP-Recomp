#include "../TiPTools.h"

class SpawnMenuPage : public TipToolsPage {
public:
    SpawnMenuPage() {
        name = "Spawn Menu";
        description = "Spawn Pinata and Items in the world.";
    }

    void OnOpen() override {
    }

    void OnDraw() override {
        ImGui::Text("Spawn Menu Will Be In Next Update");
    }

    void OnClose() override {
    }
};