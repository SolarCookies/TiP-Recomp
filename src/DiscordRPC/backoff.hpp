#pragma once
#ifndef DISCORD_BACKOFF_HPP
#define DISCORD_BACKOFF_HPP

#include <algorithm>
#include <random>

namespace discord {
    class Backoff {
    public:
        static Backoff& get() noexcept {
            static Backoff instance;
            return instance;
        }

        double rand01() noexcept {
            return m_distribution(m_generator);
        }

        void reset() noexcept {
            m_currentAmount = m_minAmount;
            m_attempts = 0;
        }

        int64_t next() noexcept {
            m_attempts++;
            auto delay = static_cast<int64_t>(static_cast<double>(m_currentAmount) * 2.0 * rand01());
            m_currentAmount = std::min(m_maxAmount, m_currentAmount + delay);
            return m_currentAmount;
        }

    private:
        int64_t m_minAmount = 500;
        int64_t m_maxAmount = 60000;
        int64_t m_currentAmount = m_minAmount;
        int32_t m_attempts = 0;
        std::mt19937_64 m_generator{std::random_device{}()};
        std::uniform_real_distribution<> m_distribution{0.0, 1.0};
    };
}

#endif // DISCORD_BACKOFF_HPP
