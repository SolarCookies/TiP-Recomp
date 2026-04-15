#include "TiPTools.h"
#include "imgui.h"

void TipToolsDialog::DrawMenu() {
    ImGui::Begin("TiP Tools");

    if (currentPage == 0) {
        for (size_t i = 0; i < pages.size(); i++) {
            if (ImGui::Button(pages[i]->name.c_str())) {
                currentPage = static_cast<uint32_t>(i + 1);
                pages[i]->OnOpen();
            }
            if (ImGui::IsItemHovered()) {
                ImGui::SetTooltip("%s", pages[i]->description.c_str());
            }
        }
    } else {
        uint32_t pageIndex = currentPage - 1;
        if (pageIndex < pages.size()) {
            if (ImGui::Button("Back")) {
                pages[pageIndex]->OnClose();
                currentPage = 0;
            }
            ImGui::Separator();
            pages[pageIndex]->OnDraw();
        } else {
            currentPage = 0;
        }
    }

    ImGui::End();
}