#include "tip_engine/hooks.h"

#include <cstdint>
#include <cmath>
#include <cstring>
#include <rex/ui/imgui_dialog.h>
#include "Overlays/Fps.h"
#include "imgui.h"

#include <rex/cvar.h>
#include "tip_engine/rex_macros.h"
#include <rex/graphics/flags.h>
#include <rex/ppc/types.h>
#include <rex/system/kernel_state.h>
#include "tip_engine/Log.h"
#include "tip_engine/D3DTypes.h"
#include "Overlays/DebugInfo.h"

#include "rex_macros.h"
#include <fstream>
#include "tip_engine/Types/CommonTypes.h"

inline float to_byteswapped_float(float f) {
    uint32_t i = std::byteswap(*reinterpret_cast<uint32_t*>(&f));
    return *reinterpret_cast<float*>(&i);
}

inline double to_byteswapped_double(double d) {
    uint64_t i = std::byteswap(*reinterpret_cast<uint64_t*>(&d));
    return *reinterpret_cast<double*>(&i);
}

REXCVAR_DEFINE_BOOL(show_fps_overlay, false, "_Trouble in Paradise", "Show FPS overlay");
REXCVAR_DEFINE_BOOL(rgb_cursor, false, "_Trouble in Paradise", "Enables the Gursor");
REXCVAR_DEFINE_BOOL(lock_fps, false, "_Trouble in Paradise", "Lock to 30 FPS");
REXCVAR_DEFINE_BOOL(show_fps, false, "_Trouble in Paradise", "Show FPS Overlay");
REXCVAR_DEFINE_BOOL(DisableMainDraw, false, "_Trouble in Paradise", "Disables the Main Draw Pass");
REXCVAR_DEFINE_BOOL(DisableUIDraw, false, "_Trouble in Paradise", "Disables the UI Draw Pass");

REXCVAR_DEFINE_BOOL(UseAspectRatioFromConfig, false, "_Trouble in Paradise", "Use Aspect Ratio from config");
REXCVAR_DEFINE_DOUBLE(AspectRatio, 1.7777778f, "_Trouble in Paradise", "Aspect Ratio");

REXCVAR_DEFINE_BOOL(SkipIntros, false, "_Trouble in Paradise", "Skip Intro Videos");

//REXCVAR_DEFINE_BOOL(Freecam, false, "_Trouble in Paradise", "Enables the Freecam");
//REXCVAR_DEFINE_DOUBLE(Freecam_X, 0.0f, "_Trouble in Paradise", "Freecam X Position");
//REXCVAR_DEFINE_DOUBLE(Freecam_Y, 0.0f, "_Trouble in Paradise", "Freecam Y Position");
//REXCVAR_DEFINE_DOUBLE(Freecam_Z, 0.0f, "_Trouble in Paradise", "Freecam Z Position");

//REXCVAR_DEFINE_BOOL(Custom_Viewport, false, "_Trouble in Paradise", "Use custom viewport");
//REXCVAR_DEFINE_INT32(Viewport_X, 0, "_Trouble in Paradise", "Custom viewport X");
//REXCVAR_DEFINE_INT32(Viewport_Y, 0, "_Trouble in Paradise", "Custom viewport Y");
//REXCVAR_DEFINE_INT32(Viewport_Width, 1920, "_Trouble in Paradise", "Custom viewport width");
//REXCVAR_DEFINE_INT32(Viewport_Height, 1080, "_Trouble in Paradise", "Custom viewport height");


//REXCVAR_DEFINE_COLOR(ambientColor, 0x000000FF, "_Trouble in Paradise", "Controls the ambient color of the scene");
//REXCVAR_DEFINE_COLOR(ambientModelColor, 0x000000FF, "_Trouble in Paradise", "Controls the ambient color of the models in the scene");
//REXCVAR_DEFINE_COLOR(directionalColor, 0xFFFFFFFF, "_Trouble in Paradise", "Controls the color of the directional light in the scene");
//REXCVAR_DEFINE_COLOR(fogColor, 0x000000FF, "_Trouble in Paradise", "Controls the color of the fog in the scene");
//REXCVAR_DEFINE_DOUBLE(fogOpacity, 1.0f, "_Trouble in Paradise", "Controls the opacity of the fog in the scene");
//REXCVAR_DEFINE_DOUBLE(blueShiftScalar, 0.0f, "_Trouble in Paradise", "Controls the intensity of the blue shift effect in the scene");
//REXCVAR_DEFINE_BOOL(cubeFogEnabled, false, "_Trouble in Paradise", "Enables cube fog in the scene");

//REXCVAR_DEFINE_INT32(maxCPU, 60, "_Trouble in Paradise", "Limits the cpu FPS to the specified value (0 for unlimited)");
//REXCVAR_DEFINE_INT32(maxGPU, 60, "_Trouble in Paradise", "Limits the gpu FPS to the specified value (0 for unlimited)");


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
    //*(float *)(virtCam + 8) = result[0];
    //*(float *)(virtCam + 12) = result[1];
    //*(float *)(virtCam + 16) = result[2];
    return rex ::GuestToHostFunction<float *>(__imp__rex_camMainGetPos_821F07E0, result);
  }
  return rex ::GuestToHostFunction<float *>(__imp__rex_camMainGetPos_821F07E0, result);
}
REX_PPC_HOOK(camMainGetPos_821F07E0);
*/

REX_PPC_EXTERN_IMPORT(camMainGetAspectRatio_821F0730);
float camMainGetAspectRatio_821F0730_Hook() {
  float aspectRatio;
  //if(REXCVAR_GET(UseAspectRatioFromConfig)) {
  //  aspectRatio = static_cast<float>(REXCVAR_GET(AspectRatio));
  //}else{
    aspectRatio = rex::GuestToHostFunction<float>(__imp__rex_camMainGetAspectRatio_821F0730);
  //}
  return aspectRatio;
} REX_PPC_HOOK(camMainGetAspectRatio_821F0730);

//supportFrustumConstructClippingFrustum_8228BE08
REX_PPC_EXTERN_IMPORT(supportFrustumConstructClippingFrustum_8228BE08);
void supportFrustumConstructClippingFrustum_8228BE08_Hook(double a1,double a2,double a3,double a4,int a5,int a6,int a7,int a8,float *a9,float *a10) {
    float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    if(REXCVAR_GET(UseAspectRatioFromConfig)) {
      a2 = customAR;
    }
    rex::GuestToHostFunction<void>(__imp__rex_supportFrustumConstructClippingFrustum_8228BE08, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
REX_PPC_HOOK(supportFrustumConstructClippingFrustum_8228BE08);


REX_PPC_EXTERN_IMPORT(camMainPostDrawLetterbox_821F0910);
int camMainPostDrawLetterbox_821F0910_Hook(){
  //float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
  //float* flt_821612EC = reinterpret_cast<float*>(0x100000000ull + 0x821612EC);
  //*flt_821612EC = 1.0f;
  return 1;
}
REX_PPC_HOOK(camMainPostDrawLetterbox_821F0910);

REX_PPC_EXTERN_IMPORT(mlMtxPerspective_82247408);
void mlMtxPerspective_82247408_Hook(float* outMtx, float fov, float aspectRatio, float nearZ, float farZ) {
    float customAR = aspectRatio;
    if(REXCVAR_GET(UseAspectRatioFromConfig)) {
      customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    }
    rex::GuestToHostFunction<void>(__imp__rex_mlMtxPerspective_82247408, outMtx, fov, customAR, nearZ, farZ);
}
REX_PPC_HOOK(mlMtxPerspective_82247408);


REX_PPC_EXTERN_IMPORT(meUpdateOutputViewport_821F0F30);
int meUpdateOutputViewport_821F0F30_Hook() {
    int result = rex::GuestToHostFunction<int>(__imp__rex_meUpdateOutputViewport_821F0F30);
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
    //r3.u32 + 0x399C | *(float *)&r3+0x399C = AspectRatio;
    float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    float* aspectRatioPtr = reinterpret_cast<float*>(0x100000000ull + r3.u32 + 0x399C);
    *aspectRatioPtr = to_byteswapped_float(customAR);
  }
}

void CPU_fps_hook() {
  fpsManager.showFPS = REXCVAR_GET(show_fps);
  auto fpshook = fpsManager.GetCreateCounter("CPU");
  fpshook->Tick();
}

void GPU_fps_hook() {
  auto fpshook = fpsManager.GetCreateCounter("GPU");
  fpshook->Tick();
}

/*
PPC_EXTERN_IMPORT(__imp__rex_appMainTickPreDraw_821C91C0);
PPC_EXTERN_IMPORT(__imp__rex_appMainDraw_821C8E78);
void MainLoop_hook() {
  using clock = std::chrono::steady_clock;

  auto last_cpu_tick = clock::now();
  auto last_gpu_draw = clock::now();
  auto cpu_accumulator = clock::duration::zero();

  int Run = 1;
  while (Run) {
    auto now = clock::now();

    // CPU tick rate from cvar (0 = unlimited)
    int32_t cpuLimit = REXCVAR_GET(maxCPU);
    if (cpuLimit > 0) {
      auto cpu_interval = std::chrono::duration_cast<clock::duration>(
          std::chrono::duration<double>(1.0 / cpuLimit));
      cpu_accumulator += now - last_cpu_tick;
      last_cpu_tick = now;

      while (cpu_accumulator >= cpu_interval) {
        Run = rex ::GuestToHostFunction<int>(__imp__rex_appMainTickPreDraw_821C91C0);
        TriggerReadCallback();
        cpu_accumulator -= cpu_interval;
        if (!Run) break;
      }
    } else {
      Run = rex ::GuestToHostFunction<int>(__imp__rex_appMainTickPreDraw_821C91C0);
      TriggerReadCallback();
    }

    // GPU draw rate from cvar (0 = unlimited)
    if (Run) {
      int32_t gpuLimit = REXCVAR_GET(maxGPU);
      if (gpuLimit > 0) {
        auto gpu_interval = std::chrono::duration_cast<clock::duration>(
            std::chrono::duration<double>(1.0 / gpuLimit));
        auto gpu_elapsed = now - last_gpu_draw;
        if (gpu_elapsed >= gpu_interval) {
          rex ::GuestToHostFunction<void>(__imp__rex_appMainDraw_821C8E78);
          last_gpu_draw = now;
        }
      } else {
        rex ::GuestToHostFunction<void>(__imp__rex_appMainDraw_821C8E78);
      }
    }

    if (cpuLimit > 0 || REXCVAR_GET(maxGPU) > 0) {
      std::this_thread::yield();
    }
  }
}
*/

void vsync_hook(PPCRegister& r10) {
  if(!REXCVAR_GET(lock_fps)) {
    r10.u32 = 0; // Force vsync off
  }

  
}

bool Space1_hook() {
  return true; // Always branch to loc_824DC830
}

bool Space2_hook() {
  return true; // Always branch to loc_824DD5C0
}

void Space3_hook(PPCRegister& r3) {
  r3.u32 = 1; // Set r3 to 1
}

void Space4_hook(PPCRegister& r6) {
  r6.u32 = 1; // Set r6 to 1
}

void Space5_hook(PPCRegister& r3) {
  r3.u32 = 0; // Set r3 to 0
}

bool Space6_hook() {
  return true; // Always branch to loc_824DDA84
}

bool Space7_hook() {
  return true; // Always branch to loc_824DDA84
}

uint32_t HI(const std::string& hexColor) {
    if (hexColor.size() != 9 || hexColor[0] != '#') {
        return 0xFFFFFFFF; // Default to white if invalid format
    }
    uint32_t r = std::stoul(hexColor.substr(1, 2), nullptr, 16);
    uint32_t g = std::stoul(hexColor.substr(3, 2), nullptr, 16);
    uint32_t b = std::stoul(hexColor.substr(5, 2), nullptr, 16);
    uint32_t a = std::stoul(hexColor.substr(7, 2), nullptr, 16);
    return (r << 24) | (g << 16) | (b << 8) | a;
}

// Classify a host-endian RGBA color as red or yellow
static bool isRedColor(uint32_t rgba) {
    uint8_t r = (rgba >> 24) & 0xFF;
    uint8_t g = (rgba >> 16) & 0xFF;
    uint8_t b = (rgba >>  8) & 0xFF;
    return r > 180 && g < 80 && b < 80;
}

static bool isYellowColor(uint32_t rgba) {
    uint8_t r = (rgba >> 24) & 0xFF;
    uint8_t g = (rgba >> 16) & 0xFF;
    uint8_t b = (rgba >>  8) & 0xFF;
    return r > 180 && g > 180 && b < 80;
}

// Triangle tracking arrays (8 red, 8 yellow)
static constexpr int MAX_TRIANGLES = 8;
static uint32_t redPtrs[MAX_TRIANGLES] = {};
static uint32_t yellowPtrs[MAX_TRIANGLES] = {};
static uint32_t redLastKnown[MAX_TRIANGLES] = {};   // value at offset 0 when captured
static uint32_t yellowLastKnown[MAX_TRIANGLES] = {};
static int redCount = 0;
static int yellowCount = 0;

void CursorColor_hook(PPCRegister& r31, PPCRegister& r27)
{
  if(!REXCVAR_GET(rgb_cursor)) {
    return;
  }

    // Resolve color pointer (guest memory is big-endian)
    uint32_t* colorPtr = reinterpret_cast<uint32_t*>(0x100000000ull + r31.u32 + 24);
    uint32_t rawColor = std::byteswap(*colorPtr); // host-endian RGBA

    // Read a stable field (offset 0) for sanity checking — we never modify this
    uint32_t baseValue = *reinterpret_cast<uint32_t*>(0x100000000ull + r31.u32);

    // Sanity check: if any stored entry's base value changed, memory was reallocated
    bool invalidated = false;
    for (int i = 0; i < redCount && !invalidated; i++) {
        uint32_t cur = *reinterpret_cast<uint32_t*>(0x100000000ull + redPtrs[i]);
        if (cur != redLastKnown[i]) invalidated = true;
    }
    for (int i = 0; i < yellowCount && !invalidated; i++) {
        uint32_t cur = *reinterpret_cast<uint32_t*>(0x100000000ull + yellowPtrs[i]);
        if (cur != yellowLastKnown[i]) invalidated = true;
    }
    if (invalidated) {
        redCount = 0;
        yellowCount = 0;
        memset(redPtrs, 0, sizeof(redPtrs));
        memset(yellowPtrs, 0, sizeof(yellowPtrs));
        memset(redLastKnown, 0, sizeof(redLastKnown));
        memset(yellowLastKnown, 0, sizeof(yellowLastKnown));
    }

    // Check if this pointer is already tracked
    bool isTracked = false;
    for (int i = 0; i < redCount; i++) {
        if (redPtrs[i] == r31.u32) { isTracked = true; break; }
    }
    if (!isTracked) {
        for (int i = 0; i < yellowCount; i++) {
            if (yellowPtrs[i] == r31.u32) { isTracked = true; break; }
        }
    }

    // If not tracked yet, classify by original color and add
    if (!isTracked) {
        if (isRedColor(rawColor) && redCount < MAX_TRIANGLES) {
            redPtrs[redCount] = r31.u32;
            redLastKnown[redCount] = baseValue;
            redCount++;
            isTracked = true;
        } else if (isYellowColor(rawColor) && yellowCount < MAX_TRIANGLES) {
            yellowPtrs[yellowCount] = r31.u32;
            yellowLastKnown[yellowCount] = baseValue;
            yellowCount++;
            isTracked = true;
        }
    }

    // Only apply rainbow to tracked (red/yellow) triangles
    if (!isTracked) return;

    // Determine if this is a red triangle (for hue offset)
    bool isRed = false;
    for (int i = 0; i < redCount; i++) {
        if (redPtrs[i] == r31.u32) { isRed = true; break; }
    }

    // Time-based hue cycling: full rainbow every 3 seconds
    auto now = std::chrono::steady_clock::now();
    static auto start = now;
    double elapsed = std::chrono::duration<double>(now - start).count();
    double hueD = fmod(elapsed * 120.0 + (isRed ? 180.0 : 0.0), 360.0); // red offset by 180°
    float hue = static_cast<float>(hueD);

    // HSV to RGB with full saturation and value
    float h = hue / 60.0f;
    int sector = static_cast<int>(h) % 6;
    float f = h - static_cast<int>(h);
    float q = 1.0f - f;

    float r, g, b;
    switch (sector) {
        case 0: r = 1; g = f; b = 0; break;
        case 1: r = q; g = 1; b = 0; break;
        case 2: r = 0; g = 1; b = f; break;
        case 3: r = 0; g = q; b = 1; break;
        case 4: r = f; g = 0; b = 1; break;
        default: r = 1; g = 0; b = q; break;
    }

    uint32_t ri = static_cast<uint32_t>(r * 255.0f);
    uint32_t gi = static_cast<uint32_t>(g * 255.0f);
    uint32_t bi = static_cast<uint32_t>(b * 255.0f);
    uint32_t rgba = (ri << 24) | (gi << 16) | (bi << 8) | 0xFF;

    // Apply cycling color, byte-swapped for PPC
    *colorPtr = std::byteswap(rgba);
}

/* 12001 */
struct gardenBudgetUnit_sl
{
  unsigned int virtualMemory;
  unsigned int physicalMemory;
  unsigned int dualShadowBuffering;
  unsigned int cubeShadowBuffering;
  unsigned int regularShadowBuffering;
  unsigned int diggableSurfacePreDraw;
  unsigned int mainPassOpaque;
  unsigned int mainPassTransparent;
};

/* 12002 */
struct gardenBudgetClassUnit_sl
{
  unsigned int classLimit[45];
};


void tagUnitsBudget_hook() {
  // Set the budget for each unit class to 9999 (0x270F in hex)
  uint32_t& limit = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8EC + 56);
  uint32_t& limit2 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8EC + 56 + 4);
  //83A5A8A8

  limit = std::byteswap(999999);
  limit2 = std::byteswap(999999);

  for (int i = 0; i < 2; i++) {
    //*reinterpret_cast<uint32_t*>(classLimitPtr + i * 4) = std::byteswap(0);
  }
  DebugLogInt32("BudgetHook", limit);


}

void tagClassUnitsBudget_hook(PPCRegister& r3) {
  //r3.u32 = the ptr to the gardenBudgetClassUnit_sl struct
  if(r3.u32 == 0) {
    return;
  }
  uint32_t* budgetPtr = reinterpret_cast<uint32_t*>(0x100000000 + r3.u32);
  for (int i = 0; i < 2260; i++) {
    budgetPtr[i] = std::byteswap(999);
  }
}

bool meUpdateOccupancyLevels_hook(PPCRegister& fp0){
  uint32_t& limit1 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8A8 + 64);
  uint32_t& limit2 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8A8 + 96);
  uint32_t& limit3 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8A8 + 132);
  uint32_t& limit4 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8A8 + 100);
  
  limit1 = std::byteswap(999999);
  limit2 = std::byteswap(999999);
  limit3 = std::byteswap(999999);
  limit4 = std::byteswap(999999);

  gardenBudgetUnit_sl* limits1 = reinterpret_cast<gardenBudgetUnit_sl*>(0x100000000 + 0x83A5A8A8 + 0);
  limits1->virtualMemory = std::byteswap(1282527612);
  limits1->physicalMemory = std::byteswap(1282527612);
  gardenBudgetUnit_sl* limits2 = reinterpret_cast<gardenBudgetUnit_sl*>(0x100000000 + 0x83A5A8A8 + 32);
  limits2->virtualMemory = std::byteswap(1282527612);
  limits2->physicalMemory = std::byteswap(1282527612);
  gardenBudgetUnit_sl* limits3 = reinterpret_cast<gardenBudgetUnit_sl*>(0x100000000 + 0x83A5A8A8 + 64);
  gardenBudgetUnit_sl* limits4 = reinterpret_cast<gardenBudgetUnit_sl*>(0x100000000 + 0x83A5A8A8 + 128);
  limits4->virtualMemory = std::byteswap(1282527612);
  limits4->physicalMemory = std::byteswap(1282527612);
  uint32_t& limit7 = *reinterpret_cast<uint32_t*>(0x100000000ull + 0x83A5A8A8ull + 28028);
  limit7 = 0x0000803F;
  return true;
}

bool skip_entityAvatarPinataSeedBigBrotherSaysYes_hook() {
  return true; // Always branch to loc_824DDA84
}

void one_hook(){
#ifndef __linux__
  REXCVAR_SET(d3d12_readback_resolve, true);
#endif
}

void two_hook(){
#ifndef __linux__
  REXCVAR_SET(d3d12_readback_resolve, false);
#endif
}

bool skipFirstDraw_hook(){
  return REXCVAR_GET(DisableMainDraw);
}

bool skipSecondDraw_hook(){
  return REXCVAR_GET(DisableUIDraw);
}

void skipRenderState0_hook(PPCRegister& r10){
  return;
  /*
  if(REXCVAR_GET(SkipShadowPass_One)){
    r10.u32 = 0; // Set shadow count to 0 to skip shadow pass
  }else{
    r10.u32 = 1;
  }
    */
}

void skipRenderState1_hook(PPCRegister& r9){
  return;
  /*
  if(REXCVAR_GET(SkipShadowPass_Two)){
    r9.u32 = 0; // Set shadow count to 0 to skip shadow pass
  }else{
    r9.u32 = 1;
  }
    */
}

void skipRenderState2_hook(PPCRegister& r9){
  return;
  /*
  if(REXCVAR_GET(SkipShadowPass_Three)){
    r9.u32 = 0; // Set shadow count to 0 to skip shadow pass
  }else{
    r9.u32 = 1;
  }
    */
}

void skipRenderState3_hook(PPCRegister& r9){
  return;
  /*
  if(REXCVAR_GET(SkipOpaquePass)){
    r9.u32 = 0; // Set shadow count to 0 to skip shadow pass
  }else{
    r9.u32 = 1;
  }
    */
}

void skipRenderState4_hook(PPCRegister& r9){
  return;
  /*
  if(REXCVAR_GET(SkipAlphaPass)){
    r9.u32 = 0; // Set shadow count to 0 to skip shadow pass
  }else{
    r9.u32 = 1;
  }
    */
}

void skipRenderState5_hook(PPCRegister& r9){
  return;
  /*
  if(REXCVAR_GET(SkipPostProcessPass)){
    r9.u32 = 0; // Set shadow count to 0 to skip shadow pass
  }else{
    r9.u32 = 1;
  }
    */
}

bool skiplighting_hook() {
  return false; // Always branch to loc_824DDA84
}

bool skiplightingTwo_hook() {
  return false; // Always branch to loc_824DDA84
}

bool SkipIntroVideos_hook() {
  return REXCVAR_GET(SkipIntros);
}

bool SkipIntroVideosTwo_hook() {
  return REXCVAR_GET(SkipIntros);
}