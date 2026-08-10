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
******************************************************************************
*/

#pragma once
#include <rex/filesystem.h>
#include <algorithm>
#include <random>
#include <rex/ui/image_decode.h>
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/imgui_drawer.h>
#include <rex/ui/immediate_drawer.h>
#include <rex/ui/keybinds.h>
#include "imgui.h"
#include "tip_engine/Globals.h"
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct StarLeaf{
    std::string name;
    std::string description;
    std::string leafPngPath = "./retip/brownleaf.png";
    std::string iconPath;
    std::function<void()> onClick;
    bool hovered = false;
};

struct StarMenuLayout {
    float panelScale   = 0.780f;
    float flowerRadius = 0.433f;
    float leafLength   = 0.987f;
    float leafWidth    = 0.960f;
    float ringSpacing  = 1.670f;
    float hubRadius    = 0.553f;
    float startAngle   = -90.0f;
    float leafRotation = 180.0f;
    float hoverScale   = 1.120f;
    float centerScale  = 2.000f;
    float arrowHeight  = 1.500f;
    float arrowPivot   = 0.750f;

    float iconScale    = 0.959f;
    float iconOffset   = -0.115f;
    float iconRotation = 0.000f;
    float wobbleAmp    = 10.00f;
    float wobbleSpeed  = 14.630f;
};

struct StarMenu{
    std::string name;
    std::vector<StarLeaf> leaves;
    StarMenuLayout layout;
    std::string centerPngPath = "./retip/center.png";
    std::string arrowPngPath  = "./retip/centerarrow.png";
    int selected = 0;
};

inline rex::ui::ImGuiDrawer* g_starMenuDrawer = nullptr;

struct StarTexture {
    std::unique_ptr<rex::ui::ImmediateTexture> tex;
    int w = 0;
    int h = 0;
};

inline const StarTexture* GetStarTexture(const std::string& path) {
    static std::unordered_map<std::string, StarTexture> cache;

    auto it = cache.find(path);
    if (it != cache.end()) return it->second.tex ? &it->second : nullptr;

    StarTexture& entry = cache[path];
    if (path.empty() || !g_starMenuDrawer) return nullptr;

    std::filesystem::path resolved(path);
    if (resolved.is_relative()) {
        resolved = rex::filesystem::GetExecutableFolder() / resolved.lexically_normal();
    }

    std::ifstream file(resolved, std::ios::binary | std::ios::ate);
    if (!file) return nullptr;
    std::vector<uint8_t> bytes(static_cast<size_t>(file.tellg()));
    file.seekg(0);
    file.read(reinterpret_cast<char*>(bytes.data()), bytes.size());

    auto pixels = rex::ui::DecodeImageRGBA(bytes.data(), bytes.size(), entry.w, entry.h);
    if (pixels.empty()) return nullptr;

    auto* immediate = g_starMenuDrawer->immediate_drawer();
    if (!immediate) {
        cache.erase(path);
        return nullptr;
    }
    entry.tex = immediate->CreateTexture(static_cast<uint32_t>(entry.w), static_cast<uint32_t>(entry.h),
                                         rex::ui::ImmediateTextureFilter::kLinear, false, pixels.data());
    return entry.tex ? &entry : nullptr;
}

inline constexpr float kStarPi = 3.14159265358979323846f;

inline void DrawRotatedSprite(ImDrawList* dl, const StarTexture& tex, ImVec2 at, float height,
                              float rotation, float pivotY, ImU32 tint) {
    const float aspect = tex.h > 0 ? static_cast<float>(tex.w) / static_cast<float>(tex.h) : 1.0f;
    const float halfW = height * aspect * 0.5f;
    const float top   = -height * pivotY;
    const float bot   =  height * (1.0f - pivotY);
    const float cs = std::cos(rotation);
    const float sn = std::sin(rotation);

    auto corner = [&](float lx, float ly) {
        return ImVec2(at.x + lx * cs - ly * sn, at.y + lx * sn + ly * cs);
    };
    dl->AddImageQuad(reinterpret_cast<ImTextureID>(tex.tex.get()),
                     corner(-halfW, top), corner(halfW, top),
                     corner(halfW, bot), corner(-halfW, bot),
                     ImVec2(0, 0), ImVec2(1, 0), ImVec2(1, 1), ImVec2(0, 1), tint);
}

inline void RenderStarMenu(StarMenu& menu){
    const int count = static_cast<int>(menu.leaves.size());
    if (count == 0) return;

    const StarMenuLayout& L = menu.layout;

    const ImVec2 avail = ImGui::GetContentRegionAvail();
    float box = (avail.x < avail.y) ? avail.x : avail.y;
    if (box < 160.0f) box = 160.0f;
    const float extent = box * L.panelScale;

    const ImVec2 origin = ImGui::GetCursorScreenPos();
    ImGui::InvisibleButton("##starmenu", ImVec2(avail.x, avail.y));
    const bool areaHovered = ImGui::IsItemHovered();
    const ImVec2 center(origin.x + avail.x * 0.5f, origin.y + avail.y * 0.5f);

    const float flowerRadius = extent * L.flowerRadius;
    const float leafLen      = flowerRadius * L.leafLength;
    const float ringRadius   = (flowerRadius - leafLen * 0.5f) * L.ringSpacing;
    const float hubRadius    = flowerRadius * L.hubRadius;
    const float hitRadius    = leafLen * 0.45f;

    const StarTexture* sharedLeafTex = GetStarTexture(menu.leaves[0].leafPngPath);
    float leafAspect = 109.0f / 192.0f;
    if (sharedLeafTex && sharedLeafTex->h > 0) {
        leafAspect = static_cast<float>(sharedLeafTex->w) / static_cast<float>(sharedLeafTex->h);
    }
    const float leafW = leafLen * leafAspect * L.leafWidth;
    const float leafH = leafLen;

    const ImVec2 mouse = ImGui::GetIO().MousePos;
    int hoveredIndex = -1;
    float bestDistSq = hitRadius * hitRadius;

    std::vector<ImVec2> positions(count);
    std::vector<float> rotations(count);
    std::vector<float> angles(count);

    const float kDegToRad = kStarPi / 180.0f;

    for (int i = 0; i < count; i++) {
        const float angle = L.startAngle * kDegToRad +
                            (kStarPi * 2.0f * static_cast<float>(i)) / static_cast<float>(count);
        angles[i] = angle;
        positions[i] = ImVec2(center.x + std::cos(angle) * ringRadius,
                              center.y + std::sin(angle) * ringRadius);
        rotations[i] = angle - kStarPi * 0.5f + L.leafRotation * kDegToRad;

        if (!areaHovered) continue;
        const float dx = mouse.x - positions[i].x;
        const float dy = mouse.y - positions[i].y;
        const float distSq = dx * dx + dy * dy;
        if (distSq < bestDistSq) {
            bestDistSq = distSq;
            hoveredIndex = i;
        }
    }

    if (hoveredIndex >= 0) menu.selected = hoveredIndex;

    ImDrawList* dl = ImGui::GetWindowDrawList();

    if (const StarTexture* centerTex = GetStarTexture(menu.centerPngPath)) {
        const float half = hubRadius * L.centerScale * 0.5f;
        dl->AddImage(reinterpret_cast<ImTextureID>(centerTex->tex.get()),
                     ImVec2(center.x - half, center.y - half),
                     ImVec2(center.x + half, center.y + half),
                     ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 255));
    } else {
        dl->AddCircleFilled(center, hubRadius, IM_COL32(40, 30, 20, 200), 48);
        dl->AddCircle(center, hubRadius, IM_COL32(240, 200, 90, 255), 48, 3.0f);
    }

    for (int i = 0; i < count; i++) {
        StarLeaf& leaf = menu.leaves[i];
        leaf.hovered = (i == hoveredIndex);

        const float scale = leaf.hovered ? L.hoverScale : 1.0f;
        const ImU32 tint  = leaf.hovered ? IM_COL32(255, 255, 255, 255) : IM_COL32(215, 215, 215, 235);

        const StarTexture* leafTex = GetStarTexture(leaf.leafPngPath);
        float thisLeafW = leafW;
        if (leafTex && leafTex->h > 0) {
            thisLeafW = leafLen * (static_cast<float>(leafTex->w) / static_cast<float>(leafTex->h)) * L.leafWidth;
        }

        const float hw = thisLeafW * 0.5f * scale;
        const float hh = leafH * 0.5f * scale;
        const float cs = std::cos(rotations[i]);
        const float sn = std::sin(rotations[i]);
        const ImVec2 p = positions[i];

        auto corner = [&](float lx, float ly) {
            return ImVec2(p.x + lx * cs - ly * sn, p.y + lx * sn + ly * cs);
        };
        const ImVec2 tl = corner(-hw, -hh);
        const ImVec2 tr = corner( hw, -hh);
        const ImVec2 br = corner( hw,  hh);
        const ImVec2 bl = corner(-hw,  hh);

        if (leafTex) {
            dl->AddImageQuad(reinterpret_cast<ImTextureID>(leafTex->tex.get()), tl, tr, br, bl,
                             ImVec2(0, 0), ImVec2(1, 0), ImVec2(1, 1), ImVec2(0, 1), tint);
        } else {
            ImVec2 poly[20];
            for (int s = 0; s < 20; s++) {
                const float t = (kStarPi * 2.0f * static_cast<float>(s)) / 20.0f;
                poly[s] = corner(std::cos(t) * hw, std::sin(t) * hh);
            }
            dl->AddConvexPolyFilled(poly, 20, leaf.hovered ? IM_COL32(150, 108, 64, 255)
                                                           : IM_COL32(122, 86, 50, 255));
        }

        if (const StarTexture* iconTex = GetStarTexture(leaf.iconPath)) {
            const float wobble = leaf.hovered
                ? L.wobbleAmp * std::sin(static_cast<float>(ImGui::GetTime()) * L.wobbleSpeed)
                : 0.0f;

            const ImVec2 iconPos(p.x + std::cos(angles[i]) * leafLen * L.iconOffset,
                                 p.y + std::sin(angles[i]) * leafLen * L.iconOffset);

            const float iconMax = thisLeafW * L.iconScale * scale;
            const float aspect = iconTex->h > 0 ? static_cast<float>(iconTex->w) / static_cast<float>(iconTex->h) : 1.0f;
            const float iconH = aspect >= 1.0f ? iconMax / aspect : iconMax;

            DrawRotatedSprite(dl, *iconTex, iconPos, iconH,
                              (L.iconRotation + wobble) * kDegToRad, 0.5f, tint);
        } else if (!leaf.name.empty()) {
            const ImVec2 ts = ImGui::CalcTextSize(leaf.name.c_str());
            dl->AddText(ImVec2(p.x - ts.x * 0.5f, p.y - ts.y * 0.5f), IM_COL32(255, 255, 255, 235),
                        leaf.name.c_str());
        }
    }

    const int arrowTarget = menu.selected;
    if (arrowTarget >= 0 && arrowTarget < count) {
        if (const StarTexture* arrowTex = GetStarTexture(menu.arrowPngPath)) {
            const float spoke = L.startAngle * kDegToRad +
                                (kStarPi * 2.0f * static_cast<float>(arrowTarget)) / static_cast<float>(count);
            DrawRotatedSprite(dl, *arrowTex, center, hubRadius * L.arrowHeight,
                              spoke + kStarPi * 0.5f, L.arrowPivot, IM_COL32(255, 255, 255, 255));
        }
    }

    const std::string& hubText = hoveredIndex >= 0 ? menu.leaves[hoveredIndex].name : menu.name;
    if (!hubText.empty()) {
        const ImVec2 ts = ImGui::CalcTextSize(hubText.c_str());
        dl->AddText(ImVec2(center.x - ts.x * 0.5f, center.y - ts.y * 0.5f), IM_COL32(255, 255, 255, 255),
                    hubText.c_str());
    }

    if (hoveredIndex >= 0) {
        StarLeaf& leaf = menu.leaves[hoveredIndex];
        if (!leaf.description.empty()) {
            ImGui::SetTooltip("%s", leaf.description.c_str());
        }
        if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && leaf.onClick) {
            leaf.onClick();
        }
    }
}

class TiPSettingsDialog : public rex::ui::ImGuiDialog {
public:
    bool visible_ = false;

    explicit TiPSettingsDialog(rex::ui::ImGuiDrawer* drawer) : rex::ui::ImGuiDialog(drawer) {
        g_starMenuDrawer = drawer;
        rex::ui::RegisterBind("bind_tip_settings", "F10", "Toggle TiP Settings overlay", [this] {
            visible_ = !visible_;
            g_StarMenuOpen = visible_;
        });
    }

    ~TiPSettingsDialog() {
        g_StarMenuOpen = false;
        rex::ui::UnregisterBind("bind_tip_settings");
    }

    void OnDraw(ImGuiIO& io) override {
        if (!visible_) return;

        const float side = (io.DisplaySize.x < io.DisplaySize.y ? io.DisplaySize.x : io.DisplaySize.y) * 0.9f;
        ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f),
                                ImGuiCond_Always, ImVec2(0.5f, 0.5f));
        ImGui::SetNextWindowSize(ImVec2(side, side), ImGuiCond_Always);

        const ImGuiWindowFlags flags =
            ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse |
            ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBackground |
            ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoNav;

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        if (ImGui::Begin("##TiPStarMenu", nullptr, flags)) {
            RenderStarMenu(menu_);
        }
        ImGui::End();
        ImGui::PopStyleVar();
    }

private:
    StarMenu menu_ = MakeDefaultMenu();

    static const std::vector<std::string>& LeafPalette() {
        static const std::vector<std::string> palette = {
            "./retip/blueleaf.png",   "./retip/brownleaf.png", "./retip/greenleaf.png",
            "./retip/limeleaf.png",   "./retip/orangeleaf.png", "./retip/pinkleaf.png",
            "./retip/purpleleaf.png", "./retip/redleaf.png",    "./retip/yellowleaf.png",
        };
        return palette;
    }

    static StarMenu MakeDefaultMenu() {
        StarMenu menu;
        menu.name = "TiP";
        static const char* kNames[8] = {"Boots", "Shovel", "Seeds", "Watering Can",
                                        "Fertilizer", "Pinata", "Camera", "Shop"};

        std::vector<std::string> colors = LeafPalette();
        std::shuffle(colors.begin(), colors.end(), std::mt19937(std::random_device{}()));

        for (int i = 0; i < 8; i++) {
            StarLeaf leaf;
            leaf.name = kNames[i];
            leaf.description = std::string(kNames[i]) + " slot";
            leaf.leafPngPath = colors[static_cast<size_t>(i) % colors.size()];
            leaf.iconPath = "./retip/icon.png";
            menu.leaves.push_back(std::move(leaf));
        }
        return menu;
    }
};
