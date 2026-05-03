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

//Win32 raw input mouse delta accumulator. Bypasses cursor positioning
//entirely so MnK's SetCursorPos centering does not contaminate motion. Uses
//RegisterRawInputDevices + a subclassed WndProc on the rex window's HWND to
//intercept WM_INPUT and read raw hardware deltas.
//
//Setup is best-effort; if it fails (non-Win32, RegisterRawInputDevices
//returns FALSE, etc) the caller should fall back to TipMouseListener.
class TipRawMouse {
 public:
#ifdef _WIN32
  bool Setup(HWND hwnd) {
    if (active_) return true;
    if (!hwnd) return false;
    hwnd_ = hwnd;

    RAWINPUTDEVICE rid = {};
    rid.usUsagePage = 0x01;  //Generic desktop
    rid.usUsage = 0x02;      //Mouse
    rid.dwFlags = 0;         //Input only when window has focus
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

  void SetClipEnabled(bool enabled) {
    if (clip_enabled_ == enabled) return;
    clip_enabled_ = enabled;
    if (!active_) return;
    if (clip_enabled_) {
      ApplyClip();
    } else {
      ClipCursor(nullptr);
    }
  }

  void Teardown() {
    if (!active_) return;
    ClipCursor(nullptr);
    if (original_wnd_proc_ && hwnd_) {
      SetWindowLongPtrW(hwnd_, GWLP_WNDPROC,
                        reinterpret_cast<LONG_PTR>(original_wnd_proc_));
    }
    RAWINPUTDEVICE remove = {0x01, 0x02, RIDEV_REMOVE, nullptr};
    RegisterRawInputDevices(&remove, 1, sizeof(remove));
    active_ = false;
    if (s_instance_ == this) s_instance_ = nullptr;
  }

  //Confine cursor to window client rect; OS releases on focus loss
  void ApplyClip() {
    if (!clip_enabled_ || !hwnd_) return;
    RECT client;
    if (!GetClientRect(hwnd_, &client)) return;
    POINT tl = {client.left, client.top};
    POINT br = {client.right, client.bottom};
    ClientToScreen(hwnd_, &tl);
    ClientToScreen(hwnd_, &br);
    RECT screen = {tl.x, tl.y, br.x, br.y};
    ClipCursor(&screen);
  }
#else
  //TODO Linux: raw input via XInput2 / wayland-relative-pointer, plus a
  //GrabPointer / pointer-confinement equivalent of ClipCursor. SDK MnK also
  //skips its cursor centering on non-Win32, so on Linux the listener path
  //stalls at screen edges. Setup returning false here makes OnCreateDialogs
  //fall back to TipMouseListener, which is functional but limited.
  bool Setup(void*) { return false; }
  void Teardown() {}
  void SetClipEnabled(bool) {}
#endif

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

 private:
#ifdef _WIN32
  static LRESULT CALLBACK SubclassedProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    //Re-clip on focus regain (OS auto-releases ClipCursor when window deactivates)
    if (m == WM_ACTIVATEAPP && w && s_instance_) {
      s_instance_->ApplyClip();
    }
    if (m == WM_MOUSEWHEEL && s_instance_) {
      std::lock_guard lock(s_instance_->mtx_);
      s_instance_->wheel_ += GET_WHEEL_DELTA_WPARAM(w);
    }
    if (m == WM_INPUT && s_instance_) {
      UINT size = 0;
      if (GetRawInputData(reinterpret_cast<HRAWINPUT>(l), RID_INPUT, nullptr,
                          &size, sizeof(RAWINPUTHEADER)) == 0 &&
          size > 0 && size <= sizeof(RAWINPUT) * 2) {
        BYTE buffer[sizeof(RAWINPUT) * 2];
        if (GetRawInputData(reinterpret_cast<HRAWINPUT>(l), RID_INPUT, buffer,
                            &size, sizeof(RAWINPUTHEADER)) == size) {
          RAWINPUT* raw = reinterpret_cast<RAWINPUT*>(buffer);
          if (raw->header.dwType == RIM_TYPEMOUSE) {
            std::lock_guard lock(s_instance_->mtx_);
            //MOUSE_MOVE_ABSOLUTE indicates a tablet/RDP-style absolute device.
            //Skip those - we want relative-only deltas for camera control.
            if ((raw->data.mouse.usFlags & MOUSE_MOVE_ABSOLUTE) == 0) {
              s_instance_->dx_ += raw->data.mouse.lLastX;
              s_instance_->dy_ += raw->data.mouse.lLastY;
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
