/*
 * Copyright 2014-2015 Matthew McGowan.
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

#include "cbox/ConnectionPool.hpp"
#include "cbox/Application.hpp"
#include <algorithm>

namespace cbox {

ConnectionPool::ConnectionPool(std::initializer_list<std::reference_wrapper<ConnectionSource>> list)
    : connectionSources(list)
{
}

void ConnectionPool::updateConnections()
{
    connections.erase(
        std::remove_if(connections.begin(), connections.end(), [](const decltype(connections)::value_type& conn) {
            return !conn->isConnected(); // remove disconnected connections from pool
        }),
        connections.end());

    for (auto& source : connectionSources) {
        while (true) {
            auto con = source.get().newConnection();
            if (!con) {
                break;
            }

            if (connections.size() >= 4) {
                auto oldest = connections.begin();
                (*oldest)->writeLog("Max connections exceeded, closing oldest");
                (*oldest)->commit();
                connections.erase(oldest);
            }

            con->writeLog(handshakeMessage());
            con->commit();
            connections.push_back(std::move(con));
        }
    }
}

void ConnectionPool::process(std::function<void(ConnectionOut&, const std::string&)> handler)
{
    updateConnections();
    for (auto& conn : connections) {
        while (auto msg = conn->readMessage()) {
            handler(*conn, msg.value());
            conn->commit();
        }
    }
}

void ConnectionPool::writeLog(const std::string& message)
{
    for (auto& conn : connections) {
        conn->writeLog(message);
        conn->commit();
    }
}

void ConnectionPool::stopAll()
{
    disconnect();
    for (auto& source : connectionSources) {
        source.get().stop();
    }
}

void ConnectionPool::startAll()
{
    for (auto& source : connectionSources) {
        source.get().start();
    }
}

} // end namespace cbox
