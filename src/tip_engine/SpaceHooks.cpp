#include "tip_engine/hooks.h"

#include <cstdint>
#include <cmath>
#include <cstring>
#include <chrono>
#include <rex/ui/imgui_dialog.h>
#include "D3DTypes.h"
#include "Log.h"
#include "Overlays/Fps.h"
#include "imgui.h"

#include <rex/cvar.h>
#include "tip_engine/rex_macros.h"
#include <rex/graphics/flags.h>
#include <rex/system/kernel_state.h>
#include "tip_engine/Log.h"
#include "tip_engine/D3DTypes.h"
#include "Overlays/DebugInfo.h"

#include "rex_macros.h"
#include <fstream>
#include <mutex>
#include "tip_engine/Types/CommonTypes.h"
#include <SDL3/SDL.h>
#include <thread>
#include <atomic>
#include "tip_engine/Globals.h"
#include "tip_engine/CustomRenderer/engine/World/World.h"
#include "tip_engine/CustomRenderer/engine/World/Camera.h"
#include "tip_engine/CustomRenderer/engine/Components/Meshes/DynamicMeshComponent.h"

bool Space1_hook() {
  return true; // Always branch to loc_824DC830
}

bool Space2_hook() {
  return true; // Always branch to loc_824DD5C0
}

void Space3_hook(PPCRegister& r3) {
  r3.u32 = 1; // Set r3 to 1
}

void Space4_hook(PPCRegister& r6) {
  r6.u32 = 1; // Set r6 to 1
}

void Space5_hook(PPCRegister& r3) {
  r3.u32 = 0; // Set r3 to 0
}

bool Space6_hook() {
  return true; // Always branch to loc_824DDA84
}

bool Space7_hook() {
  return true; // Always branch to loc_824DDA84
}


/* 12001 */
struct gardenBudgetUnit_sl
{
  unsigned int virtualMemory;
  unsigned int physicalMemory;
  unsigned int dualShadowBuffering;
  unsigned int cubeShadowBuffering;
  unsigned int regularShadowBuffering;
  unsigned int diggableSurfacePreDraw;
  unsigned int mainPassOpaque;
  unsigned int mainPassTransparent;
};

/* 12002 */
struct gardenBudgetClassUnit_sl
{
  unsigned int classLimit[45];
};

void tagUnitsBudget_hook() {
  // Set the budget for each unit class to 9999 (0x270F in hex)
  uint32_t& limit = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8EC + 56);
  uint32_t& limit2 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8EC + 56 + 4);
  //83A5A8A8

  limit = std::byteswap(999999);
  limit2 = std::byteswap(999999);

  for (int i = 0; i < 2; i++) {
    //*reinterpret_cast<uint32_t*>(classLimitPtr + i * 4) = std::byteswap(0);
  }
  DebugLogInt32("BudgetHook", limit);


}

void tagClassUnitsBudget_hook(PPCRegister& r3) {
  //r3.u32 = the ptr to the gardenBudgetClassUnit_sl struct
  if(r3.u32 == 0) {
    return;
  }
  uint32_t* budgetPtr = reinterpret_cast<uint32_t*>(0x100000000 + r3.u32);
  for (int i = 0; i < 2260; i++) {
    budgetPtr[i] = std::byteswap(999);
  }
}

bool meUpdateOccupancyLevels_hook(PPCRegister& fp0){
  uint32_t& limit1 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8A8 + 64);
  uint32_t& limit2 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8A8 + 96);
  uint32_t& limit3 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8A8 + 132);
  uint32_t& limit4 = *reinterpret_cast<uint32_t*>(0x100000000 + 0x83A5A8A8 + 100);
  
  limit1 = std::byteswap(999999);
  limit2 = std::byteswap(999999);
  limit3 = std::byteswap(999999);
  limit4 = std::byteswap(999999);

  gardenBudgetUnit_sl* limits1 = reinterpret_cast<gardenBudgetUnit_sl*>(0x100000000 + 0x83A5A8A8 + 0);
  limits1->virtualMemory = std::byteswap(1282527612);
  limits1->physicalMemory = std::byteswap(1282527612);
  gardenBudgetUnit_sl* limits2 = reinterpret_cast<gardenBudgetUnit_sl*>(0x100000000 + 0x83A5A8A8 + 32);
  limits2->virtualMemory = std::byteswap(1282527612);
  limits2->physicalMemory = std::byteswap(1282527612);
  gardenBudgetUnit_sl* limits3 = reinterpret_cast<gardenBudgetUnit_sl*>(0x100000000 + 0x83A5A8A8 + 64);
  gardenBudgetUnit_sl* limits4 = reinterpret_cast<gardenBudgetUnit_sl*>(0x100000000 + 0x83A5A8A8 + 128);
  limits4->virtualMemory = std::byteswap(1282527612);
  limits4->physicalMemory = std::byteswap(1282527612);
  uint32_t& limit7 = *reinterpret_cast<uint32_t*>(0x100000000ull + 0x83A5A8A8ull + 28028);
  limit7 = 0x0000803F;
  return true;
}

bool skip_entityAvatarPinataSeedBigBrotherSaysYes_hook() {
  return true; // Always branch to loc_824DDA84
}

int gardenBudgetGetIsTagAvailable_824DC840_Hook(unsigned int tag, int *tagClass) {
  return 1;
}

REX_PPC_HOOK(gardenBudgetGetIsTagAvailable_824DC840);

