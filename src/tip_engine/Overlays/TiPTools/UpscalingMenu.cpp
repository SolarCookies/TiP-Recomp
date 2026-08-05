/** 
******************************************************************************
* ReTiP: Viva Pinata Recompiled                                              *
******************************************************************************
* Copyright (c) 2026 SolarCookies. Licensed under custom noncommercial terms.
*
* This software is licensed for non-commercial, private, and educational use 
* only. You may modify, rewrite, and optimize this code provided that full 
* attribution is given to the original authors listed on the project repository. 
* Commercial use is prohibited.
*
* DISCLAIMER: This software is provided "as-is" without warranty of any kind. 
* This project is an unofficial fan translation layer and does NOT provide, 
* distribute, or package any copyrighted game assets, binaries, or media belonging 
* to Microsoft or Rare. Users must provide their own legally obtained game assets. 
* This software must not be used in any manner that violates Microsoft's copyrights.
* DO NOT REDISTRIBUTE GAME ASSETS OR PROMOTE PIRACY.
*
* AI USE GUIDELINES:
* This project is built with minimal AI usage. We may utilize basic inline code 
* suggestions or rely on AI assistance for debugging, but the vast majority of 
* this codebase is written by hand. We manually decompile functions,
* reverse engineer structs, and write hooks to ensure accuracy and maintainability.
*
* The core goal of ReTiP is not only to get the software running, but to 
* research, document, and learn exactly how the game operates under the hood so that 
* we can provide modding support. We do not support using AI for creative 
* task or problem solving. i.e asking an AI agent to "find a way to 
* make freecam work". Instead, AI should only be used for small, boilerplate tasks or
* parsing a 1000 line crash log to isolate an error. We actively encourage all project 
* contributors to avoid the use of AI agents entirely when writing code or decompiling functions.
*
* The truth of the matter is that AI when used currectly by people who understand the output
* can be incredibly useful just like intelisense, being able to press Tab to autocomplete a
* for loop can save time. However, AI is not a replacement for human understanding and
* should not be used to replace the process of learning and understanding how the game works.
*
* We strongly prefer the use of local models that do not harm the environment and 
* can run entirely on your own local hardware over cloud based AI services. Ultimately, 
* all pull requests and code contributions will be strictly reviewed by people who 
* understand the codebase and the game. If you list Claude or any other AI as a coauthor 
* or contributor, your PR will be rejected regardless of whether it works.
******************************************************************************
*/

#include "UpscalingMenu.h"
#include "../TiPWidgets.h"

#include <cmath>
#include <string>

static constexpr int kOptionCount = 6;

static const char* const kEffectLabels[] = {"Bilinear", "Unfiltered", "CAS", "FSR 1", "FSR 2", "FSR 3"};
static const char* const kEffectValues[] = {"bilinear", "nearest", "cas", "fsr", "fsr2", "fsr3"};
static constexpr int kEffectCount = 6;

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
    if (TiPWidgets::FloatSlider("FSR Sharpness Reduction", fsrSharpnessReduction, 0.0f, 2.0f, 0.05f,focusIndex == 2, width, sliderHoldTime, sliderAccumulator)) {
        rex::cvar::SetFlagByName("present_fsr_sharpness_reduction", std::to_string(fsrSharpnessReduction));
    }
    if (TiPWidgets::FloatSlider("CAS Extra Sharpness", casAdditionalSharpness, 0.0f, 1.0f, 0.05f, focusIndex == 3, width, sliderHoldTime, sliderAccumulator)) {
        rex::cvar::SetFlagByName("present_cas_additional_sharpness", std::to_string(casAdditionalSharpness));
    }
    if (TiPWidgets::Toggle("Output Dither", dither, focusIndex == 4, width, input)) {
        rex::cvar::SetFlagByName("present_dither", dither ? "true" : "false");
    }
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    ImGui::TextColored(ImVec4(1.0f, 0.45f, 0.45f, 1.0f), "Frame Generation");
    ImGui::Separator();

    TiPWidgets::PushListStyle();
    if (TiPWidgets::Toggle("FSR 3 Frame Generation", frameGeneration, focusIndex == 5, width, input)) {
        rex::cvar::SetFlagByName("present_fsr3_frame_generation", frameGeneration ? "true" : "false");
    }
    TiPWidgets::PopListStyle();

    ImGui::Spacing();

    if (focusIndex == 5) {
        ImGui::TextWrapped("FSR 3 Frame Gen: Interpolates an extra frame between rendered frames D3D12 only.");
    } else if (effectIndex == 0) {
        ImGui::TextWrapped("Bilinear: Normal filtering");
    } else if (effectIndex == 1) {
        ImGui::TextWrapped("Unfiltered: Nearest neighbor point sampling. Ideal for low guest resolutions.");
    } else if (effectIndex == 2) {
        ImGui::TextWrapped("CAS: Contrast adaptive sharpening.");
    } else if (effectIndex == 3) {
        ImGui::TextWrapped("FSR 1: Spatial upscale.");
    } else {
        ImGui::TextWrapped("FSR 2/3: Temporal upscaler.");
    }
}
