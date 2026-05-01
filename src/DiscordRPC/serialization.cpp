#include "serialization.hpp"

#include <discord-rpc.hpp>
#include <fmt/format.h>

struct Timestamps {
    std::optional<int64_t> start;
    std::optional<int64_t> end;
    constexpr Timestamps(int64_t start, int64_t end) noexcept {
        if (start) { this->start = start; }
        if (end) { this->end = end; }
    }
};

struct Assets {
    std::optional<std::string_view> large_image;
    std::optional<std::string_view> large_text;
    std::optional<std::string_view> small_image;
    std::optional<std::string_view> small_text;
    constexpr Assets(
        std::string_view large_image,
        std::string_view large_text,
        std::string_view small_image,
        std::string_view small_text
    ) noexcept {
        if (!large_image.empty()) { this->large_image = large_image; }
        if (!large_text.empty()) { this->large_text = large_text; }
        if (!small_image.empty()) { this->small_image = small_image; }
        if (!small_text.empty()) { this->small_text = small_text; }
    }
};

struct Party {
    std::optional<std::string_view> id;
    std::optional<std::array<int, 2>> size;
    discord::PartyPrivacy privacy;

    constexpr Party(
        std::string const& id,
        int size, int max,
        discord::PartyPrivacy privacy
    ) noexcept : privacy(privacy) {
        if (!id.empty()) { this->id = id; }
        if (size && max) { this->size = std::array{size, max}; }
    }
};

struct Secrets {
    std::optional<std::string_view> match;
    std::optional<std::string_view> join;
    std::optional<std::string_view> spectate;
    constexpr Secrets(
        std::string_view match,
        std::string_view join,
        std::string_view spectate
    ) noexcept {
        if (!match.empty()) { this->match = match; }
        if (!join.empty()) { this->join = join; }
        if (!spectate.empty()) { this->spectate = spectate; }
    }
};

struct Button {
    std::string_view label;
    std::string_view url;
    constexpr Button(std::string_view label, std::string_view url) noexcept : label(label), url(url) {}
};

template <>
struct glz::meta<Timestamps> {
    using T = Timestamps;
    static constexpr auto value = object(
        "start", &T::start,
        "end", &T::end
    );
};

template <>
struct glz::meta<Assets> {
    using T = Assets;
    static constexpr auto value = object(
        "large_image", &T::large_image,
        "large_text", &T::large_text,
        "small_image", &T::small_image,
        "small_text", &T::small_text
    );
};

template <>
struct glz::meta<Party> {
    using T = Party;
    static constexpr auto value = object(
        "id", &T::id,
        "size", &T::size,
        "privacy", &T::privacy
    );
};

template <>
struct glz::meta<Secrets> {
    using T = Secrets;
    static constexpr auto value = object(
        "match", &T::match,
        "join", &T::join,
        "spectate", &T::spectate
    );
};

template <>
struct glz::meta<Button> {
    using T = Button;
    static constexpr auto value = object(
        "label", &T::label,
        "url", &T::url
    );
};

template <>
struct glz::meta<discord::Presence> {
    using T = discord::Presence;
    static constexpr auto value = object(
        "state", [](auto&& self) -> std::optional<std::string_view> {
            if (self.getState().empty()) {
                return std::nullopt;
            }
            return self.getState();
        },
        "details", [](auto&& self) -> std::optional<std::string_view> {
            if (self.getDetails().empty()) {
                return std::nullopt;
            }
            return self.getDetails();
        },
        "timestamps", [](auto&& self) -> std::optional<Timestamps> {
            auto start = self.getStartTimestamp();
            auto end = self.getEndTimestamp();

            if (start || end) {
                return Timestamps {start, end};
            }

            return std::nullopt;
        },
        "assets", [](auto&& self) -> std::optional<Assets> {
            auto& large_image = self.getLargeImageKey();
            auto& large_text = self.getLargeImageText();
            auto& small_image = self.getSmallImageKey();
            auto& small_text = self.getSmallImageText();

            if (!large_image.empty() || !large_text.empty() || !small_image.empty() || !small_text.empty()) {
                return Assets {large_image, large_text, small_image, small_text};
            }

            return std::nullopt;
        },
        "party", [](auto&& self) -> std::optional<Party> {
            auto& id = self.getPartyID();
            auto size = self.getPartySize();
            auto max = self.getPartyMax();
            auto privacy = self.getPartyPrivacy();

            if (!id.empty() || size || max || privacy != discord::PartyPrivacy::Private) {
                return Party {id, size, max, privacy};
            }

            return std::nullopt;
        },
        "secrets", [](auto&& self) -> std::optional<Secrets> {
            auto& match = self.getMatchSecret();
            auto& join = self.getJoinSecret();
            auto& spectate = self.getSpectateSecret();

            if (!match.empty() || !join.empty() || !spectate.empty()) {
                return Secrets {match, join, spectate};
            }

            return std::nullopt;
        },
        "buttons", [](auto&& self) -> std::optional<std::vector<Button>> {
            auto& btn1 = self.getButton1();
            auto& btn2 = self.getButton2();

            if (!btn1.isEnabled() && !btn2.isEnabled()) {
                return std::nullopt;
            }

            // if secrets are set, buttons are disabled
            if (!self.getMatchSecret().empty() || !self.getJoinSecret().empty() || !self.getSpectateSecret().empty()) {
                return std::nullopt;
            }

            std::vector<Button> buttons;
            buttons.reserve(2);
            if (btn1.isEnabled()) { buttons.emplace_back(btn1.getLabel(), btn1.getURL()); }
            if (btn2.isEnabled()) { buttons.emplace_back(btn2.getLabel(), btn2.getURL()); }

            return buttons;
        },
        "instance", [](auto&& self) { return self.getInstance(); },
        "type", [](auto&& self) { return self.getActivityType(); },
        "status_display_type", [](auto&& self) { return self.getStatusDisplayType(); }
    );
};

namespace discord {
    void serializeEmptyPresence(std::string& buffer, size_t pid, int nonce) {
        buffer = fmt::format(
            R"({{"nonce":"{}","cmd":"SET_ACTIVITY","args":{{"pid":{}}}}})",
            nonce, pid
        );
    }

    void serializePresence(std::string& buffer, Presence const& presence, size_t pid, int nonce) {
        auto res = glz::write<glz::opts{.error_on_unknown_keys = false}>(presence);
        if (!res) {
            buffer = "";
            return;
        }

        buffer = fmt::format(
            R"({{"nonce":"{}","cmd":"SET_ACTIVITY","args":{{"pid":{},"activity":{}}}}})",
            nonce, pid, res.value()
        );
    }

    size_t serializeHandshake(uint8_t* buf, size_t bufSize, uint32_t rpcVersion, std::string_view appID) {
        constexpr auto format = R"({{"v":{},"client_id":"{}"}})";
        auto size = fmt::formatted_size(format, rpcVersion, appID);
        if (size > bufSize) { return 0; }
        fmt::format_to(buf, format, rpcVersion, appID);
        return size;
    }

    size_t serializeSubscribeCommand(uint8_t* buf, size_t bufSize, int nonce, std::string_view event) {
        constexpr auto format = R"({{"nonce":"{}","cmd":"SUBSCRIBE","evt":"{}"}})";
        auto size = fmt::formatted_size(format, nonce, event);
        if (size > bufSize) { return 0; }
        fmt::format_to(buf, format, nonce, event);
        return size;
    }

    size_t serializeUnsubscribeCommand(uint8_t* buf, size_t bufSize, int nonce, std::string_view event) {
        constexpr auto format = R"({{"nonce":"{}","cmd":"UNSUBSCRIBE","evt":"{}"}})";
        auto size = fmt::formatted_size(format, nonce, event);
        if (size > bufSize) { return 0; }
        fmt::format_to(buf, format, nonce, event);
        return size;
    }
}


