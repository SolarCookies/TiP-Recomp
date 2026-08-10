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
