/** 
******************************************************************************
* ReTiP: Viva Pinata Recompiled                                              *
******************************************************************************
* Copyright (c) 2026 SolarCookies. Licensed under custom noncommercial terms.
*
* This software is licensed for non-commercial, private, and educational use 
* only. You may modify, rewrite, and optimize this code provided that full 
* attribution is given to the original authors listed on the project repository. 
* Commercial use is prohibited.
*
* DISCLAIMER: This software is provided "as-is" without warranty of any kind. 
* This project is an unofficial fan translation layer and does NOT provide, 
* distribute, or package any copyrighted game assets, binaries, or media belonging 
* to Microsoft or Rare. Users must provide their own legally obtained game assets. 
* This software must not be used in any manner that violates Microsoft's copyrights.
* DO NOT REDISTRIBUTE GAME ASSETS OR PROMOTE PIRACY.
*
* AI USE GUIDELINES:
* This project is built with minimal AI usage. We may utilize basic inline code 
* suggestions or rely on AI assistance for debugging, but the vast majority of 
* this codebase is written by hand. We manually decompile functions,
* reverse engineer structs, and write hooks to ensure accuracy and maintainability.
*
* The core goal of ReTiP is not only to get the game running, but to 
* research, document, and learn exactly how the game operates under the hood so that 
* we can provide modding support. We do not support using AI for creative 
* task or problem solving. i.e asking an AI agent to "find a way to 
* make freecam work". Instead, AI should only be used for small, boilerplate tasks or
* parsing a 1000 line crash log to isolate an error. We actively encourage all project 
* contributors to avoid the use of AI agents entirely when writing code or decompiling functions.
*
* The truth of the matter is that AI when used currectly by people who understand the output
* can be incredibly useful just like intelisense, being able to press Tab to autocomplete a
* for loop can save time. However, AI is not a replacement for human understanding and
* should not be used to replace the process of learning and understanding how the game works.
*
* We strongly prefer the use of local models that do not harm the environment and 
* can run entirely on your own local hardware over cloud based AI services. Ultimately, 
* all pull requests and code contributions will be strictly reviewed by people who 
* understand the codebase and the game. If you list Claude or any other AI as a coauthor 
* or contributor, your PR will be rejected regardless of whether it works.
******************************************************************************
*/
#include "Globals.h"
#include "Log.h"
#include "rex_macros.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>

#include <rex/cvar.h>
#include <rex/input/input_system.h>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#endif

REXCVAR_DEFINE_BOOL(FreeCam, false, "TiP/Camera", "Free camera (F9): WASD/QE to fly, mouse to look");
REXCVAR_DEFINE_DOUBLE(FreeCamMoveSpeed, 200.0, "TiP/Camera", "Free camera speed in world units per second").range(1.0, 5000.0);
REXCVAR_DEFINE_DOUBLE(FreeCamSprintScale, 4.0, "TiP/Camera", "Free camera speed multiplier while Shift is held").range(1.0, 25.0);
REXCVAR_DEFINE_DOUBLE(FreeCamSensitivity, 0.08, "TiP/Camera", "Free camera mouse look sensitivity (degrees per mouse count)").range(0.005, 5.0);
REXCVAR_DEFINE_BOOL(FreeCamInvertY, false, "TiP/Camera", "Invert free camera mouse pitch");
REXCVAR_DEFINE_BOOL(FreeCamFreezePlayer, true, "TiP/Camera", "Hold gameplay input while the free camera is active so the player stays put");
REXCVAR_DEFINE_BOOL(FreeCamLockView, false, "TiP/Camera", "Freeze the clipping frustum where it stood when the free camera took off, so culling keeps testing against the player's view");

namespace {

constexpr uint32_t kCamPosOffset = 1496;
constexpr uint32_t kCamRotOffset = 1508;

constexpr float kDegToRad = 0.017453292519943295f;
constexpr float kPitchLimitDeg = 89.0f;

#ifdef _WIN32
constexpr int kKeyShift = VK_SHIFT;
constexpr int kKeyCtrl = VK_CONTROL;
constexpr int kKeySpace = VK_SPACE;
constexpr int kKeyToggle = VK_F9;
#else
constexpr int kKeyShift = 0;
constexpr int kKeyCtrl = 0;
constexpr int kKeySpace = 0;
constexpr int kKeyToggle = 0;
#endif

struct FreeCamState {
  bool active = false;
  uint32_t body = 0;
  float pos[3] = {};
  float rot[3] = {};
  std::chrono::steady_clock::time_point lastTick{};
};

FreeCamState s_cam;
bool s_toggleWasDown = false;

float ReadGuestFloat(uint32_t addr) {
  return to_byteswapped_float(*reinterpret_cast<float*>(0x100000000ull + addr));
}

void WriteGuestFloat(uint32_t addr, float value) {
  *reinterpret_cast<float*>(0x100000000ull + addr) = to_byteswapped_float(value);
}

bool s_rotIsDegrees = false;

float UnitToRadians() { return s_rotIsDegrees ? kDegToRad : 1.0f; }
float DegreesToUnits() { return s_rotIsDegrees ? 1.0f : kDegToRad; }

void ObserveGuestRot(uint32_t body) {
  if (s_rotIsDegrees) return;
  for (int i = 0; i < 3; ++i) {
    if (std::fabs(ReadGuestFloat(body + kCamRotOffset + i * 4)) > 3.2f) {
      s_rotIsDegrees = true;
      RETIP_INFO("FreeCam: guest camera angles measured as degrees");
      return;
    }
  }
}

bool KeyDown(int vk) {
#ifdef _WIN32
  return (GetAsyncKeyState(vk) & 0x8000) != 0;
#else
  (void)vk;
  return false;
#endif
}

bool KeyPressedEdge(int vk, bool& wasDown) {
  const bool down = KeyDown(vk);
  const bool pressed = down && !wasDown;
  wasDown = down;
  return pressed;
}

bool WindowFocused() {
#ifdef _WIN32
  HWND hwnd = static_cast<HWND>(g_mainWindowHandle);
  return !hwnd || GetForegroundWindow() == hwnd;
#else
  return true;
#endif
}

bool CanTakeFreeCamInput() {
  if (!WindowFocused()) return false;
  if (IsRexOverlayOpen() || g_RetipOwnUiMode || g_LaunchMenuOpen || g_QuitConfirmActive ||
      g_StarMenuOpen)
    return false;
  return true;
}

void ApplyPlayerFreeze(bool freeze) {
  if (!g_input_system) return;
  using rex::input::InputMode;
  if (freeze) {
    if (g_input_system->input_mode() == InputMode::kGame) {
      g_input_system->SetInputMode(InputMode::kUIOnly);
      g_input_system->SetShowMouseCursor(false);
    }
  } else if (!g_RetipOwnUiMode && !IsRexOverlayOpen()) {
    g_input_system->SetInputMode(InputMode::kGame);
  }
}

void ConsumeMouseLook(int32_t& dx, int32_t& dy) {
  dx = 0;
  dy = 0;
  if (g_raw_mouse) {
    dx = g_raw_mouse->ConsumeDx();
    dy = g_raw_mouse->ConsumeDy();
  } else if (g_mouse_listener) {
    dx = g_mouse_listener->ConsumeDx();
    dy = g_mouse_listener->ConsumeDy();
  }
}

void Activate(uint32_t body) {
  s_cam.active = true;
  s_cam.body = body;
  for (int i = 0; i < 3; ++i) {
    s_cam.pos[i] = ReadGuestFloat(body + kCamPosOffset + i * 4);
    s_cam.rot[i] = ReadGuestFloat(body + kCamRotOffset + i * 4);
  }
  const float pitchLimit = kPitchLimitDeg * DegreesToUnits();
  s_cam.rot[0] = std::clamp(s_cam.rot[0], -pitchLimit, pitchLimit);
  s_cam.lastTick = std::chrono::steady_clock::now();
  g_FreeCamActive = true;
  FlushRetipMouseInput();
  RETIP_INFO("FreeCam on: body {:#x} pos ({:.1f}, {:.1f}, {:.1f}) rot P{:.3f} Y{:.3f} R{:.3f}",
             body, s_cam.pos[0], s_cam.pos[1], s_cam.pos[2],
             s_cam.rot[0], s_cam.rot[1], s_cam.rot[2]);
}

void Deactivate() {
  s_cam.active = false;
  s_cam.body = 0;
  g_FreeCamActive = false;
  g_FreeCamLockView = false;
  ApplyPlayerFreeze(false);
  FlushRetipMouseInput();
  RETIP_INFO("FreeCam off");
}

void Step(float dt, bool takeInput) {
  const float unitToRad = UnitToRadians();
  const float degToUnits = DegreesToUnits();

  if (takeInput) {
    int32_t dx = 0;
    int32_t dy = 0;
    ConsumeMouseLook(dx, dy);

    const float sensitivity = static_cast<float>(REXCVAR_GET(FreeCamSensitivity)) * degToUnits;
    const float pitchSign = REXCVAR_GET(FreeCamInvertY) ? -1.0f : 1.0f;

    s_cam.rot[1] -= static_cast<float>(dx) * sensitivity;
    s_cam.rot[0] -= static_cast<float>(dy) * sensitivity * pitchSign;

    const float pitchLimit = kPitchLimitDeg * degToUnits;
    s_cam.rot[0] = std::clamp(s_cam.rot[0], -pitchLimit, pitchLimit);

    const float turn = 360.0f * degToUnits;
    s_cam.rot[1] = std::fmod(s_cam.rot[1], turn);
    if (s_cam.rot[1] < 0.0f) s_cam.rot[1] += turn;
  }

  if (!takeInput) return;

  const float pitch = s_cam.rot[0] * unitToRad;
  const float yaw = s_cam.rot[1] * unitToRad;
  const float cp = std::cos(pitch);
  const float sp = std::sin(pitch);
  const float cy = std::cos(yaw);
  const float sy = std::sin(yaw);

  const float forward[3] = {-cp * sy, sp, -cp * cy};
  const float right[3] = {cy, 0.0f, -sy};

  const float axisForward = (KeyDown('W') ? 1.0f : 0.0f) - (KeyDown('S') ? 1.0f : 0.0f);
  const float axisRight = (KeyDown('D') ? 1.0f : 0.0f) - (KeyDown('A') ? 1.0f : 0.0f);
  const float axisUp = ((KeyDown('E') || KeyDown(kKeySpace)) ? 1.0f : 0.0f) -
                       ((KeyDown('Q') || KeyDown(kKeyCtrl)) ? 1.0f : 0.0f);
  if (axisForward == 0.0f && axisRight == 0.0f && axisUp == 0.0f) return;

  float move[3] = {
      forward[0] * axisForward + right[0] * axisRight,
      forward[1] * axisForward + right[1] * axisRight + axisUp,
      forward[2] * axisForward + right[2] * axisRight,
  };

  const float length = std::sqrt(move[0] * move[0] + move[1] * move[1] + move[2] * move[2]);
  if (length > 1.0f) {
    move[0] /= length;
    move[1] /= length;
    move[2] /= length;
  }

  float speed = static_cast<float>(REXCVAR_GET(FreeCamMoveSpeed));
  if (KeyDown(kKeyShift)) speed *= static_cast<float>(REXCVAR_GET(FreeCamSprintScale));
  const float distance = speed * dt;

  s_cam.pos[0] += move[0] * distance;
  s_cam.pos[1] += move[1] * distance;
  s_cam.pos[2] += move[2] * distance;
}

void PollToggle() {
  if (!CanTakeFreeCamInput()) {
    s_toggleWasDown = KeyDown(kKeyToggle);
    return;
  }
  if (KeyPressedEdge(kKeyToggle, s_toggleWasDown)) {
    REXCVAR_SET(FreeCam, !REXCVAR_GET(FreeCam));
  }
}

void UpdateFreeCam(uint32_t body) {
  if (!REXCVAR_GET(FreeCam) || body == 0) {
    if (s_cam.active) Deactivate();
    return;
  }

  if (!s_cam.active) {
    Activate(body);
  } else if (body != s_cam.body) {
    return;
  }

  ApplyPlayerFreeze(REXCVAR_GET(FreeCamFreezePlayer));
  g_FreeCamLockView = REXCVAR_GET(FreeCamLockView);

  const auto now = std::chrono::steady_clock::now();
  float dt = std::chrono::duration<float>(now - s_cam.lastTick).count();
  s_cam.lastTick = now;
  dt = std::clamp(dt, 0.0f, 0.1f);

  Step(dt, CanTakeFreeCamInput());

  for (int i = 0; i < 3; ++i) {
    WriteGuestFloat(body + kCamPosOffset + i * 4, s_cam.pos[i]);
    WriteGuestFloat(body + kCamRotOffset + i * 4, s_cam.rot[i]);
  }
}

}

REX_EXTERN(__imp__rex_entityBodyPincamInstUpdateCamPosRot_8238E2E0);
REX_HOOK_RAW(rex_entityBodyPincamInstUpdateCamPosRot_8238E2E0) {
  const uint32_t cameraBody = ctx.r3.u32;
  __imp__rex_entityBodyPincamInstUpdateCamPosRot_8238E2E0(ctx, base);
  if (cameraBody) ObserveGuestRot(cameraBody);
  PollToggle();
  UpdateFreeCam(cameraBody);
}
