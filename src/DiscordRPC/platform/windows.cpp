#include "windows.hpp"
#include <array>
#include <memory>
#include <sddl.h>
#include <WinSock2.h>
#include <fmt/format.h>

namespace wine {
    static bool isWine() {
        static bool wine = [] {
            auto ntdll = ::GetModuleHandleW(L"ntdll.dll");
            if (!ntdll) {
                return false;
            }
            auto func = ::GetProcAddress(ntdll, "wine_get_version");
            return func != nullptr;
        }();
        return wine;
    }

    // https://stackoverflow.com/a/28523686
    struct heap_delete {
        using pointer = LPVOID;

        void operator()(LPVOID p) const {
            ::HeapFree(::GetProcessHeap(), 0, p);
        }
    };

    struct handle_delete {
        using pointer = HANDLE;

        void operator()(HANDLE p) const {
            ::CloseHandle(p);
        }
    };

    using heap_unique_ptr = std::unique_ptr<LPVOID, heap_delete>;
    using handle_unique_ptr = std::unique_ptr<HANDLE, handle_delete>;
    using uid_t = uint32_t;

    static BOOL GetUserSID(HANDLE token, PSID* sid) {
        if (token == nullptr || token == INVALID_HANDLE_VALUE) {
            SetLastError(ERROR_INVALID_PARAMETER);
            return FALSE;
        }

        DWORD tokenInformationLength = 0;
        ::GetTokenInformation(token, TokenUser, nullptr, 0, &tokenInformationLength);
        if (GetLastError() != ERROR_INSUFFICIENT_BUFFER) return FALSE;

        heap_unique_ptr data(::HeapAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY, tokenInformationLength));
        if (data.get() == nullptr) return FALSE;

        BOOL getTokenInfo = ::GetTokenInformation(
            token, TokenUser,
            data.get(), tokenInformationLength,
            &tokenInformationLength
        );
        if (!getTokenInfo) return FALSE;

        PTOKEN_USER pTokenUser = static_cast<PTOKEN_USER>(data.get());
        DWORD sidLength = ::GetLengthSid(pTokenUser->User.Sid);
        heap_unique_ptr sidPtr(::HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sidLength));
        PSID sidL = sidPtr.get();
        if (sidL == nullptr) return FALSE;

        BOOL copySid = ::CopySid(sidLength, sidL, pTokenUser->User.Sid);
        if (!copySid) return FALSE;
        if (!IsValidSid(sidL)) return FALSE;

        *sid = sidL;
        sidPtr.release();
        return TRUE;
    }

    static uid_t GetUID(HANDLE token) {
        PSID sid = nullptr;
        BOOL getSID = GetUserSID(token, &sid);
        if (!getSID || !sid) {
            return -1;
        }

        heap_unique_ptr sidPtr(sid);
        LPWSTR stringSid = nullptr;
        BOOL convertSid = ::ConvertSidToStringSidW(sid, &stringSid);
        if (!convertSid) {
            return -1;
        }

        uid_t ret = -1;
        LPCWSTR p = ::wcsrchr(stringSid, L'-');
        if (p && ::iswdigit(p[1])) {
            ++p;
            ret = ::_wtoi(p);
        }

        ::LocalFree(stringSid);
        return ret;
    }

    static uid_t getuid() {
        HANDLE process = ::GetCurrentProcess();
        handle_unique_ptr processPtr(process);
        HANDLE token = nullptr;
        BOOL openToken = ::OpenProcessToken(
            process, TOKEN_READ | TOKEN_QUERY_SOURCE, &token
        );
        if (!openToken) {
            return -1;
        }
        handle_unique_ptr tokenPtr(token);
        uid_t ret = GetUID(token);
        return ret;
    }

    static std::string getTempPath() {
        wchar_t buffer[MAX_PATH];
        DWORD result = ::GetEnvironmentVariableW(L"XDG_RUNTIME_DIR", buffer, MAX_PATH);
        if (result > 0 && result < MAX_PATH) {
            int len = WideCharToMultiByte(CP_UTF8, 0, buffer, result, nullptr, 0, nullptr, nullptr);
            std::string path(len, '\0');
            WideCharToMultiByte(CP_UTF8, 0, buffer, result, path.data(), len, nullptr, nullptr);
            return path;
        }

        // try to get userid
        auto uid = getuid();
        if (uid != static_cast<uid_t>(-1)) {
            return fmt::format("/run/user/{}", uid);
        }

        return "/run/user/1000"; // common default
    }

    static std::array<std::string, 4> const& getCandidatePaths() {
        static std::array<std::string, 4> paths = []() {
            auto base = getTempPath();

            std::array<std::string, 4> result = {
                base,
                fmt::format("{}/snap.discord", base),
                fmt::format("{}/app/com.discordapp.Discord", base),
                fmt::format("{}/app/com.discordapp.DiscordCanary", base),
            };

            return result;
        }();
        return paths;
    }

    static std::string convertWinePathToWindows(std::string const& unixPath) noexcept {
        auto command = fmt::format("winepath -w \"{}\"", unixPath);

        HANDLE hReadPipe, hWritePipe;
        SECURITY_ATTRIBUTES sa = {sizeof(SECURITY_ATTRIBUTES), nullptr, TRUE};

        if (!CreatePipe(&hReadPipe, &hWritePipe, &sa, 0)) {
            return "";
        }

        STARTUPINFOA si = {};
        si.cb = sizeof(STARTUPINFOA);
        si.hStdOutput = hWritePipe;
        si.hStdError = hWritePipe;
        si.dwFlags |= STARTF_USESTDHANDLES;

        PROCESS_INFORMATION pi = {};

        if (CreateProcessA(
            nullptr, const_cast<char*>(command.c_str()), nullptr, nullptr, TRUE,
            CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi
        )) {
            CloseHandle(hWritePipe);

            WaitForSingleObject(pi.hProcess, 5000);

            char buffer[MAX_PATH];
            DWORD bytesRead;
            std::string result;

            while (ReadFile(hReadPipe, buffer, sizeof(buffer) - 1, &bytesRead, nullptr) && bytesRead > 0) {
                buffer[bytesRead] = '\0';
                result += buffer;
            }

            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);

            std::erase(result, '\n');
            std::erase(result, '\r');

            if (!result.empty()) {
                return result;
            }
        } else {
            CloseHandle(hWritePipe);
        }

        CloseHandle(hReadPipe);
        return "";
    }
}

namespace discord::platform {
    size_t getProcessID() noexcept {
        return ::GetCurrentProcessId();
    }

    PipeConnection::PipeConnection() noexcept {
        if (wine::isWine()) {
            WSADATA wsaData;
            ::WSAStartup(MAKEWORD(2, 2), &wsaData);
        }
    }

    PipeConnection::~PipeConnection() noexcept {
        this->close();
        if (wine::isWine()) {
            ::WSACleanup();
        }
    }

    bool PipeConnection::open() noexcept {
        if (m_isOpen) {
            return false;
        }

        if (wine::isWine() && openUnix()) {
            return true;
        }

        wchar_t pipeName[] = L"\\\\?\\pipe\\discord-ipc-0";
        constexpr size_t pipeDigit = sizeof(pipeName) / sizeof(wchar_t) - 2;
        while (true) {
            m_pipe = ::CreateFileW(pipeName, GENERIC_READ | GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, 0, nullptr);
            if (m_pipe != INVALID_HANDLE_VALUE) {
                m_isOpen = true;
                return true;
            }

            auto error = ::GetLastError();
            if (error == ERROR_FILE_NOT_FOUND) {
                if (pipeName[pipeDigit] < L'9') {
                    pipeName[pipeDigit]++;
                    continue;
                }
            } else if (error == ERROR_PIPE_BUSY) {
                if (!WaitNamedPipeW(pipeName, 10000)) {
                    return false;
                }
                continue;
            }

            return false;
        }
    }

    bool PipeConnection::close() noexcept {
        if (m_useWineFallback) {
            return closeUnix();
        }

        if (m_pipe != INVALID_HANDLE_VALUE) {
            ::CloseHandle(m_pipe);
            m_pipe = INVALID_HANDLE_VALUE;
            m_isOpen = false;
        }
        return true;
    }

    bool PipeConnection::write(void const* data, size_t length) const noexcept {
        if (length == 0) {
            return true;
        }

        if (m_useWineFallback) {
            return writeUnix(data, length);
        }

        if (m_pipe == INVALID_HANDLE_VALUE) {
            return false;
        }

        if (!data) {
            return false;
        }

        auto const bytesToWrite = static_cast<DWORD>(length);
        DWORD bytesWritten = 0;
        if (!::WriteFile(m_pipe, data, bytesToWrite, &bytesWritten, nullptr)) {
            return false;
        }
        return bytesWritten == bytesToWrite;
    }

    bool PipeConnection::read(void* data, size_t length) noexcept {
        if (!data) {
            return false;
        }

        if (m_useWineFallback) {
            return readUnix(data, length);
        }

        if (m_pipe == INVALID_HANDLE_VALUE) {
            return false;
        }

        DWORD bytesRead = 0;
        if (!::PeekNamedPipe(m_pipe, nullptr, 0, nullptr, &bytesRead, nullptr)) {
            this->close();
            return false;
        }

        if (bytesRead < length) {
            return false;
        }

        if (!::ReadFile(m_pipe, data, length, &bytesRead, nullptr)) {
            this->close();
            return false;
        }

        return true;
    }

    bool PipeConnection::openUnix() noexcept {
        auto basePath = wine::getTempPath();
        if (basePath.empty()) {
            return false;
        }

        auto socket = ::socket(AF_UNIX, SOCK_STREAM, 0);
        if (socket == INVALID_SOCKET) {
            return false;
        }

        u_long mode = 1;
        ::ioctlsocket(socket, FIONBIO, &mode);

        for (auto& dir : wine::getCandidatePaths()) {
            for (int i = 0; i < 10; ++i) {
                auto socketPath = wine::convertWinePathToWindows(fmt::format("{}\\discord-ipc-{}", dir, i));
                if (socketPath.empty()) {
                    return false;
                }

                struct UnixAddr {
                    short sun_family;
                    char sun_path[108] = {};
                };

                UnixAddr addr{AF_UNIX};
                std::memcpy(addr.sun_path, socketPath.c_str(), std::min(socketPath.size(), sizeof(addr.sun_path) - 1));

                if (::connect(socket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0) {
                    m_pipe = reinterpret_cast<HANDLE>(socket);
                    m_isOpen = true;
                    m_useWineFallback = true;
                    return true;
                }
            }
        }

        return false;
    }

    bool PipeConnection::closeUnix() noexcept {
        auto socket = reinterpret_cast<SOCKET>(m_pipe);
        if (socket == INVALID_SOCKET) {
            return false;
        }

        if (::closesocket(socket) == SOCKET_ERROR) {
            return false;
        }

        m_pipe = INVALID_HANDLE_VALUE;
        m_isOpen = false;
        m_useWineFallback = false;

        return true;
    }

    bool PipeConnection::writeUnix(void const* data, size_t length) const noexcept {
        if (!data) {
            return true;
        }

        auto socket = reinterpret_cast<SOCKET>(m_pipe);
        if (socket == INVALID_SOCKET) {
            return false;
        }

        int bytesSent = ::send(socket, static_cast<char const*>(data), static_cast<int>(length), 0);
        if (bytesSent == SOCKET_ERROR) {
            return false;
        }

        return bytesSent == static_cast<int>(length);
    }

    bool PipeConnection::readUnix(void* data, size_t length) noexcept {
        if (length == 0) {
            return true;
        }

        auto socket = reinterpret_cast<SOCKET>(m_pipe);
        if (socket == INVALID_SOCKET) {
            return false;
        }

        int bytesRead = ::recv(socket, static_cast<char*>(data), static_cast<int>(length), 0);
        if (bytesRead == SOCKET_ERROR) {
            return false;
        }

        return bytesRead == static_cast<int>(length);
    }
}
