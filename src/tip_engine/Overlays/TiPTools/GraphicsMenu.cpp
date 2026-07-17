#include "GraphicsMenu.h"
#include "../TiPWidgets.h"
#include "src/tip_engine/rex_macros.h"

static constexpr int kOptionCount = 12;

REXCVAR_DEFINE_BOOL(EnableShadows, true, "TiP/Graphics", "Enables shadows");
REXCVAR_DEFINE_BOOL(EnableReflections, true, "TiP/Graphics", "Enables reflections");
REXCVAR_DEFINE_BOOL(EnableOcclusions, true, "TiP/Graphics", "Enables contact occlusions");
REXCVAR_DEFINE_BOOL(EnableTransparency, true, "TiP/Graphics", "Enables transparency pass");
REXCVAR_DEFINE_BOOL(EnableModels, true, "TiP/Graphics", "Enables depth of field post-process");
REXCVAR_DEFINE_BOOL(EnableSceneEffects, true, "TiP/Graphics", "Enables scene effects");
REXCVAR_DEFINE_BOOL(EnableBloom, true, "TiP/Graphics", "Enables bloom post-process");

 //sceneObjDrawShadowUpdate
REX_EXTERN(__imp__sub_82264AE0);
REX_HOOK_RAW(sub_82264AE0) {
    if (REXCVAR_GET(EnableShadows)) {
        __imp__sub_82264AE0(ctx, base);
    }
}

 //meRenderReflection
REX_EXTERN(__imp__sub_822F5410);
REX_HOOK_RAW(sub_822F5410) {
    if (REXCVAR_GET(EnableReflections)) {
        __imp__sub_822F5410(ctx, base);
    }
}

 //meRenderContactOcclusionPassFromRenderList
REX_EXTERN(__imp__sub_822F5BE8);
REX_HOOK_RAW(sub_822F5BE8) {
    if (REXCVAR_GET(EnableOcclusions)) {
        __imp__sub_822F5BE8(ctx, base);
    }
}

 //sceneObjDrawRenderContactOcclusionPass
REX_EXTERN(__imp__sub_82265658);
REX_HOOK_RAW(sub_82265658) {
    if (REXCVAR_GET(EnableOcclusions)) {
        __imp__sub_82265658(ctx, base);
    }
}

 //meTransparentPass
REX_EXTERN(__imp__sub_82265480);
REX_HOOK_RAW(sub_82265480) {
    if (REXCVAR_GET(EnableTransparency)) {
        __imp__sub_82265480(ctx, base);
    }
}

 //scenegraphDrawRender
REX_EXTERN(__imp__sub_822734A8);
REX_HOOK_RAW(sub_822734A8) {
    if (REXCVAR_GET(EnableModels)) {
        __imp__sub_822734A8(ctx, base);
    }
}

 //sceneEffectDraw
REX_EXTERN(__imp__sub_82217178);
REX_HOOK_RAW(sub_82217178) {
    if (REXCVAR_GET(EnableSceneEffects)) {
        __imp__sub_82217178(ctx, base);
    }
}

 //drawPostProcessBloomDraw
REX_EXTERN(__imp__sub_82206AC0);
REX_HOOK_RAW(sub_82206AC0) {
    if (REXCVAR_GET(EnableBloom)) {
        __imp__sub_82206AC0(ctx, base);
    }
}

void GraphicsMenuPage::SyncFromCVars() {
    disableMainDraw = REXCVAR_GET(DisableMainDraw);
    disableUIDraw = REXCVAR_GET(DisableUIDraw);
    useAspectRatio = REXCVAR_GET(UseAspectRatioFromConfig);
    aspectRatio = static_cast<float>(REXCVAR_GET(AspectRatio));
    skipIntros = REXCVAR_GET(SkipIntros);
    enableShadows = REXCVAR_GET(EnableShadows);
    enableReflections = REXCVAR_GET(EnableReflections);
    enableOcclusions = REXCVAR_GET(EnableOcclusions);
    enableTransparency = REXCVAR_GET(EnableTransparency);
    enableModels = REXCVAR_GET(EnableModels);
    enableSceneEffects = REXCVAR_GET(EnableSceneEffects);
    enableBloom = REXCVAR_GET(EnableBloom);
}

void GraphicsMenuPage::SyncToCVars() {
    REXCVAR_SET(DisableMainDraw, disableMainDraw);
    REXCVAR_SET(DisableUIDraw, disableUIDraw);
    REXCVAR_SET(UseAspectRatioFromConfig, useAspectRatio);
    REXCVAR_SET(AspectRatio, static_cast<double>(aspectRatio));
    REXCVAR_SET(SkipIntros, skipIntros);
    REXCVAR_SET(EnableShadows, enableShadows);
    REXCVAR_SET(EnableReflections, enableReflections);
    REXCVAR_SET(EnableOcclusions, enableOcclusions);
    REXCVAR_SET(EnableTransparency, enableTransparency);
    REXCVAR_SET(EnableModels, enableModels);
    REXCVAR_SET(EnableSceneEffects, enableSceneEffects);
    REXCVAR_SET(EnableBloom, enableBloom);
}

void GraphicsMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
        return;
    }

    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN, ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    TiPWidgets::WrapIndex(focusIndex, kOptionCount);

    if (focusIndex != prevFocusIndex) {
        sliderHoldTime = 0.0f;
        sliderAccumulator = 0.0f;
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    ImGui::TextColored(ImVec4(0.5f, 0.8f, 1.0f, 1.0f), "Rendering");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Disable Main Draw", disableMainDraw, focusIndex == 0, width, input);
    TiPWidgets::Toggle("Disable UI Draw", disableUIDraw, focusIndex == 1, width, input);
    TiPWidgets::Toggle("Skip Intros", skipIntros, focusIndex == 2, width, input);
    TiPWidgets::Toggle("Enable Shadows", enableShadows, focusIndex == 3, width, input);
    TiPWidgets::Toggle("Enable Reflections", enableReflections, focusIndex == 4, width, input);
    TiPWidgets::Toggle("Enable Occlusions", enableOcclusions, focusIndex == 5, width, input);
    TiPWidgets::Toggle("Enable Transparency", enableTransparency, focusIndex == 6, width, input);
    TiPWidgets::Toggle("Enable Depth Of Field", enableModels, focusIndex == 7, width, input);
    TiPWidgets::Toggle("Enable Scene Effects", enableSceneEffects, focusIndex == 8, width, input);
    TiPWidgets::Toggle("Enable Bloom", enableBloom, focusIndex == 9, width, input);
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(0.5f, 0.8f, 1.0f, 1.0f), "Aspect Ratio");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    TiPWidgets::Toggle("Use Custom Aspect Ratio", useAspectRatio, focusIndex == 10, width, input);
    TiPWidgets::FloatSlider("Aspect Ratio", aspectRatio, 0.5f, 3.5f, 0.01f,
                             focusIndex == 11, width, sliderHoldTime, sliderAccumulator);
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    SyncToCVars();
}
