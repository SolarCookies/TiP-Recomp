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

#include <atomic>
#include <cstdint>
#include <filesystem>
#include <mutex>
#include <string>
#include <thread>

namespace tip {

enum class IsoExtractState {
    kIdle,
    kScanning,
    kExtracting,
    kDone,
    kFailed,
};

class IsoExtractor {
public:
    IsoExtractor() = default;
    ~IsoExtractor();

    IsoExtractor(const IsoExtractor&) = delete;
    IsoExtractor& operator=(const IsoExtractor&) = delete;

    static std::string CheckDestinationWritable(const std::filesystem::path& dest);

    bool Start(std::filesystem::path iso, std::filesystem::path dest);

    void Cancel();

    IsoExtractState state() const { return state_.load(std::memory_order_acquire); }
    bool running() const {
        IsoExtractState s = state();
        return s == IsoExtractState::kScanning || s == IsoExtractState::kExtracting;
    }

    float progress() const;

    uint64_t bytes_done() const { return bytesDone_.load(std::memory_order_relaxed); }
    uint64_t bytes_total() const { return bytesTotal_.load(std::memory_order_relaxed); }
    uint32_t files_done() const { return filesDone_.load(std::memory_order_relaxed); }
    uint32_t files_total() const { return filesTotal_.load(std::memory_order_relaxed); }

    std::string current_file() const;
    std::string error() const;

private:
    void Run(std::filesystem::path iso, std::filesystem::path dest);
    void SetCurrentFile(const std::string& name);
    void Fail(std::string message);

    std::thread thread_;
    std::atomic<IsoExtractState> state_{IsoExtractState::kIdle};
    std::atomic<bool> cancel_{false};
    std::atomic<uint64_t> bytesDone_{0};
    std::atomic<uint64_t> bytesTotal_{0};
    std::atomic<uint32_t> filesDone_{0};
    std::atomic<uint32_t> filesTotal_{0};

    mutable std::mutex textMutex_;
    std::string currentFile_;
    std::string error_;
};

}
