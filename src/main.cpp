// retip - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.

#include "generated/retip_config.h"
#include "generated/retip_init.h"

#include <rex/cvar.h>
#include "tip_engine/rex_macros.h"
#include "tip_engine/Log.h"
#include "tip_engine/Types/CursorInstance.h"
#include "tip_engine/Overlays/DebugInfo.h"
#include "retip_app.h"

#include <rex/ppc/types.h>
#include <rex/logging.h>

namespace renut::log {
  inline const rex::LogCategoryId Input = rex::RegisterLogCategory("retip");
}

REX_DEFINE_APP(retip, RetipApp::Create)


int gardenBudgetGetIsTagAvailable_824DC840_Hook(unsigned int tag, int *tagClass) {
  return 1;
}

REX_PPC_HOOK(gardenBudgetGetIsTagAvailable_824DC840);


