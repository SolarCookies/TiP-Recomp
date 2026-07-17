#pragma once
#include "imgui.h"
#include "SmartStyles.h"
#include <string>
#include <functional>
#include <vector>
#include <SDL3/SDL.h>

namespace TiPWidgets {
inline float g_inputCooldownUntil = 0.0f;

inline void SetInputCooldown(float seconds = 0.25f) {
    g_inputCooldownUntil = (float)ImGui::GetTime() + seconds;
}

struct AccelState {
    float holdTime = 0.0f;
    float accumulator = 0.0f;
    void Reset() { holdTime = 0.0f; accumulator = 0.0f; }
};

inline int GetHeldDir(SDL_GamepadButton negBtn, SDL_GamepadButton posBtn, ImGuiKey negKey, ImGuiKey posKey) {
    bool neg = false, pos = false;
    int gamepadCount = 0;
    SDL_JoystickID* gamepadIDs = SDL_GetGamepads(&gamepadCount);
    if (gamepadIDs && gamepadCount > 0) {
        SDL_Gamepad* gp = SDL_OpenGamepad(gamepadIDs[0]);
        if (gp) {
            neg = SDL_GetGamepadButton(gp, negBtn);
            pos = SDL_GetGamepadButton(gp, posBtn);
            SDL_CloseGamepad(gp);
        }
    }
    SDL_free(gamepadIDs);
    if (ImGui::IsKeyDown(negKey)) neg = true;
    if (ImGui::IsKeyDown(posKey)) pos = true;
    if (neg && !pos) return -1;
    if (pos && !neg) return  1;
    return 0;
}

inline int AccelTick(AccelState& state, int dir, float maxSpeed = 30.0f, float rampTime = 1.5f) {
    if (dir == 0 || (float)ImGui::GetTime() < g_inputCooldownUntil) {
        state.Reset();
        return 0;
    }
    float dt = ImGui::GetIO().DeltaTime;
    bool firstFrame = (state.holdTime == 0.0f);
    state.holdTime += dt;

    if (firstFrame) return dir;
    if (state.holdTime <= 0.25f) return 0;

    float accelTime = state.holdTime - 0.25f;
    float t = fminf(accelTime / rampTime, 1.0f);
    float speed = 3.0f + t * t * (maxSpeed - 3.0f);
    state.accumulator += speed * dt * (float)dir;
    int delta = (int)state.accumulator;
    if (delta != 0) state.accumulator -= (float)delta;
    return delta;
}

struct ListInput {
    bool up = false;
    bool down = false;
    bool confirm = false;
    bool back = false;
    bool left = false;
    bool right = false;
};

inline bool IsSelectPressed() {
    int gamepadCount = 0;
    SDL_JoystickID* gamepadIDs = SDL_GetGamepads(&gamepadCount);
    bool pressed = false;
    if (gamepadIDs && gamepadCount > 0) {
        SDL_Gamepad* gp = SDL_OpenGamepad(gamepadIDs[0]);
        if (gp) {
            pressed = SDL_GetGamepadButton(gp, SDL_GAMEPAD_BUTTON_BACK);
            SDL_CloseGamepad(gp);
        }
    }
    SDL_free(gamepadIDs);
    return pressed;
}

inline ListInput PollInput(float& lastInputTime, float repeatDelay = 0.15f) {
    ListInput input;
    float now = (float)ImGui::GetTime();
    if (now - lastInputTime < repeatDelay) return input;
    if (now < g_inputCooldownUntil) return input;

    int gamepadCount = 0;
    SDL_JoystickID* gamepadIDs = SDL_GetGamepads(&gamepadCount);
    if (gamepadIDs && gamepadCount > 0) {
        SDL_Gamepad* gp = SDL_OpenGamepad(gamepadIDs[0]);
        if (gp) {
            if (SDL_GetGamepadButton(gp, SDL_GAMEPAD_BUTTON_DPAD_UP)) input.up = true;
            if (SDL_GetGamepadButton(gp, SDL_GAMEPAD_BUTTON_DPAD_DOWN)) input.down = true;
            if (SDL_GetGamepadButton(gp, SDL_GAMEPAD_BUTTON_DPAD_LEFT)) input.left = true;
            if (SDL_GetGamepadButton(gp, SDL_GAMEPAD_BUTTON_DPAD_RIGHT)) input.right = true;
            if (SDL_GetGamepadButton(gp, SDL_GAMEPAD_BUTTON_SOUTH)) input.confirm = true;
            if (SDL_GetGamepadButton(gp, SDL_GAMEPAD_BUTTON_EAST)) input.back = true;

            SDL_CloseGamepad(gp);
        }
    }
    SDL_free(gamepadIDs);

    if (ImGui::IsKeyPressed(ImGuiKey_UpArrow)) input.up = true;
    if (ImGui::IsKeyPressed(ImGuiKey_DownArrow)) input.down = true;
    if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow)) input.left = true;
    if (ImGui::IsKeyPressed(ImGuiKey_RightArrow)) input.right = true;
    if (ImGui::IsKeyPressed(ImGuiKey_Enter)) input.confirm = true;
    if (ImGui::IsKeyPressed(ImGuiKey_Backspace) && !ImGui::GetIO().WantTextInput) input.back = true;

    if (input.up || input.down || input.confirm || input.back || input.left || input.right) lastInputTime = now;

    return input;
}

inline void WrapIndex(int& index, int count) {
    if (count <= 0) { index = 0; return; }
    index = ((index % count) + count) % count;
}

static constexpr float kWidgetHeight = 28.0f;

inline bool ListButton(const char* label, bool isHighlighted, bool isSelected,
                        float width, float height = kWidgetHeight, bool showArrow = false) {
    ImVec4 btnColor, btnHover, btnActive;
    if (isSelected) {
        btnColor = ImVec4(0.0f, 0.78f, 0.47f, 0.85f);
        btnHover = ImVec4(0.0f, 0.88f, 0.53f, 0.95f);
        btnActive = ImVec4(0.0f, 1.0f, 0.6f, 1.0f);
    } else if (isHighlighted) {
        btnColor = ImVec4(0.15f, 0.15f, 0.15f, 0.9f);
        btnHover = ImVec4(0.25f, 0.25f, 0.25f, 0.95f);
        btnActive = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
    } else {
        btnColor = ImVec4(0.08f, 0.08f, 0.08f, 0.85f);
        btnHover = ImVec4(0.18f, 0.18f, 0.18f, 0.9f);
        btnActive = ImVec4(0.25f, 0.25f, 0.25f, 1.0f);
    }

    ImGui::PushStyleColor(ImGuiCol_Button, btnColor);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, btnHover);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, btnActive);

    if (isHighlighted) {
        ImVec2 cs = ImGui::GetCursorScreenPos();
        ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + 3.0f, cs.y + height), ImColor(0, 255, 150, 255));
    }

    std::string display = label;
    if (showArrow) {
        float arrowW = ImGui::CalcTextSize(">").x;
        float nameW = ImGui::CalcTextSize(label).x;
        float avail = width - nameW - arrowW - 24.0f;
        int padN = (int)(avail / ImGui::CalcTextSize(" ").x);
        if (padN < 1) padN = 1;
        display = std::string(label) + std::string(padN, ' ') + ">";
    }

    bool clicked = ImGui::Button(display.c_str(), ImVec2(width, height));
    ImGui::PopStyleColor(3);
    return clicked;
}

inline bool ColorListButton(const char* label, ImColor color, bool isHighlighted, float width, float height = kWidgetHeight) {
    ImVec4 base = ImVec4(color.Value.x, color.Value.y, color.Value.z, color.Value.w);
    ImVec4 btnColor = WithAlpha(Darken(base, 0.3f), isHighlighted ? 0.9f : 0.6f);
    ImVec4 btnHover = WithAlpha(base, 0.8f);
    ImVec4 btnActive = WithAlpha(Brighten(base, 0.2f), 1.0f);

    ImGui::PushStyleColor(ImGuiCol_Button, btnColor);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, btnHover);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, btnActive);

    if (isHighlighted) {
        ImVec2 cs = ImGui::GetCursorScreenPos();
        ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + 3.0f, cs.y + height), (ImU32)color);
    }

    bool clicked = ImGui::Button(label, ImVec2(width, height));
    ImGui::PopStyleColor(3);
    return clicked;
}

inline bool Dropdown(const char* label, int& currentIndex, const std::vector<const char*>& options, bool isHighlighted, float width, const ListInput& input) {
    ImVec4 bg = isHighlighted ? ImVec4(0.15f, 0.15f, 0.15f, 0.9f) : ImVec4(0.08f, 0.08f, 0.08f, 0.85f);
    ImGui::PushStyleColor(ImGuiCol_Button, bg);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.2f, 0.2f, 0.2f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.25f, 0.25f, 0.25f, 1.0f));

    if (isHighlighted) {
        ImVec2 cs = ImGui::GetCursorScreenPos();
        ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + 3.0f, cs.y + kWidgetHeight), ImColor(0, 255, 150, 255));
    }

    bool changed = false;
    int count = (int)options.size();
    if (count > 0) {
        const char* val = options[currentIndex % count];
        char buf[256];
        snprintf(buf, sizeof(buf), "%s: < %s >", label, val);
        if (ImGui::Button(buf, ImVec2(width, kWidgetHeight))) {
            currentIndex = (currentIndex + 1) % count; changed = true;
        }

        if (isHighlighted) {
            if (input.left)  { currentIndex = (currentIndex - 1 + count) % count; changed = true; }
            if (input.right) { currentIndex = (currentIndex + 1) % count; changed = true; }
        }
    }

    ImGui::PopStyleColor(3);
    return changed;
}

inline bool FloatSlider(const char* label, float& value, float min, float max, float step, bool isHighlighted, float width, float& holdTime, float& accumulator) {
    ImVec4 bg = isHighlighted ? ImVec4(0.15f, 0.15f, 0.15f, 0.9f) : ImVec4(0.08f, 0.08f, 0.08f, 0.85f);

    float textHeight = ImGui::GetTextLineHeightWithSpacing();
    float sliderHeight = kWidgetHeight * 0.5f;
    float totalHeight = textHeight + sliderHeight;
    ImVec2 cs = ImGui::GetCursorScreenPos();

    ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + width, cs.y + totalHeight), ImColor(bg));

    if (isHighlighted) {
        ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + 3.0f, cs.y + totalHeight), ImColor(0, 255, 150, 255));
    }

    float textWidth = ImGui::CalcTextSize(label).x;
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (width - textWidth) * 0.5f);
    ImGui::TextUnformatted(label);

    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.2f, 0.2f, 0.2f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.25f, 0.25f, 0.25f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.0f, 0.78f, 0.47f, 1.0f));
    ImGui::SetNextItemWidth(width);
    char hiddenLabel[128];
    snprintf(hiddenLabel, sizeof(hiddenLabel), "##%s", label);
    bool changed = ImGui::SliderFloat(hiddenLabel, &value, min, max, "%.2f");
    ImGui::PopStyleColor(4);

    float cursorEnd = ImGui::GetCursorScreenPos().y;
    float expectedEnd = cs.y + totalHeight;
    if (cursorEnd < expectedEnd) ImGui::Dummy(ImVec2(0, expectedEnd - cursorEnd));

    if (isHighlighted) {
        int dir = GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_LEFT, SDL_GAMEPAD_BUTTON_DPAD_RIGHT, ImGuiKey_LeftArrow, ImGuiKey_RightArrow);
        if (dir != 0) {
            float dt = ImGui::GetIO().DeltaTime;
            bool firstFrame = (holdTime == 0.0f);
            holdTime += dt;

            if (firstFrame) {
                value += step * (float)dir;
                changed = true;
            } else if (holdTime > 0.25f) {
                float accelTime = holdTime - 0.25f;
                float range = max - min;
                float maxSpeed = fmaxf(range * 0.3f, step * 5.0f);
                float t = fminf(accelTime / 1.5f, 1.0f);
                float speed = step * 2.0f + t * t * (maxSpeed - step * 2.0f);
                accumulator += speed * dt * (float)dir;
                float stepsAccum = accumulator / step;
                int stepsInt = (int)stepsAccum;
                if (stepsInt != 0) {
                    value += step * (float)stepsInt;
                    accumulator -= step * (float)stepsInt;
                    changed = true;
                }
            }
        } else {
            holdTime = 0.0f;
            accumulator = 0.0f;
        }
        if (value < min) value = min;
        if (value > max) value = max;
    }

    return changed;
}

inline bool IntSlider(const char* label, int& value, int min, int max, bool isHighlighted, float width, AccelState& accel) {
    ImVec4 bg = isHighlighted ? ImVec4(0.15f, 0.15f, 0.15f, 0.9f) : ImVec4(0.08f, 0.08f, 0.08f, 0.85f);

    float textHeight = ImGui::GetTextLineHeightWithSpacing();
    float sliderHeight = kWidgetHeight * 0.5f;
    float totalHeight = textHeight + sliderHeight;
    ImVec2 cs = ImGui::GetCursorScreenPos();

    ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + width, cs.y + totalHeight), ImColor(bg));

    if (isHighlighted) {
        ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + 3.0f, cs.y + totalHeight), ImColor(0, 255, 150, 255));
    }

    float textWidth = ImGui::CalcTextSize(label).x;
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (width - textWidth) * 0.5f);
    ImGui::TextUnformatted(label);

    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.2f, 0.2f, 0.2f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.25f, 0.25f, 0.25f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(0.0f, 0.78f, 0.47f, 1.0f));
    ImGui::SetNextItemWidth(width);
    char hiddenLabel[128];
    snprintf(hiddenLabel, sizeof(hiddenLabel), "##%s", label);
    bool changed = ImGui::SliderInt(hiddenLabel, &value, min, max);
    ImGui::PopStyleColor(4);

    float cursorEnd = ImGui::GetCursorScreenPos().y;
    float expectedEnd = cs.y + totalHeight;
    if (cursorEnd < expectedEnd) {
        ImGui::Dummy(ImVec2(0, expectedEnd - cursorEnd));
    }

    if (isHighlighted) {
        int dir = GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_LEFT, SDL_GAMEPAD_BUTTON_DPAD_RIGHT, ImGuiKey_LeftArrow, ImGuiKey_RightArrow);
        float maxSpeed = fmaxf((float)(max - min) * 0.4f, 5.0f);
        int delta = AccelTick(accel, dir, maxSpeed, 2.0f);
        if (delta != 0) {
            value += delta;
            changed = true;
        }
        if (value < min) value = min;
        if (value > max) value = max;
    }

    return changed;
}

inline bool Toggle(const char* label, bool& value, bool isHighlighted, float width, const ListInput& input) {
    ImVec4 bg = isHighlighted ? ImVec4(0.15f, 0.15f, 0.15f, 0.9f) : ImVec4(0.08f, 0.08f, 0.08f, 0.85f);
    ImGui::PushStyleColor(ImGuiCol_Button, bg);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.2f, 0.2f, 0.2f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.25f, 0.25f, 0.25f, 1.0f));

    if (isHighlighted) {
        ImVec2 cs = ImGui::GetCursorScreenPos();
        ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + 3.0f, cs.y + kWidgetHeight), ImColor(0, 255, 150, 255));
    }

    char buf[256];
    snprintf(buf, sizeof(buf), "%s: %s", label, value ? "ON" : "OFF");
    bool clicked = ImGui::Button(buf, ImVec2(width, kWidgetHeight));

    if (clicked || (isHighlighted && input.confirm)) {
        value = !value;
    }

    ImGui::PopStyleColor(3);
    return clicked || (isHighlighted && input.confirm);
}

// Multi-option selector: shows "Label: < Option >". Left/right (or confirm /
// click to advance) cycles through options. Returns true when index changed.
inline bool Cycler(const char* label, int& index, const char* const* options, int optionCount,
                   bool isHighlighted, float width, const ListInput& input) {
    if (optionCount <= 0) return false;
    if (index < 0) index = 0;
    if (index >= optionCount) index = optionCount - 1;

    ImVec4 bg = isHighlighted ? ImVec4(0.15f, 0.15f, 0.15f, 0.9f) : ImVec4(0.08f, 0.08f, 0.08f, 0.85f);
    ImGui::PushStyleColor(ImGuiCol_Button, bg);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.2f, 0.2f, 0.2f, 0.95f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.25f, 0.25f, 0.25f, 1.0f));

    if (isHighlighted) {
        ImVec2 cs = ImGui::GetCursorScreenPos();
        ImGui::GetWindowDrawList()->AddRectFilled(cs, ImVec2(cs.x + 3.0f, cs.y + kWidgetHeight), ImColor(0, 255, 150, 255));
    }

    char buf[256];
    snprintf(buf, sizeof(buf), "%s: < %s >", label, options[index]);
    bool clicked = ImGui::Button(buf, ImVec2(width, kWidgetHeight));

    int dir = 0;
    if (clicked || (isHighlighted && input.confirm)) dir = 1;
    if (isHighlighted && input.left) dir = -1;
    if (isHighlighted && input.right) dir = 1;

    if (dir != 0) {
        index = ((index + dir) % optionCount + optionCount) % optionCount;
    }

    ImGui::PopStyleColor(3);
    return dir != 0;
}

inline void PushListStyle() {
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
}

inline void PopListStyle() {
    ImGui::PopStyleVar(3);
}

}
