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

inline auto frameTime1=std::chrono::system_clock::now();
inline int frame1 = 0;

struct LogPacket {
    int32_t ms;
    std::string message;
};

inline std::vector<LogPacket> logMessages;

inline void TickLogMessages() {

    frame1++;
    auto Time = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> delta = Time - frameTime1;
    frameTime1 = Time;
    double fpsfromMS = 1000 / delta.count();
    if (frame1 >= 60) {
        frame1 = 0;
    }
    
    for (auto it = logMessages.begin(); it != logMessages.end();) {
        it->ms -= static_cast<int32_t>(delta.count());
        if (it->ms <= 0) {
            it = logMessages.erase(it);
        } else {
            ++it;
        }
    }

}

class LogOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit LogOverlayDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer) {}

    void OnDraw(ImGuiIO& io) override {
        ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x - 160.0f, 0.0f), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(150.0f, 720.0f), ImGuiCond_FirstUseEver);
        ImGui::Begin("Log Overlay");
        for (auto& packet : logMessages) {
            ImGui::Text("%s", packet.message.c_str());
        }
        if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
            ImGui::SetScrollHereY(1.0f);
        ImGui::End();
        TickLogMessages();
    }
};

inline void Log(std::string message, uint32_t SecondsOnScreen) {
    LogPacket packet;
    packet.ms = SecondsOnScreen * 1000; // Convert seconds to milliseconds
    packet.message = message;
    logMessages.push_back(packet);
    while (logMessages.size() > 100) {
        logMessages.erase(logMessages.begin());
    }
}
