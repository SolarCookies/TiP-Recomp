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