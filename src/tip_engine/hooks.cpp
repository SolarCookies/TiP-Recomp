#include "tip_engine/hooks.h"

#include <cstdint>
#include <cmath>
#include <cstring>
#include <rex/ui/imgui_dialog.h>
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
REXCVAR_DEFINE_BOOL(DisableMainDraw, false, "_Trouble in Paradise", "Disables the Main Draw Pass");
REXCVAR_DEFINE_BOOL(DisableUIDraw, false, "_Trouble in Paradise", "Disables the UI Draw Pass");

REXCVAR_DEFINE_BOOL(UseAspectRatioFromConfig, false, "_Trouble in Paradise", "Use Aspect Ratio from config");
REXCVAR_DEFINE_DOUBLE(AspectRatio, 1.7777778f, "_Trouble in Paradise", "Aspect Ratio");


REX_PPC_EXTERN_IMPORT(camMainGetPos_821F07E0);

float * camMainGetPos_821F07E0_Hook(float *result){
  /*
  if(REXCVAR_GET(Freecam)) {
    result[0] = to_byteswapped_float(static_cast<float>(REXCVAR_GET(Freecam_X)));
    result[1] = to_byteswapped_float(static_cast<float>(REXCVAR_GET(Freecam_Y)));
    result[2] = to_byteswapped_float(static_cast<float>(REXCVAR_GET(Freecam_Z)));

    //.data:82C34E98 Me_36.virtCam
    uintptr_t virtCam = reinterpret_cast<uintptr_t>(0x100000000ull + 0x82C34E98);
    *(float *)(virtCam + 8) = result[0];
    *(float *)(virtCam + 12) = result[1];
    *(float *)(virtCam + 16) = result[2];
    DebugLogFloat("Freecam X", static_cast<float>(REXCVAR_GET(Freecam_X)));
    DebugLogFloat("Freecam Y", static_cast<float>(REXCVAR_GET(Freecam_Y)));
    DebugLogFloat("Freecam Z", static_cast<float>(REXCVAR_GET(Freecam_Z)));

    if((float *)(virtCam + 8) != nullptr) {
        DebugLogFloat("CamMainGetPos X", *(float *)(virtCam + 8));
    }
    if((float *)(virtCam + 12) != nullptr) {
        DebugLogFloat("CamMainGetPos Y", *(float *)(virtCam + 12));
    }
    if((float *)(virtCam + 16) != nullptr) {
        DebugLogFloat("CamMainGetPos Z", *(float *)(virtCam + 16));
    }

    return result;
  }else{
    //.data:82C34E98 Me_36.virtCam
    uintptr_t virtCam = reinterpret_cast<uintptr_t>(0x100000000ull + 0x82C34E98);
    //*(float *)(virtCam + 8) = result[0];
    //*(float *)(virtCam + 12) = result[1];
    //*(float *)(virtCam + 16) = result[2];
    DebugLogFloat("Freecam X", static_cast<float>(REXCVAR_GET(Freecam_X)));
    DebugLogFloat("Freecam Y", static_cast<float>(REXCVAR_GET(Freecam_Y)));
    DebugLogFloat("Freecam Z", static_cast<float>(REXCVAR_GET(Freecam_Z)));
    if((float *)(virtCam + 8) != nullptr) {
        DebugLogFloat("CamMainGetPos X", *(float *)(virtCam + 8));
    }
    if((float *)(virtCam + 12) != nullptr) {
        DebugLogFloat("CamMainGetPos Y", *(float *)(virtCam + 12));
    }
    if((float *)(virtCam + 16) != nullptr) {
        DebugLogFloat("CamMainGetPos Z", *(float *)(virtCam + 16));
    }
    return rex ::GuestToHostFunction<float *>(__imp__rex_camMainGetPos_821F07E0, result);
  }
    */
  return rex ::GuestToHostFunction<float *>(__imp__rex_camMainGetPos_821F07E0, result);
}

REX_PPC_HOOK(camMainGetPos_821F07E0);

//double rex_camMainGetAspectRatio_821F0730()
REX_PPC_EXTERN_IMPORT(camMainGetAspectRatio_821F0730);

float camMainGetAspectRatio_821F0730_Hook() {
  if(REXCVAR_GET(UseAspectRatioFromConfig)) {
    float aspectRatio = static_cast<float>(REXCVAR_GET(AspectRatio));
    DebugLogFloat("Aspect Ratio", aspectRatio);
    return aspectRatio;
  }
  float aspectRatio = rex::GuestToHostFunction<float>(__imp__rex_camMainGetAspectRatio_821F0730);
  DebugLogFloat("Aspect Ratio", static_cast<float>(aspectRatio));
  return aspectRatio;
}

REX_PPC_HOOK(camMainGetAspectRatio_821F0730);


auto frameTime=std::chrono::system_clock::now();
int frame = 0;
double fpsHistory[10] = {};
int fpsHistoryIndex = 0;
int fpsHistoryCount = 0;

void fps_hook() {
  frame++;
  auto Time = std::chrono::system_clock::now();
  std::chrono::duration<double, std::milli> delta = Time - frameTime;
  frameTime = Time;
  double fpsfromMS = 1000 / delta.count();
  if (frame >= 2) {
    frame = 0;
    fpsHistory[fpsHistoryIndex] = fpsfromMS;
    fpsHistoryIndex = (fpsHistoryIndex + 1) % 10;
    if (fpsHistoryCount < 10) fpsHistoryCount++;

    double sum = 0.0;
    for (int i = 0; i < fpsHistoryCount; i++) sum += fpsHistory[i];
    fpsCount = sum / fpsHistoryCount;
  }

  showfps = REXCVAR_GET(show_fps_overlay);

  /*
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
  */
}

bool PresentParams_hook(PPCRegister& r11) {
  //r11.u32 is a * to a _D3DPRESENT_PARAMETERS_ struct
  if(r11.u32 == 0) {
    return false;
  }
  _D3DPRESENT_PARAMETERS_* params = reinterpret_cast<_D3DPRESENT_PARAMETERS_*>(0x100000000ull + r11.u32);

  
  auto bs = [](uint32_t v) { return std::byteswap(v); };
  auto bsi = [](int v) { return static_cast<int>(std::byteswap(static_cast<uint32_t>(v))); };

  params->FullScreen_RefreshRateInHz = bs(164);
  params->PresentationInterval = bs(0); // D3DPRESENT_INTERVAL_ONE
  if(REXCVAR_GET(lock_fps)) {
    params->PresentationInterval = bs(2); // D3DPRESENT_INTERVAL_TWO
  }

  //params->BackBufferHeight = bs(1080);
  //params->BackBufferWidth = bs(1920);
  return false;
}

void PresentParams2_hook(PPCRegister& r3){
   // Guest memory is big-endian (PPC), byte-swap each 32-bit field for host (x86)
  auto bs = [](uint32_t v) { return std::byteswap(v); };
  auto bsi = [](int v) { return static_cast<int>(std::byteswap(static_cast<uint32_t>(v))); };

  //r3 is a * to video parameters struct
  if(r3.u32 == 0) {
    return;
  }
  videoParams_s* params = reinterpret_cast<videoParams_s*>(0x100000000ull + r3.u32);
  params->resolutionType = bs(2);
  //params->width = bs(1920);
  //params->height = bs(1080);
  params->refreshRateHZ = bs(164);
  params->presentInterval = bs(0); // D3DPRESENT_INTERVAL_ONE
  if(REXCVAR_GET(lock_fps)) {
    params->presentInterval = bs(2); // D3DPRESENT_INTERVAL_TWO
  }
  params->presentImmediately = bs(1); // TRUE
}


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
  REXCVAR_SET(d3d12_readback_resolve, true);
}

void two_hook(){
  REXCVAR_SET(d3d12_readback_resolve, false);
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