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
#include "spark/Connection.hpp"
#include <memory>
#include <queue>
#include <sstream>

/**
 * A connection source that emulates a connection by two string streams, used for testing
 *
 **/

namespace platform::particle {

class StringStreamConnection : public Connection {
private:
    std::shared_ptr<std::stringstream> in;
    std::shared_ptr<std::stringstream> out;

public:
    StringStreamConnection(std::shared_ptr<std::stringstream> _in, std::shared_ptr<std::stringstream> _out)
        : in(_in)
        , out(_out)
    {
    }

    virtual ~StringStreamConnection()
    {
        stop();
    }

    std::optional<std::string> readMessage() final
    {
        // We'll just assume there won't be any partial messages
        std::string buf;
        std::getline(*in, buf);
        if (buf.size()) {
            return buf;
        } else {
            return std::nullopt;
        }
    }

    bool write(const std::string& message) final
    {
        *out << message;
        return true;
    }

    void commit() final
    {
        // we don't need to flush a stringstream
    }

    ConnectionKind kind() const final
    {
        return ConnectionKind::Mock;
    }

    bool isConnected() final
    {
        return !(in->bad() || out->bad()); // use badbit of either stream to simulate disconnect
    }

    void stop() final
    {
        in->setstate(std::istream::badbit);
        out->setstate(std::ostream::badbit);
    }
};

class StringStreamConnectionSource : public ConnectionSource {
private:
    std::queue<std::unique_ptr<StringStreamConnection>> connectionQueue;

public:
    StringStreamConnectionSource() = default;
    virtual ~StringStreamConnectionSource() = default;

    void add(std::shared_ptr<std::stringstream> in, std::shared_ptr<std::stringstream> out)
    {
        auto newConnection = std::make_unique<StringStreamConnection>(in, out);
        connectionQueue.push(std::move(newConnection));
    }

    std::unique_ptr<Connection> newConnection() final
    {
        if (connectionQueue.empty()) {
            return nullptr;
        }
        std::unique_ptr<Connection> retval = std::move(connectionQueue.front());
        connectionQueue.pop();
        return retval;
    }

    void stop() final
    {
    }

    void start() final
    {
    }
};
} // end namespace platform::particle
