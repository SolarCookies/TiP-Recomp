#include "DiscordRPC.h"
#include "Log.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <mutex>
#include <string>
#include <thread>

namespace retip::discord_rpc {

namespace {

// Discord Application ID. The "Playing X" title is the application's name in
// the Developer Portal.
constexpr const char* kDiscordClientID = "1497091207132876860";

// IPC frame opcodes.
enum : uint32_t {
    kOpHandshake = 0,
    kOpFrame     = 1,
    kOpClose     = 2,
    kOpPing      = 3,
    kOpPong      = 4,
};

std::atomic<bool> g_running{false};
std::thread       g_thread;
std::mutex        g_mutex;
Presence          g_presence;
std::atomic<bool> g_dirty{false};

HANDLE g_pipe = INVALID_HANDLE_VALUE;

bool ConnectPipe() {
    for (int i = 0; i < 10; ++i) {
        char name[64];
        std::snprintf(name, sizeof(name), "\\\\?\\pipe\\discord-ipc-%d", i);
        HANDLE h = ::CreateFileA(name, GENERIC_READ | GENERIC_WRITE, 0,
                                 nullptr, OPEN_EXISTING, 0, nullptr);
        if (h != INVALID_HANDLE_VALUE) {
            g_pipe = h;
            RETIP_INFO("DiscordRPC: connected to %s", name);
            return true;
        }
    }
    RETIP_WARN("DiscordRPC: no Discord IPC pipe found (is Discord running?)");
    return false;
}

void ClosePipe() {
    if (g_pipe != INVALID_HANDLE_VALUE) {
        ::CloseHandle(g_pipe);
        g_pipe = INVALID_HANDLE_VALUE;
    }
}

bool WriteFrame(uint32_t op, const std::string& payload) {
    if (g_pipe == INVALID_HANDLE_VALUE) return false;
    uint32_t header[2] = {op, static_cast<uint32_t>(payload.size())};
    DWORD written = 0;
    if (!::WriteFile(g_pipe, header, sizeof(header), &written, nullptr) ||
        written != sizeof(header)) {
        return false;
    }
    if (!payload.empty()) {
        if (!::WriteFile(g_pipe, payload.data(),
                         static_cast<DWORD>(payload.size()), &written,
                         nullptr) ||
            written != payload.size()) {
            return false;
        }
    }
    return true;
}

void DrainPipe(bool* outReady = nullptr) {
    if (g_pipe == INVALID_HANDLE_VALUE) return;
    while (true) {
        DWORD avail = 0;
        if (!::PeekNamedPipe(g_pipe, nullptr, 0, nullptr, &avail, nullptr)) {
            return;
        }
        if (avail < 8) return;
        uint32_t header[2] = {0, 0};
        DWORD read = 0;
        if (!::ReadFile(g_pipe, header, sizeof(header), &read, nullptr) ||
            read != sizeof(header)) {
            return;
        }
        std::string buf;
        if (header[1] > 0) {
            buf.resize(header[1]);
            DWORD total = 0;
            while (total < header[1]) {
                DWORD n = 0;
                if (!::ReadFile(g_pipe, buf.data() + total, header[1] - total,
                                &n, nullptr) ||
                    n == 0) {
                    return;
                }
                total += n;
            }
        }
        if (header[0] == kOpPing) {
            WriteFrame(kOpPong, buf);
        } else if (header[0] == kOpFrame) {
            RETIP_DEBUG("DiscordRPC: <- %s", buf.c_str());
            if (outReady && buf.find("\"evt\":\"READY\"") != std::string::npos) {
                *outReady = true;
            }
        } else if (header[0] == kOpClose) {
            RETIP_WARN("DiscordRPC: server closed: %s", buf.c_str());
            ClosePipe();
            return;
        }
    }
}

std::string JsonEscape(const std::string& in) {
    std::string out;
    out.reserve(in.size() + 2);
    for (char c : in) {
        switch (c) {
            case '"':  out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            case '\b': out += "\\b";  break;
            case '\f': out += "\\f";  break;
            case '\n': out += "\\n";  break;
            case '\r': out += "\\r";  break;
            case '\t': out += "\\t";  break;
            default:
                if (static_cast<unsigned char>(c) < 0x20) {
                    char hex[8];
                    std::snprintf(hex, sizeof(hex), "\\u%04x", c);
                    out += hex;
                } else {
                    out += c;
                }
        }
    }
    return out;
}

bool SendHandshake() {
    std::string payload = std::string("{\"v\":1,\"client_id\":\"") +
                          kDiscordClientID + "\"}";
    RETIP_INFO("DiscordRPC: -> handshake %s", payload.c_str());
    return WriteFrame(kOpHandshake, payload);
}

// Tells Discord to remove our activity. Sends SET_ACTIVITY with activity=null.
bool SendClearActivity() {
    DWORD pid = ::GetCurrentProcessId();
    std::string payload = "{\"cmd\":\"SET_ACTIVITY\",\"args\":{\"pid\":";
    payload += std::to_string(pid);
    payload += ",\"activity\":null},\"nonce\":\"";
    payload += std::to_string(::GetTickCount());
    payload += "\"}";
    RETIP_INFO("DiscordRPC: -> %s", payload.c_str());
    return WriteFrame(kOpFrame, payload);
}

bool SendActivity(const Presence& p, int64_t startTimestamp) {
    DWORD pid = ::GetCurrentProcessId();

    auto appendStr = [](std::string& dst, bool& first, const char* key,
                        const std::string& val) {
        if (val.empty()) return;
        if (!first) dst += ",";
        dst += "\"";
        dst += key;
        dst += "\":\"" + JsonEscape(val) + "\"";
        first = false;
    };

    // assets sub-object
    std::string assets;
    {
        bool firstA = true;
        assets = "{";
        appendStr(assets, firstA, "large_image", p.largeImageKey);
        appendStr(assets, firstA, "large_text",  p.largeImageText);
        appendStr(assets, firstA, "small_image", p.smallImageKey);
        appendStr(assets, firstA, "small_text",  p.smallImageText);
        assets += "}";
        if (firstA) assets.clear();  // empty -> omit
    }

    std::string activity = "{";
    bool first = true;
    appendStr(activity, first, "details", p.details);
    appendStr(activity, first, "state",   p.state);
    if (startTimestamp > 0) {
        if (!first) activity += ",";
        activity += "\"timestamps\":{\"start\":";
        activity += std::to_string(startTimestamp);
        activity += "}";
        first = false;
    }
    if (!assets.empty()) {
        if (!first) activity += ",";
        activity += "\"assets\":";
        activity += assets;
        first = false;
    }
    if (!first) activity += ",";
    activity += "\"instance\":false";
    activity += "}";

    std::string payload = "{\"cmd\":\"SET_ACTIVITY\",\"args\":{\"pid\":";
    payload += std::to_string(pid);
    payload += ",\"activity\":";
    payload += activity;
    payload += "},\"nonce\":\"";
    payload += std::to_string(::GetTickCount());
    payload += "\"}";
    RETIP_INFO("DiscordRPC: -> %s", payload.c_str());
    return WriteFrame(kOpFrame, payload);
}

void WorkerThread() {
    using clock = std::chrono::steady_clock;
    auto nextReconnect = clock::now();
    int64_t startTimestamp = std::chrono::duration_cast<std::chrono::seconds>(
                                 std::chrono::system_clock::now().time_since_epoch())
                                 .count();
    bool handshakeSent = false;
    bool ready         = false;

    while (g_running.load()) {
        if (g_pipe == INVALID_HANDLE_VALUE) {
            if (clock::now() < nextReconnect) {
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                continue;
            }
            if (!ConnectPipe()) {
                nextReconnect = clock::now() + std::chrono::seconds(15);
                continue;
            }
            handshakeSent = false;
            ready         = false;
        }

        if (!handshakeSent) {
            if (!SendHandshake()) {
                ClosePipe();
                nextReconnect = clock::now() + std::chrono::seconds(15);
                continue;
            }
            handshakeSent = true;
        }

        DrainPipe(&ready);

        if (ready && g_dirty.exchange(false)) {
            Presence snap;
            {
                std::lock_guard<std::mutex> lock(g_mutex);
                snap = g_presence;
            }
            if (!SendActivity(snap, startTimestamp)) {
                ClosePipe();
                nextReconnect = clock::now() + std::chrono::seconds(5);
                continue;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    if (g_pipe != INVALID_HANDLE_VALUE) {
        SendClearActivity();
        WriteFrame(kOpClose, "{}");
        ClosePipe();
    }
}

// Synchronous best-effort clear used from atexit / console handler when the
// worker thread can't be relied on (process dying).
void SyncClearAndClose() {
    if (g_pipe == INVALID_HANDLE_VALUE) return;
    SendClearActivity();
    WriteFrame(kOpClose, "{}");
    ClosePipe();
}

BOOL WINAPI ConsoleCtrlHandler(DWORD) {
    SyncClearAndClose();
    return FALSE;  // let default handler run
}

struct AtExitInstaller {
    AtExitInstaller() {
        std::atexit([] { SyncClearAndClose(); });
        ::SetConsoleCtrlHandler(ConsoleCtrlHandler, TRUE);
    }
} g_atExitInstaller;

}  // namespace

void Start(const Presence& initial) {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        g_presence = initial;
    }
    g_dirty = true;
    if (g_running.exchange(true)) return;
    g_thread = std::thread(WorkerThread);
}

void Start(const std::string& details, const std::string& state) {
    Presence p;
    p.details = details;
    p.state   = state;
    Start(p);
}

void SetPresence(const Presence& p) {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        g_presence = p;
    }
    g_dirty = true;
}

void SetDetails(const std::string& details) {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        g_presence.details = details;
    }
    g_dirty = true;
}

void SetState(const std::string& state) {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        g_presence.state = state;
    }
    g_dirty = true;
}

void SetLargeImage(const std::string& key, const std::string& text) {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        g_presence.largeImageKey  = key;
        g_presence.largeImageText = text;
    }
    g_dirty = true;
}

void SetSmallImage(const std::string& key, const std::string& text) {
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        g_presence.smallImageKey  = key;
        g_presence.smallImageText = text;
    }
    g_dirty = true;
}

void Stop() {
    if (!g_running.exchange(false)) return;
    if (g_thread.joinable()) g_thread.join();
}

}  // namespace retip::discord_rpc
