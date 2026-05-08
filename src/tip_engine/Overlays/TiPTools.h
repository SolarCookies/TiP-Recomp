#pragma once
#include <filesystem>
#include <utility>
#include <string>
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/keybinds.h>
#include "imgui.h"
#include "SmartStyles.h"
#include "TiPWidgets.h"

// Used for submenus in the tools overlay, such as "Spawn Menu", "World Menu" and "Player Menu" (Same stuff you would see in a GTA5 mod menu)
class TipToolsPage {
public:
    virtual ~TipToolsPage() = default;
    std::string name;
    std::string description; //Tooltip
    ImColor color = ImColor(255, 255, 255); //Default white, can be used for the button color in the main menu
    bool wantsClose = false; // Set true from OnDraw to signal parent to close this page
    virtual void OnOpen() = 0;
    virtual void OnDraw() = 0;
    virtual void OnClose() = 0;
};


class TipToolsDialog : public rex::ui::ImGuiDialog {
public:
    bool visible_ = false;
    explicit TipToolsDialog(rex::ui::ImGuiDrawer* drawer, std::filesystem::path configPath)
        : rex::ui::ImGuiDialog(drawer), configPath_(std::move(configPath)) {
            rex::ui::RegisterBind("bind_tool_overlay", "F1", "Toggle Tools overlay", [this] {
            visible_ = !visible_;
            });
        }
        ~TipToolsDialog() {
        rex::ui::UnregisterBind("bind_tool_overlay");
    }

    void DrawMenu();
    void HandleInput();
    void SaveSettings();

    void OnDraw(ImGuiIO& io) override;

    std::vector<std::unique_ptr<TipToolsPage>> pages;
    int selectedPage = -1;    // -1 = no sub-panel open
    int highlightedIndex = 0; // Currently focused item (controller/keyboard)
    float lastInputTime = 0.0f; // Input debounce timer
    TiPWidgets::AccelState vertAccel;
    std::filesystem::path configPath_;
    float lastSaveTime = -1.0f;
};
