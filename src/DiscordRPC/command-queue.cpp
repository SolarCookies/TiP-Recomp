#include <discord-rpc/command-queue.hpp>
#include <fmt/format.h>

namespace discord {
    void CommandQueue::push(std::string const& command) noexcept {
        std::lock_guard lock(m_mutex);
        m_queue.push(command);
    }

    void CommandQueue::push(std::string&& command) noexcept {
        std::lock_guard lock(m_mutex);
        m_queue.push(std::move(command));
    }

    std::string& CommandQueue::prepare() noexcept {
        m_mutex.lock();
        return m_queue.emplace();
    }

    void CommandQueue::finish() noexcept {
        m_mutex.unlock();
    }

    std::optional<std::string> CommandQueue::pop() noexcept {
        std::lock_guard lock(m_mutex);
        if (m_queue.empty()) {
            return std::nullopt;
        }
        auto cmd = std::move(m_queue.front());
        m_queue.pop();
        return cmd;
    }

    bool CommandQueue::empty() const noexcept {
        std::lock_guard lock(m_mutex);
        return m_queue.empty();
    }

    size_t CommandQueue::size() const noexcept {
        std::lock_guard lock(m_mutex);
        return m_queue.size();
    }
}