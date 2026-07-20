// retip - ReXGlue Recompiled Project

#include "generated/default/retip_init.h"

#include "retip_app.h"
#include <rex/ppc/context.h>
#include <rex/ppc/function.h>

REX_DEFINE_APP(retip, RetipApp::Create)

REX_HOOK_RAW(__imp__XUsbcamGetState) {
    ctx.r3.u64 = 0;
};


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

bool skip_entityAvatarPinataSeedBigBrotherSaysYes_hook() {
  return true; // Always branch to loc_824DDA84
}

REX_HOOK_RAW(rex_gardenBudgetGetIsTagAvailable_824DC840){
    ctx.r3.u32 = 1;
}

//BOOL __fastcall sub_821C21A8(unsigned __int8 a1)
int sub_821C21A8_Hook(unsigned __int8 a1) {
    return 1;
}
//REX_PPC_HOOK(sub_821C21A8);

//int sub_824E1158()
int sub_824E1158_Hook() {
    return 1;
}
//REX_PPC_HOOK(sub_824E1158);