#include "TiPTools.h"
#include "imgui.h"
#include "SmartStyles.h"
#include "TiPWidgets.h"
#include "tip_engine/Globals.h"

static constexpr float kMenuWidth = 220.0f;
static constexpr float kSubPanelWidth = 320.0f;
static constexpr float kMenuPadding = 2.0f;
static constexpr float kItemHeight = 32.0f;
static constexpr float kHeaderHeight = 38.0f;

void TipToolsDialog::HandleInput() {
    // When a sub-page is open, don't poll — the sub-page handles its own input.
    // The sub-page sets wantsClose=true when the user presses B at the top level.
    if (selectedPage >= 0) return;

    auto input = TiPWidgets::PollInput(lastInputTime, 0.18f);

    int pageCount = static_cast<int>(pages.size());
    if (pageCount == 0) return;

    // Accelerated up/down navigation
    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN,
                                          ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    if (vertDelta != 0) {
        highlightedIndex = ((highlightedIndex + vertDelta) % pageCount + pageCount) % pageCount;
    }
    if (input.confirm) {
        selectedPage = highlightedIndex;
        pages[selectedPage]->OnOpen();
        TiPWidgets::SetInputCooldown(0.25f);
    }
    if (input.back) {
        visible_ = false;
        TiPWidgets::SetInputCooldown(0.25f);
    }
}

void TipToolsDialog::DrawMenu() {
    // Lock game input while menu is visible
    g_LockGameInput = true;

    HandleInput();
    SetUIColor(ImColor(0, 255, 150));

    ImGuiWindowFlags menuFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoNav;

    // Calculate total window height: header + items (no extra padding since WindowPadding is 0 for the item area)
    float totalHeight = kHeaderHeight + (kItemHeight * pages.size());
    ImGui::SetNextWindowSize(ImVec2(kMenuWidth, totalHeight), ImGuiCond_Always);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin("TiP Tools###TiPMainMenu", nullptr, menuFlags);
    ImGui::PopStyleVar(); // WindowPadding

    // --- Header banner ---
    {
        ImVec2 winPos = ImGui::GetWindowPos();
        ImVec2 headerMin = ImVec2(winPos.x, winPos.y);
        ImVec2 headerMax = ImVec2(winPos.x + kMenuWidth, winPos.y + kHeaderHeight);

        ImGui::GetWindowDrawList()->AddRectFilled(headerMin, headerMax, ImColor(0, 200, 120, 255));

        // Close [X] button in top-right of header
        {
            const char* xLabel = "X";
            ImVec2 xSize = ImGui::CalcTextSize(xLabel);
            float xPad = 6.0f;
            ImVec2 xBtnMin = ImVec2(headerMax.x - xSize.x - xPad * 2.0f, headerMin.y + 2.0f);
            ImVec2 xBtnMax = ImVec2(headerMax.x - 2.0f, headerMin.y + kHeaderHeight - 2.0f);
            ImVec2 xTextPos = ImVec2(
                xBtnMin.x + ((xBtnMax.x - xBtnMin.x) - xSize.x) * 0.5f,
                xBtnMin.y + ((xBtnMax.y - xBtnMin.y) - xSize.y) * 0.5f
            );

            bool xHovered = ImGui::IsMouseHoveringRect(xBtnMin, xBtnMax);
            ImU32 xBg = xHovered ? ImColor(200, 50, 50, 255) : ImColor(0, 160, 100, 255);
            ImGui::GetWindowDrawList()->AddRectFilled(xBtnMin, xBtnMax, xBg, 4.0f);
            ImGui::GetWindowDrawList()->AddText(xTextPos, ImColor(255, 255, 255, 255), xLabel);

            if (xHovered && ImGui::IsMouseClicked(0)) {
                visible_ = false;
            }
        }

        // Center the title text
        const char* title = "ReTip 1.9 Tools";
        ImVec2 textSize = ImGui::CalcTextSize(title);
        ImVec2 textPos = ImVec2(
            headerMin.x + (kMenuWidth - textSize.x) * 0.5f,
            headerMin.y + (kHeaderHeight - textSize.y) * 0.5f
        );
        ImGui::GetWindowDrawList()->AddText(textPos, ImColor(255, 255, 255, 255), title);

        // Push cursor past the header
        ImGui::SetCursorPosY(kHeaderHeight);
        ImGui::SetCursorPosX(0);
    }

    // --- Category list items (flat, no spacing, full-width rectangles) ---
    TiPWidgets::PushListStyle();

    for (size_t i = 0; i < pages.size(); i++) {
        bool isSelected = (selectedPage == static_cast<int>(i));
        bool isHighlighted = (highlightedIndex == static_cast<int>(i));

        if (TiPWidgets::ListButton(pages[i]->name.c_str(), isHighlighted, isSelected,
                                    kMenuWidth, kItemHeight, true)) {
            highlightedIndex = static_cast<int>(i);
            if (isSelected) {
                pages[i]->OnClose();
                selectedPage = -1;
            } else {
                if (selectedPage >= 0 && selectedPage < static_cast<int>(pages.size()))
                    pages[selectedPage]->OnClose();
                selectedPage = static_cast<int>(i);
                pages[i]->OnOpen();
            }
        }

        if (ImGui::IsItemHovered()) {
            highlightedIndex = static_cast<int>(i);
            ImGui::SetTooltip("%s", pages[i]->description.c_str());
        }
    }

    TiPWidgets::PopListStyle();

    // Capture main menu position for sub-panel placement
    ImVec2 menuPos = ImGui::GetWindowPos();
    ImGui::End();
    PopUIColor();

    // Draw sub-panel to the right of the main menu
    if (selectedPage >= 0 && selectedPage < static_cast<int>(pages.size())) {
        SetUIColor(pages[selectedPage]->color);

        ImGui::SetNextWindowPos(ImVec2(menuPos.x + kMenuWidth + kMenuPadding, menuPos.y), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(kSubPanelWidth, 0), ImGuiCond_Always);

        std::string panelTitle = pages[selectedPage]->name + "###TiPSubPanel";
        bool subPanelOpen = true;
        ImGui::Begin(panelTitle.c_str(), &subPanelOpen,
            ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);

        pages[selectedPage]->OnDraw();

        ImGui::End();
        PopUIColor();

        // Check if the sub-page wants to close itself (user pressed B or clicked X)
        if (!subPanelOpen || pages[selectedPage]->wantsClose) {
            pages[selectedPage]->wantsClose = false;
            pages[selectedPage]->OnClose();
            selectedPage = -1;
            TiPWidgets::SetInputCooldown(0.25f);
        }
    }
}

void TipToolsDialog::OnDraw(ImGuiIO& io) {
    // Select (Back) controller toggle (with debounce)
    static float lastToggleTime = 0.0f;
    float now = (float)ImGui::GetTime();
    if (TiPWidgets::IsSelectPressed() && (now - lastToggleTime > 0.4f)) {
        visible_ = !visible_;
        lastToggleTime = now;
        if (visible_)
            TiPWidgets::SetInputCooldown(0.3f); // Don't immediately process A/B after opening
    }

    if (!visible_) {
        g_LockGameInput = false;
        return;
    }
    DrawMenu();
}