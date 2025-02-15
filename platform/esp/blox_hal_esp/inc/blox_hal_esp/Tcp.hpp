/*
 * Copyright 2020 BrewPi B.V./Elco Jacobs.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cbox/Connection.hpp"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

namespace cbox {

class TcpConnection : Connection {
public:
    explicit TcpConnection(TCPClient&& _client)
        : StreamConnection<TCPClient>(std::move(_client))
    {
    }
    virtual ~TcpConnection() = default;

    void stop() final
    {
        get().stop();
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
        if (spark::WiFi.ready() && !spark::WiFi.listening()) {
            if (server_enabled && !server_started) {
                server_started = server.begin();
            }

            TCPClient newClient = server.available();
            if (newClient) {
                newClient.setTimeout(100);
                return std::make_unique<TcpConnection>(std::move(newClient));
            }
        } else {
            server_started = false;
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

} // end namespace cbox
