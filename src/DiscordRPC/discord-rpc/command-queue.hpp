#pragma once
#ifndef DISCORD_RPC_COMMAND_QUEUE_HPP
#define DISCORD_RPC_COMMAND_QUEUE_HPP

#include <queue>
#include <mutex>
#include <string>
#include <optional>

namespace discord {
    /// @brief A simple command queue for Discord RPC commands
    class CommandQueue {
    public:
        CommandQueue() noexcept = default;
        ~CommandQueue() noexcept = default;

        /// @brief Adds a command to the queue
        void push(std::string const& command) noexcept;
        void push(std::string&& command) noexcept;

        /// @brief Pushes a new command to the queue and returns a reference to the prepared command.
        /// Mutex remains locked after this call, so make sure to call `finish()` after filling the command.
        std::string& prepare() noexcept;

        /// @brief Unlocks the mutex after a `prepare()` call.
        void finish() noexcept;

        /// @brief Pops a command from the queue
        std::optional<std::string> pop() noexcept;

        /// @brief Checks if the queue is empty
        bool empty() const noexcept;

        /// @brief Returns the size of the queue
        size_t size() const noexcept;

    private:
        std::queue<std::string> m_queue; ///< The internal command queue
        mutable std::mutex m_mutex;      ///< Mutex for thread safety
    };
}

#endif // DISCORD_RPC_COMMAND_QUEUE_HPP
