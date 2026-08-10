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

#include <functional>
#include <string>

namespace tip {

struct FilePickResult {
    bool ok = false;
    std::string path;
    std::string error;
};

void ShowOpenFileDialog(std::string title, std::string filterName, std::string filterPattern, std::function<void(FilePickResult)> done);

}
