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
#include <rex/ppc/types.h>
#include <rex/system/kernel_state.h>
#include <rex/ppc/types.h>
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