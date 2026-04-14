#include "ViewportWindow.h"

void ViewportWindow::Draw(float& window_width, float& window_height, Camera& camera, VinceWindow& window, bool isShadowPass, const char* Name)
{
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.0f, 0.2f, 0.5f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin(Name);
    if (!isShadowPass) {
        window_width = ImGui::GetContentRegionAvail().x;
        window_height = ImGui::GetContentRegionAvail().y;
        camera.height = window_height;
        camera.width = window_width;
    }
    else {
        window_width = 4096;
        window_height = 4096;
        camera.height = 4096;
        camera.width = 4096;
    }

    // ... wireframe code unchanged ...

    if (isShadowPass) {
        window.getFrameBuffer2()->rescale_framebuffer(4096, 4096);
    }
    else {
        window.getFrameBuffer()->rescale_framebuffer(window_width, window_height);
    }

    if (!isShadowPass) {
        glViewport(0, 0, window_width, window_height);
    }
    else {
        // glViewport(0, 0, 512, 512);
    }

    ImVec2 pos = ImGui::GetCursorScreenPos();
    if (isShadowPass) {
        ImGui::GetWindowDrawList()->AddImage(
            (ImTextureID)(intptr_t)window.getFrameBuffer2()->texture_id,
            pos,
            ImVec2(pos.x + 512, pos.y + 512),
            ImVec2(0, 1),
            ImVec2(1, 0)
        );
    }
    else {
        ImGui::GetWindowDrawList()->AddImage(
            (ImTextureID)(intptr_t)window.getFrameBuffer()->texture_id,
            pos,
            ImVec2(pos.x + window_width, pos.y + window_height),
            ImVec2(0, 1),
            ImVec2(1, 0)
        );
    }

    ImGui::End();
    ImGui::PopStyleVar();
	ImGui::PopStyleColor();
}
