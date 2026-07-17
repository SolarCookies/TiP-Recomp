#include "UpscalingMenu.h"
#include "../TiPWidgets.h"

#include <cmath>
#include <string>

static constexpr int kOptionCount = 6;

static const char* const kEffectLabels[] = {"Bilinear", "CAS", "FSR 1", "FSR 2", "FSR 3"};
static const char* const kEffectValues[] = {"bilinear", "cas", "fsr", "fsr2", "fsr3"};
static constexpr int kEffectCount = 5;

static const char* const kQualityLabels[] = {"Auto", "Native AA", "Quality",
                                             "Balanced", "Performance", "Ultra Perf"};
static const char* const kQualityValues[] = {"auto", "nativeaa", "quality",
                                             "balanced", "performance", "ultra_performance"};
static constexpr int kQualityCount = 6;

static int IndexOfValue(const std::string& value, const char* const* values, int count) {
    for (int i = 0; i < count; i++) {
        if (value == values[i]) return i;
    }
    return 0;
}

void UpscalingMenuPage::SyncFromCVars() {
    effectIndex = IndexOfValue(rex::cvar::Query<std::string>("present_effect"),
                               kEffectValues, kEffectCount);
    qualityIndex = IndexOfValue(rex::cvar::Query<std::string>("present_fsr_quality_mode"),
                                kQualityValues, kQualityCount);
    fsrSharpnessReduction = static_cast<float>(rex::cvar::Query<double>("present_fsr_sharpness_reduction"));
    casAdditionalSharpness = static_cast<float>(rex::cvar::Query<double>("present_cas_additional_sharpness"));
    dither = rex::cvar::Query<bool>("present_dither");
    frameGeneration = rex::cvar::Query<bool>("present_fsr3_frame_generation");
}

void UpscalingMenuPage::OnDraw() {
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

    ImGui::TextColored(ImVec4(1.0f, 0.45f, 0.45f, 1.0f), "Upscaling");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    if (TiPWidgets::Cycler("Effect", effectIndex, kEffectLabels, kEffectCount,
                           focusIndex == 0, width, input)) {
        rex::cvar::SetFlagByName("present_effect", kEffectValues[effectIndex]);
    }
    if (TiPWidgets::Cycler("FSR Quality", qualityIndex, kQualityLabels, kQualityCount,
                           focusIndex == 1, width, input)) {
        rex::cvar::SetFlagByName("present_fsr_quality_mode", kQualityValues[qualityIndex]);
    }
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1.0f, 0.45f, 0.45f, 1.0f), "Sharpening");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    if (TiPWidgets::FloatSlider("FSR Sharpness Reduction", fsrSharpnessReduction, 0.0f, 2.0f, 0.05f,
                                focusIndex == 2, width, sliderHoldTime, sliderAccumulator)) {
        rex::cvar::SetFlagByName("present_fsr_sharpness_reduction",
                                 std::to_string(fsrSharpnessReduction));
    }
    if (TiPWidgets::FloatSlider("CAS Extra Sharpness", casAdditionalSharpness, 0.0f, 1.0f, 0.05f,
                                focusIndex == 3, width, sliderHoldTime, sliderAccumulator)) {
        rex::cvar::SetFlagByName("present_cas_additional_sharpness",
                                 std::to_string(casAdditionalSharpness));
    }
    if (TiPWidgets::Toggle("Output Dither", dither, focusIndex == 4, width, input)) {
        rex::cvar::SetFlagByName("present_dither", dither ? "true" : "false");
    }
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1.0f, 0.45f, 0.45f, 1.0f), "Frame Generation");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    if (TiPWidgets::Toggle("FSR 3 Frame Generation", frameGeneration, focusIndex == 5, width,
                           input)) {
        rex::cvar::SetFlagByName("present_fsr3_frame_generation",
                                 frameGeneration ? "true" : "false");
    }
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    if (focusIndex == 5) {
        ImGui::TextWrapped("FSR 3 Frame Gen: Interpolates an extra frame between rendered "
                           "frames (D3D12 only). Works with any Effect above.");
    } else if (effectIndex == 0) {
        ImGui::TextWrapped("Bilinear: Normal filtering");
    } else if (effectIndex == 1) {
        ImGui::TextWrapped("CAS: Contrast adaptive sharpening.");
    } else if (effectIndex == 2) {
        ImGui::TextWrapped("FSR 1: Spatial upscale.");
    } else {
        ImGui::TextWrapped("FSR 2/3: Temporal upscaler.");
    }
}
