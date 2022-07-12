/*
 * Copyright 2013 Matthew McGowan
 * Copyright 2013 BrewPi/Elco Jacobs.
 *
 * This file is part of BrewPi.
 *
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "control/DS2413.hpp"
#include "control/OneWire.hpp"

bool DS2413::update()
{
    bool success = false;
    if (auto oneWire = selectRom()) {
        if (!writeNeeded()) { // skip read if we need to write anyway, which also returns status
            if (!oneWire->write(ACCESS_READ)) {
                return false;
            }
            uint8_t status;
            if (!oneWire->read(status)) {
                return false;
            }
            success = processStatus(status);
            connected(success);
        }

        if (writeNeeded()) { // check again
            oneWire->reset();
            oneWire->select(m_address);
            uint8_t data = (desiredState & 0b1000) >> 2 | (desiredState & 0b0010) >> 1;
            uint8_t bytes[3] = {ACCESS_WRITE, data, uint8_t(~data)};

            if (oneWire->write_bytes(bytes, 3)) {
                /* Acknowledgement byte, 0xAA for success, 0xFF for failure. */

                if (oneWire->read(data) && data == ACK_SUCCESS) {
                    if (oneWire->read(data)) {
                        success = processStatus(data);
                    }
                }
            }
        }
        oneWire->reset();
        connected(success);
        return success;
    }
    connected(false);
    return false;
}

bool DS2413::writeNeeded()
{
    return !connected() || (desiredState & 0b1010) != (actualState & 0b1010);
}

uint8_t bitMask(uint8_t channel)
{
    if (channel == 1) {
        return 0b0010;
    }
    if (channel == 2) {
        return 0b1000;
    }
    return 0x00;
}

IoArray::ChannelValue DS2413::writeChannelImpl(uint8_t channel, IoArray::ChannelValue val)
{
    bool latchEnabled = val.has_value() && *val > 0;

    if (latchEnabled) {
        desiredState &= ~bitMask(channel);
    } else {
        desiredState |= bitMask(channel);
    }
    if (writeNeeded()) {
        // only directly update when connected, to prevent disconnected devices to continuously try to update
        // they will reconnect in the normal update tick, which should happen every second
        update();
    }
    return readChannelImpl(channel);
}

IoArray::ChannelValue DS2413::readChannelImpl(uint8_t channel) const
{
    if (connected()) {
        // to reduce onewire communication, we assume the last read value in update() is correct
        // only in update(), actual onewire communication will take place to get the latest state
        if (channel == 1) {
            return (actualState & 0b0001) == 0 ? ChannelValue{1} : ChannelValue{0};
        } else if (channel == 2) {
            return (actualState & 0b0100) == 0 ? ChannelValue{1} : ChannelValue{0};
        }
    }
    return ChannelValue{};
}

bool DS2413::setChannelTypeImpl(uint8_t channel, ChannelType chanType)
{
    if (chanType == ChannelType::OUTPUT_DIGITAL || chanType == ChannelType::INPUT_DIGITAL) {
        // disable latch. For inputs it stays disabled. For outputs it can be toggled later.
        writeChannelImpl(channel, 0);
        return true;
    }
    return false;
}

bool DS2413::processStatus(uint8_t data)
{
    uint8_t newState = data & 0x0F;
    uint8_t verification = ((~data) >> 4) & 0xF;
    if (newState == verification) {
        actualState = newState;
        return true;
    }
    return false;
}
