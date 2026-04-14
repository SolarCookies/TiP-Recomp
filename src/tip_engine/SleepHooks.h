#include <cstdint>
#include <cmath>
#include <cstring>
#include <timeapi.h>
#include <rex/cvar.h>
#include <rex/graphics/flags.h>
#include <rex/ppc/types.h>
#include <rex/system/kernel_state.h>
#include <fstream>
#include <thread>
#include <atomic>


inline std::once_flag g_timer_init;

inline void EnableHighResTimer() {
    std::call_once(g_timer_init, [] {
        timeBeginPeriod(1);
        });
}

inline void DisableHighResTimer() {
    timeEndPeriod(1);
    }

// Sleep CRT hook
inline ppc_u32_result_t Sleep_hook(ppc_u32_t ms) {
    EnableHighResTimer();

    if (ms == 0) {
        SwitchToThread();
        return 0;
    }

    auto target = std::chrono::steady_clock::now()
                + std::chrono::milliseconds(uint32_t(ms));

    if (ms >= 2) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(uint32_t(ms)) - std::chrono::microseconds(1500));
    } else {
        // Must yield to OS so lower-priority threads get scheduled
        ::Sleep(1);
    }

    while (std::chrono::steady_clock::now() < target)
        _mm_pause();

    return 0;
}
PPC_HOOK(rex_Sleep_82AFCCF8, Sleep_hook);