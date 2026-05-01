#pragma once
#ifndef DISCORD_RPC_CONNECTION_HPP
#define DISCORD_RPC_CONNECTION_HPP

#include "serialization.hpp"
#include "platform/platform.hpp"

#include <string>
#include <fmt/format.h>

namespace discord {
    struct HandshakeResponse {
        std::string cmd;
        struct Data { User user; } data;
        std::string evt;

        [[nodiscard]] User const& toUser() const noexcept { return data.user; }
    };

    struct ClosePacket {
        int code;
        std::string message;
    };

    enum class ErrorCode : int32_t {
        Unknown     = -1,
        Success     = 0,
        PipeClosed  = 1,
        ReadCorrupt = 2,
    };

    constexpr ErrorCode toErr(int32_t v) noexcept { return static_cast<ErrorCode>(v); }
    constexpr int32_t toInt(ErrorCode v) noexcept { return static_cast<int32_t>(v); }

    class Connection {
    private:
        inline static Connection* s_instance = nullptr;

        Connection() noexcept = default;
        ~Connection() noexcept {
            this->close();
        }

    public:
        static Connection& get() noexcept {
            if (!s_instance) {
                s_instance = new Connection();
            }
            return *s_instance;
        }

        static void destroyInstance() {
            delete s_instance;
            s_instance = nullptr;
        }

        Connection(Connection const&) = delete;
        Connection(Connection&&) = delete;
        Connection& operator=(Connection const&) = delete;
        Connection& operator=(Connection&&) = delete;

        enum class Opcode : uint32_t {
            Handshake = 0,
            Frame     = 1,
            Close     = 2,
            Ping      = 3,
            Pong      = 4,
        };

        enum class State : uint32_t {
            Disconnected     = 0,
            SentHandshake    = 1,
            AwaitingResponse = 2,
            Connected        = 3,
        };

        struct MessageFrame {
            static constexpr auto MaxSize = 64 * 1024;
            static constexpr auto HeaderSize = sizeof(Opcode) + sizeof(uint32_t);
            static constexpr auto MaxDataSize = MaxSize - HeaderSize;

            Opcode opcode;
            uint32_t length;
            uint8_t data[MaxDataSize];

            [[nodiscard]] size_t size() const noexcept { return length + HeaderSize; }

            void setMessage(Opcode opcode, size_t length, uint8_t const* data) noexcept {
                this->opcode = opcode;
                this->length = std::min(length, MaxDataSize);
                std::memcpy(this->data, data, length);
            }

            void setMessage(Opcode opcode, std::string_view data) noexcept {
                return this->setMessage(opcode, data.size(), reinterpret_cast<uint8_t const*>(data.data()));
            }
        };

        [[nodiscard]] bool isOpen() const { return m_state == State::Connected; }

        void sendError() const {
            RPCManager::get().invokeOnErrored(toInt(m_lastError), m_lastErrorMessage);
        }

        void open(std::string_view appID) noexcept {
            if (m_state == State::Connected) {
                return;
            }

            if (m_state == State::Disconnected && !m_pipe.open()) {
                return;
            }

            if (m_state == State::SentHandshake) {
                std::string buffer;
                if (!this->read(buffer)) {
                    return;
                }

                HandshakeResponse packet;
                if (glz::read<glz::opts{.error_on_unknown_keys = false}>(packet, buffer)) {
                    m_lastError = ErrorCode::ReadCorrupt;
                    m_lastErrorMessage = "Failed to read handshake response";
                    this->close();
                    sendError();
                    return;
                }

                if (packet.cmd != "DISPATCH" || packet.evt != "READY") {
                    m_lastError = ErrorCode::ReadCorrupt;
                    m_lastErrorMessage = "Unexpected handshake response";
                    this->close();
                    sendError();
                    return;
                }

                m_state = State::Connected;
                RPCManager::get().invokeOnReady(packet.toUser());
                return;
            }

            m_frame->opcode = Opcode::Handshake;
            m_frame->length = serializeHandshake(
                m_frame->data, MessageFrame::MaxDataSize,
                1, appID
            );

            if (m_pipe.write(m_frame.get(), m_frame->size())) {
                m_state = State::SentHandshake;
            } else {
                this->close();
            }
        }

        void close() {
            if (m_state == State::Disconnected) {
                return;
            }

            RPCManager::get().invokeOnDisconnected(toInt(m_lastError), m_lastErrorMessage);
            m_pipe.close();
            m_state = State::Disconnected;
        }

        bool write(std::string_view buffer) {
            if (m_state != State::Connected) {
                return false;
            }

            m_frame->setMessage(Opcode::Frame, buffer);

            if (!m_pipe.write(m_frame.get(), m_frame->size())) {
                this->close();
                return false;
            }

            return true;
        }

        [[nodiscard]] ErrorCode lastError() const noexcept { return m_lastError; }
        [[nodiscard]] std::string const& lastErrorMessage() const noexcept { return m_lastErrorMessage; }

        bool read(std::string& buffer) {
            if (m_state != State::Connected && m_state != State::SentHandshake) {
                return false;
            }

            do {
                // Read header
                bool success = m_pipe.read(m_frame.get(), MessageFrame::HeaderSize);
                if (!success) {
                    if (!m_pipe.isOpen()) {
                        m_lastError = ErrorCode::PipeClosed;
                        m_lastErrorMessage = "Pipe closed";
                        this->close();
                        sendError();
                    }
                    return false;
                }

                // Read data
                if (m_frame->length > 0) {
                    success = m_pipe.read(m_frame->data, m_frame->length);
                    if (!success) {
                        m_lastError = ErrorCode::ReadCorrupt;
                        m_lastErrorMessage = "Partial data in frame";
                        this->close();
                        sendError();
                        return false;
                    }
                    m_frame->data[m_frame->length] = '\0';
                }

                switch (m_frame->opcode) {
                    case Opcode::Frame: {
                        buffer.assign(reinterpret_cast<char*>(m_frame->data), m_frame->length);
                        return true;
                    }
                    case Opcode::Close: {
                        buffer.assign(reinterpret_cast<char*>(m_frame->data), m_frame->length);
                        ClosePacket packet;
                        if (glz::read<glz::opts{.error_on_unknown_keys = false}>(packet, buffer)) {
                            m_lastError = ErrorCode::ReadCorrupt;
                            m_lastErrorMessage = "Failed to read close packet";
                            sendError();
                        } else {
                            m_lastError = toErr(packet.code);
                            m_lastErrorMessage = packet.message;
                            sendError();
                        }
                        this->close();
                        return false;
                    }
                    case Opcode::Ping: {
                        m_frame->opcode = Opcode::Pong;
                        if (!m_pipe.write(m_frame.get(), m_frame->size())) {
                            this->close();
                            return false;
                        }
                    } break;
                    case Opcode::Pong: break;
                    case Opcode::Handshake:
                    default: {
                        m_lastError = ErrorCode::ReadCorrupt;
                        m_lastErrorMessage = "Bad IPC opcode";
                        this->close();
                        sendError();
                        return false;
                    }
                }
            } while (true);
        }

        [[nodiscard]] MessageFrame& getFrame() const noexcept { return *m_frame; }

    private:
        platform::PipeConnection m_pipe{};
        State m_state = State::Disconnected;
        std::unique_ptr<MessageFrame> m_frame = std::make_unique<MessageFrame>();
        ErrorCode m_lastError = ErrorCode::Success;
        std::string m_lastErrorMessage{};
    };
}

#endif // DISCORD_RPC_CONNECTION_HPP
