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

#include "LaunchMenu.h"
#include "tip_engine/Globals.h"
#include "tip_engine/version.h"
#include <rex/cvar.h>
#include <rex/filesystem.h>
#include <rex/gamejolt.h>
#include <rex/ui/image_decode.h>
#include "tip_engine/FilePicker.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#endif

REXCVAR_DEFINE_BOOL(ShowLaunchMenu, true, "TiP", "Show the launcher on startup");

REXCVAR_DECLARE(bool, EnableShadows);
REXCVAR_DECLARE(bool, EnableReflections);
REXCVAR_DECLARE(bool, EnableOcclusions);
REXCVAR_DECLARE(bool, EnableTransparency);
REXCVAR_DECLARE(bool, EnableModels);
REXCVAR_DECLARE(bool, EnableSceneEffects);
REXCVAR_DECLARE(bool, EnableBloom);
REXCVAR_DECLARE(bool, SkipIntros);
REXCVAR_DECLARE(bool, UseAspectRatioFromConfig);
REXCVAR_DECLARE(double, AspectRatio);
REXCVAR_DECLARE(bool, fullscreen);
REXCVAR_DECLARE(bool, DiscordActivity);
REXCVAR_DECLARE(bool, show_fps);
REXCVAR_DECLARE(bool, lock_fps);

#define CVAR_CHECKBOX(label, cvar) { bool v = REXCVAR_GET(cvar); if (ImGui::Checkbox(label, &v)) REXCVAR_SET(cvar, v); }

enum AspectChoice { kAspect16x9 = 0, kAspect16x10, kAspect21x9, kAspect32x9, kAspectNative, kAspectCustom, kAspectCount };
static constexpr const char* kAspectNames[kAspectCount] = {
    "16:9 Widescreen",
    "16:10 Widescreen",
    "21:9 Widescreen",
    "32:9 Widescreen",
    "Native",
    "Custom"
};
static double AspectRatioForChoice(int choice) {
    switch (choice) {
        case kAspect16x10: return 16.0 / 10.0;
        case kAspect21x9:  return 21.0 / 9.0;
        case kAspect32x9:  return 32.0 / 9.0;
        default:           return 16.0 / 9.0;
    }
}

static constexpr const char* kResolutionNames[2] = { "720p", "1440p" };
static constexpr int kResolutionScales[2] = { 1, 2 };

struct QualityPreset {
    bool shadows, reflections, occlusions, transparency, models, sceneEffects, bloom;
};
static constexpr const char* kQualityNames[4] = { "Low", "Medium", "High", "Ultra" };
static constexpr QualityPreset kQualityPresets[4] = {
    /* Low */ { false, false, false, true, true, false, false },
    /* Medium */ { false, false, true,  true, true, false, true  },
    /* High */ { true,  false, true,  true, true, false, true  },
    /* Ultra */ { true,  true,  true,  true, true, true,  true  },
};

static void ApplyQualityPreset(int index) {
    const QualityPreset& p = kQualityPresets[index];
    REXCVAR_SET(EnableShadows, p.shadows);
    REXCVAR_SET(EnableReflections, p.reflections);
    REXCVAR_SET(EnableOcclusions, p.occlusions);
    REXCVAR_SET(EnableTransparency, p.transparency);
    REXCVAR_SET(EnableModels, p.models);
    REXCVAR_SET(EnableSceneEffects, p.sceneEffects);
    REXCVAR_SET(EnableBloom, p.bloom);
}

static int DetectQualityPreset() {
    for (int i = 0; i < 4; i++) {
        const QualityPreset& p = kQualityPresets[i];
        if (REXCVAR_GET(EnableShadows) == p.shadows &&
            REXCVAR_GET(EnableReflections) == p.reflections &&
            REXCVAR_GET(EnableOcclusions) == p.occlusions &&
            REXCVAR_GET(EnableTransparency) == p.transparency &&
            REXCVAR_GET(EnableModels) == p.models &&
            REXCVAR_GET(EnableSceneEffects) == p.sceneEffects &&
            REXCVAR_GET(EnableBloom) == p.bloom) {
            return i;
        }
    }
    return 3;
}

static constexpr const char* kDiscordUrl = "https://discord.gg/39AtUkYr7s";
static constexpr const char* kPatreonUrl = "https://www.patreon.com/cw/SolarCookies";
static constexpr const char* kKofiUrl    = "https://ko-fi.com/solarcookies";
static constexpr const char* kGithubUrl  = "https://github.com/SolarCookies/TiP-Recomp";
static constexpr const char* kGameJoltTokenUrl = "https://gamejolt.com/help/tokens";
static constexpr const char* kGameJoltPopupId = "##retip_gamejolt";
static constexpr float kGjSize = 40.0f;

static constexpr const char* kAssetsWizardId = "Game Assets Required##retip_assets";
static constexpr const char* kAssetsWizardText =
    "We cant legally provide the game assets for this recomp, Obtain a .iso file of the game and "
    "select it to start the extraction process, Once complete the play button will appear";
static constexpr float kAssetsWizardWidth = 720.0f;

static constexpr float kPad = 24.0f;
static constexpr float kBarHeight = 116.0f;
static constexpr float kWallpaperVerticalShift = 260.0f;
static constexpr float kBtnHeight = 46.0f;
static constexpr float kBtnGap = 10.0f;
static constexpr float kRowBottomPad = 22.0f;
static constexpr float kCheckboxGap = 10.0f;

bool LaunchMenuDialog::WillShowOnStartup() {
    return REXCVAR_GET(ShowLaunchMenu);
}

void LaunchMenuDialog::ReleaseWallpaper() {
    wallpaper_.reset();
    wallpaperPixels_.clear();
    wallpaperPixels_.shrink_to_fit();
    gjIcon_.reset();
}

void LaunchMenuDialog::EnsureWallpaper() {
    if (wallpaper_ || wallpaperLoadFailed_) return;

    if (wallpaperPixels_.empty()) {
        auto path = rex::filesystem::GetExecutableFolder() / "retip" / "wallpaper.png";
        std::ifstream file(path, std::ios::binary | std::ios::ate);
        if (!file) {
            wallpaperLoadFailed_ = true;
            return;
        }
        std::vector<uint8_t> bytes(static_cast<size_t>(file.tellg()));
        file.seekg(0);
        file.read(reinterpret_cast<char*>(bytes.data()), bytes.size());

        wallpaperPixels_ = rex::ui::DecodeImageRGBA(bytes.data(), bytes.size(), wallpaperW_, wallpaperH_);
        if (wallpaperPixels_.empty()) {
            wallpaperLoadFailed_ = true;
            return;
        }
    }

    auto* immediate = imgui_drawer()->immediate_drawer();
    if (!immediate) return;
    wallpaper_ = immediate->CreateTexture(wallpaperW_, wallpaperH_, rex::ui::ImmediateTextureFilter::kLinear, false, wallpaperPixels_.data());
    if (wallpaper_) {
        wallpaperPixels_.clear();
        wallpaperPixels_.shrink_to_fit();
    }
}

void LaunchMenuDialog::EnsureGameJoltIcon() {
    if (gjIcon_ || gjIconLoadFailed_) return;

    auto path = rex::filesystem::GetExecutableFolder() / "retip" / "gamejolt.png";
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) {
        gjIconLoadFailed_ = true;
        return;
    }
    std::vector<uint8_t> bytes(static_cast<size_t>(file.tellg()));
    file.seekg(0);
    file.read(reinterpret_cast<char*>(bytes.data()), bytes.size());

    auto pixels = rex::ui::DecodeImageRGBA(bytes.data(), bytes.size(), gjIconW_, gjIconH_);
    if (pixels.empty()) {
        gjIconLoadFailed_ = true;
        return;
    }
    auto* immediate = imgui_drawer()->immediate_drawer();
    if (!immediate) return;
    gjIcon_ = immediate->CreateTexture(gjIconW_, gjIconH_, rex::ui::ImmediateTextureFilter::kLinear, false, pixels.data());
    if (!gjIcon_) gjIconLoadFailed_ = true;
}

void LaunchMenuDialog::DrawGameJoltButton(float left, float top) {
    if (!rex::gamejolt::IsStarted()) return;

    EnsureGameJoltIcon();

    ImGui::SetCursorPos(ImVec2(left, top));
    ImGui::InvisibleButton("##gj_account", ImVec2(kGjSize, kGjSize));
    const bool hovered = ImGui::IsItemHovered();
    const bool clicked = ImGui::IsItemClicked();

    ImDrawList* dl = ImGui::GetWindowDrawList();
    const ImVec2 tl = ImGui::GetItemRectMin();
    const ImVec2 br = ImGui::GetItemRectMax();
    const ImVec2 center((tl.x + br.x) * 0.5f, (tl.y + br.y) * 0.5f);
    const float radius = kGjSize * 0.5f;

    const auto state = rex::gamejolt::GetSignInState();
    ImU32 ring = IM_COL32(128, 128, 140, 255);
    const char* status = "Not signed in";
    switch (state) {
        case rex::gamejolt::SignInState::kSignedIn:
            ring = IM_COL32(51, 204, 102, 255); status = "Signed in"; break;
        case rex::gamejolt::SignInState::kPending:
            ring = IM_COL32(255, 190, 51, 255); status = "Signing in..."; break;
        case rex::gamejolt::SignInState::kFailed:
            ring = IM_COL32(229, 77, 77, 255); status = "Sign-in failed"; break;
        case rex::gamejolt::SignInState::kSignedOut:
            break;
    }

    dl->AddCircleFilled(center, radius, IM_COL32(0, 0, 0, hovered ? 205 : 140));
    if (gjIcon_) {
        const float inset = 4.0f;
        dl->AddImageRounded(reinterpret_cast<ImTextureID>(gjIcon_.get()),
                            ImVec2(tl.x + inset, tl.y + inset), ImVec2(br.x - inset, br.y - inset),
                            ImVec2(0, 0), ImVec2(1, 1), IM_COL32_WHITE, radius - inset);
    } else {
        constexpr float kPi = 3.14159265f;
        const ImU32 fg = IM_COL32(225, 228, 235, 255);
        dl->AddCircleFilled(ImVec2(center.x, center.y - radius * 0.22f), radius * 0.27f, fg);
        dl->PathClear();
        dl->PathArcTo(ImVec2(center.x, center.y + radius * 0.60f), radius * 0.48f, kPi, kPi * 2.0f);
        dl->PathFillConvex(fg);
    }
    dl->AddCircle(center, radius - 1.0f, ring, 0, 2.5f);

    if (hovered) {
        const std::string user = rex::gamejolt::GetUsername();
        ImGui::BeginTooltip();
        if (state == rex::gamejolt::SignInState::kSignedIn && !user.empty()) {
            ImGui::Text("Game Jolt: %s", user.c_str());
        } else {
            ImGui::Text("Game Jolt: %s", status);
        }
        ImGui::TextDisabled("Click to manage your account");
        ImGui::EndTooltip();
    }

    if (clicked) {
        const std::string user = rex::gamejolt::GetUsername();
        if (!user.empty()) std::snprintf(gjUsername_, sizeof(gjUsername_), "%s", user.c_str());
        std::memset(gjToken_, 0, sizeof(gjToken_));
        gjPopupQueued_ = true;
    }
}

void LaunchMenuDialog::DrawGameJoltPopup() {
    if (!rex::gamejolt::IsStarted()) return;
    if (gjPopupQueued_) {
        ImGui::OpenPopup(kGameJoltPopupId);
        gjPopupQueued_ = false;
    }

    ImGui::SetNextWindowSize(ImVec2(390.0f, 0.0f), ImGuiCond_Always);
    if (!ImGui::BeginPopup(kGameJoltPopupId)) return;

    const auto state = rex::gamejolt::GetSignInState();
    ImGui::SeparatorText("Game Jolt");

    if (state == rex::gamejolt::SignInState::kSignedIn) {
        ImGui::Text("Signed in as %s", rex::gamejolt::GetUsername().c_str());
        ImGui::TextDisabled("Trophies are awarded automatically as you play.");
        ImGui::Spacing();
        if (ImGui::Button("Sign Out", ImVec2(120.0f, 0.0f))) rex::gamejolt::SignOut();
        ImGui::SameLine();
        if (ImGui::Button("Sync Trophies", ImVec2(140.0f, 0.0f))) rex::gamejolt::SyncTrophies();
    } else if (state == rex::gamejolt::SignInState::kPending) {
        ImGui::TextDisabled("Signing in...");
    } else {
        ImGui::TextWrapped(
            "Sign in to earn Game Jolt trophies for your achievements. Your user token is not your "
            "password - grab it from your Game Jolt account page.");
        ImGui::Spacing();
        ImGui::SetNextItemWidth(-1.0f);
        ImGui::InputTextWithHint("##gj_user", "Username", gjUsername_, sizeof(gjUsername_));
        ImGui::SetNextItemWidth(-1.0f);
        ImGui::InputTextWithHint("##gj_token", "User token", gjToken_, sizeof(gjToken_),
                                 ImGuiInputTextFlags_Password);
        ImGui::Spacing();

        const bool canSubmit = gjUsername_[0] != '\0' && gjToken_[0] != '\0';
        ImGui::BeginDisabled(!canSubmit);
        if (ImGui::Button("Sign In", ImVec2(120.0f, 0.0f))) {
            rex::gamejolt::SignIn(gjUsername_, gjToken_);
            std::memset(gjToken_, 0, sizeof(gjToken_));
        }
        ImGui::EndDisabled();
        ImGui::SameLine();
        if (ImGui::Button("Get my token", ImVec2(140.0f, 0.0f))) SDL_OpenURL(kGameJoltTokenUrl);

        if (state == rex::gamejolt::SignInState::kFailed) {
            const std::string error = rex::gamejolt::GetLastError();
            ImGui::Spacing();
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.45f, 0.45f, 1.0f));
            ImGui::TextWrapped("%s", error.empty() ? "Sign-in failed." : error.c_str());
            ImGui::PopStyleColor();
        }
    }

    ImGui::EndPopup();
}

void LaunchMenuDialog::SyncOptionsFromCVars() {
    if (REXCVAR_GET(UseAspectRatioFromConfig)) {
        double ar = REXCVAR_GET(AspectRatio);
        if (fabs(ar - AspectRatioForChoice(kAspect16x10)) < 0.01) aspectIndex_ = kAspect16x10;
        else if (fabs(ar - AspectRatioForChoice(kAspect21x9)) < 0.01) aspectIndex_ = kAspect21x9;
        else if (fabs(ar - AspectRatioForChoice(kAspect32x9)) < 0.01) aspectIndex_ = kAspect32x9;
        else { aspectIndex_ = kAspectCustom; customAspectRatio_ = static_cast<float>(ar); }
    } else {
        aspectIndex_ = kAspect16x9;
    }

    resolutionIndex_ = (rex::cvar::Query<int32_t>("resolution_scale") >= kResolutionScales[1]) ? 1 : 0;
    qualityIndex_ = DetectQualityPreset();
}

double LaunchMenuDialog::EffectiveAspectRatio() const {
    if (aspectIndex_ == kAspectCustom) return static_cast<double>(customAspectRatio_);
    if (aspectIndex_ == kAspect16x9 || aspectIndex_ == kAspectNative) return 16.0 / 9.0;
    return AspectRatioForChoice(aspectIndex_);
}

void LaunchMenuDialog::ResizeWindowToAspect(double aspectRatio) {
#ifdef _WIN32
    if (!window_ || window_->IsFullscreen()) return;
    HWND hwnd = reinterpret_cast<HWND>(window_->GetNativeWindowHandle());
    if (!hwnd || IsZoomed(hwnd)) return;

    int height = kResolutionScales[resolutionIndex_] * 720;
    int width = static_cast<int>(std::lround(height * aspectRatio));

    RECT rect{0, 0, width, height};
    DWORD style = static_cast<DWORD>(GetWindowLongPtrW(hwnd, GWL_STYLE));
    DWORD exStyle = static_cast<DWORD>(GetWindowLongPtrW(hwnd, GWL_EXSTYLE));
    AdjustWindowRectEx(&rect, style, FALSE, exStyle);
    SetWindowPos(hwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
#endif
}

void LaunchMenuDialog::StartGame() {
    REXCVAR_SET(ShowLaunchMenu, showOnStartup);
    rex::cvar::SaveConfig(configPath_);
    visible_ = false;
    optionsOpen_ = false;
    g_LaunchMenuOpen = false;
    if (onClosed_) {
        auto cb = std::move(onClosed_);
        onClosed_ = nullptr;
        cb();
    }
}

static bool BrandButton(const char* label, ImVec4 color, ImVec2 size) {
    ImGui::PushStyleColor(ImGuiCol_Button, color);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(color.x * 1.15f, color.y * 1.15f, color.z * 1.15f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(color.x * 0.85f, color.y * 0.85f, color.z * 0.85f, 1.0f));
    bool clicked = ImGui::Button(label, size);
    ImGui::PopStyleColor(3);
    return clicked;
}

void LaunchMenuDialog::OnDraw(ImGuiIO& io) {
    if (!initialized_) {
        initialized_ = true;
        showOnStartup = REXCVAR_GET(ShowLaunchMenu);
        visible_ = showOnStartup || !gameInstalled_;
    }

    g_LaunchMenuOpen = visible_;
    if (!visible_) {
        ReleaseWallpaper();
        return;
    }

    EnsureWallpaper();

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(io.DisplaySize, ImGuiCond_Always);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::Begin("##ReTiPLauncher", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNav);
    ImGui::PopStyleVar(3);

    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 disp = io.DisplaySize;

    if (wallpaper_) {
        float scale = std::max(disp.x / (float)wallpaperW_, disp.y / (float)wallpaperH_);
        ImVec2 size(wallpaperW_ * scale, wallpaperH_ * scale);
        float posY = (disp.y - size.y) * 0.5f - kWallpaperVerticalShift;
        posY = std::clamp(posY, disp.y - size.y, 0.0f);
        ImVec2 pos((disp.x - size.x) * 0.5f, posY);
        dl->AddImage(reinterpret_cast<ImTextureID>(wallpaper_.get()), pos, ImVec2(pos.x + size.x, pos.y + size.y));
    } else {
        dl->AddRectFilled(ImVec2(0, 0), disp, ImColor(14, 16, 20, 255));
    }

    DrawGameJoltButton(kPad, kPad);

    if (window_) {
        const ImVec2 fsSize(120.0f, 34.0f);
        const char* fsLabel = window_->IsFullscreen() ? "Windowed" : "Fullscreen";
        ImGui::SetCursorPos(ImVec2(disp.x - kPad - fsSize.x, kPad));
        if (BrandButton(fsLabel, ImVec4(0.0f, 0.0f, 0.0f, 0.55f), fsSize)) {
            rex::cvar::SetFlagByName("fullscreen", window_->IsFullscreen() ? "false" : "true");
        }
    }

    float barTop = disp.y - kBarHeight;
    dl->AddRectFilledMultiColor(ImVec2(0, barTop - 70.0f), ImVec2(disp.x, barTop), ImColor(0, 0, 0, 0), ImColor(0, 0, 0, 0), ImColor(0, 0, 0, 200), ImColor(0, 0, 0, 200));
    dl->AddRectFilled(ImVec2(0, barTop), disp, ImColor(0, 0, 0, 200));

    ImGui::SetCursorPos(ImVec2(kPad, barTop + 20.0f));
    ImGui::SetWindowFontScale(2.0f);
    ImGui::TextUnformatted("ReTiP");
    float titleWidth = ImGui::CalcTextSize("ReTiP").x * 2.0f;
    ImGui::SetWindowFontScale(1.0f);
    ImGui::SetCursorPos(ImVec2(kPad + 2.0f, barTop + 58.0f));
    ImGui::TextDisabled("Version %s", retipversion.c_str());

    float rowY = disp.y - kRowBottomPad - kBtnHeight;

    const ImVec2 btnSize(120.0f, kBtnHeight);
    const float kGroupGap = 30.0f;
    const float kOptionsGap = 16.0f;
    float rowWidth = btnSize.x * 4.0f + kBtnGap * 3.0f;
    const ImVec2 playSize(gameInstalled_ ? 170.0f : 0.0f, kBtnHeight);
    const ImVec2 optionsSize(170.0f, kBtnHeight);
    float playX = disp.x - kPad - playSize.x;
    float optionsX = playX - (gameInstalled_ ? kOptionsGap : 0.0f) - optionsSize.x;

    float rowX = (disp.x - rowWidth) * 0.5f;
    rowX = std::max(rowX, kPad + titleWidth + kBtnGap * 2.0f);
    rowX = std::min(rowX, optionsX - kGroupGap - rowWidth);

    bool play = false;
    if (gameInstalled_) {
        ImGui::SetCursorPos(ImVec2(playX, rowY));
        ImGui::SetWindowFontScale(1.15f);
        play = BrandButton("PLAY", ImVec4(0.0f, 0.62f, 0.36f, 1.0f), playSize);
        ImGui::SetWindowFontScale(1.0f);
    }

    ImGui::SetCursorPos(ImVec2(optionsX, rowY));
    ImGui::SetWindowFontScale(1.15f);
    if (BrandButton("OPTIONS", ImVec4(0.22f, 0.45f, 0.60f, 1.0f), optionsSize)) {
        bool wasOpen = optionsOpen_;
        optionsOpen_ = !optionsOpen_;
        if (optionsOpen_ && !wasOpen) SyncOptionsFromCVars();
    }
    ImGui::SetWindowFontScale(1.0f);

    if (gameInstalled_) {
        float checkboxY = rowY - ImGui::GetFrameHeightWithSpacing() - kCheckboxGap;
        ImGui::SetCursorPos(ImVec2(playX, checkboxY));
        if (ImGui::Checkbox("Show this launcher on startup", &showOnStartup)) {
            REXCVAR_SET(ShowLaunchMenu, showOnStartup);
        }
    }

    ImGui::SetCursorPos(ImVec2(rowX, rowY));
    if (BrandButton("Patreon", ImVec4(0.90f, 0.27f, 0.25f, 1.0f), btnSize)) SDL_OpenURL(kPatreonUrl);
    ImGui::SameLine(0.0f, kBtnGap);
    if (BrandButton("Discord", ImVec4(0.33f, 0.39f, 0.90f, 1.0f), btnSize)) SDL_OpenURL(kDiscordUrl);
    ImGui::SameLine(0.0f, kBtnGap);
    if (BrandButton("Ko-fi", ImVec4(0.95f, 0.35f, 0.45f, 1.0f), btnSize)) SDL_OpenURL(kKofiUrl);
    ImGui::SameLine(0.0f, kBtnGap);
    if (BrandButton("GitHub", ImVec4(0.25f, 0.28f, 0.33f, 1.0f), btnSize)) SDL_OpenURL(kGithubUrl);

    DrawGameJoltPopup();

    ImGui::End();

    DrawOptionsWindow(io);
    DrawAssetsWizard(io);

    if (assetsJustInstalled_) {
        assetsJustInstalled_ = false;
        if (onAssetsInstalled_) {
            auto cb = std::move(onAssetsInstalled_);
            onAssetsInstalled_ = nullptr;
            cb(assetsDir_);
        }
    }

    const bool enterToPlay = ImGui::IsKeyPressed(ImGuiKey_Enter) && !ImGui::IsAnyItemActive() &&
                             !ImGui::IsPopupOpen(kGameJoltPopupId);
    if (gameInstalled_ && (play || enterToPlay)) {
        StartGame();
    }
}

void LaunchMenuDialog::OpenIsoPicker() {
    if (isoPickerBusy_) return;
    isoPickerBusy_ = true;
    isoError_.clear();

    isoPick_ = std::make_shared<IsoPickResult>();
    auto shared = isoPick_;
    tip::ShowOpenFileDialog("Select the game disc image", "Xbox 360 disc image", "*.iso",
                            [shared](tip::FilePickResult result) {
                                std::lock_guard<std::mutex> lock(shared->mutex);
                                shared->path = std::move(result.path);
                                shared->error = std::move(result.error);
                                shared->ready = true;
                            });
}

void LaunchMenuDialog::PollIsoPicker() {
    if (!isoPick_) return;

    std::string chosen;
    std::string failure;
    {
        std::lock_guard<std::mutex> lock(isoPick_->mutex);
        if (!isoPick_->ready) return;
        chosen = isoPick_->path;
        failure = isoPick_->error;
    }
    isoPick_.reset();
    isoPickerBusy_ = false;

    if (!failure.empty()) {
        isoError_ = std::move(failure);
        return;
    }
    if (chosen.empty()) return;
    if (!extractor_.Start(std::filesystem::path(chosen), assetsDir_)) {
        isoError_ = extractor_.error();
    }
}

void LaunchMenuDialog::DrawAssetsWizard(ImGuiIO& io) {
    if (gameInstalled_) return;

    PollIsoPicker();

    if (!ImGui::IsPopupOpen(kAssetsWizardId)) ImGui::OpenPopup(kAssetsWizardId);

    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(kAssetsWizardWidth, 0.0f), ImGuiCond_Always);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(22.0f, 20.0f));
    const bool open = ImGui::BeginPopupModal(kAssetsWizardId, nullptr,
                                             ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                                             ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
    ImGui::PopStyleVar();
    if (!open) return;

    const float contentWidth = ImGui::GetContentRegionAvail().x;
    const float wrapPos = ImGui::GetCursorPosX() + contentWidth;

    ImGui::SetWindowFontScale(1.2f);
    ImGui::PushTextWrapPos(wrapPos);
    ImGui::TextUnformatted(kAssetsWizardText);
    ImGui::PopTextWrapPos();
    ImGui::SetWindowFontScale(1.0f);

    ImGui::Spacing();
    ImGui::PushTextWrapPos(wrapPos);
    ImGui::TextDisabled("Destination: %s", assetsDir_.string().c_str());
    ImGui::PopTextWrapPos();
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    const tip::IsoExtractState state = extractor_.state();
    if (state == tip::IsoExtractState::kScanning || state == tip::IsoExtractState::kExtracting) {
        char overlay[64];
        if (state == tip::IsoExtractState::kScanning) {
            std::snprintf(overlay, sizeof(overlay), "Reading image...");
        } else {
            std::snprintf(overlay, sizeof(overlay), "%.0f%%  (%u / %u files)",
                          extractor_.progress() * 100.0f, extractor_.files_done(),
                          extractor_.files_total());
        }
        ImGui::ProgressBar(extractor_.progress(), ImVec2(contentWidth, 32.0f), overlay);

        ImGui::Spacing();
        ImGui::PushTextWrapPos(ImGui::GetCursorPosX() + contentWidth);
        ImGui::TextDisabled("%s", extractor_.current_file().c_str());
        ImGui::PopTextWrapPos();
    } else {
        const char* label = isoPickerBusy_ ? "Waiting for file picker..." : "Select Iso";
        const ImVec2 buttonSize(220.0f, 44.0f);
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (contentWidth - buttonSize.x) * 0.5f);
        ImGui::BeginDisabled(isoPickerBusy_);
        if (BrandButton(label, ImVec4(0.85f, 0.55f, 0.0f, 1.0f), buttonSize)) {
            OpenIsoPicker();
        }
        ImGui::EndDisabled();

        const std::string message = !isoError_.empty() ? isoError_
                                  : state == tip::IsoExtractState::kFailed ? extractor_.error()
                                  : std::string();
        if (!message.empty()) {
            ImGui::Spacing();
            ImGui::PushTextWrapPos(ImGui::GetCursorPosX() + contentWidth);
            ImGui::TextColored(ImVec4(1.0f, 0.42f, 0.38f, 1.0f), "%s", message.c_str());
            ImGui::PopTextWrapPos();
        }
    }

    if (state == tip::IsoExtractState::kDone) {
        gameInstalled_ = true;
        assetsJustInstalled_ = true;
        ImGui::CloseCurrentPopup();
    }

    ImGui::EndPopup();
}

void LaunchMenuDialog::DrawOptionsWindow(ImGuiIO& io) {
    if (!optionsOpen_) return;

    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.45f), ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    if (ImGui::Begin("Options", &optionsOpen_,ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse)) {
        static constexpr float kItemWidth = 240.0f;

        ImGui::SeparatorText("Display");

        ImGui::TextUnformatted("Aspect Ratio");
        ImGui::SetNextItemWidth(kItemWidth);
        if (ImGui::Combo("##AspectRatio", &aspectIndex_, kAspectNames, kAspectCount)) {
            if (aspectIndex_ == kAspect16x9 || aspectIndex_ == kAspectNative) {
                REXCVAR_SET(UseAspectRatioFromConfig, false);
            } else if (aspectIndex_ == kAspectCustom) {
                REXCVAR_SET(UseAspectRatioFromConfig, true);
                REXCVAR_SET(AspectRatio, static_cast<double>(customAspectRatio_));
            } else {
                REXCVAR_SET(UseAspectRatioFromConfig, true);
                REXCVAR_SET(AspectRatio, AspectRatioForChoice(aspectIndex_));
            }
            rex::cvar::SetFlagByName("fullscreen_span_monitors", aspectIndex_ == kAspect32x9 ? "true" : "false");
            if (aspectIndex_ != kAspectNative) ResizeWindowToAspect(EffectiveAspectRatio());
        }

        if (aspectIndex_ == kAspectCustom) {
            ImGui::SetNextItemWidth(kItemWidth);
            if (ImGui::InputFloat("##CustomAspectRatio", &customAspectRatio_, 0.0f, 0.0f, "%.4f")) {
                if (customAspectRatio_ < 0.5f) customAspectRatio_ = 0.5f;
                if (customAspectRatio_ > 4.0f) customAspectRatio_ = 4.0f;
                REXCVAR_SET(AspectRatio, static_cast<double>(customAspectRatio_));
                ResizeWindowToAspect(customAspectRatio_);
            }
        }

        ImGui::TextUnformatted("Resolution");
        ImGui::SetNextItemWidth(kItemWidth);
        if (ImGui::Combo("##Resolution", &resolutionIndex_, kResolutionNames, 2)) {
            rex::cvar::SetFlagByName("resolution_scale", std::to_string(kResolutionScales[resolutionIndex_]));
            if (aspectIndex_ != kAspectNative) ResizeWindowToAspect(EffectiveAspectRatio());
        }

        ImGui::TextUnformatted("Quality");
        ImGui::SetNextItemWidth(kItemWidth);
        if (ImGui::Combo("##Quality", &qualityIndex_, kQualityNames, 4)) {
            ApplyQualityPreset(qualityIndex_);
        }

        ImGui::Spacing();
        ImGui::SeparatorText("General");

        if (window_) {
            bool fs = window_->IsFullscreen();
            if (ImGui::Checkbox("Fullscreen", &fs)) {
                rex::cvar::SetFlagByName("fullscreen", fs ? "true" : "false");
            }
        }
        CVAR_CHECKBOX("Discord Activity", DiscordActivity);
        CVAR_CHECKBOX("Show FPS", show_fps);
        CVAR_CHECKBOX("Lock FPS", lock_fps);
        CVAR_CHECKBOX("Skip Intros", SkipIntros);
    }
    ImGui::End();
}
