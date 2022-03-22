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
#include <memory>
#include <queue>
#include <sstream>

namespace cbox {

/**
 * A connection source that emulates a connection by two string streams, used for testing
 *
 **/

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

    virtual std::optional<std::string> readMessage() override final
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

    virtual bool write(const std::string& message) override final
    {
        *out << message;
        return true;
    }

    virtual void commit() override final
    {
        // we don't need to flush a stringstream
    }

    virtual StreamType streamType() const override final
    {
        return StreamType::Mock;
    }

    virtual bool isConnected() override final
    {
        return !(in->bad() || out->bad()); // use badbit of either stream to simulate disconnect
    }

    virtual void stop() override final
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

    virtual std::unique_ptr<Connection> newConnection() override final
    {
        if (connectionQueue.empty()) {
            return nullptr;
        }
        std::unique_ptr<Connection> retval = std::move(connectionQueue.front());
        connectionQueue.pop();
        return retval;
    }

    virtual void stop() override final
    {
    }

    virtual void start() override final
    {
    }
};
} // end namespace cbox
