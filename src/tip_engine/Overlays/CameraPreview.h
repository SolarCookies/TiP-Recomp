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
* The core goal of ReTiP is not only to get the game running, but to 
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

#pragma once
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/imgui_drawer.h>
#include <rex/ui/immediate_drawer.h>
#include "imgui.h"
#include "UsbCam.h"
#include <cstdint>
#include <memory>
#include <vector>

class CameraPreviewDialog : public rex::ui::ImGuiDialog {
public:
    explicit CameraPreviewDialog(rex::ui::ImGuiDrawer* drawer) : rex::ui::ImGuiDialog(drawer) {}

    ~CameraPreviewDialog() {
        tex_.reset();
    }

    void OnDraw(ImGuiIO& io) override {
        std::vector<uint8_t> rgba;
        uint32_t w = 0, h = 0, fmtCC = 0;
        uint64_t camSeq = 0;
        const bool hasFrame = UsbCam_GetFrameRGBA(rgba, w, h, fmtCC, camSeq);

        ++drawCount_;

        ImGui::SetNextWindowSize(ImVec2(340.0f, 260.0f), ImGuiCond_FirstUseEver);
        if (!ImGui::Begin("Camera Preview")) { ImGui::End(); return; }

        if (hasFrame && w > 0 && h > 0) {
            rex::ui::ImmediateDrawer* imm = imgui_drawer()->immediate_drawer();

            if (imm && camSeq != lastSeq_) {
                lastSeq_ = camSeq;
                tex_ = imm->CreateTexture(w, h, rex::ui::ImmediateTextureFilter::kLinear, false, rgba.data());
                texW_ = w;
                texH_ = h;
            }

            if (tex_) {
                ImVec2 avail = ImGui::GetContentRegionAvail();
                avail.y -= ImGui::GetTextLineHeightWithSpacing() * 2.0f;

                const float aspect = static_cast<float>(w) / static_cast<float>(h);
                float dw = avail.x, dh = dw / aspect;
                if (dh > avail.y) { dh = avail.y; dw = dh * aspect; }

                ImGui::Image(reinterpret_cast<ImTextureID>(tex_.get()), ImVec2(dw, dh));
            }

            ImGui::Text("%c%c%c%c  %ux%u",
                static_cast<char>( fmtCC        & 0xFF),
                static_cast<char>((fmtCC >>  8) & 0xFF),
                static_cast<char>((fmtCC >> 16) & 0xFF),
                static_cast<char>((fmtCC >> 24) & 0xFF),
                w, h);
            ImGui::Text("cam frames: %llu  draws: %llu", (unsigned long long)camSeq, (unsigned long long)drawCount_);
        } else {
            ImGui::TextDisabled("No camera frame available");
            ImGui::Text("draws: %llu", (unsigned long long)drawCount_);
        }

        ImGui::End();
    }

private:
    std::unique_ptr<rex::ui::ImmediateTexture> tex_;
    uint32_t texW_     = 0;
    uint32_t texH_     = 0;
    uint64_t lastSeq_  = UINT64_MAX;
    uint64_t drawCount_ = 0;
};
