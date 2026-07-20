#pragma once
#include <filesystem>
#include <functional>
#include <memory>
#include <utility>
#include <vector>
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/immediate_drawer.h>
#include <rex/cvar.h>
#include "imgui.h"

REXCVAR_DECLARE(bool, ShowLaunchMenu);

class LaunchMenuDialog : public rex::ui::ImGuiDialog {
public:
    LaunchMenuDialog(rex::ui::ImGuiDrawer* drawer, rex::ui::Window* window, std::filesystem::path configPath, bool gameInstalled) : rex::ui::ImGuiDialog(drawer), window_(window), configPath_(std::move(configPath)), gameInstalled_(gameInstalled) {}

    static bool WillShowOnStartup();

    void SetOnClosed(std::function<void()> cb) { onClosed_ = std::move(cb); }

    void ReleaseWallpaper();

    void OnDraw(ImGuiIO& io) override;

private:
    void EnsureWallpaper();
    void DrawOptionsWindow(ImGuiIO& io);
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

    rex::ui::Window* window_ = nullptr;
    std::filesystem::path configPath_;
    std::function<void()> onClosed_;
    bool gameInstalled_ = true;
};
