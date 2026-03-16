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
    uint32_t ms;
    std::string message;
};

inline std::vector<LogPacket> logMessages;


class LogOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit LogOverlayDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer) {}

    void OnDraw(ImGuiIO& io) override {
        ImGui::Begin("Log Overlay");
        //ImGui::SetWindowPos(ImVec2(10.0f, 50.0f));
        //ImGui::SetWindowBgAlpha(0.0f);
        //ImGui::Text("Number of messages: %d", (int)logMessages.size());
        for (const auto& packet : logMessages) {
            ImGui::Text("%s", packet.message.c_str());
        }
        ImGui::End();
    }
};

inline void AddLogMessage(std::string message, uint32_t SecondsOnScreen) {
    LogPacket packet;
    packet.ms = SecondsOnScreen * 1000; // Convert seconds to milliseconds
    packet.message = message;
    logMessages.push_back(packet);
}

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
        it->ms -= delta.count();
        if (it->ms <= 0) {
            it = logMessages.erase(it);
        } else {
            ++it;
        }
    }

}