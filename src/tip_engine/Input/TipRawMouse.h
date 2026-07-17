#pragma once

#include <cstdint>
#include <mutex>
#include <utility>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#endif

class TipRawMouse {
 public:
#ifdef _WIN32
  bool Setup(HWND hwnd) {
    if (active_) return true;
    if (!hwnd) return false;
    hwnd_ = hwnd;

    RAWINPUTDEVICE rid = {};
    rid.usUsagePage = 0x01; //Generic desktop
    rid.usUsage = 0x02; //Mouse
    rid.dwFlags = 0; //Input only when window has focus
    rid.hwndTarget = hwnd;
    if (!RegisterRawInputDevices(&rid, 1, sizeof(rid))) {
      return false;
    }

    s_instance_ = this;
    original_wnd_proc_ = reinterpret_cast<WNDPROC>(SetWindowLongPtrW(
        hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(SubclassedProc)));
    if (!original_wnd_proc_) {
      RAWINPUTDEVICE remove = {0x01, 0x02, RIDEV_REMOVE, nullptr};
      RegisterRawInputDevices(&remove, 1, sizeof(remove));
      s_instance_ = nullptr;
      return false;
    }
    active_ = true;
    ApplyClip();
    return true;
  }

  void Teardown() {
    if (!active_) return;
    ClipCursor(nullptr);
    if (original_wnd_proc_ && hwnd_) {
      SetWindowLongPtrW(hwnd_, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(original_wnd_proc_));
    }
    RAWINPUTDEVICE remove = {0x01, 0x02, RIDEV_REMOVE, nullptr};
    RegisterRawInputDevices(&remove, 1, sizeof(remove));
    active_ = false;
    if (s_instance_ == this) s_instance_ = nullptr;
  }

  void SetClipEnabled(bool enabled) {
    clip_enabled_ = enabled;
    if (enabled) {
      ApplyClip();
    } else {
      ClipCursor(nullptr);
    }
  }

  void ApplyClip() {
    if (!hwnd_ || !clip_enabled_) return;
    // Never confine the cursor unless our window is the foreground window. If
    // the user has clicked away to another app/monitor we must leave the cursor
    // free.
    if (GetForegroundWindow() != hwnd_) return;
    RECT client;
    if (!GetClientRect(hwnd_, &client)) return;
    POINT tl = {client.left, client.top};
    POINT br = {client.right, client.bottom};
    ClientToScreen(hwnd_, &tl);
    ClientToScreen(hwnd_, &br);
    RECT screen = {tl.x, tl.y, br.x, br.y};
    // Don't snap an outside cursor back into the window. This is the Alt-release
    // case: the user held Alt to free the pointer, moved it onto another
    // monitor, and let go while still hovering that other window. Re-clipping
    // here is what teleports the pointer to the edge of the game window and
    // traps it. Skip the clip; it will be re-established via WM_MOUSEMOVE the
    // moment the pointer re-enters our (focused) window.
    POINT cursor;
    if (GetCursorPos(&cursor) && !PtInRect(&screen, cursor)) return;
    ClipCursor(&screen);
  }

  std::pair<int32_t, int32_t> ConsumeDelta() {
    std::lock_guard lock(mtx_);
    int32_t dx = dx_, dy = dy_;
    dx_ = 0;
    dy_ = 0;
    return {dx, dy};
  }

  int32_t ConsumeDx() {
    std::lock_guard lock(mtx_);
    int32_t v = dx_;
    dx_ = 0;
    return v;
  }

  int32_t ConsumeDy() {
    std::lock_guard lock(mtx_);
    int32_t v = dy_;
    dy_ = 0;
    return v;
  }

  int32_t ConsumeWheel() {
    std::lock_guard lock(mtx_);
    int32_t v = wheel_;
    wheel_ = 0;
    return v;
  }
#endif

 private:
#ifdef _WIN32
  static LRESULT CALLBACK SubclassedProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    if (m == WM_ACTIVATEAPP && s_instance_) {
      if (w) {
        s_instance_->ApplyClip();
      } else {
        // Lost focus (Alt-Tab, clicked another app/monitor): free the cursor so
        // it can leave. It re-clips on WM_MOUSEMOVE once we're focused again.
        ClipCursor(nullptr);
      }
    }
    // Re-establish the clip as soon as the pointer re-enters the focused game
    // window. WM_MOUSEMOVE is only delivered while the cursor is over us, and
    // ApplyClip's own guards keep this a no-op unless we're foreground and the
    // pointer is genuinely inside the client rect.
    if (m == WM_MOUSEMOVE && s_instance_) {
      s_instance_->ApplyClip();
    }
    if (m == WM_INPUT && s_instance_) {
      UINT size = 0;
      if (GetRawInputData(reinterpret_cast<HRAWINPUT>(l), RID_INPUT, nullptr, &size, sizeof(RAWINPUTHEADER)) == 0 &&
          size > 0 && size <= sizeof(RAWINPUT) * 2) {
        BYTE buffer[sizeof(RAWINPUT) * 2];
        if (GetRawInputData(reinterpret_cast<HRAWINPUT>(l), RID_INPUT, buffer, &size, sizeof(RAWINPUTHEADER)) == size) {
          RAWINPUT* raw = reinterpret_cast<RAWINPUT*>(buffer);
          if (raw->header.dwType == RIM_TYPEMOUSE) {
            std::lock_guard lock(s_instance_->mtx_);
            if ((raw->data.mouse.usFlags & MOUSE_MOVE_ABSOLUTE) == 0) {
              s_instance_->dx_ += raw->data.mouse.lLastX;
              s_instance_->dy_ += raw->data.mouse.lLastY;
            }
            if (raw->data.mouse.usButtonFlags & RI_MOUSE_WHEEL) {
              s_instance_->wheel_ += static_cast<int16_t>(raw->data.mouse.usButtonData);
            }
          }
        }
      }
    }
    WNDPROC orig = s_instance_ ? s_instance_->original_wnd_proc_ : nullptr;
    if (orig) {
      return CallWindowProcW(orig, h, m, w, l);
    }
    return DefWindowProcW(h, m, w, l);
  }

  static inline TipRawMouse* s_instance_ = nullptr;
  HWND hwnd_ = nullptr;
  WNDPROC original_wnd_proc_ = nullptr;
  bool active_ = false;
  bool clip_enabled_ = true;
#endif

  std::mutex mtx_;
  int32_t dx_ = 0;
  int32_t dy_ = 0;
  int32_t wheel_ = 0;
};
