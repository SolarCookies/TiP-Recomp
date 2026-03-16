#include "tip_engine/hooks.h"

#include <atomic>
#include <chrono>
#include <thread>
#include <cstdint> // For uintptr_t
#include <rex/ui/imgui_dialog.h>
#include "Log.h"
#include "imgui.h"

#include <rex/cvar.h>
#include <rex/ppc/types.h>
#include <rex/system/kernel_state.h>
#include "tip_engine/Log.h"

#include "rex_macros.h"

#pragma pack(push, 2)
struct videoParams_s
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
#pragma pack(pop)

struct HWND__;

/* 239 */
enum _D3DFORMAT : uint32_t
{
  D3DFMT_DXT1 = 0x1A200152,
  D3DFMT_LIN_DXT1 = 0x1A200052,
  D3DFMT_DXT2 = 0x1A200153,
  D3DFMT_LIN_DXT2 = 0x1A200053,
  D3DFMT_DXT3 = 0x1A200153,
  D3DFMT_LIN_DXT3 = 0x1A200053,
  D3DFMT_DXT3A = 0x1A20017A,
  D3DFMT_LIN_DXT3A = 0x1A20007A,
  D3DFMT_DXT3A_1111 = 0x1A20017D,
  D3DFMT_LIN_DXT3A_1111 = 0x1A20007D,
  D3DFMT_DXT4 = 0x1A200154,
  D3DFMT_LIN_DXT4 = 0x1A200054,
  D3DFMT_DXT5 = 0x1A200154,
  D3DFMT_LIN_DXT5 = 0x1A200054,
  D3DFMT_DXT5A = 0x1A20017B,
  D3DFMT_LIN_DXT5A = 0x1A20007B,
  D3DFMT_DXN = 0x1A200171,
  D3DFMT_LIN_DXN = 0x1A200071,
  D3DFMT_CTX1 = 0x1A20017C,
  D3DFMT_LIN_CTX1 = 0x1A20007C,
  D3DFMT_A8 = 0x4900102,
  D3DFMT_LIN_A8 = 0x4900002,
  D3DFMT_L8 = 0x28000102,
  D3DFMT_LIN_L8 = 0x28000002,
  D3DFMT_R5G6B5 = 0x28280144,
  D3DFMT_LIN_R5G6B5 = 0x28280044,
  D3DFMT_R6G5B5 = 0x28280145,
  D3DFMT_LIN_R6G5B5 = 0x28280045,
  D3DFMT_L6V5U5 = 0x2A200B45,
  D3DFMT_LIN_L6V5U5 = 0x2A200A45,
  D3DFMT_X1R5G5B5 = 0x28280143,
  D3DFMT_LIN_X1R5G5B5 = 0x28280043,
  D3DFMT_A1R5G5B5 = 0x18280143,
  D3DFMT_LIN_A1R5G5B5 = 0x18280043,
  D3DFMT_A4R4G4B4 = 0x1828014F,
  D3DFMT_LIN_A4R4G4B4 = 0x1828004F,
  D3DFMT_X4R4G4B4 = 0x2828014F,
  D3DFMT_LIN_X4R4G4B4 = 0x2828004F,
  D3DFMT_Q4W4V4U4 = 0x1A20AB4F,
  D3DFMT_LIN_Q4W4V4U4 = 0x1A20AA4F,
  D3DFMT_A8L8 = 0x800014A,
  D3DFMT_LIN_A8L8 = 0x800004A,
  D3DFMT_G8R8 = 0x2D20014A,
  D3DFMT_LIN_G8R8 = 0x2D20004A,
  D3DFMT_V8U8 = 0x2D20AB4A,
  D3DFMT_LIN_V8U8 = 0x2D20AA4A,
  D3DFMT_D16 = 0x1A220158,
  D3DFMT_LIN_D16 = 0x1A220058,
  D3DFMT_L16 = 0x28000158,
  D3DFMT_LIN_L16 = 0x28000058,
  D3DFMT_R16F = 0x2DA2AB5E,
  D3DFMT_LIN_R16F = 0x2DA2AA5E,
  D3DFMT_R16F_EXPAND = 0x2DA2AB5B,
  D3DFMT_LIN_R16F_EXPAND = 0x2DA2AA5B,
  D3DFMT_UYVY = 0x1A20014C,
  D3DFMT_LIN_UYVY = 0x1A20004C,
  D3DFMT_LE_UYVY = 0x1A20010C,
  D3DFMT_LE_LIN_UYVY = 0x1A20000C,
  D3DFMT_G8R8_G8B8 = 0x1828014C,
  D3DFMT_LIN_G8R8_G8B8 = 0x1828004C,
  D3DFMT_R8G8_B8G8 = 0x1828014B,
  D3DFMT_LIN_R8G8_B8G8 = 0x1828004B,
  D3DFMT_YUY2 = 0x1A20014B,
  D3DFMT_LIN_YUY2 = 0x1A20004B,
  D3DFMT_LE_YUY2 = 0x1A20010B,
  D3DFMT_LE_LIN_YUY2 = 0x1A20000B,
  D3DFMT_A8R8G8B8 = 0x18280186,
  D3DFMT_LIN_A8R8G8B8 = 0x18280086,
  D3DFMT_X8R8G8B8 = 0x28280186,
  D3DFMT_LIN_X8R8G8B8 = 0x28280086,
  D3DFMT_A8B8G8R8 = 0x1A200186,
  D3DFMT_LIN_A8B8G8R8 = 0x1A200086,
  D3DFMT_X8B8G8R8 = 0x2A200186,
  D3DFMT_LIN_X8B8G8R8 = 0x2A200086,
  D3DFMT_X8L8V8U8 = 0x2A200B86,
  D3DFMT_LIN_X8L8V8U8 = 0x2A200A86,
  D3DFMT_Q8W8V8U8 = 0x1A20AB86,
  D3DFMT_LIN_Q8W8V8U8 = 0x1A20AA86,
  D3DFMT_A2R10G10B10 = 0x182801B6,
  D3DFMT_LIN_A2R10G10B10 = 0x182800B6,
  D3DFMT_X2R10G10B10 = 0x282801B6,
  D3DFMT_LIN_X2R10G10B10 = 0x282800B6,
  D3DFMT_A2B10G10R10 = 0x1A2001B6,
  D3DFMT_LIN_A2B10G10R10 = 0x1A2000B6,
  D3DFMT_A2W10V10U10 = 0x1A202BB6,
  D3DFMT_LIN_A2W10V10U10 = 0x1A202AB6,
  D3DFMT_A16L16 = 0x8000199,
  D3DFMT_LIN_A16L16 = 0x8000099,
  D3DFMT_G16R16 = 0x2D200199,
  D3DFMT_LIN_G16R16 = 0x2D200099,
  D3DFMT_V16U16 = 0x2D20AB99,
  D3DFMT_LIN_V16U16 = 0x2D20AA99,
  D3DFMT_R10G11B11 = 0x282801B7,
  D3DFMT_LIN_R10G11B11 = 0x282800B7,
  D3DFMT_R11G11B10 = 0x282801B8,
  D3DFMT_LIN_R11G11B10 = 0x282800B8,
  D3DFMT_W10V11U11 = 0x2A20ABB7,
  D3DFMT_LIN_W10V11U11 = 0x2A20AAB7,
  D3DFMT_W11V11U10 = 0x2A20ABB8,
  D3DFMT_LIN_W11V11U10 = 0x2A20AAB8,
  D3DFMT_G16R16F = 0x2D22AB9F,
  D3DFMT_LIN_G16R16F = 0x2D22AA9F,
  D3DFMT_G16R16F_EXPAND = 0x2D22AB9C,
  D3DFMT_LIN_G16R16F_EXPAND = 0x2D22AA9C,
  D3DFMT_L32 = 0x280001A1,
  D3DFMT_LIN_L32 = 0x280000A1,
  D3DFMT_R32F = 0x2DA2ABA4,
  D3DFMT_LIN_R32F = 0x2DA2AAA4,
  D3DFMT_D24S8 = 0x2D200196,
  D3DFMT_LIN_D24S8 = 0x2D200096,
  D3DFMT_D24X8 = 0x2DA00196,
  D3DFMT_LIN_D24X8 = 0x2DA00096,
  D3DFMT_D24FS8 = 0x1A220197,
  D3DFMT_LIN_D24FS8 = 0x1A220097,
  D3DFMT_D32 = 0x1A2201A1,
  D3DFMT_LIN_D32 = 0x1A2200A1,
  D3DFMT_A16B16G16R16 = 0x1A20015A,
  D3DFMT_LIN_A16B16G16R16 = 0x1A20005A,
  D3DFMT_Q16W16V16U16 = 0x1A20AB5A,
  D3DFMT_LIN_Q16W16V16U16 = 0x1A20AA5A,
  D3DFMT_A16B16G16R16F = 0x1A22AB60,
  D3DFMT_LIN_A16B16G16R16F = 0x1A22AA60,
  D3DFMT_A16B16G16R16F_EXPAND = 0x1A22AB5D,
  D3DFMT_LIN_A16B16G16R16F_EXPAND = 0x1A22AA5D,
  D3DFMT_A32L32 = 0x80001A2,
  D3DFMT_LIN_A32L32 = 0x80000A2,
  D3DFMT_G32R32 = 0x2D2001A2,
  D3DFMT_LIN_G32R32 = 0x2D2000A2,
  D3DFMT_V32U32 = 0x2D20ABA2,
  D3DFMT_LIN_V32U32 = 0x2D20AAA2,
  D3DFMT_G32R32F = 0x2D22ABA5,
  D3DFMT_LIN_G32R32F = 0x2D22AAA5,
  D3DFMT_A32B32G32R32 = 0x1A2001A3,
  D3DFMT_LIN_A32B32G32R32 = 0x1A2000A3,
  D3DFMT_Q32W32V32U32 = 0x1A20ABA3,
  D3DFMT_LIN_Q32W32V32U32 = 0x1A20AAA3,
  D3DFMT_A32B32G32R32F = 0x1A22ABA6,
  D3DFMT_LIN_A32B32G32R32F = 0x1A22AAA6,
  D3DFMT_A2B10G10R10F_EDRAM = 0x1A2201BF,
  D3DFMT_G16R16_EDRAM = 0x2D20AB8D,
  D3DFMT_A16B16G16R16_EDRAM = 0x1A20AB55,
  D3DFMT_LE_X8R8G8B8 = 0x28280106,
  D3DFMT_LE_A8R8G8B8 = 0x18280106,
  D3DFMT_LE_X2R10G10B10 = 0x28280136,
  D3DFMT_LE_A2R10G10B10 = 0x18280136,
  D3DFMT_INDEX16 = 0x1,
  D3DFMT_INDEX32 = 0x6,
  D3DFMT_LE_INDEX16 = 0x0,
  D3DFMT_LE_INDEX32 = 0x4,
  D3DFMT_VERTEXDATA = 0x8,
  D3DFMT_UNKNOWN = 0xFFFFFFFF,
  D3DFMT_FORCE_DWORD = 0x7FFFFFFF,
};

/* 236 */
enum _D3DMULTISAMPLE_TYPE : uint32_t
{
  D3DMULTISAMPLE_NONE = 0x0,
  D3DMULTISAMPLE_2_SAMPLES = 0x1,
  D3DMULTISAMPLE_4_SAMPLES = 0x2,
  D3DMULTISAMPLE_FORCE_DWORD = 0x7FFFFFFF,
};

/* 309 */
enum _D3DSWAPEFFECT : uint32_t
{
  D3DSWAPEFFECT_DISCARD = 0x1,
  D3DSWAPEFFECT_FLIP = 0x2,
  D3DSWAPEFFECT_COPY = 0x3,
  D3DSWAPEFFECT_FORCE_DWORD = 0x7FFFFFFF,
};

/* 332 */
enum _D3DCOLORSPACE : uint32_t
{
  D3DCOLORSPACE_RGB = 0x0,
  D3DCOLORSPACE_YCbCr601 = 0x1,
  D3DCOLORSPACE_YCbCr709 = 0x2,
  D3DCOLORSPACE_FORCE_DWORD = 0x7FFFFFFF,
};

/* 3129 */
struct _D3DRING_BUFFER_PARAMETERS
{
  unsigned int Flags;
  unsigned int PrimarySize;
  void *pPrimary;
  unsigned int SecondarySize;
  void *pSecondary;
  unsigned int SegmentCount;
};

/* 3130 */
struct _D3DRECT
{
  int x1;
  int y1;
  int x2;
  int y2;
};

/* 3131 */
struct _D3DVIDEO_SCALER_PARAMETERS
{
  _D3DRECT ScalerSourceRect;
  unsigned int ScaledOutputWidth;
  unsigned int ScaledOutputHeight;
  unsigned int FilterProfile;
};

/* 3132 */
struct _D3DPRESENT_PARAMETERS_
{
  unsigned int BackBufferWidth;
  unsigned int BackBufferHeight;
  _D3DFORMAT BackBufferFormat;
  unsigned int BackBufferCount;
  _D3DMULTISAMPLE_TYPE MultiSampleType;
  unsigned int MultiSampleQuality;
  _D3DSWAPEFFECT SwapEffect;
  HWND__ *hDeviceWindow;
  int Windowed;
  int EnableAutoDepthStencil;
  _D3DFORMAT AutoDepthStencilFormat;
  unsigned int Flags;
  unsigned int FullScreen_RefreshRateInHz;
  unsigned int PresentationInterval;
  int DisableAutoBackBuffer;
  int DisableAutoFrontBuffer;
  _D3DFORMAT FrontBufferFormat;
  _D3DCOLORSPACE FrontBufferColorSpace;
  _D3DRING_BUFFER_PARAMETERS RingBufferParameters;
  _D3DVIDEO_SCALER_PARAMETERS VideoScalerParameters;
};


REXCVAR_DEFINE_BOOL(show_fps_overlay, false, "_Trouble in Paradise", "Show FPS overlay");

auto frameTime=std::chrono::system_clock::now();
int frame = 0;

void fps_hook() {
  //TickLogMessages();
  frame++;
  auto Time = std::chrono::system_clock::now();
  std::chrono::duration<double, std::milli> delta = Time - frameTime;
  frameTime = Time;
  double fpsfromMS = 1000 / delta.count();
  if (frame >= 60) {
    frame = 0;
    fpsCount = fpsfromMS;
  }
  showfps = REXCVAR_GET(show_fps_overlay);
}

bool PresentParams_hook(PPCRegister& r11) {
  //r11.u32 is a * to a _D3DPRESENT_PARAMETERS_ struct
  if(r11.u32 == 0) {
    return false;
  }
  _D3DPRESENT_PARAMETERS_* params = reinterpret_cast<_D3DPRESENT_PARAMETERS_*>(0x100000000ull + r11.u32);

  
  // Guest memory is big-endian (PPC), byte-swap each 32-bit field for host (x86)
  auto bs = [](uint32_t v) { return _byteswap_ulong(v); };
  auto bsi = [](int v) { return static_cast<int>(_byteswap_ulong(static_cast<uint32_t>(v))); };

  params->FullScreen_RefreshRateInHz = bs(60);
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
  //params->width = bs(1920);
  //params->height = bs(1080);
  params->refreshRateHZ = bs(120);
  params->presentInterval = bs(0); // D3DPRESENT_INTERVAL_ONE
  params->presentImmediately = bs(1); // TRUE
}


void vsync_hook(PPCRegister& r10) {
  r10.u32 = 0; // Force vsync off
}