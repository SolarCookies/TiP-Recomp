#include "GraphicsMenu.h"
#include "../TiPWidgets.h"

static constexpr int kOptionCount = 12;

void GraphicsMenuPage::SyncFromCVars() {
    disableFur = REXCVAR_GET(DisableFur);
    disableMainDraw = REXCVAR_GET(DisableMainDraw);
    disableUIDraw = REXCVAR_GET(DisableUIDraw);
    useAspectRatio = REXCVAR_GET(UseAspectRatioFromConfig);
    aspectRatio = static_cast<float>(REXCVAR_GET(AspectRatio));
    skipIntros = REXCVAR_GET(SkipIntros);

    #ifdef DEBUG_BUILD
    previewDrawVerticesUP = REXCVAR_GET(PreviewDrawVerticesUP);
    previewBeginIndexedVertices = REXCVAR_GET(PreviewBeginIndexedVertices);
    previewXuiDraw = REXCVAR_GET(PreviewXuiDraw);
    previewDrawColoredQuad = REXCVAR_GET(PreviewDrawColoredQuad);
    previewDrawQuad2D = REXCVAR_GET(PreviewDrawQuad2D);
    previewDrawTexturedQuad = REXCVAR_GET(PreviewDrawTexturedQuad);
    #endif
    
}

void GraphicsMenuPage::SyncToCVars() {
    REXCVAR_SET(DisableFur, disableFur);
    REXCVAR_SET(DisableMainDraw, disableMainDraw);
    REXCVAR_SET(DisableUIDraw, disableUIDraw);
    REXCVAR_SET(UseAspectRatioFromConfig, useAspectRatio);
    REXCVAR_SET(AspectRatio, static_cast<double>(aspectRatio));
    REXCVAR_SET(SkipIntros, skipIntros);

    #ifdef DEBUG_BUILD
    REXCVAR_SET(PreviewDrawVerticesUP, previewDrawVerticesUP);
    REXCVAR_SET(PreviewBeginIndexedVertices, previewBeginIndexedVertices);
    REXCVAR_SET(PreviewXuiDraw, previewXuiDraw);
    REXCVAR_SET(PreviewDrawColoredQuad, previewDrawColoredQuad);
    REXCVAR_SET(PreviewDrawQuad2D, previewDrawQuad2D);
    REXCVAR_SET(PreviewDrawTexturedQuad, previewDrawTexturedQuad);
    #endif
}

void GraphicsMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
        return;
    }

    // Accelerated up/down navigation
    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN,
                                          ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    TiPWidgets::WrapIndex(focusIndex, kOptionCount);

    if (focusIndex != prevFocusIndex) {
        sliderHoldTime = 0.0f;
        sliderAccumulator = 0.0f;
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    // Section: Rendering
    ImGui::TextColored(ImVec4(0.5f, 0.8f, 1.0f, 1.0f), "Rendering");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Disable Fur", disableFur, focusIndex == 0, width, input);
    TiPWidgets::Toggle("Disable Main Draw", disableMainDraw, focusIndex == 1, width, input);
    TiPWidgets::Toggle("Disable UI Draw", disableUIDraw, focusIndex == 2, width, input);
    TiPWidgets::Toggle("Skip Intros", skipIntros, focusIndex == 3, width, input);
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    // Section: Aspect Ratio
    ImGui::TextColored(ImVec4(0.5f, 0.8f, 1.0f, 1.0f), "Aspect Ratio");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Use Custom Aspect Ratio", useAspectRatio, focusIndex == 4, width, input);
    TiPWidgets::FloatSlider("Aspect Ratio", aspectRatio, 0.5f, 3.5f, 0.01f,
                             focusIndex == 5, width, sliderHoldTime, sliderAccumulator);
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    // Section: Debug Previews
    ImGui::TextColored(ImVec4(0.5f, 0.8f, 1.0f, 1.0f), "Debug Previews");
    ImGui::Separator();

    #ifdef DEBUG_BUILD
    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Preview DrawVerticesUP", previewDrawVerticesUP, focusIndex == 6, width, input);
    TiPWidgets::Toggle("Preview IndexedVertices", previewBeginIndexedVertices, focusIndex == 7, width, input);
    TiPWidgets::Toggle("Preview XUI Draw", previewXuiDraw, focusIndex == 8, width, input);
    TiPWidgets::Toggle("Preview Colored Quad", previewDrawColoredQuad, focusIndex == 9, width, input);
    TiPWidgets::Toggle("Preview Quad 2D", previewDrawQuad2D, focusIndex == 10, width, input);
    TiPWidgets::Toggle("Preview Textured Quad", previewDrawTexturedQuad, focusIndex == 11, width, input);
    TiPWidgets::PopListStyle();
    #endif

    // Write all changes back to CVars every frame
    SyncToCVars();
}
