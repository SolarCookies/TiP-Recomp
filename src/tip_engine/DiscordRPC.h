// Minimal Discord Rich Presence client.
//
// Communicates with the local Discord client over a named pipe (IPC), using a
// hand-rolled JSON payload — no third-party dependencies.
//
// To make Discord display "Playing ReTiP", create an Application named "ReTiP"
// at https://discord.com/developers/applications and paste its Application ID
// into kDiscordClientID in DiscordRPC.cpp. Upload artwork there and reference
// the asset names via SetLargeImage/SetSmallImage.
#pragma once

#include <string>

namespace retip::discord_rpc {

struct Presence {
    std::string details;         // first line under the title, e.g. "In Main Menu"
    std::string state;           // second line, e.g. "Level 196"
    std::string largeImageKey;   // asset name from the Developer Portal
    std::string largeImageText;  // tooltip shown on hover
    std::string smallImageKey;
    std::string smallImageText;
};

// Spawns a background thread (idempotent). Sets the initial presence.
void Start(const Presence& initial = {});

// Convenience overload: only details/state.
void Start(const std::string& details, const std::string& state = "");

// Updates the presence; the worker thread will push it on the next tick.
void SetPresence(const Presence& p);

// Per-field setters for incremental updates from gameplay code.
void SetDetails(const std::string& details);
void SetState(const std::string& state);
void SetLargeImage(const std::string& key, const std::string& text = "");
void SetSmallImage(const std::string& key, const std::string& text = "");

// Stops the worker and clears the presence.
void Stop();

}  // namespace retip::discord_rpc
