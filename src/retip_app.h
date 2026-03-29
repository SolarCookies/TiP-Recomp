// retip - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>
#include "tip_engine/hooks.h"
#include <rex/ppc/function.h>
#include "tip_engine/Log.h"
#include "tip_engine/Overlays/Fps.h"
#include "tip_engine/Overlays/DebugInfo.h"



class RetipApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<RetipApp>(new RetipApp(ctx, "retip",
        PPCImageConfig));
  }

  // Override virtual hooks for customization:
  // void OnPreSetup(rex::RuntimeConfig& config) override {}
  // void OnPostSetup() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // void OnShutdown() override {}
  // void OnConfigurePaths(rex::PathConfig& paths) override {}
  void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {
        drawer->AddDialog(new FpsOverlayDialog(drawer));
        //drawer->AddDialog(new DebugOverlayDialog(drawer));
    }
};

PPC_STUB(__imp__XUsbcamSetView)
PPC_STUB(__imp__XUsbcamSetCaptureMode)
PPC_STUB(__imp__XUsbcamSetConfig)
PPC_STUB(__imp__XUsbcamReadFrame)
PPC_STUB(__imp__XUsbcamDestroy)
PPC_STUB(__imp__XUsbcamGetState)
PPC_STUB(__imp__XUsbcamCreate)