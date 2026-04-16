#include "Globals.h"
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
#include <SDL3/SDL.h>
#include <thread>
#include <atomic>
#include "tip_engine/Globals.h"

//REXCVAR_DEFINE_INT32(DEBUGYAW, 0, "_Trouble in Paradise", "Debug Yaw");

/*
//rex_meCursorCamCalculatePos_821EBE28
REX_PPC_EXTERN_IMPORT(meCursorCamCalculatePos_821EBE28);
int meCursorCamCalculatePos_821EBE28_Hook(int camera, float *pos) {
    int result = rex::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculatePos_821EBE28, camera, pos);

    //auto [nx, ny] = raw_input->GetMovementInputNormalized();
    float WASD_DeltaX = 0.0f;
    float WASD_DeltaY = 0.0f;
    if (g_raw_input) {
        auto [nx, ny] = g_raw_input->GetMovementInputNormalized();
        WASD_DeltaX = nx * 1.0f;
        WASD_DeltaY = ny * 1.0f;
    }

    float baseX = to_byteswapped_float(pos[0]);
    float baseY = to_byteswapped_float(pos[2]);

    float finalx = baseX + WASD_DeltaX;
    float finaly = baseY + WASD_DeltaY;
    
    //float* posPtr = reinterpret_cast<float*>(camera + 104);
    pos[0] = to_byteswapped_float(finalx);
    pos[2] = to_byteswapped_float(finaly);
    
    return result;
}
REX_PPC_HOOK(meCursorCamCalculatePos_821EBE28)

//rex_meCursorCamCalculateYaw_822C1B18
REX_PPC_EXTERN_IMPORT(meCursorCamCalculateYaw_822C1B18);
int meCursorCamCalculateYaw_822C1B18_Hook(int camera, int controls) {
    int result = rex::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculateYaw_822C1B18, camera, controls);
    float* YawPtr = reinterpret_cast<float*>(0x100000000ull + camera + 32);
    g_raw_input->SetMouseCapture(false);

    auto [nx, ny] = g_raw_input->GetMouseDelta();
    float sensitivity = 1.0f;
    float yawDelta = ny * sensitivity;
    float currentYaw = to_byteswapped_float(*YawPtr);
    float newYaw = currentYaw + yawDelta;

    YawPtr[0] = to_byteswapped_float(newYaw);

    return result;
}
REX_PPC_HOOK(meCursorCamCalculateYaw_822C1B18)

//rex_meCursorCamCalculatePitch_822C1C00
REX_PPC_EXTERN_IMPORT(meCursorCamCalculatePitch_822C1C00);
int meCursorCamCalculatePitch_822C1C00_Hook(int camera, int controls) {
    int result = rex::GuestToHostFunction<int>(__imp__rex_meCursorCamCalculatePitch_822C1C00, camera, controls);
    return result;
}
REX_PPC_HOOK(meCursorCamCalculatePitch_822C1C00)
*/
//rex_meCursorCamCalculateZoom_822C1CE0
REX_PPC_EXTERN_IMPORT(meCursorCamCalculateZoom_822C1CE0);
void meCursorCamCalculateZoom_822C1CE0_Hook(int camera, int controls) {
    
    float* ZoomOutPtr = reinterpret_cast<float*>(0x100000000ull + camera + 84);
    if(!g_IsPlacingBuilding) {
        ZoomOutPtr[0] = to_byteswapped_float(1150.0f); //Further zoom out (Zoom Max)
    }else{
        ZoomOutPtr[0] = to_byteswapped_float(300.0f); //Zoom in when placing building
    }
    float* PitchMaxPtr = reinterpret_cast<float*>(0x100000000ull + camera + 60);
    PitchMaxPtr[0] = to_byteswapped_float(89.0f); //Increase pitch max
    float* PitchMinPtr = reinterpret_cast<float*>(0x100000000ull + camera + 52);
    PitchMinPtr[0] = to_byteswapped_float(-89.0f); //Decrease pitch min
    

    rex::GuestToHostFunction<void>(__imp__rex_meCursorCamCalculateZoom_822C1CE0, camera, controls);
}
REX_PPC_HOOK(meCursorCamCalculateZoom_822C1CE0)

