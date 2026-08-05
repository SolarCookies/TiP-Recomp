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

#include "FilePicker.h"

#include <thread>
#include <utility>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <shobjidl.h>
#include <vector>
#else
#include <array>
#include <cstdio>
#endif

namespace tip {

namespace {

#ifdef _WIN32

std::string WideToUtf8(const wchar_t* wide) {
    if (!wide || !*wide) return {};
    const int size = WideCharToMultiByte(CP_UTF8, 0, wide, -1, nullptr, 0, nullptr, nullptr);
    if (size <= 1) return {};
    std::string out(size_t(size) - 1, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wide, -1, out.data(), size, nullptr, nullptr);
    return out;
}

std::wstring Utf8ToWide(const std::string& utf8) {
    if (utf8.empty()) return {};
    const int size = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, nullptr, 0);
    if (size <= 1) return {};
    std::wstring out(size_t(size) - 1, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, out.data(), size);
    return out;
}

FilePickResult RunPicker(const std::string& title, const std::string& filterName, const std::string& filterPattern) {
    FilePickResult result;

    const HRESULT init = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    const bool uninitialize = SUCCEEDED(init);

    IFileOpenDialog* dialog = nullptr;
    HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_INPROC_SERVER,
                                  IID_PPV_ARGS(&dialog));
    if (SUCCEEDED(hr)) {
        const std::wstring wideTitle = Utf8ToWide(title);
        const std::wstring wideFilterName = Utf8ToWide(filterName);
        const std::wstring wideFilterPattern = Utf8ToWide(filterPattern);
        if (!wideTitle.empty()) dialog->SetTitle(wideTitle.c_str());

        const COMDLG_FILTERSPEC filters[] = {
            {wideFilterName.c_str(), wideFilterPattern.c_str()},
            {L"All files", L"*.*"},
        };
        dialog->SetFileTypes(ARRAYSIZE(filters), filters);

        DWORD options = 0;
        if (SUCCEEDED(dialog->GetOptions(&options))) {
            dialog->SetOptions(options | FOS_FORCEFILESYSTEM | FOS_FILEMUSTEXIST | FOS_PATHMUSTEXIST | FOS_NOCHANGEDIR);
        }

        hr = dialog->Show(nullptr);
        if (SUCCEEDED(hr)) {
            IShellItem* item = nullptr;
            if (SUCCEEDED(dialog->GetResult(&item)) && item) {
                PWSTR path = nullptr;
                if (SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, &path)) && path) {
                    result.path = WideToUtf8(path);
                    CoTaskMemFree(path);
                }
                item->Release();
            }
            result.ok = true;
        } else if (hr == HRESULT_FROM_WIN32(ERROR_CANCELLED)) {
            result.ok = true;
        } else {
            result.error = "The file picker could not be opened (0x" + std::to_string(static_cast<unsigned long>(hr)) + ").";
        }
        dialog->Release();
    } else {
        result.error = "The file picker could not be created (0x" + std::to_string(static_cast<unsigned long>(hr)) + ").";
    }

    if (uninitialize) CoUninitialize();
    return result;
}

#else

FilePickResult RunPicker(const std::string& title, const std::string& filterName, const std::string& filterPattern) {
    FilePickResult result;
    const std::string commands[] = {
        "zenity --file-selection --title=\"" + title + "\" --file-filter=\"" + filterName + " | " +
            filterPattern + "\" --file-filter=\"All files | *\" 2>/dev/null",
        "kdialog --getopenfilename . \"" + filterPattern + "\" 2>/dev/null",
    };

    for (const std::string& command : commands) {
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) continue;
        std::string output;
        std::array<char, 512> chunk{};
        while (fgets(chunk.data(), int(chunk.size()), pipe)) output += chunk.data();
        const int status = pclose(pipe);
        if (status != 0 && output.empty()) continue;
        while (!output.empty() && (output.back() == '\n' || output.back() == '\r')) output.pop_back();
        result.ok = true;
        result.path = output;
        return result;
    }

    result.error = "No file picker is available. Install zenity or kdialog, or pass the game folder with --game_data_root.";
    return result;
}

#endif

}

void ShowOpenFileDialog(std::string title, std::string filterName, std::string filterPattern, std::function<void(FilePickResult)> done) {
    std::thread([title = std::move(title), filterName = std::move(filterName), filterPattern = std::move(filterPattern), done = std::move(done)]() mutable {
        FilePickResult result = RunPicker(title, filterName, filterPattern);
        if (done) done(std::move(result));
    }).detach();
}

}
