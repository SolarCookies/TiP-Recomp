#pragma once
#include <rex/ui/window.h>
#include <rex/ui/window_listener.h>

#include <cstdint>
#include <cstdlib>
#include <mutex>
#include <utility>

class TipMouseListener final : public rex::ui::WindowInputListener {
 public:
  explicit TipMouseListener(rex::ui::Window* window) : window_(window) {}

  void OnMouseMove(rex::ui::MouseEvent& e) override {
    std::lock_guard lock(mtx_);
    int32_t x = e.x();
    int32_t y = e.y();

    if (!received_first_event_) {
      prev_x_ = x;
      prev_y_ = y;
      received_first_event_ = true;
      return;
    }

    int32_t actual_dx = x - prev_x_;
    int32_t actual_dy = y - prev_y_;

    constexpr int32_t kRecenterTolerance = 4;
    constexpr int32_t kTeleportThreshold = 200;
    int32_t cx = static_cast<int32_t>(window_->GetActualLogicalWidth() / 2);
    int32_t cy = static_cast<int32_t>(window_->GetActualLogicalHeight() / 2);
    bool near_center = std::abs(x - cx) <= kRecenterTolerance && std::abs(y - cy) <= kRecenterTolerance;
    bool huge_delta = std::abs(actual_dx) > kTeleportThreshold || std::abs(actual_dy) > kTeleportThreshold;
    if (near_center && huge_delta) {
      prev_x_ = x;
      prev_y_ = y;
      return;
    }

    dx_ += actual_dx;
    dy_ += actual_dy;
    prev_x_ = x;
    prev_y_ = y;
  }

  void OnMouseWheel(rex::ui::MouseEvent& e) override {
    std::lock_guard lock(mtx_);
    wheel_ += e.scroll_y();
  }

  std::pair<int32_t, int32_t> ConsumeDelta() {
    std::lock_guard lock(mtx_);
    int32_t dx = dx_;
    int32_t dy = dy_;
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
    int32_t w = wheel_;
    wheel_ = 0;
    return w;
  }

 private:
  rex::ui::Window* window_;
  std::mutex mtx_;
  int32_t dx_ = 0;
  int32_t dy_ = 0;
  int32_t wheel_ = 0;
  int32_t prev_x_ = 0;
  int32_t prev_y_ = 0;
  bool received_first_event_ = false;
};
