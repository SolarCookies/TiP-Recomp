#pragma once
#include <memory>
#include <rex/input/input_system.h>
#include <rex/ui/virtual_key.h>
#include "tip_engine/Input/TipMouseListener.h"
#include "tip_engine/Input/TipRawMouse.h"

inline float to_byteswapped_float(float f) {
    uint32_t i = std::byteswap(*reinterpret_cast<uint32_t*>(&f));
    return *reinterpret_cast<float*>(&i);
}

inline double to_byteswapped_double(double d) {
    uint64_t i = std::byteswap(*reinterpret_cast<uint64_t*>(&d));
    return *reinterpret_cast<double*>(&i);
}

//inline rex::input::IRawInput* g_raw_input = nullptr;

inline void* g_mainWindowHandle = nullptr;

inline bool g_IsPlacingBuilding = false;

inline std::unique_ptr<TipMouseListener> g_mouse_listener = nullptr;

inline std::unique_ptr<TipRawMouse> g_raw_mouse = nullptr;

inline rex::input::InputSystem* g_input_system = nullptr;

inline bool g_LockGameInput = false;
inline bool g_RetipInputUiMode = false;
inline bool g_LaunchMenuOpen = false;
inline bool g_InRomanceMinigame = false;
inline bool g_QuitConfirmActive = false;

inline bool IsRetipGameInputActive() {
    if (g_LockGameInput) {
        return false;
    }
    if (g_input_system && g_input_system->input_mode() != rex::input::InputMode::kGame) {
        return false;
    }
    return true;
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

    g_input_system->SetInputMode(ui_mode ? rex::input::InputMode::kUIOnly : rex::input::InputMode::kGame);
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

struct SpawnRequest {
    bool pending = false;
    uint32_t tagID = 0;
    float scale = 1.0f;
    bool spawnWild = false;
    int wildcard = 0;   // 0=none, 1-3=wildcard body traits
};

inline SpawnRequest g_SpawnRequest;
inline uint32_t g_LastSpawnedEntity = 0;

inline uint32_t playerPos = 0;
inline uint32_t playerRot = 0;
