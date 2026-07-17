#pragma once
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/window.h>
#include "imgui.h"

// Full-screen "Are you sure you want to quit?" confirmation prompt.
//
// Pressing Shift+Esc or End raises the prompt; confirming closes the window
// (which quits the app via the SDK's OnClosing path). While the prompt is up it
// sets g_QuitConfirmActive so TiPToolsDialog keeps the game input locked and the
// mouse cursor free (see SetRetipInputUiMode in Globals.h), letting the user
// click the buttons.
class QuitMenuDialog : public rex::ui::ImGuiDialog {
public:
    QuitMenuDialog(rex::ui::ImGuiDrawer* drawer, rex::ui::Window* window)
        : rex::ui::ImGuiDialog(drawer), window_(window) {}

    void OnDraw(ImGuiIO& io) override;

private:
    void DrawConfirm(ImGuiIO& io);

    rex::ui::Window* window_ = nullptr;
    bool showConfirm_ = false;
    bool escWasDown_ = false;
    bool endWasDown_ = false;
};
