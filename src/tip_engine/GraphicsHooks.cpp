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
#include "tip_engine/CustomRenderer/engine/Actors/VertexPreviewActor.h"

REXCVAR_DEFINE_BOOL(DisableMainDraw, false, "_Trouble in Paradise", "Disables the Main Draw Pass");
REXCVAR_DEFINE_BOOL(DisableUIDraw, false, "_Trouble in Paradise", "Disables the UI Draw Pass");
REXCVAR_DEFINE_BOOL(UseAspectRatioFromConfig, false, "_Trouble in Paradise", "Use Aspect Ratio from config");
REXCVAR_DEFINE_DOUBLE(AspectRatio, 1.7777778f, "_Trouble in Paradise", "Aspect Ratio");
REXCVAR_DEFINE_BOOL(SkipIntros, false, "_Trouble in Paradise", "Skip Intro Videos");


// Guest memory bounds for safety checks
static constexpr uint64_t GUEST_MEM_BASE = 0x100000000ull;
static constexpr uint64_t GUEST_MEM_SIZE = 0x100000000ull; // 4GB guest address space
static constexpr uint32_t MAX_PREVIEW_VERTS = 10000;
static constexpr uint32_t MAX_SANE_STRIDE = 256;

static bool IsGuestRangeValid(uint32_t guestAddr, uint64_t size) {
    if (guestAddr == 0) return false;
    uint64_t end = static_cast<uint64_t>(guestAddr) + size;
    return end <= GUEST_MEM_SIZE;
}

#ifdef DEBUG_BUILD

REXCVAR_DEFINE_BOOL(PreviewDrawVerticesUP, false, "_Trouble in Paradise", "Preview DrawVerticesUP vertices as points");
REXCVAR_DEFINE_BOOL(PreviewBeginIndexedVertices, false, "_Trouble in Paradise", "Preview BeginIndexedVertices vertices as points");
REXCVAR_DEFINE_BOOL(PreviewXuiDraw, false, "_Trouble in Paradise", "Preview XUI draw calls");

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
    int result = rex::ppc::GuestToHostFunction<int>(
        __imp__rex_render_D3DDevice_BeginIndexedVertices_82664640, pDevice, PrimitiveType, BaseVertexIndex, NumVertices,
        IndexCount, IndexDataFormat, VertexStreamZeroStride, ppIndexDataint, ppVertexData, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28);

    // Capture vertex info for preview - this function is called by both
    // DrawIndexedPrimitiveUP and other indexed draw paths
    // Save buffer pointers now; actual data read happens in DrawIndexedVertices
    // (the caller copies vertex/index data into the buffers between Begin and Draw)
    if (REXCVAR_GET(PreviewBeginIndexedVertices) && result == 0 && ppVertexData && ppIndexDataint && NumVertices > 0 && VertexStreamZeroStride >= 12) {
        g_VertexPreview.enabled = true;

        uint8_t* guestBase = reinterpret_cast<uint8_t*>(GUEST_MEM_BASE);
        uint32_t vertBufPtr = std::byteswap(*reinterpret_cast<uint32_t*>(guestBase + ppVertexData));
        uint32_t idxBufPtr = std::byteswap(*reinterpret_cast<uint32_t*>(guestBase + ppIndexDataint));

        g_VertexPreview.pending.vertBufGuestPtr = vertBufPtr;
        g_VertexPreview.pending.idxBufGuestPtr = idxBufPtr;
        g_VertexPreview.pending.numVertices = NumVertices;
        g_VertexPreview.pending.stride = VertexStreamZeroStride;
        g_VertexPreview.pending.indexFormat = IndexDataFormat;
        g_VertexPreview.pending.valid = true;
    }

    return result;
}
REX_PPC_HOOK(render_D3DDevice_BeginIndexedVertices_82664640);
#endif

#ifdef DEBUG_BUILD
REX_PPC_EXTERN_IMPORT(render_D3DDevice_DrawIndexedVertices_82664FF0);
void render_D3DDevice_DrawIndexedVertices_82664FF0_Hook(
  int pDevice,
  char PrimitiveType,
  int BaseVertexIndex,
  int StartIndex,
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
    rex::ppc::GuestToHostFunction<void>(
        __imp__rex_render_D3DDevice_DrawIndexedVertices_82664FF0, pDevice, PrimitiveType, BaseVertexIndex, StartIndex,
        IndexCount, IndexDataFormat, VertexStreamZeroStride, ppIndexData, ppVertexData, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28);

    // Capture indexed face data for preview using pending state from BeginIndexedVertices
    if (!REXCVAR_GET(PreviewBeginIndexedVertices) || !g_VertexPreview.pending.valid)
        return;

    auto& p = g_VertexPreview.pending;
    uint8_t* guestBase = reinterpret_cast<uint8_t*>(GUEST_MEM_BASE);

    if (IndexCount == 0 || p.stride < 12 || p.stride > MAX_SANE_STRIDE)
        return;

    // D3DFMT_INDEX16 = 101, D3DFMT_INDEX32 = 102
    bool is32bit = (p.indexFormat == 102);
    uint32_t indexSize = is32bit ? 4 : 2;

    uint64_t idxOffset = static_cast<uint64_t>(StartIndex) * indexSize;
    uint64_t idxBytes = idxOffset + static_cast<uint64_t>(IndexCount) * indexSize;
    uint64_t vertBytes = static_cast<uint64_t>(p.numVertices) * p.stride;

    if (!p.idxBufGuestPtr || !p.vertBufGuestPtr ||
        !IsGuestRangeValid(p.idxBufGuestPtr, idxBytes) ||
        !IsGuestRangeValid(p.vertBufGuestPtr, vertBytes))
        return;

    uint8_t* idxData = guestBase + p.idxBufGuestPtr + idxOffset;
    uint8_t* vertData = guestBase + p.vertBufGuestPtr;

    // Read vertex positions
    uint32_t safeNumVerts = std::min(p.numVertices, MAX_PREVIEW_VERTS);
    std::vector<glm::vec3> vertPositions(safeNumVerts);
    for (uint32_t i = 0; i < safeNumVerts; i++) {
        uint8_t* vp = vertData + i * p.stride;
        float x = to_byteswapped_float(*reinterpret_cast<float*>(vp + 0));
        float y = to_byteswapped_float(*reinterpret_cast<float*>(vp + 4));
        float z = to_byteswapped_float(*reinterpret_cast<float*>(vp + 8));
        if (std::isfinite(x) && std::isfinite(y) && std::isfinite(z)) {
            vertPositions[i] = glm::vec3(x, y, z);
        }
    }

    // Read raw indices and apply BaseVertexIndex
    uint32_t safeIndexCount = std::min(IndexCount, MAX_PREVIEW_VERTS * 3);
    std::vector<uint32_t> rawIndices(safeIndexCount);
    bool indicesValid = true;
    for (uint32_t i = 0; i < safeIndexCount; i++) {
        uint32_t idx;
        if (is32bit) {
            idx = std::byteswap(*reinterpret_cast<uint32_t*>(idxData + i * 4));
        } else {
            idx = std::byteswap(*reinterpret_cast<uint16_t*>(idxData + i * 2));
        }
        int32_t adjusted = static_cast<int32_t>(idx) + BaseVertexIndex;
        if (adjusted < 0 || static_cast<uint32_t>(adjusted) >= safeNumVerts) {
            indicesValid = false;
            break;
        }
        rawIndices[i] = static_cast<uint32_t>(adjusted);
    }
    if (!indicesValid) return;

    // Convert to triangle list based on primitive type
    std::vector<uint32_t> triIndices;
    switch (PrimitiveType) {
        case 4: // D3DPT_TRIANGLELIST
            triIndices = std::move(rawIndices);
            break;
        case 6: // D3DPT_TRIANGLESTRIP
            triIndices.reserve((safeIndexCount - 2) * 3);
            for (uint32_t i = 2; i < safeIndexCount; i++) {
                if (i % 2 == 0) {
                    triIndices.push_back(rawIndices[i-2]);
                    triIndices.push_back(rawIndices[i-1]);
                    triIndices.push_back(rawIndices[i]);
                } else {
                    triIndices.push_back(rawIndices[i-1]);
                    triIndices.push_back(rawIndices[i-2]);
                    triIndices.push_back(rawIndices[i]);
                }
            }
            break;
        case 5: // D3DPT_TRIANGLEFAN
            triIndices.reserve((safeIndexCount - 2) * 3);
            for (uint32_t i = 2; i < safeIndexCount; i++) {
                triIndices.push_back(rawIndices[0]);
                triIndices.push_back(rawIndices[i-1]);
                triIndices.push_back(rawIndices[i]);
            }
            break;
        case 13: // D3DPT_QUADLIST
            triIndices.reserve((safeIndexCount / 4) * 6);
            for (uint32_t i = 0; i + 3 < safeIndexCount; i += 4) {
                triIndices.push_back(rawIndices[i]);
                triIndices.push_back(rawIndices[i+1]);
                triIndices.push_back(rawIndices[i+2]);
                triIndices.push_back(rawIndices[i]);
                triIndices.push_back(rawIndices[i+2]);
                triIndices.push_back(rawIndices[i+3]);
            }
            break;
        default:
            return; // unsupported primitive type
    }

    if (!triIndices.empty()) {
        g_VertexPreview.PushIndexedMesh(vertPositions, triIndices);
    }
}
REX_PPC_HOOK(render_D3DDevice_DrawIndexedVertices_82664FF0);

#endif


//supportFrustumConstructClippingFrustum_8228BE08
REX_PPC_EXTERN_IMPORT(supportFrustumConstructClippingFrustum_8228BE08);
void supportFrustumConstructClippingFrustum_8228BE08_Hook(double a1,double a2,double a3,double a4,int a5,int a6,int a7,int a8,float *a9,float *a10) {
    Log(LogLevel::Info, "supportFrustumConstructClippingFrustum Hook Hit");
    float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    if(REXCVAR_GET(UseAspectRatioFromConfig)) {
      a2 = customAR;
    }
    rex::ppc::GuestToHostFunction<void>(__imp__rex_supportFrustumConstructClippingFrustum_8228BE08, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    Log(LogLevel::Info, "supportFrustumConstructClippingFrustum Hook Finished");
}
REX_PPC_HOOK(supportFrustumConstructClippingFrustum_8228BE08);


REX_PPC_EXTERN_IMPORT(camMainPostDrawLetterbox_821F0910);
int camMainPostDrawLetterbox_821F0910_Hook(){
    Log(LogLevel::Info, "camMainPostDrawLetterbox Hook Hit");
  //float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
  //float* flt_821612EC = reinterpret_cast<float*>(0x100000000ull + 0x821612EC);
  //*flt_821612EC = 1.0f;
  return 1;
}
REX_PPC_HOOK(camMainPostDrawLetterbox_821F0910);

REX_PPC_EXTERN_IMPORT(mlMtxPerspective_82247408);
void mlMtxPerspective_82247408_Hook(float* outMtx, float fov, float aspectRatio, float nearZ, float farZ) {
    Log(LogLevel::Info, "mlMtxPerspective Hook Hit");
    float customAR = aspectRatio;
    if(REXCVAR_GET(UseAspectRatioFromConfig)) {
      customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    }
    rex::ppc::GuestToHostFunction<void>(__imp__rex_mlMtxPerspective_82247408, outMtx, fov, customAR, nearZ, farZ);
    Log(LogLevel::Info, "mlMtxPerspective Hook Finished");
}
REX_PPC_HOOK(mlMtxPerspective_82247408);


REX_PPC_EXTERN_IMPORT(meUpdateOutputViewport_821F0F30);
int meUpdateOutputViewport_821F0F30_Hook() {
    Log(LogLevel::Info, "meUpdateOutputViewport Hook Hit");
    int result = rex::ppc::GuestToHostFunction<int>(__imp__rex_meUpdateOutputViewport_821F0F30);
    if(REXCVAR_GET(UseAspectRatioFromConfig)) {
        Log(LogLevel::Info, "Updating Aspect Ratio in meUpdateOutputViewport");
        float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
        float* aspectRatioPtr = reinterpret_cast<float*>(0x100000000ull + 0x82C34F00);
        *aspectRatioPtr = to_byteswapped_float(customAR);
        Log(LogLevel::Info, "Aspect Ratio Updated in meUpdateOutputViewport");
    }
    
    Log(LogLevel::Info, "meUpdateOutputViewport Hook Finished");
    return result;
}
REX_PPC_HOOK(meUpdateOutputViewport_821F0F30);

void AspectRatio_hook(PPCRegister& r3) {
  if(REXCVAR_GET(UseAspectRatioFromConfig)) {
    
    Log(LogLevel::Info, "Aspect Ratio Hook Hit");
    //r3.u32 + 0x399C | *(float *)&r3+0x399C = AspectRatio;
    float customAR = static_cast<float>(REXCVAR_GET(AspectRatio));
    if(r3.u32){
      float* aspectRatioPtr = reinterpret_cast<float*>(0x100000000ull + r3.u32 + 0x399C);
      *aspectRatioPtr = to_byteswapped_float(customAR);
    }
    Log(LogLevel::Info, "Aspect Ratio Hook Finished");
  }
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

#ifdef _DEBUG
// Hook for sub_826645F8 - DrawVerticesUP (non-indexed immediate vertex draw)
// Captures vertex positions and forwards them to the VertexPreviewActor

REX_PPC_EXTERN_IMPORT(render_D3DDevice_DrawVerticesUP_826645F8);
uint32_t render_D3DDevice_DrawVerticesUP_826645F8_Hook(
    uint32_t pDevice,
    uint32_t PrimitiveType,
    uint32_t VertexCount,
    uint32_t pVertexData,
    uint32_t VertexStreamZeroStride)
{
    // Call the original function first - always forward regardless of preview state
    uint32_t result = rex::ppc::GuestToHostFunction<uint32_t>(
        __imp__rex_render_D3DDevice_DrawVerticesUP_826645F8,
        pDevice, PrimitiveType, VertexCount, pVertexData, VertexStreamZeroStride);

    
    // If preview is enabled, capture vertex positions
    if (!REXCVAR_GET(PreviewDrawVerticesUP)) {
        return result;
    }

    g_VertexPreview.enabled = true;

    // Sanity checks
    if (!pVertexData || VertexCount == 0 || VertexStreamZeroStride < 12 || VertexStreamZeroStride > MAX_SANE_STRIDE) {
        return result;
    }

    uint32_t safeCount = std::min(VertexCount, MAX_PREVIEW_VERTS);
    uint64_t totalBytes = static_cast<uint64_t>(safeCount) * VertexStreamZeroStride;

    if (!IsGuestRangeValid(pVertexData, totalBytes)) {
        return result;
    }

    uint8_t* vertData = reinterpret_cast<uint8_t*>(GUEST_MEM_BASE) + pVertexData;

    for (uint32_t i = 0; i < safeCount; i++) {
        uint8_t* vertPtr = vertData + (i * VertexStreamZeroStride);

        float x = to_byteswapped_float(*reinterpret_cast<float*>(vertPtr + 0));
        float y = to_byteswapped_float(*reinterpret_cast<float*>(vertPtr + 4));
        float z = to_byteswapped_float(*reinterpret_cast<float*>(vertPtr + 8));

        // Skip NaN/Inf vertices
        if (std::isfinite(x) && std::isfinite(y) && std::isfinite(z)) {
            g_VertexPreview.Push(glm::vec3(x, y, z));
        }
    }

    return result;
}
REX_PPC_HOOK(render_D3DDevice_DrawVerticesUP_826645F8);
#endif

#ifdef DEBUG_BUILD
// Hook for XUI non-indexed draw
REX_PPC_EXTERN_IMPORT(ui_Xui_XuiDevice_DrawPrimitiveUP_826EC800);
int ui_Xui_XuiDevice_DrawPrimitiveUP_826EC800_Hook(
    uint32_t a1,      // XuiDevice*
    uint32_t a2,      // PrimitiveType
    uint32_t a3,      // PrimitiveCount
    uint32_t a4,      // pVertexData (guest ptr)
    uint32_t a5)      // VertexStride
{
    int result = rex::ppc::GuestToHostFunction<int>(
        __imp__rex_ui_Xui_XuiDevice_DrawPrimitiveUP_826EC800,
        a1, a2, a3, a4, a5);

    if (!REXCVAR_GET(PreviewXuiDraw)) return result;

    g_VertexPreview.enabled = true;

    // Compute vertex count: multiplier * primitiveCount + extra
    uint32_t vertexCount = 0;
    switch (a2) {
        case 1:  vertexCount = a3; break;           // POINTLIST
        case 2:  vertexCount = a3 * 2; break;       // LINELIST
        case 3:  vertexCount = a3 + 1; break;       // LINESTRIP
        case 4:  vertexCount = a3 * 3; break;       // TRIANGLELIST
        case 5:  vertexCount = a3 + 2; break;       // TRIANGLEFAN
        case 6:  vertexCount = a3 + 2; break;       // TRIANGLESTRIP
        case 8:  vertexCount = a3 * 3; break;       // RECTLIST
        case 13: vertexCount = a3 * 4; break;       // QUADLIST
        default: return result;
    }

    if (!a4 || vertexCount == 0 || a5 < 12 || a5 > MAX_SANE_STRIDE) return result;

    uint32_t safeCount = std::min(vertexCount, MAX_PREVIEW_VERTS);
    uint64_t totalBytes = static_cast<uint64_t>(safeCount) * a5;
    if (!IsGuestRangeValid(a4, totalBytes)) return result;

    uint8_t* vertData = reinterpret_cast<uint8_t*>(GUEST_MEM_BASE) + a4;

    // Read vertex positions
    std::vector<glm::vec3> positions(safeCount);
    for (uint32_t i = 0; i < safeCount; i++) {
        uint8_t* vp = vertData + i * a5;
        float x = to_byteswapped_float(*reinterpret_cast<float*>(vp + 0));
        float y = to_byteswapped_float(*reinterpret_cast<float*>(vp + 4));
        float z = to_byteswapped_float(*reinterpret_cast<float*>(vp + 8));
        if (std::isfinite(x) && std::isfinite(y) && std::isfinite(z)) {
            positions[i] = glm::vec3(x, y, z);
        }
    }

    // Generate triangle indices from sequential vertices
    std::vector<uint32_t> triIndices;
    switch (a2) {
        case 4: // TRIANGLELIST
            triIndices.resize(safeCount);
            for (uint32_t i = 0; i < safeCount; i++) triIndices[i] = i;
            break;
        case 5: // TRIANGLEFAN
            triIndices.reserve((safeCount - 2) * 3);
            for (uint32_t i = 2; i < safeCount; i++) {
                triIndices.push_back(0);
                triIndices.push_back(i - 1);
                triIndices.push_back(i);
            }
            break;
        case 6: // TRIANGLESTRIP
            triIndices.reserve((safeCount - 2) * 3);
            for (uint32_t i = 2; i < safeCount; i++) {
                if (i % 2 == 0) {
                    triIndices.push_back(i - 2);
                    triIndices.push_back(i - 1);
                    triIndices.push_back(i);
                } else {
                    triIndices.push_back(i - 1);
                    triIndices.push_back(i - 2);
                    triIndices.push_back(i);
                }
            }
            break;
        case 13: // QUADLIST
            triIndices.reserve((safeCount / 4) * 6);
            for (uint32_t i = 0; i + 3 < safeCount; i += 4) {
                triIndices.push_back(i);
                triIndices.push_back(i + 1);
                triIndices.push_back(i + 2);
                triIndices.push_back(i);
                triIndices.push_back(i + 2);
                triIndices.push_back(i + 3);
            }
            break;
        default:
            // Point/line types - push as unindexed points
            for (uint32_t i = 0; i < safeCount; i++) {
                g_VertexPreview.Push(positions[i]);
            }
            return result;
    }

    if (!triIndices.empty()) {
        g_VertexPreview.PushIndexedMesh(positions, triIndices);
    }

    return result;
}
REX_PPC_HOOK(ui_Xui_XuiDevice_DrawPrimitiveUP_826EC800);
#endif

#ifdef DEBUG_BUILD
// Hook for sub_82202EE0 - draws a colored quad using BeginVertices
// Vertex format: float x, float y, DWORD color, float u, float v (stride 0x14 = 20 bytes)
// Also captures the world matrix from a6 which is multiplied with projMtx
REXCVAR_DEFINE_BOOL(PreviewDrawColoredQuad, false, "_Trouble in Paradise", "Preview sub_82202EE0 colored quad vertices");

REX_PPC_EXTERN_IMPORT(render_DrawColoredQuad_82202EE0);
uint32_t render_DrawColoredQuad_82202EE0_Hook(
    uint32_t a1,
    uint32_t a2,
    uint32_t a3,
    uint32_t a4,
    uint32_t a5,
    uint32_t a6)
{
    uint32_t result = rex::ppc::GuestToHostFunction<uint32_t>(
        __imp__rex_render_DrawColoredQuad_82202EE0,
        a1, a2, a3, a4, a5, a6);

    if (!REXCVAR_GET(PreviewDrawColoredQuad) || !result) return result;

    g_VertexPreview.enabled = true;

    // result is the guest pointer to the vertex buffer filled by the original function
    // 4 vertices, stride 20: float x, float y, DWORD color, float u, float v
    if (!IsGuestRangeValid(result, 4 * 20)) return result;

    uint8_t* guestBase = reinterpret_cast<uint8_t*>(GUEST_MEM_BASE);
    uint8_t* vertData = guestBase + result;

    std::vector<glm::vec3> positions(4);
    for (int i = 0; i < 4; i++) {
        uint8_t* vp = vertData + i * 20;
        float x = to_byteswapped_float(*reinterpret_cast<float*>(vp + 0));
        float y = to_byteswapped_float(*reinterpret_cast<float*>(vp + 4));
        // z is implicit 0 for this 2D quad
        if (std::isfinite(x) && std::isfinite(y)) {
            positions[i] = glm::vec3(x, y, 0.0f);
        }
    }

    // QUADLIST: 2 triangles from 4 verts
    std::vector<uint32_t> triIndices = {0, 1, 2, 0, 2, 3};
    g_VertexPreview.PushIndexedMesh(positions, triIndices);

    return result;
}
REX_PPC_HOOK(render_DrawColoredQuad_82202EE0);
#endif

#ifdef DEBUG_BUILD
// Hook for sub_822015D8 - draws a centered 2D quad using BeginVertices
// Vertex format: float x, float y, float z(=0), float u, float v (stride 0x14)
REXCVAR_DEFINE_BOOL(PreviewDrawQuad2D, false, "_Trouble in Paradise", "Preview sub_822015D8 2D quad vertices");

REX_PPC_EXTERN_IMPORT(render_DrawQuad2D_822015D8);
uint32_t render_DrawQuad2D_822015D8_Hook(
    uint32_t a1,
    uint32_t a2,
    uint32_t a3,
    uint32_t a4,
    uint32_t a5)
{
    uint32_t result = rex::ppc::GuestToHostFunction<uint32_t>(
        __imp__rex_render_DrawQuad2D_822015D8,
        a1, a2, a3, a4, a5);

    if (!REXCVAR_GET(PreviewDrawQuad2D) || !result) return result;

    g_VertexPreview.enabled = true;

    // 4 verts, stride 20 bytes, format: x, y, z, u, v
    if (!IsGuestRangeValid(result, 4 * 20)) return result;

    uint8_t* guestBase = reinterpret_cast<uint8_t*>(GUEST_MEM_BASE);
    uint8_t* vertData = guestBase + result;

    std::vector<glm::vec3> positions(4);
    for (int i = 0; i < 4; i++) {
        uint8_t* vp = vertData + i * 20;
        float x = to_byteswapped_float(*reinterpret_cast<float*>(vp + 0));
        float y = to_byteswapped_float(*reinterpret_cast<float*>(vp + 4));
        float z = to_byteswapped_float(*reinterpret_cast<float*>(vp + 8));
        if (std::isfinite(x) && std::isfinite(y) && std::isfinite(z)) {
            positions[i] = glm::vec3(x, y, z);
        }
    }

    std::vector<uint32_t> triIndices = {0, 1, 2, 0, 2, 3};
    g_VertexPreview.PushIndexedMesh(positions, triIndices);

    return result;
}
REX_PPC_HOOK(render_DrawQuad2D_822015D8);
#endif

#ifdef DEBUG_BUILD
// Hook for sub_82204AA0 - draws a textured quad with matrix setup
// Vertex format: float x, float y, DWORD color, float u, float v (stride 0x14)
REXCVAR_DEFINE_BOOL(PreviewDrawTexturedQuad, false, "_Trouble in Paradise", "Preview sub_82204AA0 textured quad vertices");

REX_PPC_EXTERN_IMPORT(render_DrawTexturedQuad_82204AA0);
uint32_t render_DrawTexturedQuad_82204AA0_Hook(
    uint32_t a1,
    uint32_t a2,
    uint32_t a3,
    uint32_t a4,
    uint32_t a5,
    uint32_t a6,
    double a7,
    double a8)
{
    uint32_t result = rex::ppc::GuestToHostFunction<uint32_t>(
        __imp__rex_render_DrawTexturedQuad_82204AA0,
        a1, a2, a3, a4, a5, a6, a7, a8);

    if (!REXCVAR_GET(PreviewDrawTexturedQuad) || !result) return result;

    g_VertexPreview.enabled = true;

    // 4 verts, stride 20, format: x, y, DWORD_color, u, v
    if (!IsGuestRangeValid(result, 4 * 20)) return result;

    uint8_t* guestBase = reinterpret_cast<uint8_t*>(GUEST_MEM_BASE);
    uint8_t* vertData = guestBase + result;

    std::vector<glm::vec3> positions(4);
    for (int i = 0; i < 4; i++) {
        uint8_t* vp = vertData + i * 20;
        float x = to_byteswapped_float(*reinterpret_cast<float*>(vp + 0));
        float y = to_byteswapped_float(*reinterpret_cast<float*>(vp + 4));
        if (std::isfinite(x) && std::isfinite(y)) {
            positions[i] = glm::vec3(x, y, 0.0f);
        }
    }

    std::vector<uint32_t> triIndices = {0, 1, 2, 0, 2, 3};
    g_VertexPreview.PushIndexedMesh(positions, triIndices);

    return result;
}
REX_PPC_HOOK(render_DrawTexturedQuad_82204AA0);
#endif
