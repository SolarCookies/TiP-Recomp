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
#include "tip_engine/Types/CommonTypes.h"
#include <SDL3/SDL.h>
#include <thread>
#include <atomic>
#include "tip_engine/Globals.h"

REXCVAR_DEFINE_BOOL(DisableMainDraw, false, "TiP/Graphics", "Disables the Main Draw Pass");
REXCVAR_DEFINE_BOOL(DisableUIDraw, false, "TiP/Graphics", "Disables the UI Draw Pass");
REXCVAR_DEFINE_BOOL(UseAspectRatioFromConfig, false, "TiP/Graphics", "Use Aspect Ratio from config");
REXCVAR_DEFINE_DOUBLE(AspectRatio, 1.7777778f, "TiP/Graphics", "Aspect Ratio");
REXCVAR_DEFINE_BOOL(SkipIntros, false, "TiP/Graphics", "Skip Intro Videos");

REX_PPC_EXTERN_IMPORT(supportFrustumConstructClippingFrustum_8228BE08);
void supportFrustumConstructClippingFrustum_8228BE08_Hook(double a1,double a2,double a3,double a4,int a5,int a6,int a7,int a8,float *a9,float *a10) {
    float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    if(REXCVAR_GET(UseAspectRatioFromConfig)) {
      a2 = customAR;
    }
    GuestToHostFunction<void>(__imp__rex_supportFrustumConstructClippingFrustum_8228BE08, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
REX_PPC_HOOK(supportFrustumConstructClippingFrustum_8228BE08);

REX_PPC_EXTERN_IMPORT(camMainPostDrawLetterbox_821F0910);
int camMainPostDrawLetterbox_821F0910_Hook(){
  return 1;
}
REX_PPC_HOOK(camMainPostDrawLetterbox_821F0910);

REX_PPC_EXTERN_IMPORT(mlMtxPerspective_82247408);
void mlMtxPerspective_82247408_Hook(float* outMtx, float fov, float aspectRatio, float nearZ, float farZ) {
    float customAR = aspectRatio;
    if(REXCVAR_GET(UseAspectRatioFromConfig)) {
      customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    }
    GuestToHostFunction<void>(__imp__rex_mlMtxPerspective_82247408, outMtx, fov, customAR, nearZ, farZ);
}
REX_PPC_HOOK(mlMtxPerspective_82247408);

REX_PPC_EXTERN_IMPORT(meUpdateOutputViewport_821F0F30);
int meUpdateOutputViewport_821F0F30_Hook() {
    int result = GuestToHostFunction<int>(__imp__rex_meUpdateOutputViewport_821F0F30);
    if(REXCVAR_GET(UseAspectRatioFromConfig)) {
        float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
        float* aspectRatioPtr = reinterpret_cast<float*>(0x100000000ull + 0x82C34F00);
        *aspectRatioPtr = to_byteswapped_float(customAR);
    }
    return result;
}
REX_PPC_HOOK(meUpdateOutputViewport_821F0F30);

void AspectRatio_hook(PPCRegister& r3) {
  if(REXCVAR_GET(UseAspectRatioFromConfig)) {
    float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    if(r3.u32){
      float* aspectRatioPtr = reinterpret_cast<float*>(0x100000000ull + r3.u32 + 0x399C);
      *aspectRatioPtr = to_byteswapped_float(customAR);
    }
  }
}

bool SkipIntroVideos_hook() {
  return REXCVAR_GET(SkipIntros);
}

bool SkipIntroVideosTwo_hook() {
  return REXCVAR_GET(SkipIntros);
}

// Ingame camera is open
void one_hook(){
#ifndef __linux__
  rex::cvar::SetFlagByName("d3d12_readback_resolve", "true");
#endif
}

// Ingame camera is not open
void two_hook(){
#ifndef __linux__
  rex::cvar::SetFlagByName("d3d12_readback_resolve", "false");
#endif
}

bool skipFirstDraw_hook(){
  return REXCVAR_GET(DisableMainDraw);
}

bool skipSecondDraw_hook(){
  return REXCVAR_GET(DisableUIDraw);
}

//Kept here for debug
bool skiplighting_hook() {
  return false;
}

//Kept here for debug
bool skiplightingTwo_hook() {
  return false;
}
/*
bool SkipIntroVideos_hook() {
  //return REXCVAR_GET(SkipIntros);
  return false;
}

bool SkipIntroVideosTwo_hook() {
  //return REXCVAR_GET(SkipIntros);
  return false;
}
*/