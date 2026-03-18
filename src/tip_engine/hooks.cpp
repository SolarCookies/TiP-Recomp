#include "tip_engine/hooks.h"

#include <rex/ui/imgui_dialog.h>
#include "imgui.h"

#include <rex/cvar.h>
#include <rex/ppc/types.h>
#include <rex/system/kernel_state.h>
#include "tip_engine/Log.h"
#include "tip_engine/D3DTypes.h"

#include "rex_macros.h"


REXCVAR_DEFINE_BOOL(show_fps_overlay, false, "_Trouble in Paradise", "Show FPS overlay");

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
}

bool PresentParams_hook(PPCRegister& r11) {
  //r11.u32 is a * to a _D3DPRESENT_PARAMETERS_ struct
  if(r11.u32 == 0) {
    return false;
  }
  _D3DPRESENT_PARAMETERS_* params = reinterpret_cast<_D3DPRESENT_PARAMETERS_*>(0x100000000ull + r11.u32);

  
  auto bs = [](uint32_t v) { return _byteswap_ulong(v); };
  auto bsi = [](int v) { return static_cast<int>(_byteswap_ulong(static_cast<uint32_t>(v))); };

  params->FullScreen_RefreshRateInHz = bs(164);
  params->PresentationInterval = bs(0); // D3DPRESENT_INTERVAL_ONE

  //params->BackBufferHeight = bs(1080);
  //params->BackBufferWidth = bs(1920);
  return false;
}

void PresentParams2_hook(PPCRegister& r3){
   // Guest memory is big-endian (PPC), byte-swap each 32-bit field for host (x86)
  auto bs = [](uint32_t v) { return _byteswap_ulong(v); };
  auto bsi = [](int v) { return static_cast<int>(_byteswap_ulong(static_cast<uint32_t>(v))); };

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
  params->presentImmediately = bs(1); // TRUE
}


void vsync_hook(PPCRegister& r10) {
  r10.u32 = 0; // Force vsync off
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