#pragma once
#ifndef DISCORD_WINDOWS_HPP
#define DISCORD_WINDOWS_HPP

#define WIN32_LEAN_AND_MEAN
#define NOMCX
#define NOSERVICE
#define NOIME
#define NOMINMAX
#include <cstdint>
#include <Windows.h>

namespace discord::platform {
    size_t getProcessID() noexcept;

    class PipeConnection {
    public:
        PipeConnection() noexcept;
        ~PipeConnection() noexcept;

        bool open() noexcept;
        bool close() noexcept;

        bool write(void const* data, size_t length) const noexcept;
        bool read(void* data, size_t length) noexcept;

        [[nodiscard]] bool isOpen() const noexcept { return m_isOpen; }

    private:
        // Unix methods for Wine compatibility
        bool openUnix() noexcept;
        bool closeUnix() noexcept;
        bool writeUnix(void const* data, size_t length) const noexcept;
        bool readUnix(void* data, size_t length) noexcept;

        HANDLE m_pipe = INVALID_HANDLE_VALUE;
        bool m_isOpen = false;
        bool m_useWineFallback = false;
    };
}

#endif // DISCORD_WINDOWS_HPP
