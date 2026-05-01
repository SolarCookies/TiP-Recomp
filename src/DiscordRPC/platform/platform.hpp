#pragma once
#ifndef DISCORD_PLATFORM_HPP
#define DISCORD_PLATFORM_HPP

#include <cstdint>

#ifdef _WIN32
    #include "windows.hpp"
#elif defined(__linux__)
    #include "linux.hpp"
#elif defined(__APPLE__)
    #include "macos.hpp"
#else
    #error "Unsupported platform"
#endif

#endif // DISCORD_PLATFORM_HPP