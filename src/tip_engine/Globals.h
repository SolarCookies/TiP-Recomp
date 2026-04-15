#pragma once
#include <memory>
#include <rex/input/input_system.h>
#include <rex/ui/virtual_key.h>
#include "tip_engine/CustomRenderer/Window.h"
#include "tip_engine/CustomRenderer/engine/World/Camera.h"

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