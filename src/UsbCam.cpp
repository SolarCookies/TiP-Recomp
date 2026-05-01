#include <rex/ppc/context.h>
#include <rex/ppc/function.h>
#include "tip_engine/Log.h"

#include <cstdint>
/*
namespace {
// Defaults match the SDK's most common test configuration.  SetCaptureMode
// will overwrite these when the title configures the camera.
uint32_t g_camWidth  = 320;
uint32_t g_camHeight = 240;

// Arbitrary non-zero handle; the wrappers only ever check it for non-zero.
constexpr uint32_t kFakeCamHandle = 0xCA50C001u;
}  // namespace

extern "C" PPC_FUNC(__imp__XUsbcamCreate) {
    (void)base;
    // Write the fake handle into the caller-provided out-parameter (r5 is a
    // guest virtual address).  PPC_STORE_U32 handles endianness.
    if (ctx.r5.u32) {
        PPC_STORE_U32(ctx.r5.u32, kFakeCamHandle);
    }
    ctx.r3.u64 = 0;  // ERROR_SUCCESS
    Log(LogLevel::Error, "XUsbcamCreate called - returning fake handle");
}

extern "C" PPC_FUNC(__imp__XUsbcamDestroy) {
    (void)base;
    ctx.r3.u64 = 0;
    Log(LogLevel::Error, "XUsbcamDestroy called");
}

extern "C" PPC_FUNC(__imp__XUsbcamGetState) {
    (void)base;
    // 2 == XCAMDEVICESTATE_INITIALIZED.  The wrapper at sub_82ACF198 only
    // returns success when GetState reports 2.
    ctx.r3.u64 = 2;
    Log(LogLevel::Error, "XUsbcamGetState called - returning INITIALIZED");
}

extern "C" PPC_FUNC(__imp__XUsbcamSetConfig) {
    (void)base;
    ctx.r3.u64 = 0;
    Log(LogLevel::Error, "XUsbcamSetConfig called");
}

extern "C" PPC_FUNC(__imp__XUsbcamSetView) {
    (void)base;
    ctx.r3.u64 = 0;
    Log(LogLevel::Error, "XUsbcamSetView called");
}

extern "C" PPC_FUNC(__imp__XUsbcamSetCaptureMode) {
    (void)base;
    Log(LogLevel::Error, "XUsbcamSetCaptureMode called");
    // Wrapper packs (width << 16) | height into its arg2 and unpacks it into
    // r6/r7 before the call, so the real width/height live there.
    const uint32_t w = ctx.r6.u32;
    const uint32_t h = ctx.r7.u32;
    if (w && h && w <= 1280 && h <= 960) {
        g_camWidth  = w;
        g_camHeight = h;
    }
    ctx.r3.u64 = 0;
}

extern "C" PPC_FUNC(__imp__XUsbcamReadFrame) {
    // Fill the guest-side frame buffer with a UV gradient encoded in YUY2:
    //   pixel pair = [Y0, U, Y1, V]
    // Y is held high so brightness is constant; U ramps along X (red-ish)
    // and V ramps along Y (green-ish) once the title's YUV->RGB shader runs.
    const uint32_t pBits = ctx.r4.u32;
    const uint32_t pitch = ctx.r5.u32;

    if (pBits != 0) {
        const uint32_t w = g_camWidth;
        const uint32_t h = g_camHeight;
        // Default pitch if the wrapper didn't supply one (YUY2 == 2 bpp).
        const uint32_t rowStride = pitch ? pitch : (w * 2);

        constexpr uint8_t kY = 200;  // bright luma
        for (uint32_t y = 0; y < h; ++y) {
            uint8_t* row = base + pBits + y * rowStride;
            const uint8_t V = static_cast<uint8_t>((y * 255u) / (h ? h : 1));
            for (uint32_t x = 0; x + 1 < w; x += 2) {
                const uint8_t U =
                    static_cast<uint8_t>((x * 255u) / (w ? w : 1));
                row[x * 2 + 0] = kY;  // Y0
                row[x * 2 + 1] = U;   // U
                row[x * 2 + 2] = kY;  // Y1
                row[x * 2 + 3] = V;   // V
            }
        }
    }

    ctx.r3.u64 = 0;  // ERROR_SUCCESS - synchronous completion
    Log(LogLevel::Error, "XUsbcamReadFrame called");
}
*/