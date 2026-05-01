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
#include "tip_engine/DiscordRPC.h"

#include "rex_macros.h"
#include <fstream>
#include <mutex>
#include <filesystem>
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
REXCVAR_DEFINE_BOOL(DiscordActivity, false, "_Trouble in Paradise", "Discord Activity");

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
  Log(LogLevel::Info, "CPU Hook Hit");
  fpsManager.showFPS = REXCVAR_GET(show_fps);
  auto fpshook = fpsManager.GetCreateCounter("Tick");
  fpshook->Tick();
  Log(LogLevel::Info, "CPU Hook Finished");
}

void GPU_fps_hook() {
  //auto fpshook = fpsManager.GetCreateCounter("GPU");
  //fpshook->Tick();
  Log(LogLevel::Info, "GPU Hook Hit");

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
  Log(LogLevel::Info, "GPU Hook Finished");
/*
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

    g_camera->cameraMatrix = gameProj * gameView;
  }

  g_world->TickWorld(deltaTime);
  g_world->Render(windowPtr.get(), g_camera.get());


  windowPtr->EndFrame();

  glfwMakeContextCurrent(nullptr);
  */
}

void vsync_hook(PPCRegister& r10) {
  Log(LogLevel::Info, "VSync Hook Hit");
  if(!REXCVAR_GET(lock_fps)) {
    r10.u32 = 0; // Force vsync off
    //REXCVAR_SET(vsync, false);
  }else{
    REXCVAR_SET(vsync, true);
  }
  Log(LogLevel::Info, "VSync Hook Finished");
  //d3d12_submit_on_primary_buffer_end
  //REXCVAR_SET(d3d12_submit_on_primary_buffer_end, false);
  //REXCVAR_SET(scribble_heap, true);
  
}

inline bool VSyncBefore;
inline bool lockFPSBefore;
inline bool InRomanceMinigame = false;

void InRomanceMinigame_hook(){
  Log(LogLevel::Info, "In Romance Minigame Hook Hit");
  if(!InRomanceMinigame) {
    VSyncBefore = REXCVAR_GET(vsync);
    lockFPSBefore = REXCVAR_GET(lock_fps);
  }
  InRomanceMinigame = true;
  REXCVAR_SET(vsync, true);
  REXCVAR_SET(lock_fps, true);
  Log(LogLevel::Info, "In Romance Minigame Hook Finished");
}

void NotInRomanceMinigame_hook(){
  Log(LogLevel::Info, "Not In Romance Minigame Hook Hit");
  REXCVAR_SET(vsync, VSyncBefore);
  REXCVAR_SET(lock_fps, lockFPSBefore);
  InRomanceMinigame = false;
  Log(LogLevel::Info, "Not In Romance Minigame Hook Finished");
}

void NotPlacingBuilding_hook(){
  Log(LogLevel::Info, "Not Placing Building Hook Hit");
  g_IsPlacingBuilding = false;
  Log(LogLevel::Info, "Not Placing Building Hook Finished");
}

void PlacingBuilding_hook(){
  Log(LogLevel::Info, "Placing Building Hook Hit");
  g_IsPlacingBuilding = true;
  Log(LogLevel::Info, "Placing Building Hook Finished");
}

char sceneNameBuffer[126];

PPC_EXTERN_IMPORT(__imp__rex_gardenMainGetGardenScene_824E1120);
PPC_EXTERN_FUNC(rex_spawn_supportPinataCreateGeneralEx_82575C30);
PPC_EXTERN_FUNC(rex_gardenMainGetGardenScene_824E1120) {
  Log(LogLevel::Info, "Get Garden Scene Hook Hit");
    __imp__rex_gardenMainGetGardenScene_824E1120(ctx, base);

    uint32_t gardenScene = ctx.r3.u32;
    if (gardenScene <= 0) return;
    scene = gardenScene;
    
    Log(LogLevel::Info, std::string("Current Scene: ") + sceneNameBuffer);

    if(REXCVAR_GET(DiscordActivity)){
      Log(LogLevel::Info, "Updating Discord Activity");
      char* sceneNamePtr = reinterpret_cast<char*>(0x100000000ull + gardenScene);
      std::strncpy(sceneNameBuffer, sceneNamePtr, sizeof(sceneNameBuffer) - 1);
      sceneNameBuffer[sizeof(sceneNameBuffer) - 1] = '\0';

      std::string ActualSceneName;
      std::string_view sceneNameView(sceneNameBuffer);
      if(sceneNameView.find("aid_script_pinata_game_newfrontend_garden") != std::string_view::npos) {
        ActualSceneName = "Main Menu";
      }else if(sceneNameView.find("aid_script_pinata_game_garden_blank") != std::string_view::npos) {
        ActualSceneName = "Garden";
      }else if(sceneNameView.find("aid_script_pinata_game_credits") != std::string_view::npos) {
        ActualSceneName = "Credits";
      }
      retip::discord_rpc::SetDetails(std::string("In ") + ActualSceneName);
      Log(LogLevel::Info, "Discord Activity Updated");
    }
    

    if (g_SpawnRequest.pending){
      Log(LogLevel::Info, "Processing pending spawn request");
      uint32_t tagID = g_SpawnRequest.tagID;
      float spawnScale = g_SpawnRequest.scale;
      int wildcard = g_SpawnRequest.wildcard;
      bool spawnWild = g_SpawnRequest.spawnWild;
      g_SpawnRequest.pending = false;

      PPCContext saveCtx = ctx;

      float* pos = reinterpret_cast<float*>(0x100000000ull + playerPos);

      float poss[3] = { pos[0], pos[1], pos[2] };

      ctx.r3.u64 = gardenScene;
      if(spawnWild) {
          ctx.r4.u64 = reinterpret_cast<uint64_t>(pos);
      } else {
          ctx.r4.u64 = 0; //a2
      }
      ctx.r5.u64 = 0; //a3
      ctx.r7.u64 = tagID; //a5
      ctx.r9.u64 = 0; //a7
      ctx.r10.u64 = 0; //a8
      ctx.f1.f64 = (double)spawnScale; //a9
      ctx.f2.f64 = 1.0; //a2 (Age) 1 = adult, 0 = baby (Babies still use spawnScale)

      rex_spawn_supportPinataCreateGeneralEx_82575C30(ctx, base);
      
      g_LastSpawnedEntity = ctx.r3.u32;

      ctx = saveCtx;
      Log(LogLevel::Info, "Pending spawn request processed");
    }
    Log(LogLevel::Info, "Get Garden Scene Hook Finished");

}


#ifdef DEBUG_BUILD
REX_PPC_EXTERN_IMPORT(entityBodyPinataAnimalSetIsWildcard_82383538);
int entityBodyPinataAnimalSetIsWildcard_82383538_Hook(int a1, int a2) {
    return rex::GuestToHostFunction<int>(__imp__rex_entityBodyPinataAnimalSetIsWildcard_82383538, a1, a2);
};
REX_PPC_HOOK(entityBodyPinataAnimalSetIsWildcard_82383538);


//int __fastcall rex_spawn_egg_82334638(int a1, int a2, int a3)
REX_PPC_EXTERN_IMPORT(spawn_egg_82334638);
int spawn_egg_82334638_Hook(int a1, int a2, int a3) {

  //*(_DWORD *)(a1 + 4840) IsWildcard
  //*(_DWORD *)(a1 + 4844) IsWildcardID
  //int* isWildcardPtr = reinterpret_cast<int*>(0x100000000ull + a1 + 4840);
  //isWildcardPtr[0] = std::byteswap(1); // Force wildcard
  //isWildcardPtr[1] = std::byteswap(1); // Force wildcard ID

  int result = rex::GuestToHostFunction<int>(__imp__rex_spawn_egg_82334638, a1, a2, a3);

  return result;
};
REX_PPC_HOOK(spawn_egg_82334638);
#endif


