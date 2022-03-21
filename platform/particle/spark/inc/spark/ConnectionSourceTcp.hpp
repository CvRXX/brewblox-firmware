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

#include "cbox/Connection.hpp"
#include "spark_wiring_tcpclient.h"
#include "spark_wiring_tcpserver.h"
#include "spark_wiring_wifi.h"

namespace cbox {

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

    virtual std::optional<std::string> readMessage() override final
    {
        buffer.resize(buffer.size() + client.available());
        client.readBytes(buffer.data() + buffer.size(), client.available());

        auto newlinePos = buffer.find_first_of('\n');
        if (newlinePos == std::string::npos) {
            return std::nullopt;
        }

        std::string message = buffer.substr(0, newlinePos + 1);
        buffer.erase(0, newlinePos + 1);
        return std::make_optional(message);
    }

    virtual bool write(const std::string& message) override final
    {
        return client.write((const uint8_t*)message.c_str(), message.size()) == message.size();
    }

    virtual StreamType streamType() const override final
    {
        return StreamType::Tcp;
    }

    virtual bool isConnected() override final
    {
        return client.status();
    }

    virtual void stop() override final
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

    std::unique_ptr<Connection> newConnection() override final
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

    virtual void stop() override final
    {
        server.stop();
        server_enabled = false;
    }

    virtual void start() override final
    {
        server_enabled = true;
        server.begin();
    }
};

} // end namespace cbox
