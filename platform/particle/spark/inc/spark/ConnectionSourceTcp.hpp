/*
 * Copyright 2018 Brewblox / Elco Jacobs
 *
 * This file is part of Brewblox.
 *
 * Controlbox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cbox/Base64.hpp"
#include "spark/Connection.hpp"
#include "spark_wiring_tcpclient.h"
#include "spark_wiring_tcpserver.h"
#include "spark_wiring_wifi.h"

namespace platform::particle {

class TcpConnection : public Connection {
private:
    TCPClient client;
    std::string buffer;

public:
    explicit TcpConnection(TCPClient&& _client)
        : client(std::move(_client))
    {
    }
    virtual ~TcpConnection() = default;

    std::optional<std::string> readMessage() final
    {
        bool hasMessage = false;
        buffer.reserve(buffer.size() + client.available());

        while (true) {
            auto c = client.read();
            if (c < 0) {
                break;
            }
            if (c == Separator::MESSAGE) {
                hasMessage = true;
                break;
            }
            buffer.push_back((uint8_t)c);
        }

        if (!hasMessage) {
            return std::nullopt;
        }

        // spool until next message start
        while (true) {
            auto c = client.peek();
            if (c < 0 || cbox::is_b64(c)) {
                break;
            }
            client.read();
        }

        std::string line;
        line.swap(buffer);
        return std::make_optional(std::move(line));
    }

    bool write(const std::string& message) final
    {
        return client.write(reinterpret_cast<const uint8_t*>(message.data()),
                            message.size())
               == message.size();
    }

    void commit() final
    {
        client.flush();
    }

    ConnectionKind kind() const final
    {
        return ConnectionKind::Tcp;
    }

    bool isConnected() final
    {
        return client.status();
    }

    void stop() final
    {
        client.stop();
    }
};

class TcpConnectionSource : public ConnectionSource {
private:
    TCPServer server;
    bool server_started = false;
    bool server_enabled = false;

public:
    TcpConnectionSource(uint16_t port)
        : server(port)
    {
    }
    virtual ~TcpConnectionSource() = default;

    std::unique_ptr<Connection> newConnection() final
    {
        if (spark::WiFi.ready()) {
            if (server_enabled && !server_started) {
                server_started = server.begin();
            }

            TCPClient newClient = server.available();
            if (newClient) {
                newClient.setTimeout(100);
                return std::make_unique<TcpConnection>(std::move(newClient));
            }
        } else {
            stop();
        }
        return std::unique_ptr<Connection>();
    }

    void stop() final
    {
        server.stop();
        server_enabled = false;
    }

    void start() final
    {
        server_enabled = true;
        server.begin();
    }
};
} // end namespace platform::particle
