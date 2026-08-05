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

REXCVAR_DEFINE_BOOL(UseCustomLighting, false, "TiP/Lighting", "");
REXCVAR_DEFINE_INT32(directionalColor, 0x00000000, "TiP/Lighting", "").color();
REXCVAR_DEFINE_INT32(ambientColor, 0xFFFFFFFF, "TiP/Lighting", "").color();
REXCVAR_DEFINE_INT32(ambientModelColor, 0xFFFFFFFF, "TiP/Lighting", "").color();
REXCVAR_DEFINE_INT32(fogColor, 0, "TiP/Lighting", "").color();
REXCVAR_DEFINE_INT32(fogOpacity, 0, "TiP/Lighting", "");
REXCVAR_DEFINE_INT32(blueShiftScalar, 0, "TiP/Lighting", "");
REXCVAR_DEFINE_BOOL(cubeFogEnabled, 0, "TiP/Lighting", "");
REXCVAR_DEFINE_DOUBLE(fogNearDist, 0.0, "TiP/Lighting", "");
REXCVAR_DEFINE_DOUBLE(fogFarDist, 0.0, "TiP/Lighting", "");

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
  if(REXCVAR_GET(UseCustomLighting)){
    lightMainWorkspace_s* workspace = reinterpret_cast<lightMainWorkspace_s*>(0x100000000ull + 0x82C3C010);
    workspace->dirLight.col = {
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(directionalColor) >> 24) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(directionalColor) >> 16) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(directionalColor) >> 8) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(directionalColor)) & 0xFF) / 255.0f)
    };
    workspace->ambientCol = {
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(ambientColor) >> 24) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(ambientColor) >> 16) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(ambientColor) >> 8) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(ambientColor)) & 0xFF) / 255.0f)
    };
    workspace->modelAmbientCol = {
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(ambientModelColor) >> 24) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(ambientModelColor) >> 16) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(ambientModelColor) >> 8) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(ambientModelColor)) & 0xFF) / 255.0f)
    };

    workspace->fogCol = {
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(fogColor) >> 24) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(fogColor) >> 16) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(fogColor) >> 8) & 0xFF) / 255.0f),
        to_byteswapped_float(static_cast<float>((REXCVAR_GET(fogColor)) & 0xFF) / 255.0f)
    };
    workspace->fogOpacity = to_byteswapped_float(static_cast<float>(REXCVAR_GET(fogOpacity)));
    workspace->blueShiftScalar = to_byteswapped_float(static_cast<float>(REXCVAR_GET(blueShiftScalar)));
    workspace->cubeFogEnabled = REXCVAR_GET(cubeFogEnabled) ? 1 : 0;
    workspace->fogFarDist = to_byteswapped_float(static_cast<float>((REXCVAR_GET(fogFarDist))));
    workspace->fogNearDist = to_byteswapped_float(static_cast<float>((REXCVAR_GET(fogNearDist))));
  }
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
/* 347 */

/* 18 */
struct __declspec(align(2)) videoParams_s
{
  int resolutionType;
  unsigned int width;
  unsigned int height;
  unsigned char progressiveScan;
  unsigned int pbSize;
  unsigned int pbKickOff;
  unsigned int backBufferCount;
  unsigned char presentInterval;
  unsigned char presentImmediately;
  unsigned char enableAutoDepthStencil;
  unsigned char wideScreen;
  unsigned char pixelAspect10x11;
  unsigned char antiAliasType;
  unsigned char refreshRateHZ;
};

REXCVAR_DEFINE_INT32(tip_backbuffer_width, 0, "TiP/Resolution", "Override the guest backbuffer width (0 = default)").lifecycle(rex::cvar::Lifecycle::kRequiresRestart);
REXCVAR_DEFINE_INT32(tip_backbuffer_height, 0, "TiP/Resolution", "Override the guest backbuffer height (0 = default)").lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

//meCreatePresentParams_8229BF20
REX_EXTERN(__imp__sub_8229BF20);
REX_HOOK_RAW(sub_8229BF20) {
    uint32_t presentParamsAddr = ctx.r4.u32;
    __imp__sub_8229BF20(ctx, base);
    int32_t width = REXCVAR_GET(tip_backbuffer_width);
    int32_t height = REXCVAR_GET(tip_backbuffer_height);
    if (width <= 0 || height <= 0 || !presentParamsAddr) return;
    uint32_t* backBufferWidth = reinterpret_cast<uint32_t*>(0x100000000ull + presentParamsAddr);
    uint32_t* backBufferHeight = reinterpret_cast<uint32_t*>(0x100000000ull + presentParamsAddr + 4);
    *backBufferWidth = std::byteswap(static_cast<uint32_t>(width));
    *backBufferHeight = std::byteswap(static_cast<uint32_t>(height));
};

//meVideoInit_8229BA80
REX_EXTERN(__imp__sub_8229BA80);
REX_HOOK_RAW(sub_8229BA80) {
    int32_t width = REXCVAR_GET(tip_backbuffer_width);
    int32_t height = REXCVAR_GET(tip_backbuffer_height);
    if (width > 0 && height > 0) {
        videoParams_s* videoParams = reinterpret_cast<videoParams_s*>(0x100000000ull + ctx.r3.u32);
        videoParams->width = std::byteswap(static_cast<unsigned int>(width));
        videoParams->height = std::byteswap(static_cast<unsigned int>(height));
    }
    __imp__sub_8229BA80(ctx, base);
};

//rex_camMainReset_821F0570
REX_EXTERN(__imp__sub_821F0570);
REX_HOOK_RAW(sub_821F0570) {
    __imp__sub_821F0570(ctx, base);
    int32_t width = REXCVAR_GET(tip_backbuffer_width);
    int32_t height = REXCVAR_GET(tip_backbuffer_height);
    if (width <= 0 || height <= 0) return;
    camMainWorkspace_s* me_36 = reinterpret_cast<camMainWorkspace_s*>(0x100000000ull + 0x82C34D48);
    me_36->viewport.w = std::byteswap(width);
    me_36->viewport.h = std::byteswap(height);
    me_36->outputViewport.w = std::byteswap(width);
    me_36->outputViewport.h = std::byteswap(height);

    videoParams_s* videoParams = reinterpret_cast<videoParams_s*>(0x100000000ull + 0x83A56158);
    videoParams->width = std::byteswap(width);
    videoParams->height = std::byteswap(height);
};

REX_EXTERN(__imp__sub_8229AF50);
REX_HOOK_RAW(sub_8229AF50) {
    __imp__sub_8229AF50(ctx, base);
    int32_t width = REXCVAR_GET(tip_backbuffer_width);
    int32_t height = REXCVAR_GET(tip_backbuffer_height);
    if (width <= 0 || height <= 0) return;
    camMainWorkspace_s* me_36 = reinterpret_cast<camMainWorkspace_s*>(0x100000000ull + 0x82C34D48);
    me_36->viewport.w = std::byteswap(width);
    me_36->viewport.h = std::byteswap(height);
    me_36->outputViewport.w = std::byteswap(width);
    me_36->outputViewport.h = std::byteswap(height);

    videoParams_s* videoParams = reinterpret_cast<videoParams_s*>(0x100000000ull + 0x83A56158);
    videoParams->width = std::byteswap(width);
    videoParams->height = std::byteswap(height);
};

bool skip_cutscenes_hook(){
  return true;
}

void time_hook(PPCRegister& r3) {
}

void time_hook2(PPCRegister& r3) {
}