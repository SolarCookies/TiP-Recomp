#pragma once
#ifndef DISCORD_SERIALIZATION_HPP
#define DISCORD_SERIALIZATION_HPP

#include <glaze/glaze.hpp>

#include <cstdint>
#include <string>

namespace discord {
    class Presence;

    void serializeEmptyPresence(std::string& buffer, size_t pid, int nonce);
    void serializePresence(std::string& buffer, Presence const& presence, size_t pid, int nonce);
    size_t serializeHandshake(uint8_t* buf, size_t bufSize, uint32_t rpcVersion, std::string_view appID);
    size_t serializeSubscribeCommand(uint8_t* buf, size_t bufSize, int nonce, std::string_view event);
    size_t serializeUnsubscribeCommand(uint8_t* buf, size_t bufSize, int nonce, std::string_view event);
}

#endif // DISCORD_SERIALIZATION_HPP