#include "tip_engine/hooks.h"

#include <cstdint>
#include <cmath>
#include <cstring>
#include <chrono>
#include <rex/ui/imgui_dialog.h>
#include "D3DTypes.h"
#include "Log.h"
#include "Overlays/Fps.h"
#include "imgui.h"

#include <rex/cvar.h>
#include "tip_engine/rex_macros.h"
#include <rex/graphics/flags.h>
#include <rex/system/kernel_state.h>
#include "tip_engine/Log.h"
#include "tip_engine/D3DTypes.h"
#include "Overlays/DebugInfo.h"

#include "rex_macros.h"
#include <fstream>
#include <mutex>
#include "tip_engine/Types/CommonTypes.h"
#include <SDL3/SDL.h>
#include <thread>
#include <atomic>
#include "tip_engine/Globals.h"
#include "tip_engine/CustomRenderer/engine/World/World.h"
#include "tip_engine/CustomRenderer/engine/World/Camera.h"
#include "tip_engine/CustomRenderer/engine/Components/Meshes/DynamicMeshComponent.h"

REXCVAR_DEFINE_BOOL(lock_fps, false, "_Trouble in Paradise", "Lock to 30 FPS");
REXCVAR_DEFINE_BOOL(show_fps, false, "_Trouble in Paradise", "Show FPS Overlay");
REXCVAR_DEFINE_BOOL(DisableFur, false, "_Trouble in Paradise", "Disables Fur Rendering");

/*
REX_PPC_EXTERN_IMPORT(camMainGetPos_821F07E0);

float * camMainGetPos_821F07E0_Hook(float *result){
  if(REXCVAR_GET(Freecam)) {
    result[0] = to_byteswapped_float(static_cast<float>(REXCVAR_GET(Freecam_X)));
    result[1] = to_byteswapped_float(static_cast<float>(REXCVAR_GET(Freecam_Y)));
    result[2] = to_byteswapped_float(static_cast<float>(REXCVAR_GET(Freecam_Z)));

    //.data:82C34E98 Me_36.virtCam
    camVirt_s* virtCam = reinterpret_cast<camVirt_s*>(0x100000000ull + 0x82C34E98);
    virtCam->pos.x = result[0];
    virtCam->pos.y = result[1];
    virtCam->pos.z = result[2];

    camMainWorkspace_s* workspace = reinterpret_cast<camMainWorkspace_s*>(0x100000000ull + 0x82C34D48);

    if(REXCVAR_GET(Custom_Viewport)) {
      workspace->FullScreenViewport.X = std::byteswap(static_cast<uint32_t>(REXCVAR_GET(Viewport_X)));
      workspace->FullScreenViewport.Y = std::byteswap(static_cast<uint32_t>(REXCVAR_GET(Viewport_Y)));
      workspace->FullScreenViewport.Width = std::byteswap(static_cast<uint32_t>(REXCVAR_GET(Viewport_Width)));
      workspace->FullScreenViewport.Height = std::byteswap(static_cast<uint32_t>(REXCVAR_GET(Viewport_Height)));
      workspace->outputViewportIsDirty = 1;
    }

    //DebugLogInt32("CamPtr", uint32_t(workspace->virtCam));
    //camVirt_s* virtCam1 = reinterpret_cast<camVirt_s*>(0x100000000ull + workspace->virtCam);
    //DebugLogFloat("CamPosX", to_byteswapped_float(virtCam1->pos.x));
    //DebugLogFloat("CamPosY", to_byteswapped_float(virtCam1->pos.y));
    //DebugLogFloat("CamPosZ", to_byteswapped_float(virtCam1->pos.z));


    return result;
  }else{
    //.data:82C34E98 Me_36.virtCam
    //camVirt_s* virtCam = reinterpret_cast<camVirt_s*>(0x100000000ull + 0x82C34E98);
    // *(float *)(virtCam + 8) = result[0];
    // *(float *)(virtCam + 12) = result[1];
    // *(float *)(virtCam + 16) = result[2];
    return rex ::GuestToHostFunction<float *>(__imp__rex_camMainGetPos_821F07E0, result);
  }
  return rex ::GuestToHostFunction<float *>(__imp__rex_camMainGetPos_821F07E0, result);
}
REX_PPC_HOOK(camMainGetPos_821F07E0);
*/


#include <rex/input/input_system.h>
#include <rex/ui/virtual_key.h>
#include "Globals.h"

using rex::ui::VirtualKey;

bool processEvents()
{
  /*
  if (!g_raw_input) return false;

    float deltaX = 0, deltaY = 0;
    auto [dx, dy] = g_raw_input->GetMouseDelta();
    deltaX += dx;
    deltaY += dy;

    DebugLogFloat("MouseDeltaX", deltaX);
    DebugLogFloat("MouseDeltaY", deltaY);
    //Debug flt_8215C724
    float* flt_8215C724 = reinterpret_cast<float*>(0x100000000ull + 0x8215C724);
    DebugLogFloat("flt_8215C724", to_byteswapped_float(*flt_8215C724));

    */
    return true;
}

bool hasmouseinput = false;


static auto lastFrameTime = std::chrono::high_resolution_clock::now();
void CPU_fps_hook() {
  fpsManager.showFPS = REXCVAR_GET(show_fps);
  auto fpshook = fpsManager.GetCreateCounter("Tick");
  fpshook->Tick();
}

void GPU_fps_hook() {
  //auto fpshook = fpsManager.GetCreateCounter("GPU");
  //fpshook->Tick();

  scenegraphDrawStaticWorkspace_s* drawStaticWorkspace = reinterpret_cast<scenegraphDrawStaticWorkspace_s*>(0x100000000ull + 0x82BEBC78);
  videoParams_s* videoParams = reinterpret_cast<videoParams_s*>(0x100000000ull + 0x83A56158);
  if(REXCVAR_GET(DisableFur)) {
    for (int i = 0; i < 6; i++) {
      drawStaticWorkspace[i].isFurEnabled = 0;
      drawStaticWorkspace[i].isFurEnabledCount = 0;
    }
  } else {
    for (int i = 0; i < 6; i++) {
      drawStaticWorkspace[i].isFurEnabled = 1;
      drawStaticWorkspace[i].isFurEnabledCount = 1;
    }
  }

  if (!windowPtr || !g_world || !g_camera) return;

  auto currentTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<float> elapsed = currentTime - lastFrameTime;
  float deltaTime = elapsed.count();
  lastFrameTime = currentTime;

  glfwPollEvents();
  if(glfwWindowShouldClose(windowPtr->getWindow())) {
    glfwMakeContextCurrent(nullptr);
    exit(0);
  }

  if (windowPtr->isOverlay() && g_mainWindowHandle) {
    windowPtr->SyncToOwnerWindow(g_mainWindowHandle);
  }

  static bool gladReloaded = false;
  glfwMakeContextCurrent(windowPtr->getWindow());
  if (!gladReloaded) {
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glEnable(GL_DEPTH_TEST);
    gladReloaded = true;
  }

  int fbWidth, fbHeight;
  glfwGetFramebufferSize(windowPtr->getWindow(), &fbWidth, &fbHeight);
  if (fbWidth <= 0 || fbHeight <= 0) {
    glfwMakeContextCurrent(nullptr);
    return;
  }
  g_camera->width = static_cast<float>(fbWidth);
  g_camera->height = static_cast<float>(fbHeight);

  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glViewport(0, 0, fbWidth, fbHeight);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  g_camera->Inputs(windowPtr->getWindow());
  g_camera->updateMatrix(45.0f, 0.01f, 100000.0f);

  {
    camMainWorkspace_s* camWorkspace = reinterpret_cast<camMainWorkspace_s*>(0x100000000ull + 0x82C34D48);

    glm::mat4 gameView(1.0f);
    glm::mat4 gameProj(1.0f);
    glm::mat4 gameBasis(1.0f);
    for (int row = 0; row < 4; row++) {
      for (int col = 0; col < 4; col++) {
        gameView[row][col] = to_byteswapped_float(drawStaticWorkspace[0].view[row][col]);
        gameProj[row][col] = to_byteswapped_float(drawStaticWorkspace[0].projection[row][col]);
        gameBasis[row][col] = to_byteswapped_float(drawStaticWorkspace[0].basis[row][col]);
      }
    }

    g_camera->Position.x = to_byteswapped_float(camWorkspace->visCamToWorldMtx[3][0]);
    g_camera->Position.y = to_byteswapped_float(camWorkspace->visCamToWorldMtx[3][1]);
    g_camera->Position.z = to_byteswapped_float(camWorkspace->visCamToWorldMtx[3][2]);

    DebugLogFloat("CameraPosX", g_camera->Position.x);
    DebugLogFloat("CameraPosY", g_camera->Position.y);
    DebugLogFloat("CameraPosZ", g_camera->Position.z);

    g_camera->cameraMatrix = gameProj * gameView;
  }

  g_world->TickWorld(deltaTime);
  g_world->Render(windowPtr.get(), g_camera.get());


  windowPtr->EndFrame();

  glfwMakeContextCurrent(nullptr);
}

void vsync_hook(PPCRegister& r10) {
  if(!REXCVAR_GET(lock_fps)) {
    r10.u32 = 0; // Force vsync off
    //REXCVAR_SET(vsync, false);
  }else{
    REXCVAR_SET(vsync, true);
  }
  //d3d12_submit_on_primary_buffer_end
  //REXCVAR_SET(d3d12_submit_on_primary_buffer_end, false);
  //REXCVAR_SET(scribble_heap, true);
  
}

inline bool VSyncBefore;
inline bool lockFPSBefore;
inline bool InRomanceMinigame = false;

void InRomanceMinigame_hook(){
  if(!InRomanceMinigame) {
    VSyncBefore = REXCVAR_GET(vsync);
    lockFPSBefore = REXCVAR_GET(lock_fps);
  }
  InRomanceMinigame = true;
  REXCVAR_SET(vsync, true);
  REXCVAR_SET(lock_fps, true);
}

void NotInRomanceMinigame_hook(){
  REXCVAR_SET(vsync, VSyncBefore);
  REXCVAR_SET(lock_fps, lockFPSBefore);
  InRomanceMinigame = false;
}

void NotPlacingBuilding_hook(){
  g_IsPlacingBuilding = false;
}

void PlacingBuilding_hook(){
  g_IsPlacingBuilding = true;
}

void SpawnCapture_hook(
    PPCRegister& r3, PPCRegister& r4, PPCRegister& r5, PPCRegister& r6,
    PPCRegister& r7, PPCRegister& r8, PPCRegister& r9, PPCRegister& r10)
{
  scene = r3.u32;
}

// ============================================================
// Spawn System — gardenMainGetGardenScene hook
// ============================================================
// gardenMainGetGardenScene (0x824E1120) fires every frame on the PPC thread.
// After calling the original, ctx.r3 = garden scene pointer.
// We use this to process queued spawn requests from the UI thread.
//
// sub_82575C30: supportPinataCreateGeneralEx
//   Calls meCreatePinataAvatar (sub_82575E50) which dispatches by tag type,
//   then calls meCreateAvatar (sub_825758D8) for piñatas.
//
// Register layout for sub_82575C30:
//   r3  = scene (sceneMainWorkspace_s*)
//   r4  = pos   (const mlVec* — guest pointer to float[3], 0 = origin)
//   r5  = rot   (const mlRot_s* — guest pointer to float[3], 0 = zero rotation)
//   r7  = tag   (supportPinataTag_e — the species/item ID to spawn)
//   r9  = owner (pinatajuice_Owner_e — 0 = Garden)
//   r10 = wildcard (stored at entity+468 via meCreateAvatar)
//   f1  = scale (double — game scale, 1.0 = normal)
//   f2  = age   (double — piñata age, 0.0 = baby/egg, 1.0 = adult)
//
// Returns spawned entity pointer in r3 (0 = failed).
//
// NOTE: sub_82575AB8 (supportPinataCreateGeneral) does NOT forward r9/r10
// to the downstream functions — it always passes 0 for wildcard and owner.
// Use sub_82575C30 instead for wildcard support.
// ============================================================

// Original gardenMainGetGardenScene — we call through to it first
PPC_EXTERN_IMPORT(__imp__rex_gardenMainGetGardenScene_824E1120);

// rex_spawn_supportPinataCreateGeneralEx_82575C30: creation function with wildcard support
// This is the recompiled original (hooked name from retip_hooked.toml).
PPC_EXTERN_FUNC(rex_spawn_supportPinataCreateGeneralEx_82575C30);

// Hook: override gardenMainGetGardenScene, call original, then process spawn queue
PPC_EXTERN_FUNC(rex_gardenMainGetGardenScene_824E1120) {
    // Call the original implementation — after this, ctx.r3 = garden scene ptr
    __imp__rex_gardenMainGetGardenScene_824E1120(ctx, base);

    // Process pending spawn request (queued from SpawnMenu UI)
    if (!g_SpawnRequest.pending) return;

    uint32_t gardenScene = ctx.r3.u32;
    if (gardenScene == 0) return; // Not in a garden, can't spawn

    uint32_t tagID = g_SpawnRequest.tagID;
    float spawnScale = g_SpawnRequest.scale;
    int wildcard = g_SpawnRequest.wildcard;
    g_SpawnRequest.pending = false;

    PPCContext saveCtx = ctx;

    // Set up registers for supportPinataCreateGeneralEx (0x82575C30)
    //ctx.r3.u64 = gardenScene;
    ctx.r4.u64 = 0;             // pos = null (spawn at origin)
    ctx.r5.u64 = 0;             // rot = null (zero rotation)
    ctx.r7.u64 = tagID;         // species tag
    ctx.r9.u64 = 0;             // owner = Garden (0)
    //ctx.r10.u64 = wildcard;     // wildcard trait → entity+468
    ctx.f1.f64 = (double)spawnScale;
    ctx.f2.f64 = 1.0;           // age (0 = baby/egg)

    rex_spawn_supportPinataCreateGeneralEx_82575C30(ctx, base);

    g_LastSpawnedEntity = ctx.r3.u32;

    ctx = saveCtx;
}