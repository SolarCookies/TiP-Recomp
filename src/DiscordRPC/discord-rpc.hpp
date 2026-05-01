#pragma once
#ifndef DISCORD_RPC_HPP
#define DISCORD_RPC_HPP

#include <array>
#include <atomic>
#include <chrono>
#include <functional>
#include <memory>
#include <mutex>
#include <optional>
#include <string>

#include "discord-rpc/command-queue.hpp"
#include "discord-rpc/presence.hpp"

namespace discord {
    class Connection;
    struct IOWorker;

    struct User {
        std::string id;
        std::string username;
        std::string discriminator;
        std::optional<std::string> global_name;
        std::optional<std::string> avatar;
        bool bot = false;
        uint64_t flags = 0;
        int premium_type = 0;
    };

    class RPCManager {
    private:
        // prevent construction from outside
        RPCManager() noexcept = default;
        ~RPCManager() noexcept;

        friend class Connection;

    public:
        static RPCManager& get() noexcept {
            static RPCManager instance;
            return instance;
        }

        // prevent copying/moving
        RPCManager(RPCManager const&) = delete;
        RPCManager(RPCManager&&) = delete;
        RPCManager& operator=(RPCManager const&) = delete;
        RPCManager& operator=(RPCManager&&) = delete;

        /// Initializes the RPC manager and starts the IO worker (if not disabled)
        RPCManager& initialize() noexcept;

        /// Disconnects the RPC manager and stops the IO worker (if not disabled)
        RPCManager& shutdown() noexcept;

        /// Sends a heartbeat to the Discord client
        /// @note This function is called automatically by the IO worker thread (if not disabled)
        RPCManager& update() noexcept;

        /// Send a new presence to the Discord client
        RPCManager& refresh() noexcept;

        /// Get current rich presence information. You can use this to access the builder directly.
        Presence& getPresence() noexcept { return m_presence; }

        /// Clear the current rich presence information. Calls refresh() automatically.
        RPCManager& clearPresence() noexcept;

        #define GENERATE_SETTER_LRVALUE(type, name, member) \
        RPCManager& name(type const& member) noexcept { m_##member = member; return *this; } \
        RPCManager& name(type&& member) noexcept { m_##member = std::move(member); return *this; }

        GENERATE_SETTER_LRVALUE(std::string, setClientID, clientID)
        GENERATE_SETTER_LRVALUE(Presence, setPresence, presence)
        GENERATE_SETTER_LRVALUE(std::function<void(User const&)>, onReady, onReady)
        GENERATE_SETTER_LRVALUE(std::function<void(int, std::string_view)>, onDisconnected, onDisconnected)
        GENERATE_SETTER_LRVALUE(std::function<void(int, std::string_view)>, onErrored, onErrored)
        GENERATE_SETTER_LRVALUE(std::function<void(std::string_view)>, onJoinGame, onJoinGame)
        GENERATE_SETTER_LRVALUE(std::function<void(std::string_view)>, onSpectateGame, onSpectateGame)
        GENERATE_SETTER_LRVALUE(std::function<void(User const&)>, onJoinRequest, onJoinRequest)

        #undef GENERATE_SETTER_LRVALUE

    private:
        void invokeOnReady(User const& user) const noexcept {
            if (m_onReady) { m_onReady(user); }
        }

        void invokeOnDisconnected(int errcode, std::string_view message) const noexcept {
            if (m_onDisconnected) { m_onDisconnected(errcode, message); }
        }

        void invokeOnErrored(int errcode, std::string_view message) const noexcept {
            if (m_onErrored) { m_onErrored(errcode, message); }
        }

        void invokeOnJoinGame(std::string_view joinSecret) const noexcept {
            if (m_onJoinGame) { m_onJoinGame(joinSecret); }
        }

        void invokeOnSpectateGame(std::string_view spectateSecret) const noexcept {
            if (m_onSpectateGame) { m_onSpectateGame(spectateSecret); }
        }

        void invokeOnJoinRequest(User const& user) const noexcept {
            if (m_onJoinRequest) { m_onJoinRequest(user); }
        }

        void updateReconnectTime() noexcept;

    private:
        // User settings
        std::string m_clientID;
        Presence m_presence{};
        std::function<void(User const&)> m_onReady;
        std::function<void(int, std::string_view)> m_onDisconnected;
        std::function<void(int, std::string_view)> m_onErrored;
        std::function<void(std::string_view)> m_onJoinGame;
        std::function<void(std::string_view)> m_onSpectateGame;
        std::function<void(User const&)> m_onJoinRequest;

        // State
        bool m_initialized = false;

        // Internal
        IOWorker* m_ioWorker = nullptr;
        std::chrono::time_point<std::chrono::system_clock> m_nextConnect = std::chrono::system_clock::now();
        size_t m_processID = 0;
        int m_nonce = 1;
        CommandQueue m_commandQueue{};
    };
}

#endif // DISCORD_RPC_HPP
