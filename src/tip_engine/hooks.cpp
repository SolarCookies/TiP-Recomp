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
#include <rex/ppc/types.h>
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

REXCVAR_DEFINE_BOOL(rgb_cursor, false, "_Trouble in Paradise", "Enables the Gursor");
REXCVAR_DEFINE_BOOL(lock_fps, false, "_Trouble in Paradise", "Lock to 30 FPS");
REXCVAR_DEFINE_BOOL(show_fps, false, "_Trouble in Paradise", "Show FPS Overlay");
REXCVAR_DEFINE_BOOL(DisableMainDraw, false, "_Trouble in Paradise", "Disables the Main Draw Pass");
REXCVAR_DEFINE_BOOL(DisableUIDraw, false, "_Trouble in Paradise", "Disables the UI Draw Pass");

REXCVAR_DEFINE_BOOL(UseAspectRatioFromConfig, false, "_Trouble in Paradise", "Use Aspect Ratio from config");
REXCVAR_DEFINE_DOUBLE(AspectRatio, 1.7777778f, "_Trouble in Paradise", "Aspect Ratio");

REXCVAR_DEFINE_BOOL(SkipIntros, false, "_Trouble in Paradise", "Skip Intro Videos");
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
    //*(float *)(virtCam + 8) = result[0];
    //*(float *)(virtCam + 12) = result[1];
    //*(float *)(virtCam + 16) = result[2];
    return rex ::GuestToHostFunction<float *>(__imp__rex_camMainGetPos_821F07E0, result);
  }
  return rex ::GuestToHostFunction<float *>(__imp__rex_camMainGetPos_821F07E0, result);
}
REX_PPC_HOOK(camMainGetPos_821F07E0);
*/


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
    if(r3.u32){
      float* aspectRatioPtr = reinterpret_cast<float*>(0x100000000ull + r3.u32 + 0x399C);
      *aspectRatioPtr = to_byteswapped_float(customAR);
    }
  }
}

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


REX_PPC_EXTERN_IMPORT(render_D3DDevice_BeginIndexedVertices_82664640);
int render_D3DDevice_BeginIndexedVertices_82664640_Hook(
    uint32_t pDevice,
    uint32_t PrimitiveType,
    int32_t  BaseVertexIndex,
    uint32_t NumVertices,
    uint32_t IndexCount,
    uint32_t IndexDataFormat,
    uint32_t VertexStreamZeroStride,
    uint32_t ppIndexDataint,
    uint32_t ppVertexData,
    uint32_t a10,
    uint32_t a11,
    uint32_t a12,
    uint32_t a13,
    uint32_t a14,
    uint32_t a15,
    uint32_t a16,
    uint32_t a17,
    uint32_t a18,
    uint32_t a19,
    uint32_t a20,
    uint32_t a21,
    uint32_t a22,
    uint32_t a23,
    uint32_t a24,
    uint32_t a25,
    uint32_t a26,
    uint32_t a27,
    uint32_t a28)
{
  /*
  std::string primitiveStr1;
  switch (PrimitiveType) {
    case 1: primitiveStr1 = "POINTLIST"; break;
    case 2: primitiveStr1 = "LINELIST"; break;
    case 3: primitiveStr1 = "LINESTRIP"; break;
    case 4: primitiveStr1 = "TRIANGLELIST"; break;
    case 5: primitiveStr1 = "TRIANGLEFAN"; break;
    case 6: primitiveStr1 = "TRIANGLESTRIP"; break;
    case 8: primitiveStr1 = "RECTLIST"; break;
    case 13: primitiveStr1 = "QUADLIST"; break;
    default: primitiveStr1 = "UNKNOWN"; break;
  }
  primitiveStr1 += " NumVertices=" + std::to_string(NumVertices);
  primitiveStr1 += " IndexCount=" + std::to_string(IndexCount);
  primitiveStr1 += " BaseVertexIndex=" + std::to_string(BaseVertexIndex);
  primitiveStr1 += " IndexDataFormat=" + std::to_string(IndexDataFormat);
  primitiveStr1 += " VertexStreamZeroStride=" + std::to_string(VertexStreamZeroStride);
  //primitiveStr1 += " ppIndexData=" + (ppIndexData ? ("0x" + std::to_string(*ppIndexData)) : "null");
  //primitiveStr1 += " ppVertexData=" + (ppVertexData ? ("0x" + std::to_string(*ppVertexData)) : "null");
*/

    int result = rex::GuestToHostFunction<int>(
        __imp__rex_render_D3DDevice_BeginIndexedVertices_82664640, pDevice, PrimitiveType, BaseVertexIndex, NumVertices,
        IndexCount, IndexDataFormat, VertexStreamZeroStride, ppIndexDataint, ppVertexData, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28);

    return result;
}
REX_PPC_HOOK(render_D3DDevice_BeginIndexedVertices_82664640);


REX_PPC_EXTERN_IMPORT(render_D3DDevice_DrawIndexedVertices_82664FF0);
void render_D3DDevice_DrawIndexedVertices_82664FF0_Hook(
  int pDevice,
  char PrimitiveType,
  int BaseVertexIndex,
  int NumVertices,
  unsigned int IndexCount,
  int IndexDataFormat,
  unsigned int VertexStreamZeroStride,
  unsigned int ppIndexData,
  unsigned int ppVertexData,
  int a10,
  int a11,
  int a12,
  int a13,
  int a14,
  int a15,
  int a16,
  int a17,
  int a18,
  int a19,
  int a20,
  int a21,
  int a22,
  int a23,
  int a24,
  int a25,
  int a26,
  int a27,
  int a28)
  {
    /*
  std::string primitiveStr;
  switch (PrimitiveType) {
    case 1: primitiveStr = "POINTLIST"; break;
    case 2: primitiveStr = "LINELIST"; break;
    case 3: primitiveStr = "LINESTRIP"; break;
    case 4: primitiveStr = "TRIANGLELIST"; break;
    case 5: primitiveStr = "TRIANGLEFAN"; break;
    case 6: primitiveStr = "TRIANGLESTRIP"; break;
    case 8: primitiveStr = "RECTLIST"; break;
    case 13: primitiveStr = "QUADLIST"; break;
    default: primitiveStr = "UNKNOWN"; break;
  }
  primitiveStr += " NumVertices=" + std::to_string(NumVertices);
  primitiveStr += " IndexCount=" + std::to_string(IndexCount);
  primitiveStr += " BaseVertexIndex=" + std::to_string(BaseVertexIndex);
  primitiveStr += " IndexDataFormat=" + std::to_string(IndexDataFormat);
  primitiveStr += " VertexStreamZeroStride=" + std::to_string(VertexStreamZeroStride);
  //primitiveStr += " ppIndexData=" + (ppIndexData ? ("0x" + std::to_string(*ppIndexData)) : "null");
  //primitiveStr += " ppVertexData=" + (ppVertexData ? ("0x" + std::to_string(*ppVertexData)) : "null");


  Log(LogLevel::Error, "DrawIndexedVertices called: " + primitiveStr);
  */
    rex::GuestToHostFunction<void>(
        __imp__rex_render_D3DDevice_DrawIndexedVertices_82664FF0, pDevice, PrimitiveType, BaseVertexIndex, NumVertices,
        IndexCount, IndexDataFormat, VertexStreamZeroStride, ppIndexData, ppVertexData, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28);
}
REX_PPC_HOOK(render_D3DDevice_DrawIndexedVertices_82664FF0);



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

void InRomanceMinigame_hook(){
  VSyncBefore = REXCVAR_GET(vsync);
  lockFPSBefore = REXCVAR_GET(lock_fps);
  REXCVAR_SET(vsync, true);
  REXCVAR_SET(lock_fps, true);
}

void NotInRomanceMinigame_hook(){
  REXCVAR_SET(vsync, VSyncBefore);
  REXCVAR_SET(lock_fps, lockFPSBefore);
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

void NotPlacingBuilding_hook(){
  g_IsPlacingBuilding = false;
}

void PlacingBuilding_hook(){
  g_IsPlacingBuilding = true;
}