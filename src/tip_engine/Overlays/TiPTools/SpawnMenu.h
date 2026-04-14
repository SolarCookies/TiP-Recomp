#include "../TiPTools.h"

class SpawnMenuPage : public TipToolsPage {
public:
    SpawnMenuPage() {
        name = "Spawn Menu";
        description = "Spawn various entities in the world.";
    }

    void OnOpen() override {
    }

    void OnDraw() override {
        ImGui::Text("Spawn Menu Content Goes Here");
    }

    void OnClose() override {
    }
};