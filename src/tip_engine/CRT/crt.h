#pragma once

#include <bit>
#include <cstdint>
#include <cstring>
#include <rex/hook.h>
#include <rex/logging.h>
#include <rex/ppc.h>
#include <rex/ppc/context.h>
#include <rex/ppc/function.h>
#include <rex/runtime.h>
#include <rex/system/function_dispatcher.h>
#include <rex/system/thread_state.h>
#include <string>
#include <filesystem>
#include <fstream>

#define REX_PPC_EXTERN_IMPORT(function) \
    REX_EXTERN(__imp__rex_##function)


#define REX_PPC_INVOKE2(return_type, function, ...) \
	rex::ppc::GuestToHostFunction<return_type>(__imp__rex_##function, __VA_ARGS__)


static uint8_t* gm = nullptr;
static inline uint8_t* guest_mem()
{
    if (!gm) gm = rex::Runtime::instance()->memory()->virtual_membase();
    return gm;
}

/* ------- Example of a basic Raw Hook ------- */

// using "unsigned int __fastcall mathAbs(int x)" as an example

//REX_PPC_EXTERN_IMPORT(mathAbs);

//REX_HOOK_RAW(rex_mathAbs)
//{
    //uint32_t x = ctx.r3.u32; //Gets the value of the first argument (x) from the guest register struct 
    
    //__imp__rex_mathAbs(ctx, base); //Calls the original function

    // Rather then calling the original function which would have set r3 to the absolute value of x using translated ppc code
    // We can just set the value of r3 to the absolute value of x using std::abs and then return from the hook that way its ideally faster and more efficient
    //ctx.r3.u32 = std::abs(static_cast<int32_t>(ctx.r3.u32)); 
//}