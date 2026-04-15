#pragma once
#include "../World/Camera.h"
#include "../World/World.h"

class ViewportWindow {
public:
	ViewportWindow() = default;
	~ViewportWindow() = default;

	void Draw(float& window_width, float& window_height, Camera& camera, VinceWindow& window, bool isShadowPass, const char* Name = "Viewport");
    

	bool wireframe = false;
	
};
