#pragma once
#include <string>
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/keybinds.h>
#include "imgui.h"

// Used for submenus in the tools overlay, such as "Spawn Menu", "World Menu" and "Player Menu" (Same stuff you would see in a GTA5 mod menu)
class TipToolsPage {
public:
    virtual ~TipToolsPage() = default;
    std::string name;
    std::string description; //Tooltip
    virtual void OnOpen() = 0;
    virtual void OnDraw() = 0;
    virtual void OnClose() = 0;
};


class TipToolsDialog : public rex::ui::ImGuiDialog {
public:
    bool visible_ = false;
    explicit TipToolsDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer) {
            rex::ui::RegisterBind("bind_tool_overlay", "F1", "Toggle Tools overlay", [this] {
            visible_ = !visible_;
            });
        }
        ~TipToolsDialog() {
        rex::ui::UnregisterBind("bind_tool_overlay");
    }

    void DrawMenu();

    void OnDraw(ImGuiIO& io) override{
        if (!visible_) return;
        DrawMenu();
    }

    std::vector<std::unique_ptr<TipToolsPage>> pages;
    uint32_t currentPage = 0; //0 is the main menu, 1 is the 0 index of "pages"
};