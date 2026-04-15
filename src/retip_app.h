// retip - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <memory>
#include <rex/rex_app.h>
#include "retip_config.h"
#include "tip_engine/hooks.h"
#include <rex/ppc/function.h>
#include "tip_engine/Log.h"
#include "tip_engine/Overlays/Fps.h"
#include "tip_engine/Overlays/DebugInfo.h"
#include "ImPlot/implot.h"
#include "Webcam.h"
#include "tip_engine/Globals.h"
#include "tip_engine/SleepHooks.h"
#include "tip_engine/Overlays/TiPTools.h"
#include "tip_engine/Overlays/TiPTools/SpawnMenu.h"
#include "tip_engine/CustomRenderer/Window.h"
#include "tip_engine/CustomRenderer/engine/World/World.h"
#include "tip_engine/CustomRenderer/engine/World/Camera.h"

#include "tip_engine/CustomRenderer/engine/Actors/SkyboxActor.h"
#include "tip_engine/CustomRenderer/engine/Actors/DebugGridActor.h"

REXCVAR_DEFINE_BOOL(SolarRendererPreview, false, "_Trouble in Paradise/Graphics", "Enables the Solar Renderer").lifecycle(rex::cvar::Lifecycle::kRequiresRestart);
REXCVAR_DEFINE_BOOL(OverlaySolarRenderer, false, "_Trouble in Paradise/Graphics", "Overlay Solar Renderer on main window").lifecycle(rex::cvar::Lifecycle::kRequiresRestart);


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
   void OnPostSetup() override {
        ImPlot::CreateContext();
        g_raw_input = runtime()->input_system()->GetRawInput();
        timeBeginPeriod(1);

        if(REXCVAR_GET(SolarRendererPreview)) {

            windowPtr = std::make_unique<VinceWindow>(1280, 720, "TiP Recomp", REXCVAR_GET(OverlaySolarRenderer));
            windowPtr->SetupImGuiIO();
            windowPtr->InitFrameBuffer();

            glEnable(GL_DEPTH_TEST);
            glfwSwapInterval(0);

            g_world = new World();

            // Add a skybox actor to the world
            auto skyboxActor = std::make_unique<Skybox>();
            g_world->AddActor(std::move(skyboxActor));

            // Debug grid: 10x10 cubes on the XZ plane for camera testing
            auto debugGrid = std::make_unique<DebugGrid>();
            g_world->AddActor(std::move(debugGrid));

            g_world->ConstructWorld();

            g_camera = std::make_unique<class Camera>(1280.0f, 720.0f, glm::vec3(0.0f, 0.0f, 2.0f));

            // Release the GL context so CPU_fps_hook can acquire it on its thread
            glfwMakeContextCurrent(nullptr);
            
        }
   }

  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
   void OnShutdown() override {
        ImPlot::DestroyContext();
        DisableHighResTimer();
        delete g_world;
        g_world = nullptr;
   }
  // void OnConfigurePaths(rex::PathConfig& paths) override {}
  void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {
        // Capture main window handle now that the window exists
        if (windowPtr && windowPtr->isOverlay() && window()) {
            g_mainWindowHandle = window()->GetNativeWindowHandle();
        }

        drawer->AddDialog(new DebugOverlayDialog(drawer));
        auto fpsDialog = new FpsOverlayDialog(drawer);
        fpsDialog->fpsManager = &fpsManager;
        drawer->AddDialog(fpsDialog);

        auto tipToolsDialog = new TipToolsDialog(drawer);
        drawer->AddDialog(tipToolsDialog);
        tipToolsDialog->pages.push_back(std::make_unique<SpawnMenuPage>());
    }
};

PPC_STUB(__imp__XUsbcamSetView)
PPC_STUB(__imp__XUsbcamSetCaptureMode)
PPC_STUB(__imp__XUsbcamSetConfig)
PPC_STUB(__imp__XUsbcamReadFrame)
PPC_STUB(__imp__XUsbcamDestroy)
PPC_STUB(__imp__XUsbcamCreate)
PPC_STUB(__imp__XUsbcamGetState)

/*
inline int XUsbcamGetState_Replacement() {
    return 2;
}

PPC_HOOK(__imp__XUsbcamGetState, XUsbcamGetState_Replacement)

inline int XUsbcamCreate_Replacement(int buffer, int bufferSize, int* outHandle){
    *outHandle = std::byteswap(1);
    return 2;
}

PPC_HOOK(__imp__XUsbcamCreate, XUsbcamCreate_Replacement)

inline int XUsbcamReadFrame_Replacement(int handle, int pBuffer, int size, XUsbcamCallback callback, int context) {
    auto cam = fpsManager.GetCreateCounter("cam");

    cam->Tick();

    DebugLogInt32("callback size", size);
    DebugLogInt64("callback context", context);
    DebugLogInt64("callback handle", handle);
    DebugLogInt64("callback buffer", pBuffer);
    DebugLogInt64("callback callback ptr", (int64_t)callback);
    
    ReadCallback = callback; // Store the callback for later use
    ReadCallbackContext = context; // Store the context for later use
    ReadCallbackSize = size; // Store the size for later use
    
    return 2; 
}

PPC_HOOK(__imp__XUsbcamReadFrame, XUsbcamReadFrame_Replacement)


//((int (__fastcall *)(int, int, int, int *))XUsbcamSetConfig[0])(dword_82C11A5C, v16, v15, &v13);

//((int (__fastcall *)(int, int, int, int, int (*)(), int))XUsbcamSetView[0])(dword_82C11A5C,a1,a2,a3,v11,v8);

//((int (__fastcall *)(int, int, char *, unsigned int, _DWORD, int, _DWORD, int (*)()))XUsbcamSetCaptureMode[0])(dword_82C11A5C,4,"21VN",HIWORD(a2),(unsigned __int16)a2,v12,0,v10);

inline int XUsbcamSetConfig_Replacement(int a1, int a2, int a3, int* outConfig) {
    return 2;
}
PPC_HOOK(__imp__XUsbcamSetConfig, XUsbcamSetConfig_Replacement)

inline int XUsbcamSetView_Replacement(int a1, int a2, int a3, int a4, int (*callback)(), int a6) {
    return 2;
}
PPC_HOOK(__imp__XUsbcamSetView, XUsbcamSetView_Replacement)

inline int XUsbcamSetCaptureMode_Replacement(int a1, int a2, char* a3, unsigned int a4, int a5, int a6, int a7, int (*callback)()) {
    return 0;
}
PPC_HOOK(__imp__XUsbcamSetCaptureMode, XUsbcamSetCaptureMode_Replacement)
*/