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
* The core goal of ReTiP is not only to get the software running, but to 
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

// retip - ReXGlue Recompiled Project
//
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <filesystem>
#include <functional>
#include <memory>
#include <optional>

#include <rex/rex_app.h>

#ifdef _WIN32
#include <timeapi.h>
#pragma comment(lib, "winmm.lib")
#endif
#include "tip_engine/Globals.h"
#include <rex/discord_rpc.h>
#include <rex/filesystem.h>
#include <rex/gamejolt.h>

#if __has_include("gamejolt_keys.h")
#include "gamejolt_keys.h"
#include "gamejolt_trophies.h"
#endif

#include "tip_engine/hooks.h"
#include "tip_engine/Overlays/Fps.h"
#include "tip_engine/Overlays/LaunchMenu.h"
#include "tip_engine/Overlays/QuitMenu.h"
#include "tip_engine/Overlays/TiPTools.h"
#include "tip_engine/Overlays/TiP/TiPSettings.h"
#include "tip_engine/Overlays/TiPTools/SpawnMenu.h"
#include "tip_engine/Overlays/TiPTools/GraphicsMenu.h"
#include "tip_engine/Overlays/TiPTools/UpscalingMenu.h"
#include "tip_engine/Overlays/TiPTools/SettingsMenu.h"
#include "tip_engine/Overlays/TiPTools/PlantMenu.h"
#include "tip_engine/Overlays/TiPTools/PlayerMenu.h"
#include "tip_engine/Overlays/TiPTools/ShovelMenu.h"

class RetipApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<RetipApp>(new RetipApp(ctx, "retip", PPCImageConfig));
  }

  void OnPostSetup() override {
    rex::discord_rpc::Presence rpc;

    rpc.details_ = "";
    rpc.state_ = "";
    rpc.large_image_key_ = "10979_viva_piata_trouble_in_paradise";
    rpc.large_image_text_ = "ReTiP";

    rex::discord_rpc::Start("1497091207132876860", rpc);

#if defined(RETIP_GAMEJOLT_GAME_ID) && defined(RETIP_GAMEJOLT_KEY)
    retip::RegisterGameJoltTrophies();
    rex::gamejolt::Start(RETIP_GAMEJOLT_GAME_ID, RETIP_GAMEJOLT_KEY);
#endif

    //optimization tom suggested
    timeBeginPeriod(1);

    //Force MnK driver on regardless of toml, since EXE may run from build dir without retip.toml
    rex::cvar::SetFlagByName("mnk_mode", "true");

    //Silence MnK's mouse->right-stick path; CursorHooks consumes mouse delta directly
    rex::cvar::SetFlagByName("mnk_sensitivity", "0");

    g_input_system = static_cast<rex::input::InputSystem*>(runtime()->input_system());

    g_RexOverlayOpenFn = [this] { return IsBuiltinOverlayOpen(); };

    auto* w = window();
    if (!w) return;
    auto listener = std::make_unique<TipMouseListener>(w);
    w->AddInputListener(listener.get(), 1);
    g_mouse_listener = std::move(listener);

#ifdef _WIN32
    HWND hwnd = reinterpret_cast<HWND>(w->GetNativeWindowHandle());
    auto raw = std::make_unique<TipRawMouse>();
    if (raw->Setup(hwnd)) {
      g_raw_mouse = std::move(raw);
    }
#endif
  }

  void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {

    fps_dialog_ = std::make_unique<FpsOverlayDialog>(drawer);
    fps_dialog_->fpsManager = &fpsManager;
    drawer->AddDialog(fps_dialog_.get());

    gameInstalled_ = !game_data_root().empty() && std::filesystem::exists(game_data_root() / "default.xex");
    launch_dialog_ = std::make_unique<LaunchMenuDialog>(drawer, window(), "retip.toml", gameInstalled_, DefaultAssetsDir());
    launch_dialog_->SetOnAssetsInstalled([this](std::filesystem::path assets) { OnAssetsInstalled(std::move(assets)); });
    drawer->AddDialog(launch_dialog_.get());

    quit_dialog_ = std::make_unique<QuitMenuDialog>(drawer, window());
    drawer->AddDialog(quit_dialog_.get());

    tools_dialog_ = std::make_unique<TipToolsDialog>(drawer, "retip.toml");
    tools_dialog_->pages.push_back(std::make_unique<SpawnMenuPage>());
    tools_dialog_->pages.push_back(std::make_unique<PlayerMenuPage>());
    tools_dialog_->pages.push_back(std::make_unique<PlantMenuPage>());
    tools_dialog_->pages.push_back(std::make_unique<ShovelMenuPage>());
    tools_dialog_->pages.push_back(std::make_unique<GraphicsMenuPage>());
    tools_dialog_->pages.push_back(std::make_unique<UpscalingMenuPage>());
    tools_dialog_->pages.push_back(std::make_unique<SettingsMenuPage>());
    drawer->AddDialog(tools_dialog_.get());

    settings_dialog_ = std::make_unique<TiPSettingsDialog>(drawer);
    drawer->AddDialog(settings_dialog_.get());
  }

  void LaunchModule() override {
    if (launch_dialog_ && (LaunchMenuDialog::WillShowOnStartup() || launch_dialog_->IsVisible())) {
      launch_dialog_->SetOnClosed([this] { rex::ReXApp::LaunchModule(); });
      return;
    }
    rex::ReXApp::LaunchModule();
  }

  void OnShutdown() override {
    rex::discord_rpc::Stop();
    if (launch_dialog_) launch_dialog_->ReleaseWallpaper();
  }

  bool WantsUIInputMode() const override { return g_RetipOwnUiMode; }

  static std::filesystem::path DefaultAssetsDir() {
    return rex::filesystem::GetExecutableFolder() / "assets";
  }

  std::optional<rex::PathConfig> OnFinalizePaths(
      const rex::PathConfig& defaults,
      std::function<void(rex::PathConfig)> resume) override {
    if (!gameInstalled_) {
      pending_paths_ = defaults;
      resume_paths_ = std::move(resume);
      return std::nullopt;
    }
    return defaults;
  }

  void OnAssetsInstalled(std::filesystem::path assets) {
    gameInstalled_ = true;
    if (!resume_paths_) return;
    rex::PathConfig paths = pending_paths_;
    paths.game_data_root = std::move(assets);
    auto resume = std::move(resume_paths_);
    resume_paths_ = nullptr;
    resume(std::move(paths));
  }

  // std::unique_ptr<rex::ui::ImGuiDialog> CreateAchievementsOverlay() override;
  // std::unique_ptr<rex::ui::AchievementNotificationDialog>
  // CreateAchievementNotificationDialog() override;

  void OnConfigurePaths(rex::PathConfig &paths) override {
    if (paths.game_data_root.empty()) {
      auto assets_next_to_exe = DefaultAssetsDir();
      auto assets_in_build = std::filesystem::current_path() / "../../../assets"; // TiP-Recomp/assets/ TiP-Recomp/out/build/win-amd64-relwithdebinfo/retip.exe
      if (std::filesystem::exists(assets_next_to_exe)) {
        paths.game_data_root = assets_next_to_exe;
      } else if (std::filesystem::exists(assets_in_build)) {
        paths.game_data_root = assets_in_build;
      }
    }
  }

 private:
  bool gameInstalled_ = true;
  rex::PathConfig pending_paths_;
  std::function<void(rex::PathConfig)> resume_paths_;
  std::unique_ptr<FpsOverlayDialog> fps_dialog_;
  std::unique_ptr<LaunchMenuDialog> launch_dialog_;
  std::unique_ptr<QuitMenuDialog> quit_dialog_;
  std::unique_ptr<TipToolsDialog> tools_dialog_;
  std::unique_ptr<TiPSettingsDialog> settings_dialog_;
};

REX_STUB(__imp__XUsbcamSetView)
REX_STUB(__imp__XUsbcamSetCaptureMode)
REX_STUB(__imp__XUsbcamSetConfig)
REX_STUB(__imp__XUsbcamReadFrame)
REX_STUB(__imp__XUsbcamDestroy)
REX_STUB(__imp__XUsbcamCreate)
//REX_STUB(__imp__XUsbcamGetState) in main.cpp I have a empty hook that silences the log that there is a stub