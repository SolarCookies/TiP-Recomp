#include "Fps.h"
#include <tip_engine/hooks.h> // for fpsCount and showfps


struct FpsRange {
    float Min;
    float Max;
    ImVec4 Color;
};

static bool ShadowEnabled = false;

static const FpsRange fpsRanges[] = {
    { 120.0f, 9999.0f, ImVec4(1.0f, 1.0f, 1.0f, 1.0f) },  // white
    {  59.0f,  120.0f, ImVec4(0.5f, 0.8f, 1.0f, 1.0f) },  // light blue
    {  30.0f,   59.0f, ImVec4(0.5f, 1.0f, 0.5f, 1.0f) },  // light green
    {  20.0f,   30.0f, ImVec4(1.0f, 1.0f, 0.4f, 1.0f) },  // yellow
    {  10.0f,   20.0f, ImVec4(1.0f, 0.4f, 0.4f, 1.0f) },  // red
    {   0.0f,   10.0f, ImVec4(0.8f, 0.2f, 0.2f, 1.0f) },  // dark red
};

static ImVec4 GetFpsColor(float fps) {
    auto lerp = [](const ImVec4& a, const ImVec4& b, float t) {
        return ImVec4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t,
                      a.z + (b.z - a.z) * t, 1.0f);
    };

    for (int i = 0; i < rex::countof(fpsRanges); i++) {
        const auto& range = fpsRanges[i];
        if (fps >= range.Min) {
            float t = (fps - range.Min) / (range.Max - range.Min);
            if (t > 1.0f) t = 1.0f;
            ImVec4 nextColor = (i > 0) ? fpsRanges[i - 1].Color : range.Color;
            return lerp(range.Color, nextColor, t);
        }
    }
    return fpsRanges[rex::countof(fpsRanges) - 1].Color;
}

void FpsOverlayDialog::OnDraw(ImGuiIO& io) {
    if (!showfps) {
        return; // Don't draw the overlay if it's disabled
	}
    const double fps = fpsCount;

    ImGui::SetNextWindowPos(ImVec2(10.0f, 10.0f));
    ImGui::SetNextWindowBgAlpha(0.5f);
    ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0, 0, 0, 0));
    ImGui::SetNextWindowSize(ImVec2(80.0f, 0.0f));

    ImGuiWindowFlags flags = 
        ImGuiWindowFlags_NoDecoration |
        ImGuiWindowFlags_NoInputs |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoBringToFrontOnFocus;

    if (ImGui::Begin("##fps_overlay", nullptr, flags)) {
        ImVec4 color = GetFpsColor(static_cast<float>(fps));

        char buf[64];
        snprintf(buf, sizeof(buf), "FPS: %.1f", fps);
        ImVec2 pos = ImGui::GetCursorPos();

        ImGui::SetWindowFontScale(1.5f);

        // Shadow outline for readability
        if(ShadowEnabled){
            const ImVec4 shadow(0.0f, 0.0f, 0.0f, 1.0f);
            const float off = 2.0f;
            ImGui::SetCursorPos(ImVec2(pos.x + off, pos.y));       ImGui::TextColored(shadow, "%s", buf);
            ImGui::SetCursorPos(ImVec2(pos.x - off, pos.y));       ImGui::TextColored(shadow, "%s", buf);
            ImGui::SetCursorPos(ImVec2(pos.x, pos.y + off));       ImGui::TextColored(shadow, "%s", buf);
            ImGui::SetCursorPos(ImVec2(pos.x, pos.y - off));       ImGui::TextColored(shadow, "%s", buf);
            ImGui::SetCursorPos(ImVec2(pos.x + off, pos.y + off)); ImGui::TextColored(shadow, "%s", buf);
            ImGui::SetCursorPos(ImVec2(pos.x - off, pos.y - off)); ImGui::TextColored(shadow, "%s", buf);
            ImGui::SetCursorPos(ImVec2(pos.x + off, pos.y - off)); ImGui::TextColored(shadow, "%s", buf);
            ImGui::SetCursorPos(ImVec2(pos.x - off, pos.y + off)); ImGui::TextColored(shadow, "%s", buf);
        }

        ImGui::SetCursorPos(pos);
        ImGui::TextColored(color, "%s", buf);
    }
    ImGui::End();
    ImGui::PopStyleColor();
}