#include "LaunchMenu.h"
#include "tip_engine/Globals.h"
#include "tip_engine/version.h"
#include <rex/cvar.h>
#include <rex/filesystem.h>
#include <rex/ui/image_decode.h>
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>
#include <fstream>

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
    "16:9 Widescreen", "16:10 Widescreen", "21:9 Widescreen", "32:9 Widescreen", "Native", "Custom"
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
static constexpr const char* kGoopieUrl  = "https://goopie.xyz/#/library";

static constexpr float kPad = 24.0f;
static constexpr float kBarHeight = 116.0f;
static constexpr float kWallpaperVerticalShift = 160.0f;
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
        visible_ = REXCVAR_GET(ShowLaunchMenu);
        showOnStartup = visible_;
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
    const ImVec2 playSize(gameInstalled_ ? 170.0f : 260.0f, kBtnHeight);
    const ImVec2 optionsSize(170.0f, kBtnHeight);
    float playX = disp.x - kPad - playSize.x;
    float optionsX = playX - kOptionsGap - optionsSize.x;

    float rowX = (disp.x - rowWidth) * 0.5f;
    rowX = std::max(rowX, kPad + titleWidth + kBtnGap * 2.0f);
    rowX = std::min(rowX, optionsX - kGroupGap - rowWidth);

    ImGui::SetCursorPos(ImVec2(playX, rowY));
    ImGui::SetWindowFontScale(gameInstalled_ ? 1.15f : 1.0f);
    ImVec4 playColor = gameInstalled_ ? ImVec4(0.0f, 0.62f, 0.36f, 1.0f) : ImVec4(0.85f, 0.55f, 0.0f, 1.0f);
    bool play = BrandButton(gameInstalled_ ? "PLAY" : "Install with Goopie", playColor, playSize);
    ImGui::SetWindowFontScale(1.0f);

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

    ImGui::End();

    DrawOptionsWindow(io);

    if (play || (gameInstalled_ && ImGui::IsKeyPressed(ImGuiKey_Enter))) {
        if (gameInstalled_) {
            StartGame();
        } else {
            SDL_OpenURL(kGoopieUrl);
        }
    }
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
