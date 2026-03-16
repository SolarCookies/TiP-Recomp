# retip - ReXGlue Recompiled Project
#
# This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(retip LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(RETIP_SOURCES
    src/main.cpp
    src/tip_engine/hooks.cpp
    src/tip_engine/rex_macros.h
)

if(WIN32)
    add_executable(retip WIN32 ${RETIP_SOURCES})
else()
    add_executable(retip ${RETIP_SOURCES})
endif()

rexglue_setup_target(retip)

