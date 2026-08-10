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
#include <filesystem>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/immediate_drawer.h>
#include <rex/cvar.h>
#include "imgui.h"
#include "tip_engine/IsoExtract.h"

REXCVAR_DECLARE(bool, ShowLaunchMenu);

class LaunchMenuDialog : public rex::ui::ImGuiDialog {
public:
    LaunchMenuDialog(rex::ui::ImGuiDrawer* drawer, rex::ui::Window* window, std::filesystem::path configPath, bool gameInstalled, std::filesystem::path assetsDir) : rex::ui::ImGuiDialog(drawer), window_(window), configPath_(std::move(configPath)), assetsDir_(std::move(assetsDir)), gameInstalled_(gameInstalled) {}

    static bool WillShowOnStartup();

    void SetOnClosed(std::function<void()> cb) { onClosed_ = std::move(cb); }

    void SetOnAssetsInstalled(std::function<void(std::filesystem::path)> cb) { onAssetsInstalled_ = std::move(cb); }

    bool IsVisible() const { return visible_; }

    void ReleaseWallpaper();

    void OnDraw(ImGuiIO& io) override;

private:
    struct IsoPickResult {
        std::mutex mutex;
        std::string path;
        std::string error;
        bool ready = false;
    };

    void EnsureWallpaper();
    void EnsureGameJoltIcon();
    void DrawGameJoltButton(float left, float top);
    void DrawGameJoltPopup();
    void DrawOptionsWindow(ImGuiIO& io);
    void DrawAssetsWizard(ImGuiIO& io);
    void PollIsoPicker();
    void OpenIsoPicker();
    void SyncOptionsFromCVars();
    void StartGame();
    double EffectiveAspectRatio() const;
    void ResizeWindowToAspect(double aspectRatio);

    bool visible_ = false;
    bool initialized_ = false;
    bool showOnStartup = true;
    bool optionsOpen_ = false;

    int aspectIndex_ = 0;
    float customAspectRatio_ = 1.7777778f;
    int resolutionIndex_ = 0;
    int qualityIndex_ = 3;

    std::unique_ptr<rex::ui::ImmediateTexture> wallpaper_;
    std::vector<uint8_t> wallpaperPixels_;
    int wallpaperW_ = 0;
    int wallpaperH_ = 0;
    bool wallpaperLoadFailed_ = false;

    std::unique_ptr<rex::ui::ImmediateTexture> gjIcon_;
    int gjIconW_ = 0;
    int gjIconH_ = 0;
    bool gjIconLoadFailed_ = false;
    char gjUsername_[64] = {};
    char gjToken_[128] = {};
    bool gjPopupQueued_ = false;

    rex::ui::Window* window_ = nullptr;
    std::filesystem::path configPath_;
    std::filesystem::path assetsDir_;
    std::function<void()> onClosed_;
    std::function<void(std::filesystem::path)> onAssetsInstalled_;
    bool gameInstalled_ = true;

    tip::IsoExtractor extractor_;
    std::shared_ptr<IsoPickResult> isoPick_;
    std::string isoError_;
    bool isoPickerBusy_ = false;
    bool assetsJustInstalled_ = false;
};
