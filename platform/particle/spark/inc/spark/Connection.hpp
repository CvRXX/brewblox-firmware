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

#pragma once
#include <functional>
#include <memory>
#include <optional>
#include <string>

namespace platform::particle {

enum class ConnectionKind : uint8_t {
    Mock = 0,
    Usb = 1,
    Tcp = 2,
};

enum Separator : char {
    NONE = 0,
    CHUNK = ',',
    MESSAGE = '\n',
};

class ResponseWriter {
public:
    ResponseWriter(const ResponseWriter&) = delete;
    ResponseWriter& operator=(const ResponseWriter&) = delete;

    ResponseWriter(ResponseWriter&&) = default;
    ResponseWriter& operator=(ResponseWriter&&) = default;

    virtual ~ResponseWriter() = default;

    virtual ConnectionKind kind() const = 0;

    virtual bool write(const std::string& message) = 0;

    virtual bool write(Separator sep)
    {
        return write(std::string(1, sep));
    }

    virtual bool writeLog(const std::string& message)
    {
        return write("<")
               && write(message)
               && write(">");
    }

    virtual void commit() = 0;
};

class Connection : public ResponseWriter {
public:
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

    Connection(Connection&&) = default;
    Connection& operator=(Connection&&) = default;

    virtual ~Connection() = default;

    virtual std::optional<std::string> readMessage() = 0;
    virtual bool isConnected() = 0;
    virtual void stop() = 0;
};

class ConnectionSource {
public:
    ConnectionSource() = default;
    virtual ~ConnectionSource() = default;

    virtual std::unique_ptr<Connection> newConnection() = 0;

    virtual void start() = 0;
    virtual void stop() = 0;
};

} // end namespace platform::particle
