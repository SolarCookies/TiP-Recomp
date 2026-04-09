#pragma once
#include <rex/ui/imgui_dialog.h>
#include <string>
#include <vector>
#include "imgui.h"

//Probably overkill but eh..
inline void strncpy_s_MultiPlatform(char* dest, size_t destSize, const char* src, size_t count) {
#if defined(_WIN32)
    strncpy_s(dest, destSize, src, count);
#else
    snprintf(dest, destSize, "%.*s", static_cast<int>(count), src);
#endif
}


enum DebugInfoType_e : uint32_t
{
    Bool = 0x0,
    Int = 0x1,
    Float = 0x2,
    String = 0x3,
    Int64 = 0x4,
    Int32 = 0x5
};

struct DebugInfo_s
{
    DebugInfoType_e type;
    char name[128];
    unsigned char valueBuffer[512];
};

inline std::vector<DebugInfo_s> g_debugInfoList;

inline DebugInfo_s* FindDebugInfo(const std::string& name) {
    for (auto& info : g_debugInfoList) {
        if (strncmp(info.name, name.c_str(), sizeof(info.name)) == 0)
            return &info;
    }
    return nullptr;
}

inline void DebugLogBool(const std::string& name, bool value) {
    if (auto* existing = FindDebugInfo(name)) {
        *reinterpret_cast<bool*>(existing->valueBuffer) = value;
        return;
    }
    DebugInfo_s info;
    info.type = DebugInfoType_e::Bool;
    strncpy_s_MultiPlatform(info.name, sizeof(info.name), name.c_str(), sizeof(info.name) - 1);
    *reinterpret_cast<bool*>(info.valueBuffer) = value;
    g_debugInfoList.push_back(info);
}

inline void DebugLogInt(const std::string& name, int value) {
    if (auto* existing = FindDebugInfo(name)) {
        *reinterpret_cast<int*>(existing->valueBuffer) = value;
        return;
    }
    DebugInfo_s info;
    info.type = DebugInfoType_e::Int;
    strncpy_s_MultiPlatform(info.name, sizeof(info.name), name.c_str(), sizeof(info.name) - 1);
    *reinterpret_cast<int*>(info.valueBuffer) = value;
    g_debugInfoList.push_back(info);
}

inline void DebugLogInt32(const std::string& name, uint32_t value) {
    if (auto* existing = FindDebugInfo(name)) {
        *reinterpret_cast<uint32_t*>(existing->valueBuffer) = value;
        return;
    }
    DebugInfo_s info;
    info.type = DebugInfoType_e::Int32;
    strncpy_s_MultiPlatform(info.name, sizeof(info.name), name.c_str(), sizeof(info.name) - 1);
    *reinterpret_cast<uint32_t*>(info.valueBuffer) = value;
    g_debugInfoList.push_back(info);
}

inline void DebugLogInt64(const std::string& name, uint64_t value) {
    if (auto* existing = FindDebugInfo(name)) {
        *reinterpret_cast<uint64_t*>(existing->valueBuffer) = value;
        return;
    }
    DebugInfo_s info;
    info.type = DebugInfoType_e::Int64;
    strncpy_s_MultiPlatform(info.name, sizeof(info.name), name.c_str(), sizeof(info.name) - 1);
    *reinterpret_cast<uint64_t*>(info.valueBuffer) = value;
    g_debugInfoList.push_back(info);
}

inline void DebugLogFloat(const std::string& name, float value) {
    if (auto* existing = FindDebugInfo(name)) {
        *reinterpret_cast<float*>(existing->valueBuffer) = value;
        return;
    }
    DebugInfo_s info;
    info.type = DebugInfoType_e::Float;
    strncpy_s_MultiPlatform(info.name, sizeof(info.name), name.c_str(), sizeof(info.name) - 1);
    *reinterpret_cast<float*>(info.valueBuffer) = value;
    g_debugInfoList.push_back(info);
}

inline void DebugLogString(const std::string& name, const std::string& value) {
    if (auto* existing = FindDebugInfo(name)) {
        strncpy_s_MultiPlatform(reinterpret_cast<char*>(existing->valueBuffer), sizeof(existing->valueBuffer), value.c_str(), sizeof(existing->valueBuffer) - 1);
        return;
    }
    DebugInfo_s info;
    info.type = DebugInfoType_e::String;
    strncpy_s_MultiPlatform(info.name, sizeof(info.name), name.c_str(), sizeof(info.name) - 1);
    strncpy_s_MultiPlatform(reinterpret_cast<char*>(info.valueBuffer), sizeof(info.valueBuffer), value.c_str(), sizeof(info.valueBuffer) - 1);
    g_debugInfoList.push_back(info);
}

inline std::string GetDebugInfoValueString(const DebugInfo_s& info) {
    switch (info.type) {
        case DebugInfoType_e::Bool:
            return *reinterpret_cast<const bool*>(info.valueBuffer) ? "True" : "False";
        case DebugInfoType_e::Int:
            return std::to_string(*reinterpret_cast<const int*>(info.valueBuffer));
        case DebugInfoType_e::Float:
            return std::to_string(*reinterpret_cast<const float*>(info.valueBuffer));
        case DebugInfoType_e::String:
            return std::string(reinterpret_cast<const char*>(info.valueBuffer));
        case DebugInfoType_e::Int64:
            return std::to_string(*reinterpret_cast<const uint64_t*>(info.valueBuffer));
        case DebugInfoType_e::Int32:
            return std::to_string(*reinterpret_cast<const uint32_t*>(info.valueBuffer));
        default:
            return "Unknown Type";
    }
}

class DebugOverlayDialog : public rex::ui::ImGuiDialog {
public:
    explicit DebugOverlayDialog(rex::ui::ImGuiDrawer* drawer)
        : rex::ui::ImGuiDialog(drawer) {}

    void OnDraw(ImGuiIO& io) override{
        ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Always);
        ImGui::SetNextWindowBgAlpha(0.35f);
        ImGui::Begin("Debug Info", nullptr, ImGuiWindowFlags_NoResize);
        for (const auto& info : g_debugInfoList) {
            ImGui::Text("%s: %s", info.name, GetDebugInfoValueString(info).c_str());
        }
        ImGui::End();
    }
};