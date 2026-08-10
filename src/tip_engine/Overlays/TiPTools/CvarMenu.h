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
******************************************************************************
*/

#pragma once

#include "../TiPTools.h"
#include "../TiPWidgets.h"

#include <cstdint>
#include <string>
#include <vector>

#include <rex/cvar.h>

class CvarMenuPage : public TipToolsPage {
public:
    explicit CvarMenuPage(std::string category);

    void OnOpen() override;
    void OnDraw() override;
    void OnClose() override {}

private:
    struct Row {
        std::string name;
        std::string label;
    };

    void RefreshRows();
    bool DrawRow(size_t index, const rex::cvar::FlagEntry& info, bool focused, float width,
                 const TiPWidgets::ListInput& input);

    std::vector<Row> rows_;
    std::vector<TiPWidgets::AccelState> rowAccel_;
    std::vector<float> rowHold_;
    std::vector<float> rowAccum_;
    std::vector<std::vector<char>> textBuffers_;
    std::vector<uint8_t> textActive_;

    float inputTimer_ = 0.0f;
    int focusIndex_ = 0;
    TiPWidgets::AccelState vertAccel_;
    size_t registrySize_ = 0;
};
