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
