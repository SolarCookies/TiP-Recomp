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
* The core goal of ReTiP is not only to get the software running, but to 
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
