#pragma once
#ifndef DISCORD_RPC_PRESENCE_HPP
#define DISCORD_RPC_PRESENCE_HPP

#include <array>
#include <cstdint>
#include <string>
#include <utility>

namespace discord {
    enum class PartyPrivacy : int32_t {
        Private = 0,
        Public  = 1,
    };

    enum class ActivityType : int32_t {
        Game = 0,
        Streaming = 1,
        Listening = 2,
        Watching = 3,
        Custom = 4, // Note: only works for bot accounts
        Competing = 5,
    };

    enum class StatusDisplayType {
        Name = 0,
        State = 1,
        Details = 2,
    };

    class Presence {
    public:
        static Presence& get() noexcept;

        #define GENERATE_GETSET_LRVALUE(type, name, member) \
        Presence& set##name(type const& member) noexcept { m_##member = member; return *this; } \
        Presence& set##name(type&& member) noexcept { m_##member = std::move(member); return *this; }\
        type const& get##name() const noexcept { return m_##member; }

        #define GENERATE_GETSET_VALUE(type, name, member) \
        Presence& set##name(type member) noexcept { m_##member = member; return *this; } \
        type get##name() const noexcept { return m_##member; }

        #define GENERATE_GETSET_BUTTON(index) \
        Button& getButton##index() noexcept { return m_buttons[index - 1]; } \
        Button const& getButton##index() const noexcept { return m_buttons[index - 1]; } \
        Presence& setButton##index(Button const& button) noexcept { m_buttons[index - 1] = button; return *this; } \
        Presence& setButton##index(Button&& button) noexcept { m_buttons[index - 1] = std::move(button); return *this; } \
        Presence& setButton##index(std::string const& label, std::string const& url, bool enabled = true) noexcept { \
            m_buttons[index - 1].set(label, url, enabled); \
            return *this; \
        } \
        Presence& setButton##index(std::string&& label, std::string&& url, bool enabled = true) noexcept { \
            m_buttons[index - 1].set(std::move(label), std::move(url), enabled); \
            return *this; \
        }

        class Button {
        public:
            [[nodiscard]] bool isEnabled() const noexcept { return enabled; }
            [[nodiscard]] std::string const& getLabel() const noexcept { return label; }
            [[nodiscard]] std::string const& getURL() const noexcept { return url; }

            Button& setEnabled(bool enabled) noexcept {
                this->enabled = enabled;
                return *this;
            }

            Button& setLabel(std::string const& label) noexcept {
                this->label = label;
                return *this;
            }

            Button& setLabel(std::string&& label) noexcept {
                this->label = std::move(label);
                return *this;
            }

            Button& setURL(std::string const& url) noexcept {
                this->url = url;
                return *this;
            }

            Button& setURL(std::string&& url) noexcept {
                this->url = std::move(url);
                return *this;
            }

            Button& set(std::string const& label, std::string const& url, bool enabled = true) noexcept {
                this->label = label;
                this->url = url;
                this->enabled = enabled;
                return *this;
            }

            Button& set(std::string&& label, std::string&& url, bool enabled = true) noexcept {
                this->label = std::move(label);
                this->url = std::move(url);
                this->enabled = enabled;
                return *this;
            }

        private:
            bool enabled = false;
            std::string label;
            std::string url;
        };

        GENERATE_GETSET_LRVALUE(std::string, State, state)
        GENERATE_GETSET_LRVALUE(std::string, Details, details)
        GENERATE_GETSET_VALUE(int64_t, StartTimestamp, startTimestamp)
        GENERATE_GETSET_VALUE(int64_t, EndTimestamp, endTimestamp)
        GENERATE_GETSET_LRVALUE(std::string, LargeImageKey, largeImageKey)
        GENERATE_GETSET_LRVALUE(std::string, LargeImageText, largeImageText)
        GENERATE_GETSET_LRVALUE(std::string, SmallImageKey, smallImageKey)
        GENERATE_GETSET_LRVALUE(std::string, SmallImageText, smallImageText)
        GENERATE_GETSET_LRVALUE(std::string, PartyID, partyID)
        GENERATE_GETSET_VALUE(int32_t, PartySize, partySize)
        GENERATE_GETSET_VALUE(int32_t, PartyMax, partyMax)
        GENERATE_GETSET_VALUE(PartyPrivacy, PartyPrivacy, partyPrivacy)
        GENERATE_GETSET_VALUE(ActivityType, ActivityType, activityType)
        GENERATE_GETSET_VALUE(StatusDisplayType, StatusDisplayType, statusDisplayType)
        GENERATE_GETSET_LRVALUE(std::string, MatchSecret, matchSecret)
        GENERATE_GETSET_LRVALUE(std::string, JoinSecret, joinSecret)
        GENERATE_GETSET_LRVALUE(std::string, SpectateSecret, spectateSecret)
        GENERATE_GETSET_VALUE(bool, Instance, instance)

        GENERATE_GETSET_BUTTON(1)
        GENERATE_GETSET_BUTTON(2)

        #undef GENERATE_GETSET_BUTTON
        #undef GENERATE_GETSET_LRVALUE
        #undef GENERATE_GETSET_VALUE

        Presence& clear() noexcept;

        /// Calls the RPCManager::refresh() function to update the presence
        void refresh() const noexcept;

    private:
        std::string m_state;
        std::string m_details;
        int64_t m_startTimestamp = 0;
        int64_t m_endTimestamp = 0;
        std::string m_largeImageKey;
        std::string m_largeImageText;
        std::string m_smallImageKey;
        std::string m_smallImageText;
        std::string m_partyID;
        int32_t m_partySize = 0;
        int32_t m_partyMax = 0;
        PartyPrivacy m_partyPrivacy = PartyPrivacy::Private;
        ActivityType m_activityType = ActivityType::Game;
        StatusDisplayType m_statusDisplayType = StatusDisplayType::Name;
        std::string m_matchSecret;
        std::string m_joinSecret;
        std::string m_spectateSecret;
        std::array<Button, 2> m_buttons;
        bool m_instance = false;
    };
}

#endif // DISCORD_RPC_PRESENCE_HPP