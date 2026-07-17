#include "tip_engine/hooks.h"

#include <cstdint>
#include <cmath>
#include <cstring>
#include <chrono>
#include <rex/ui/imgui_dialog.h>
#include "Log.h"
#include "Overlays/Fps.h"
#include "imgui.h"
#include <rex/cvar.h>
#include "tip_engine/rex_macros.h"
#include <rex/graphics/flags.h>
#include <rex/system/kernel_state.h>
#include "tip_engine/Log.h"
#include "Overlays/DebugInfo.h"
#include "rex_macros.h"
#include <fstream>
#include <mutex>
#include <filesystem>
#include <unordered_map>
#include "tip_engine/Types/CommonTypes.h"
#include <SDL3/SDL.h>
#include <thread>
#include <atomic>
#include <winnt.h>
#include "tip_engine/Globals.h"
#include <rex/input/input_system.h>
#include <rex/ui/virtual_key.h>
#include "Globals.h"
#include "../../generated/default/retip_globals.h"
#include <rex/discord_rpc.h>
#include <rex/ppc/guest_global.h>

REXCVAR_DEFINE_BOOL(lock_fps, false, "TiP/Fps", "Lock to 30 FPS");
REXCVAR_DEFINE_BOOL(show_fps, false, "TiP/Fps", "Show FPS Overlay");
//REXCVAR_DEFINE_BOOL(DisableFur, false, "TiP/Graphics", "Disables Fur Rendering");
REXCVAR_DEFINE_BOOL(DiscordActivity, true, "TiP/Discord", "Enable Discord Activity");
REXCVAR_DEFINE_BOOL(ShowStartupOverlay, true, "TiP", "Show Startup Overlay");
REXCVAR_DEFINE_BOOL(FramebufferClear, false, "TiP", "Disables the FramebufferClear logic");

static auto lastFrameTime = std::chrono::high_resolution_clock::now();
void CPU_fps_hook() {
  fpsManager.showFPS = REXCVAR_GET(show_fps);
  auto fpshook = fpsManager.GetCreateCounter("Tick");
  //retip::globals::g_disableFramebufferClear = (int)REXCVAR_GET(FramebufferClear);
  int* Clear = reinterpret_cast<int*>(0x100000000ull + 0x83D26F68);
  *Clear = 1;
  fpshook->Tick();
}

void GPU_fps_hook() {
/*
  scenegraphDrawStaticWorkspace_s* drawStaticWorkspace = reinterpret_cast<scenegraphDrawStaticWorkspace_s*>(0x100000000ull + 0x82BEBC78);
  //videoParams_s* videoParams = reinterpret_cast<videoParams_s*>(0x100000000ull + 0x83A56158);
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
*/
}

void vsync_hook(PPCRegister& r10) {
  if(!REXCVAR_GET(lock_fps)) {
    r10.u32 = 0;
  }else{
    rex::cvar::SetFlagByName("vsync", "true");
  }
}

inline bool VSyncBefore;
inline bool lockFPSBefore;
inline bool SavedRomanceVideoState = false;

void InRomanceMinigame_hook(){
  if(!g_InRomanceMinigame) {
    VSyncBefore = rex::cvar::Query<bool>("vsync");
    lockFPSBefore = REXCVAR_GET(lock_fps);
    SavedRomanceVideoState = true;
  }
  SetRetipRomanceMinigame(true);
  rex::cvar::SetFlagByName("vsync", "true");
  REXCVAR_SET(lock_fps, true);
}

void NotInRomanceMinigame_hook(){
  if(g_InRomanceMinigame && SavedRomanceVideoState) {
    rex::cvar::SetFlagByName("vsync", VSyncBefore ? "true" : "false");
    REXCVAR_SET(lock_fps, lockFPSBefore);
  }
  SavedRomanceVideoState = false;
  SetRetipRomanceMinigame(false);
}

void NotPlacingBuilding_hook(){
  g_IsPlacingBuilding = false;
}

void PlacingBuilding_hook(){
  g_IsPlacingBuilding = true;
}

char sceneNameBuffer[126];

REX_EXTERN(__imp__rex_gardenMainGetGardenScene_824E1120);
REX_EXTERN(rex_spawn_supportPinataCreateGeneralEx_82575C30);
REX_HOOK_RAW(rex_gardenMainGetGardenScene_824E1120) {
    __imp__rex_gardenMainGetGardenScene_824E1120(ctx, base);

    uint32_t gardenScene = ctx.r3.u32;
    if (gardenScene <= 0) return;
    scene = gardenScene;

    if(REXCVAR_GET(DiscordActivity)){
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
      rex::discord_rpc::SetDetails(std::string("In ") + ActualSceneName);
    }

    if (g_SpawnRequest.pending){
      uint32_t tagID = g_SpawnRequest.tagID;
      float spawnScale = g_SpawnRequest.scale;
      int wildcard = g_SpawnRequest.wildcard;
      bool spawnWild = g_SpawnRequest.spawnWild;
      g_SpawnRequest.pending = false;

      PPCContext saveCtx = ctx;

      float* pos = reinterpret_cast<float*>(0x100000000ull + playerPos);
      float poss[3] = {pos[0], pos[1], pos[2]};

      ctx.r3.u64 = gardenScene;
      if(spawnWild) {
          pos[0] = to_byteswapped_float(0.0);
          pos[1] = to_byteswapped_float(0.0);
          pos[2] = to_byteswapped_float(260.0);
          ctx.r4.u64 = reinterpret_cast<uint64_t>(pos);
          //ctx.r4.u64 = playerPos;
          ctx.r5.u64 = playerRot;
      } else {
          ctx.r4.u64 = playerPos;
          ctx.r5.u64 = playerRot;
      }
      ctx.r7.u64 = tagID; //a5
      ctx.r9.u64 = 0; //a7
      ctx.r10.u64 = 0; //a8
      ctx.f1.f64 = (double)spawnScale; //a9
      ctx.f2.f64 = 1.0; //a2 (Age) 1 = adult, 0 = baby (Babies still use spawnScale)

      rex_spawn_supportPinataCreateGeneralEx_82575C30(ctx, base);

      g_LastSpawnedEntity = ctx.r3.u32;

      ctx = saveCtx;
      pos[0] = poss[0];
      pos[1] = poss[1];
      pos[2] = poss[2];
    }
    Log(LogLevel::Info, "Get Garden Scene Hook Finished");

}

//REXCVAR_DEFINE_BOOL(IgnoreAllRequirements, false, "TiP", "Ignore all requirements (for testing and fun)");
/*
REX_EXTERN(__imp__rex_requirementsMet_82537810);
REX_HOOK_RAW(rex_requirementsMet_82537810) {
    if(REXCVAR_GET(IgnoreAllRequirements)) {
        ctx.r3.s32 = 1;
        return;
    }
    __imp__rex_requirementsMet_82537810(ctx, base);
};
*/

