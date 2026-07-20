# retip - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(retip LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(REXGLUE_ENABLE_TEXTURES "Enable texture dumping and replacement" ON)
option(REXGLUE_ENABLE_SHADERS "Enable experimental shader debugging and replacing" ON)


include(generated/rexglue.cmake)

# Sources
set(RETIP_SOURCES
    src/main.cpp
    src/tip_engine/CursorHooks.cpp
    src/tip_engine/hooks.cpp
    src/tip_engine/GraphicsHooks.cpp
    src/tip_engine/Overlays/Fps.cpp
    src/tip_engine/Overlays/LaunchMenu.cpp
    src/tip_engine/Overlays/QuitMenu.cpp
    src/tip_engine/Overlays/TiPTools.cpp
    src/tip_engine/Overlays/TiPTools/SpawnMenu.cpp
    src/tip_engine/Overlays/TiPTools/GraphicsMenu.cpp
    src/tip_engine/Overlays/TiPTools/UpscalingMenu.cpp
    src/tip_engine/Overlays/TiPTools/SettingsMenu.cpp
    src/tip_engine/Overlays/TiPTools/PinataMenu.cpp
    src/tip_engine/Overlays/TiPTools/PlantMenu.cpp
    src/tip_engine/Overlays/TiPTools/PlayerMenu.cpp
    src/tip_engine/Overlays/TiPTools/RuffianMenu.cpp
    src/tip_engine/Overlays/TiPTools/ShovelMenu.cpp
    src/tip_engine/CRT/math.cpp
    src/tip_engine/CRT/assetman.cpp
)

if(WIN32)
    list(APPEND RETIP_SOURCES icon/app.rc)
    add_executable(retip WIN32 ${RETIP_SOURCES})
else()
    add_executable(retip ${RETIP_SOURCES})
endif()

rexglue_setup_target(retip GPU_PLUGINS xenos)
