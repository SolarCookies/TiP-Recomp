// retip - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <memory>
#include <rex/rex_app.h>
#include "generated/retip_init.h"
#include "tip_engine/hooks.h"
#include <rex/ppc/function.h>
#include "tip_engine/Log.h"
#include "tip_engine/Overlays/Fps.h"
#include "tip_engine/Overlays/DebugInfo.h"
#include "ImPlot/implot.h"
#include "Webcam.h"
#include "tip_engine/Globals.h"
#include "tip_engine/Overlays/TiPTools.h"
#include "tip_engine/Overlays/TiPTools/SpawnMenu.h"
#include "tip_engine/Overlays/TiPTools/PlayerMenu.h"
#include "tip_engine/Overlays/TiPTools/GraphicsMenu.h"
#include "tip_engine/Overlays/TiPTools/SettingsMenu.h"
#include "tip_engine/Overlays/TiPTools/PinataMenu.h"
#include "tip_engine/Overlays/TiPTools/PlantMenu.h"
#include "tip_engine/Overlays/TiPTools/ShovelMenu.h"
#include "tip_engine/Overlays/TiPTools/RuffianMenu.h"
#include "tip_engine/Overlays/StartupOverlay.h"
#include "tip_engine/Input/TipMouseListener.h"
#include "tip_engine/Input/TipRawMouse.h"
#include "tip_engine/CustomRenderer/Window.h"
#include "tip_engine/CustomRenderer/engine/World/World.h"
#include "tip_engine/CustomRenderer/engine/World/Camera.h"

#include "tip_engine/CustomRenderer/engine/Actors/SkyboxActor.h"
#include "tip_engine/CustomRenderer/engine/Actors/DebugGridActor.h"
#include "tip_engine/CustomRenderer/engine/Actors/VertexPreviewActor.h"
#include "tip_engine/DiscordRPC.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#include <cstdint>
#include <timeapi.h>
#include <fstream>
#include <thread>
#include <atomic>

#ifdef DEBUG_BUILD
REXCVAR_DEFINE_BOOL(SolarRendererPreview, false, "_Trouble in Paradise/Graphics", "Enables the Solar Renderer").lifecycle(rex::cvar::Lifecycle::kRequiresRestart);
REXCVAR_DEFINE_BOOL(OverlaySolarRenderer, false, "_Trouble in Paradise/Graphics", "Overlay Solar Renderer on main window").lifecycle(rex::cvar::Lifecycle::kRequiresRestart);
#endif

REXCVAR_DEFINE_BOOL(ShowStartupOverlay, true, "_Trouble in Paradise", "Show startup overlay popup");

//Pulled from SDK's mnk_input_driver.cpp - no public header declares it
REXCVAR_DECLARE(bool, mnk_mode);
REXCVAR_DECLARE(double, mnk_sensitivity);


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
        Log(LogLevel::Info, "Application Started");

        ImPlot::CreateContext();
        //g_raw_input = runtime()->input_system()->GetRawInput();
        timeBeginPeriod(1);

        g_input_system = static_cast<rex::input::InputSystem*>(runtime()->input_system());
        SetRetipInputUiMode(false);

        //Force MnK driver on regardless of toml, since EXE may run from build dir without retip.toml
        //Edit, this is not needed, goopie will download the toml from the release, and also some might want to use the mouse for the f4 menu
        //Curently Im not sure if there is a button to disable the mouse lock like Alt but that might be worth looking into before
        //forceing mouse locks
        //REXCVAR_SET(mnk_mode, true);

        //Silence MnK's mouse->right-stick path; CursorHooks consumes mouse delta directly
        REXCVAR_SET(mnk_sensitivity, 0.0);

        //timeBeginPeriod(1);

        Log(LogLevel::Info, "Initializing Discord RPC");
        retip::discord_rpc::Presence rpc;
        rpc.details        = "";
        rpc.state          = "";
        rpc.largeImageKey  = "10979_viva_piata_trouble_in_paradise";
        rpc.largeImageText = "ReTiP";
        retip::discord_rpc::Start(rpc);
        Log(LogLevel::Info, "Discord RPC Initialized");

#ifdef DEBUG_BUILD
        if(REXCVAR_GET(SolarRendererPreview)) {

            windowPtr = std::make_unique<VinceWindow>(1280, 720, "Solar Renderer", REXCVAR_GET(OverlaySolarRenderer));
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

            // Vertex preview: renders DrawVerticesUP captured verts as points
            auto vertexPreview = std::make_unique<VertexPreviewActor>();
            g_world->AddActor(std::move(vertexPreview));

            g_world->ConstructWorld();

            g_camera = std::make_unique<class Camera>(1280.0f, 720.0f, glm::vec3(0.0f, 0.0f, 2.0f));

            // Release the GL context so CPU_fps_hook can acquire it on its thread
            glfwMakeContextCurrent(nullptr);
            
        }
        #endif
   }

  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
   void OnShutdown() override {
        Log(LogLevel::Info, "Application Shutting Down");
     
        SetRetipInputUiMode(false);
        g_input_system = nullptr;

        if (g_raw_mouse) {
            g_raw_mouse->Teardown();
        }
        g_raw_mouse.reset();
        if (g_mouse_listener && window()) {
            window()->RemoveInputListener(g_mouse_listener.get());
        }
        g_mouse_listener.reset();

        Log(LogLevel::Info, "Shutting down Discord RPC");
        retip::discord_rpc::Stop();

        Log(LogLevel::Info, "Cleaning up resources");
        ImPlot::DestroyContext();

        Log(LogLevel::Info, "Cleaning up world and renderer");
        //timeEndPeriod(1);
        delete g_world;
        g_world = nullptr;
    }

  // void OnConfigurePaths(rex::PathConfig& paths) override {}
  void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {
    Log(LogLevel::Info, "Creating UI Dialogs");
    #ifdef DEBUG_BUILD
        if (windowPtr && windowPtr->isOverlay() && window()) {
            g_mainWindowHandle = window()->GetNativeWindowHandle();
        }
    #endif

        //Mouse delta source for native mouse-look. Try Win32 raw input first
        //(bypasses MnK's cursor centering -> no contamination from SetCursorPos
        //events). Fall back to the WindowInputListener path if raw input setup
        //fails (non-Win32 builds, or if RegisterRawInputDevices refuses).
        if (window()) {
            g_raw_mouse = std::make_unique<TipRawMouse>();
            bool raw_active = false;
#ifdef _WIN32
            HWND hwnd = static_cast<HWND>(window()->GetNativeWindowHandle());
            raw_active = g_raw_mouse->Setup(hwnd);
#endif
            if (!raw_active) {
                g_raw_mouse.reset();
                g_mouse_listener = std::make_unique<TipMouseListener>(window());
                window()->AddInputListener(g_mouse_listener.get(), 0);
            }
        }

        drawer->AddDialog(new StartupOverlayDialog(drawer));
        //drawer->AddDialog(new DebugOverlayDialog(drawer));
        auto fpsDialog = new FpsOverlayDialog(drawer);
        fpsDialog->fpsManager = &fpsManager;
        drawer->AddDialog(fpsDialog);

        auto tipToolsDialog = new TipToolsDialog(drawer);
        drawer->AddDialog(tipToolsDialog);
        
        tipToolsDialog->pages.push_back(std::make_unique<PlayerMenuPage>());
        tipToolsDialog->pages.push_back(std::make_unique<PinataMenuPage>());
        tipToolsDialog->pages.push_back(std::make_unique<PlantMenuPage>());
        tipToolsDialog->pages.push_back(std::make_unique<ShovelMenuPage>());
        tipToolsDialog->pages.push_back(std::make_unique<RuffianMenuPage>());
        tipToolsDialog->pages.push_back(std::make_unique<SpawnMenuPage>());
        //tipToolsDialog->pages.push_back(std::make_unique<GraphicsMenuPage>());
        //tipToolsDialog->pages.push_back(std::make_unique<SettingsMenuPage>());
        Log(LogLevel::Info, "UI Dialogs Created");
    }
};

PPC_STUB(__imp__XUsbcamSetView)
PPC_STUB(__imp__XUsbcamSetCaptureMode)
PPC_STUB(__imp__XUsbcamSetConfig)
PPC_STUB(__imp__XUsbcamReadFrame)
PPC_STUB(__imp__XUsbcamDestroy)
PPC_STUB(__imp__XUsbcamCreate)
PPC_STUB(__imp__XUsbcamGetState)
