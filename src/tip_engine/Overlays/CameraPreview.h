#pragma once
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/imgui_drawer.h>
#include <rex/ui/immediate_drawer.h>
#include "imgui.h"
#include "UsbCam.h"
#include <cstdint>
#include <memory>
#include <vector>

// ImGui overlay that previews the live camera feed exactly as the game sees it.
// Converts the DirectShow frame (NV12/YUY2/I420) to RGBA on the CPU and
// uploads it as a D3D12 ImmediateTexture. The texture is only re-created when
// the camera delivers a new frame (tracked via frameSeq).
class CameraPreviewDialog : public rex::ui::ImGuiDialog {
public:
    explicit CameraPreviewDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer) {}

    ~CameraPreviewDialog() {
        tex_.reset();
    }

    void OnDraw(ImGuiIO& /*io*/) override {
        std::vector<uint8_t> rgba;
        uint32_t w = 0, h = 0, fmtCC = 0;
        uint64_t camSeq = 0;
        const bool hasFrame = UsbCam_GetFrameRGBA(rgba, w, h, fmtCC, camSeq);

        ++drawCount_;

        ImGui::SetNextWindowSize(ImVec2(340.0f, 260.0f), ImGuiCond_FirstUseEver);
        if (!ImGui::Begin("Camera Preview")) { ImGui::End(); return; }

        if (hasFrame && w > 0 && h > 0) {
            rex::ui::ImmediateDrawer* imm = imgui_drawer()->immediate_drawer();

            // Only re-upload to the GPU when the camera has produced a new frame.
            if (imm && camSeq != lastSeq_) {
                lastSeq_ = camSeq;
                tex_ = imm->CreateTexture(w, h,
                                          rex::ui::ImmediateTextureFilter::kLinear,
                                          /*is_repeated=*/false,
                                          rgba.data());
                texW_ = w;
                texH_ = h;
            }

            if (tex_) {
                // Fit the image to the available content region.
                ImVec2 avail = ImGui::GetContentRegionAvail();
                avail.y -= ImGui::GetTextLineHeightWithSpacing() * 2.0f; // room for labels below

                const float aspect = static_cast<float>(w) / static_cast<float>(h);
                float dw = avail.x, dh = dw / aspect;
                if (dh > avail.y) { dh = avail.y; dw = dh * aspect; }

                ImGui::Image(reinterpret_cast<ImTextureID>(tex_.get()), ImVec2(dw, dh));
            }

            // Format label and diagnostics
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
    uint64_t lastSeq_  = UINT64_MAX;  // force first upload
    uint64_t drawCount_ = 0;
};

