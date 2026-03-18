#pragma once
#include <rex/ui/imgui_dialog.h>
#include "imgui.h"


class FpsOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit FpsOverlayDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer) {}

    void OnDraw(ImGuiIO& io) override;
};