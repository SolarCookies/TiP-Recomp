#pragma once
#include <memory>
#include <rex/input/input_system.h>
#include <rex/ui/virtual_key.h>
#include "tip_engine/CustomRenderer/Window.h"
#include "tip_engine/CustomRenderer/engine/World/Camera.h"
#include "tip_engine/Input/TipMouseListener.h"
#include "tip_engine/Input/TipRawMouse.h"

class World;

inline float to_byteswapped_float(float f) {
    uint32_t i = std::byteswap(*reinterpret_cast<uint32_t*>(&f));
    return *reinterpret_cast<float*>(&i);
}

inline double to_byteswapped_double(double d) {
    uint64_t i = std::byteswap(*reinterpret_cast<uint64_t*>(&d));
    return *reinterpret_cast<double*>(&i);
}

//inline rex::input::IRawInput* g_raw_input = nullptr;

inline std::unique_ptr<VinceWindow> windowPtr = nullptr;
inline World* g_world = nullptr;
inline std::unique_ptr<class Camera> g_camera = nullptr;

// Main rexglue window handle for overlay tracking
inline void* g_mainWindowHandle = nullptr;

inline bool g_IsPlacingBuilding = false;

// Raw mouse delta + wheel source for camera/zoom hooks; see TipMouseListener.h
inline std::unique_ptr<TipMouseListener> g_mouse_listener = nullptr;

// Win32 raw input handler. Preferred path on Windows because it bypasses
// MnK's cursor centering entirely; see TipRawMouse.h. Null on non-Win32 or
// when raw input setup fails (CursorHooks falls back to g_mouse_listener).
inline std::unique_ptr<TipRawMouse> g_raw_mouse = nullptr;

// ReXGlue input system. Used to hand mouse ownership to host overlays without
// fighting the MnK driver's capture loop.
inline rex::input::InputSystem* g_input_system = nullptr;

// When true, game input (gamepad/keyboard to the guest) should be blocked.
// Set while host UI owns input, such as TiPTools or Alt-unlocked cursor mode.
inline bool g_LockGameInput = false;
inline bool g_RetipInputUiMode = false;
inline bool g_InRomanceMinigame = false;

inline bool IsRetipGameInputActive() {
    if (g_LockGameInput) {
        return false;
    }
    return !g_input_system || g_input_system->IsGameInputActive();
}

inline void SetRetipInputUiMode(bool ui_mode) {
    if (g_RetipInputUiMode == ui_mode) {
        return;
    }

    g_RetipInputUiMode = ui_mode;
    g_LockGameInput = ui_mode;

    if (g_raw_mouse) {
        g_raw_mouse->SetClipEnabled(!ui_mode);
    }

    if (!g_input_system) {
        return;
    }

    g_input_system->SetInputMode(ui_mode ? rex::input::InputMode::kUIOnly
                                         : rex::input::InputMode::kGame);
    g_input_system->SetShowMouseCursor(ui_mode);
}

inline void FlushRetipMouseInput() {
    if (g_raw_mouse) {
        g_raw_mouse->ConsumeDelta();
        g_raw_mouse->ConsumeWheel();
    }

    if (g_mouse_listener) {
        g_mouse_listener->ConsumeDelta();
        g_mouse_listener->ConsumeWheel();
    }
}

inline void SetRetipRomanceMinigame(bool active) {
    if (g_InRomanceMinigame == active) {
        return;
    }

    g_InRomanceMinigame = active;
    FlushRetipMouseInput();
}

inline uint32_t scene = 0;

// Spawn request queued from UI thread, processed on PPC thread by gardenMainGetGardenScene hook
struct SpawnRequest {
    bool pending = false;
    uint32_t tagID = 0;
    float scale = 1.0f;
    bool spawnWild = false;
    int wildcard = 0;   // 0=none, 1-3=wildcard body traits
};
inline SpawnRequest g_SpawnRequest;
inline uint32_t g_LastSpawnedEntity = 0;

// Guest address (uint32_t) of the player position float[3]. Set elsewhere when
// the player's position becomes known; used by the spawn hook to spawn wild
// pinatas at the player's current location.
inline uint32_t playerPos = 0;

// Guest address (uint32_t) of the player rotation. Set alongside playerPos
// from the cursor camera tick hook; used by the spawn hook.
inline uint32_t playerRot = 0;
