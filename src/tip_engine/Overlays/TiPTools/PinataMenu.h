#pragma once


#include "../TiPTools.h"
#include "../TiPWidgets.h"
#include <rex/cvar.h>

REXCVAR_DECLARE(bool, disableSurfacePreferences);

class PinataMenuPage : public TipToolsPage {
public:
	PinataMenuPage() {
		name = "Pinata Settings";
		description = "Pinata related options";
		color = ImColor(255, 105, 180);
	}

	void OnOpen() override {
		focusIndex = 0;
		SyncFromCVars();
	}

	void OnDraw() override;

	void OnClose() override {}

	void SyncFromCVars();
	void SyncToCVars();

	float inputTimer = 0.0f;
	int focusIndex = 0;
	TiPWidgets::AccelState vertAccel;
	int prevFocusIndex = -1;

	// Local state mirroring CVars
	bool disableSurfacePreferences_ = false;
};
