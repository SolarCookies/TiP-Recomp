
# retip - ReXGlue Recompiled Project
#
# This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(retip LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(RETIP_SOURCES
    src/main.cpp
    src/UsbCam.cpp
    src/tip_engine/hooks.cpp
    src/tip_engine/Overlays/Fps.cpp
    src/tip_engine/Overlays/TiPTools.cpp
    src/tip_engine/rex_macros.h
    src/ImPlot/implot.cpp
    src/ImPlot/implot_items.cpp
    src/ImPlot/implot.h
    src/ImPlot/implot_internal.h
    src/tip_engine/CursorHooks.cpp
    src/tip_engine/GraphicsHooks.cpp
    src/tip_engine/SpaceHooks.cpp
    src/tip_engine/DiscordRPC.cpp
    src/tip_engine/DiscordRPC.h

    # Custom Renderer
    src/tip_engine/CustomRenderer/OpenGL_Stuff.h
    src/tip_engine/CustomRenderer/Window.cpp
    src/tip_engine/CustomRenderer/Window.h
    src/tip_engine/CustomRenderer/engine/Shaders/FrameBuffer.cpp
    src/tip_engine/CustomRenderer/engine/Shaders/VBO.cpp
    src/tip_engine/CustomRenderer/engine/Shaders/VAO.cpp
    src/tip_engine/CustomRenderer/engine/Shaders/EBO.cpp
    src/tip_engine/CustomRenderer/engine/Shaders/Texture.cpp
    src/tip_engine/CustomRenderer/engine/Shaders/ShaderClass.cpp
    src/tip_engine/CustomRenderer/engine/World/CameraClass.cpp
    src/tip_engine/CustomRenderer/engine/World/Camera.cpp
    src/tip_engine/CustomRenderer/engine/World/World.cpp
    src/tip_engine/CustomRenderer/engine/Windows/ViewportWindow.cpp
    src/tip_engine/CustomRenderer/engine/Actors/Actor.cpp
    src/tip_engine/CustomRenderer/engine/Components/Component.cpp
    src/tip_engine/CustomRenderer/engine/Components/Meshes/DynamicMeshComponent.cpp
    src/tip_engine/CustomRenderer/engine/Components/Lights/LightComponent.cpp
    src/tip_engine/CustomRenderer/engine/Utils/Crypto/sha256.cpp
    src/tip_engine/Overlays/TiPTools/SpawnMenu.cpp
    src/tip_engine/Overlays/TiPTools/PlayerMenu.cpp
    src/tip_engine/Overlays/TiPTools/GraphicsMenu.cpp
    src/tip_engine/Overlays/TiPTools/SettingsMenu.cpp
    src/tip_engine/Overlays/TiPTools/PinataMenu.cpp
    src/tip_engine/Overlays/TiPTools/PlantMenu.cpp
    src/tip_engine/Overlays/TiPTools/RuffianMenu.cpp
    src/tip_engine/SleepHooks.cpp

    # Vendor sources
    Vendors/glad.c
    Vendors/stb_image/stb_image.cpp
    Vendors/imgui/imgui_impl_glfw.cpp
    Vendors/imgui/imgui_impl_glfw.h
    Vendors/imgui/imgui_impl_opengl3_loader.h
    Vendors/imgui/imgui_impl_opengl3.cpp
    Vendors/imgui/imgui_impl_opengl3.h
    Vendors/imgui/imstb_rectpack.h
    Vendors/imgui/imstb_textedit.h
    Vendors/imgui/imstb_truetype.h
)

if(WIN32)
    list(APPEND RETIP_SOURCES icon/app.rc)
    add_executable(retip WIN32 ${RETIP_SOURCES})
else()
    add_executable(retip ${RETIP_SOURCES})
endif()

rexglue_setup_target(retip)

# Vendor include directories
target_include_directories(retip PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/GLFW/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/glad
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/gli
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/half
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/KHR
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/stb_image
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/zlib_x64-windows-static/include
)

# Vendor libraries
target_link_directories(retip PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/GLFW/lib-vc2022
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendors/zlib_x64-windows-static/lib
)

target_compile_options(retip PRIVATE
    -Wno-missing-template-arg-list-after-template-kw
)

target_link_libraries(retip PRIVATE
    glfw3.lib
    opengl32.lib
    zlib.lib
)
