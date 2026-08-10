/**
******************************************************************************
* ReTiP: Viva Pinata Recompiled                                              *
******************************************************************************
* Copyright (c) 2026 SolarCookies. Licensed under custom noncommercial terms.
*
* This software is licensed for non-commercial, private, and educational use 
* only. You may modify, rewrite, and optimize this code provided that full 
* attribution is given to the original authors listed on the project repository. 
* Commercial use is prohibited.
******************************************************************************
*/

#pragma once

#include <cstdint>
#include <atomic>
#include <chrono>
#include <thread>
#include <rex/ui/imgui_dialog.h>
#include <string>
#include "imgui.h"
#include <vector>

#include <rex/cvar.h>
#include <rex/system/kernel_state.h>
#include <rex/logging.h>

namespace renut::log {
  inline const rex::LogCategoryId Input = rex::RegisterLogCategory("retip");
}

#define RETIP_TRACE(...) REXLOG_CAT_TRACE(::renut::log::Input, __VA_ARGS__)
#define RETIP_DEBUG(...) REXLOG_CAT_DEBUG(::renut::log::Input, __VA_ARGS__)
#define RETIP_INFO(...)  REXLOG_CAT_INFO(::renut::log::Input, __VA_ARGS__)
#define RETIP_WARN(...)  REXLOG_CAT_WARN(::renut::log::Input, __VA_ARGS__)
#define RETIP_ERROR(...) REXLOG_CAT_ERROR(::renut::log::Input, __VA_ARGS__)

enum class LogLevel {
    Trace,
    Debug,
    Info,
    Warn,
    Error
};

inline void Log(LogLevel level, const std::string& message) {
    return;
    switch (level) {
        case LogLevel::Trace:
            RETIP_TRACE(message.c_str());
            break;
        case LogLevel::Debug:
            RETIP_DEBUG(message.c_str());
            break;
        case LogLevel::Info:
            RETIP_INFO(message.c_str());
            break;
        case LogLevel::Warn:
            RETIP_WARN(message.c_str());
            break;
        case LogLevel::Error:
            RETIP_ERROR(message.c_str());
            break;
    }
}
