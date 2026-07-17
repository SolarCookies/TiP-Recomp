#pragma once
#include <filesystem>
#include <utility>
#include <string>
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/keybinds.h>
#include "imgui.h"
#include "SmartStyles.h"
#include "TiPWidgets.h"

class TipToolsPage {
public:
    virtual ~TipToolsPage() = default;
    std::string name;
    std::string description; // this is a tooltip when hovering with the mouse
    ImColor color = ImColor(255, 255, 255);
    bool wantsClose = false;
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
            rex::ui::RegisterBind("bind_upscaling_menu", "F11", "Toggle Upscaling menu", [this] {
            TogglePage("Upscaling");
            });
        }
        ~TipToolsDialog() {
        rex::ui::UnregisterBind("bind_tool_overlay");
        rex::ui::UnregisterBind("bind_upscaling_menu");
    }

    void TogglePage(const std::string& pageName) {
        int index = -1;
        for (size_t i = 0; i < pages.size(); i++) {
            if (pages[i]->name == pageName) {
                index = static_cast<int>(i);
                break;
            }
        }
        if (index < 0) return;
        if (visible_ && selectedPage == index) {
            pages[index]->OnClose();
            selectedPage = -1;
            visible_ = false;
            return;
        }
        if (selectedPage >= 0 && selectedPage < static_cast<int>(pages.size())) {
            pages[selectedPage]->OnClose();
        }
        visible_ = true;
        selectedPage = index;
        highlightedIndex = index;
        pages[index]->OnOpen();
    }

    void DrawMenu();
    void HandleInput();
    void SaveSettings();

    void OnDraw(ImGuiIO& io) override;

    std::vector<std::unique_ptr<TipToolsPage>> pages;
    int selectedPage = -1;
    int highlightedIndex = 0;
    float lastInputTime = 0.0f;
    TiPWidgets::AccelState vertAccel;
    std::filesystem::path configPath_;
    float lastSaveTime = -1.0f;
};
