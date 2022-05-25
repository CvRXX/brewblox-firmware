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
#include "spark_wiring_usbserial.h"

namespace platform::particle {

static bool serial_connection_active = false;

class SerialConnection : public Connection {
private:
    std::string buffer;
    USBSerial& stream;

public:
    SerialConnection(USBSerial& ser)
        : stream(ser)
    {
        serial_connection_active = true;
    }

    virtual ~SerialConnection()
    {
        stop();
        serial_connection_active = false;
    };

    std::optional<std::string> readMessage() final
    {
        bool hasMessage = false;
        buffer.reserve(buffer.size() + 50); // ballpark guess, stream.available() is never >1

        while (true) {
            auto c = stream.read();
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
            auto c = stream.peek();
            if (c < 0 || cbox::is_b64(c)) {
                break;
            }
            stream.read();
        }

        std::string line;
        line.swap(buffer);
        return std::make_optional(std::move(line));
    }

    bool write(const std::string& message) final
    {
        return stream.write(reinterpret_cast<const uint8_t*>(message.data()),
                            message.size())
               == message.size();
    }

    void commit() final
    {
        stream.flush();
    }

    ConnectionKind kind() const final
    {
        return ConnectionKind::Usb;
    }

    bool isConnected() final
    {
        return stream.isConnected();
    }

    void stop() final
    {
        stream.flush();
    }
};

class SerialConnectionSource : public ConnectionSource {
private:
    bool serial_enabled = false;
    USBSerial& ser;

public:
    SerialConnectionSource(USBSerial& serial)
        : ser(serial)
    {
    }

    std::unique_ptr<Connection> newConnection() final
    {
        if (serial_enabled && !serial_connection_active && ser.isConnected()) {
            return std::make_unique<SerialConnection>(ser);
        }
        return std::unique_ptr<Connection>();
    }

    void start() final
    {
        serial_enabled = true;
        ser.begin(115200);
    }

    void stop() final
    {
        // ser.end(); Don't close serial, leave it open
        serial_enabled = false;
    }
};

} // end namespace platform::particle
