// retip - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.

#include "generated/retip_config.h"
#include "generated/retip_init.h"
#include "tip_engine/Types/CursorInstance.h"
#include <fstream>

#include "tip_engine/rex_macros.h"
#include <cstdint>
#include <type_traits>
#include "tip_engine/Log.h"

#include <rex/ppc/types.h>
#include "retip_app.h"
#include <rex/logging.h>
#include <iostream>
#include "tip_engine/Overlays/DebugInfo.h"

namespace renut::log {
  inline const rex::LogCategoryId Input = rex::RegisterLogCategory("retip");
}

#define RENUT_TRACE(...) REXLOG_CAT_TRACE(::renut::log::Input, __VA_ARGS__)
#define RENUT_DEBUG(...) REXLOG_CAT_DEBUG(::renut::log::Input, __VA_ARGS__)
#define RENUT_INFO(...)  REXLOG_CAT_INFO(::renut::log::Input, __VA_ARGS__)
#define RENUT_WARN(...)  REXLOG_CAT_WARN(::renut::log::Input, __VA_ARGS__)
#define RENUT_ERROR(...) REXLOG_CAT_ERROR(::renut::log::Input, __VA_ARGS__)

REX_DEFINE_APP(retip, RetipApp::Create)


int gardenBudgetGetIsTagAvailable_824DC840_Hook(unsigned int tag, int *tagClass) {
  return 1;
}

REX_PPC_HOOK(gardenBudgetGetIsTagAvailable_824DC840);


int Sleep_82AFCCF8_Hook(unsigned int ms) {
  //Use thread sleep instead of busy waiting to reduce CPU usage
  //std::this_thread::sleep_for(std::chrono::milliseconds(ms));
  return 0;
}
PPC_HOOK(sub_82AFCCF8, Sleep_82AFCCF8_Hook);

int rex_WaitForSingleObjectEx_Hook(uint32_t handle, uint32_t milliseconds, bool alertable) {
  //Use thread sleep instead of busy waiting to reduce CPU usage
  //std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
  return 0;
}
PPC_HOOK(rex_WaitForSingleObjectEx, rex_WaitForSingleObjectEx_Hook);