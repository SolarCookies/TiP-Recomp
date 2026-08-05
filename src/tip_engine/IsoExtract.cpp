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

#include "IsoExtract.h"

#include "Log.h"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <fstream>
#include <system_error>
#include <unordered_set>
#include <vector>

namespace tip {

namespace fs = std::filesystem;

namespace {

constexpr uint32_t kSectorSize = 2048;
constexpr size_t kDirentHeaderSize = 0xe;
constexpr uint64_t kVolumeSector = 32;
constexpr uint8_t kAttrDirectory = 0x10;

constexpr uint64_t kPartitionOffsets[] = {
    0,
    405798912,
    265879552,
    34078720,
};

constexpr const char kVolumeMagic[20] = {'M', 'I', 'C', 'R', 'O', 'S', 'O', 'F', 'T', '*', 'X', 'B', 'O', 'X', '*', 'M', 'E', 'D', 'I', 'A'};

constexpr uint32_t kMaxDirentTableSectors = 4096;
constexpr int kMaxDirectoryDepth = 64;
constexpr size_t kCopyBufferSize = 4u << 20;

uint16_t Read16(const uint8_t* p) { return uint16_t(p[0]) | (uint16_t(p[1]) << 8); }

uint32_t Read32(const uint8_t* p) {
    return uint32_t(p[0]) | (uint32_t(p[1]) << 8) | (uint32_t(p[2]) << 16) | (uint32_t(p[3]) << 24);
}

constexpr uint16_t kCp1252High[32] = {
    0x20AC, 0x0000, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
    0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0x0000, 0x017D, 0x0000,
    0x0000, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
    0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0x0000, 0x017E, 0x0178,
};

std::string Cp1252ToUtf8(const uint8_t* bytes, size_t length) {
    std::string out;
    out.reserve(length);
    for (size_t i = 0; i < length; i++) {
        uint32_t cp = bytes[i];
        if (cp >= 0x80 && cp <= 0x9f) {
            cp = kCp1252High[cp - 0x80];
            if (cp == 0) cp = 0xfffd;
        }
        if (cp < 0x80) {
            out.push_back(char(cp));
        } else if (cp < 0x800) {
            out.push_back(char(0xc0 | (cp >> 6)));
            out.push_back(char(0x80 | (cp & 0x3f)));
        } else {
            out.push_back(char(0xe0 | (cp >> 12)));
            out.push_back(char(0x80 | ((cp >> 6) & 0x3f)));
            out.push_back(char(0x80 | (cp & 0x3f)));
        }
    }
    return out;
}

bool IsSafeName(const std::string& name) {
    if (name.empty() || name == "." || name == "..") return false;
    if (name.size() > 255) return false;
    for (unsigned char c : name) {
        if (c < 0x20) return false;
        if (c == '/' || c == '\\' || c == ':' || c == '*' || c == '?' || c == '"' || c == '<' || c == '>' || c == '|') {
            return false;
        }
    }
    return true;
}

fs::path Utf8ToPath(const std::string& utf8) {
    return fs::path(std::u8string(utf8.begin(), utf8.end()));
}

bool EqualsIgnoreCase(const std::string& a, const char* b) {
    size_t i = 0;
    for (; i < a.size() && b[i]; i++) {
        if (std::tolower(static_cast<unsigned char>(a[i])) !=
            std::tolower(static_cast<unsigned char>(b[i]))) {
            return false;
        }
    }
    return i == a.size() && b[i] == '\0';
}

struct DirEntry {
    std::string name;
    uint32_t sector = 0;
    uint32_t size = 0;
    bool directory = false;
};

struct FileTask {
    fs::path relative;
    std::string display;
    uint32_t sector = 0;
    uint32_t size = 0;
};

class IsoReader {
public:
    bool Open(const fs::path& path) {
        stream_.open(path, std::ios::binary);
        if (!stream_) return false;
        stream_.seekg(0, std::ios::end);
        if (!stream_) return false;
        length_ = uint64_t(stream_.tellg());
        return true;
    }

    void set_base(uint64_t base) { base_ = base; }
    uint64_t length() const { return length_; }

    bool ReadAt(uint64_t offset, void* buffer, size_t size) {
        const uint64_t absolute = base_ + offset;
        if (absolute > length_ || size > length_ - absolute) return false;
        stream_.clear();
        stream_.seekg(std::streamoff(absolute), std::ios::beg);
        if (!stream_) return false;
        stream_.read(static_cast<char*>(buffer), std::streamsize(size));
        return bool(stream_) && size_t(stream_.gcount()) == size;
    }

private:
    std::ifstream stream_;
    uint64_t length_ = 0;
    uint64_t base_ = 0;
};

bool ReadVolumeDescriptor(IsoReader& reader, uint32_t& rootSector, uint32_t& rootSize) {
    uint8_t sector[kSectorSize];
    if (!reader.ReadAt(kVolumeSector * kSectorSize, sector, sizeof(sector))) return false;
    if (std::memcmp(sector, kVolumeMagic, sizeof(kVolumeMagic)) != 0) return false;
    if (std::memcmp(sector + 0x7ec, kVolumeMagic, sizeof(kVolumeMagic)) != 0) return false;
    rootSector = Read32(sector + 0x14);
    rootSize = Read32(sector + 0x18);
    return true;
}

bool ScanDirentTable(IsoReader& reader, uint32_t tableSector, uint32_t tableSize,
                     std::vector<DirEntry>& out, std::string& error) {
    out.clear();
    if (tableSize == 0) return true;

    const uint32_t sectorCount = (tableSize + kSectorSize - 1) / kSectorSize;
    if (sectorCount > kMaxDirentTableSectors) {
        error = "The image contains a malformed directory table.";
        return false;
    }

    std::vector<uint8_t> buffer(size_t(sectorCount) * kSectorSize);
    if (!reader.ReadAt(uint64_t(tableSector) * kSectorSize, buffer.data(), buffer.size())) {
        error = "The image ended unexpectedly while reading a directory table. It may be truncated or corrupt.";
        return false;
    }

    size_t sector = 0;
    size_t offset = 0;
    while (sector < sectorCount) {
        if (offset + kDirentHeaderSize > kSectorSize) {
            sector++;
            offset = 0;
            continue;
        }

        const uint8_t* entry = buffer.data() + sector * kSectorSize + offset;
        bool allZero = true, allOnes = true;
        for (size_t i = 0; i < kDirentHeaderSize; i++) {
            if (entry[i] != 0x00) allZero = false;
            if (entry[i] != 0xff) allOnes = false;
        }
        if (allZero || allOnes) {
            sector++;
            offset = 0;
            continue;
        }

        DirEntry dirent;
        dirent.sector = Read32(entry + 4);
        dirent.size = Read32(entry + 8);
        dirent.directory = (entry[12] & kAttrDirectory) != 0;
        const uint8_t nameLength = entry[13];

        if (offset + kDirentHeaderSize + nameLength > kSectorSize) {
            error = "The image contains a malformed directory entry.";
            return false;
        }
        dirent.name = Cp1252ToUtf8(entry + kDirentHeaderSize, nameLength);
        if (!IsSafeName(dirent.name)) {
            error = "The image contains a file name that cannot be written to disk.";
            return false;
        }
        out.push_back(std::move(dirent));

        offset += kDirentHeaderSize + nameLength;
        offset = (offset + 3) & ~size_t(3);
    }

    return true;
}

bool CollectTree(IsoReader& reader, uint32_t tableSector, uint32_t tableSize,
                 const fs::path& relative, const std::string& display, int depth,
                 std::unordered_set<uint64_t>& visited, std::vector<fs::path>& directories,
                 std::vector<FileTask>& files, uint64_t& totalBytes, std::string& error) {
    if (depth > kMaxDirectoryDepth) {
        error = "The image directory tree is nested too deeply.";
        return false;
    }
    const uint64_t key = (uint64_t(tableSector) << 32) | tableSize;
    if (tableSize != 0 && !visited.insert(key).second) return true;

    std::vector<DirEntry> entries;
    if (!ScanDirentTable(reader, tableSector, tableSize, entries, error)) return false;

    for (const DirEntry& entry : entries) {
        const fs::path childRelative = relative / Utf8ToPath(entry.name);
        const std::string childDisplay = display.empty() ? entry.name : display + "/" + entry.name;
        if (entry.directory) {
            directories.push_back(childRelative);
            if (!CollectTree(reader, entry.sector, entry.size, childRelative, childDisplay,
                             depth + 1, visited, directories, files, totalBytes, error)) {
                return false;
            }
        } else {
            if (entry.size != 0 &&
                uint64_t(entry.sector) * kSectorSize + entry.size > reader.length()) {
                error = "The image is truncated: '" + childDisplay + "' extends past the end of "
                        "the file.";
                return false;
            }
            FileTask task;
            task.relative = childRelative;
            task.display = childDisplay;
            task.sector = entry.sector;
            task.size = entry.size;
            files.push_back(std::move(task));
            totalBytes += entry.size;
        }
    }

    return true;
}

std::string DescribeError(const std::error_code& ec) {
    if (ec == std::errc::permission_denied) {
        return "access was denied. Run ReTiP as administrator, or move it out of a protected "
               "folder such as Program Files.";
    }
    if (ec == std::errc::no_space_on_device) return "the drive ran out of space.";
    if (ec == std::errc::read_only_file_system) return "the drive is read-only.";
    return ec.message();
}

}

IsoExtractor::~IsoExtractor() {
    Cancel();
    if (thread_.joinable()) thread_.join();
}

std::string IsoExtractor::CheckDestinationWritable(const fs::path& dest) {
    std::error_code ec;
    fs::create_directories(dest, ec);
    if (ec && !fs::is_directory(dest)) {
        return "Could not create '" + dest.string() + "': " + DescribeError(ec);
    }
    if (!fs::is_directory(dest)) {
        return "'" + dest.string() + "' exists but is not a folder.";
    }

    const fs::path probe = dest / ".retip_write_test";
    {
        std::ofstream file(probe, std::ios::binary | std::ios::trunc);
        if (!file || !file.write("retip", 5)) {
            return "Cannot write to '" + dest.string() +
                   "': access was denied. Run ReTiP as administrator, or move it out of a "
                   "protected folder such as Program Files.";
        }
    }
    fs::remove(probe, ec);
    return {};
}

bool IsoExtractor::Start(fs::path iso, fs::path dest) {
    if (running()) return false;
    if (thread_.joinable()) thread_.join();

    cancel_.store(false, std::memory_order_relaxed);
    bytesDone_.store(0, std::memory_order_relaxed);
    bytesTotal_.store(0, std::memory_order_relaxed);
    filesDone_.store(0, std::memory_order_relaxed);
    filesTotal_.store(0, std::memory_order_relaxed);
    {
        std::lock_guard<std::mutex> lock(textMutex_);
        currentFile_.clear();
        error_.clear();
    }

    std::error_code ec;
    if (!fs::is_regular_file(iso, ec)) {
        Fail("'" + iso.string() + "' is not a file.");
        return false;
    }
    std::string writable = CheckDestinationWritable(dest);
    if (!writable.empty()) {
        Fail(std::move(writable));
        return false;
    }

    state_.store(IsoExtractState::kScanning, std::memory_order_release);
    thread_ = std::thread(&IsoExtractor::Run, this, std::move(iso), std::move(dest));
    return true;
}

void IsoExtractor::Cancel() { cancel_.store(true, std::memory_order_relaxed); }

float IsoExtractor::progress() const {
    const uint64_t total = bytes_total();
    if (total == 0) return state() == IsoExtractState::kDone ? 1.0f : 0.0f;
    const float ratio = float(double(bytes_done()) / double(total));
    return std::clamp(ratio, 0.0f, 1.0f);
}

std::string IsoExtractor::current_file() const {
    std::lock_guard<std::mutex> lock(textMutex_);
    return currentFile_;
}

std::string IsoExtractor::error() const {
    std::lock_guard<std::mutex> lock(textMutex_);
    return error_;
}

void IsoExtractor::SetCurrentFile(const std::string& name) {
    std::lock_guard<std::mutex> lock(textMutex_);
    currentFile_ = name;
}

void IsoExtractor::Fail(std::string message) {
    RETIP_ERROR("ISO extraction failed: {}", message);
    {
        std::lock_guard<std::mutex> lock(textMutex_);
        error_ = std::move(message);
    }
    state_.store(IsoExtractState::kFailed, std::memory_order_release);
}

void IsoExtractor::Run(fs::path iso, fs::path dest) {
    IsoReader reader;
    if (!reader.Open(iso)) {
        Fail("Could not open '" + iso.string() + "'. Check that the file still exists and is not "
             "in use by another program.");
        return;
    }

    uint32_t rootSector = 0;
    uint32_t rootSize = 0;
    bool found = false;
    for (uint64_t base : kPartitionOffsets) {
        if (base >= reader.length()) continue;
        reader.set_base(base);
        if (ReadVolumeDescriptor(reader, rootSector, rootSize)) {
            RETIP_INFO("Found XDVDFS volume at partition offset {}", base);
            found = true;
            break;
        }
    }
    if (!found) {
        Fail("This does not look like an Xbox 360 game image. Select an uncompressed .iso "
             "extracted from your own disc (a redump or XGD image works; .zip, .rar and split "
             "images do not).");
        return;
    }

    SetCurrentFile("Reading image contents...");

    std::unordered_set<uint64_t> visited;
    std::vector<fs::path> directories;
    std::vector<FileTask> files;
    uint64_t totalBytes = 0;
    std::string error;
    if (!CollectTree(reader, rootSector, rootSize, fs::path(), std::string(), 0, visited,
                     directories, files, totalBytes, error)) {
        Fail(std::move(error));
        return;
    }
    if (files.empty()) {
        Fail("The image contains no files.");
        return;
    }

    std::stable_partition(files.begin(), files.end(), [](const FileTask& task) {
        return !(task.relative.parent_path().empty() &&
                 EqualsIgnoreCase(task.relative.filename().string(), "default.xex"));
    });

    std::error_code ec;
    const fs::space_info space = fs::space(dest, ec);
    if (!ec && space.available < totalBytes) {
        Fail("Not enough free space on the destination drive: " +
             std::to_string(totalBytes / (1024 * 1024)) + " MB are needed but only " +
             std::to_string(space.available / (1024 * 1024)) + " MB are available.");
        return;
    }

    bytesTotal_.store(totalBytes, std::memory_order_relaxed);
    filesTotal_.store(uint32_t(files.size()), std::memory_order_relaxed);
    state_.store(IsoExtractState::kExtracting, std::memory_order_release);
    RETIP_INFO("Extracting {} files ({} bytes) from {} to {}", files.size(), totalBytes,
               iso.string(), dest.string());

    for (const fs::path& directory : directories) {
        fs::create_directories(dest / directory, ec);
        if (ec && !fs::is_directory(dest / directory)) {
            Fail("Could not create '" + (dest / directory).string() + "': " + DescribeError(ec));
            return;
        }
    }

    std::vector<uint8_t> buffer(kCopyBufferSize);
    for (const FileTask& task : files) {
        if (cancel_.load(std::memory_order_relaxed)) {
            Fail("Extraction was cancelled.");
            return;
        }

        SetCurrentFile(task.display);
        const fs::path target = dest / task.relative;

        std::ofstream output(target, std::ios::binary | std::ios::trunc);
        if (!output) {
            Fail("Could not write '" + target.string() +
                 "': access was denied. Run ReTiP as administrator, or move it out of a "
                 "protected folder such as Program Files.");
            return;
        }

        uint64_t remaining = task.size;
        uint64_t offset = uint64_t(task.sector) * kSectorSize;
        while (remaining > 0) {
            if (cancel_.load(std::memory_order_relaxed)) {
                Fail("Extraction was cancelled.");
                return;
            }
            const size_t chunk = size_t(std::min<uint64_t>(remaining, buffer.size()));
            if (!reader.ReadAt(offset, buffer.data(), chunk)) {
                Fail("Failed to read '" + task.display +
                     "' from the image. It may be truncated or corrupt.");
                return;
            }
            if (!output.write(reinterpret_cast<const char*>(buffer.data()),
                              std::streamsize(chunk))) {
                Fail("Failed to write '" + target.string() +
                     "'. The drive may be full, write protected, or disconnected.");
                return;
            }
            offset += chunk;
            remaining -= chunk;
            bytesDone_.fetch_add(chunk, std::memory_order_relaxed);
        }

        output.close();
        if (output.fail()) {
            Fail("Failed to finish writing '" + target.string() +
                 "'. The drive may be full, write protected, or disconnected.");
            return;
        }
        filesDone_.fetch_add(1, std::memory_order_relaxed);
    }

    if (!fs::exists(dest / "default.xex")) {
        Fail("The image did not contain default.xex, so it is not a copy of this game.");
        return;
    }

    SetCurrentFile("Done");
    state_.store(IsoExtractState::kDone, std::memory_order_release);
    RETIP_INFO("ISO extraction complete");
}

}
