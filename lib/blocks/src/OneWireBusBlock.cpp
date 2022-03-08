/*
 * Copyright 2020 BrewPi B.V.
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

#include "blocks/OneWireBusBlock.h"
#include "control/OneWire.h"
#include "control/OneWireAddress.h"
#include "pb_encode.h"
#include <limits>

bool streamAdresses(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    OneWireAddress address;
    OneWire* busPtr = reinterpret_cast<OneWire*>(*arg);
    if (busPtr == nullptr) {
        return false;
    }
    while (busPtr->search(address)) {
        if (!pb_encode_tag_for_field(stream, field)) {
            return false;
        }
        uint64_t addr = uint64_t(address);
        if (!pb_encode_fixed64(stream, &addr)) {
            return false;
        }
    }
    return true;
}

OneWireBusBlock::OneWireBusBlock(OneWire& ow, void (*onShortDetected_)())
    : bus(ow)
    , command({NO_OP, 0})
{
    onShortDetected = onShortDetected_;
    bus.init();
}

/**
 * Read value
 * - an ID encoded as a variable length ID chain (values > 0x80 mean there is more data)
 * - previous command data count - N
 * - previous command data - N bytes
 * - command rsult (variable length)
 * - cmd 00: no-op always 00 (success)
 * - cmd 01: reset bus (00 on success, FF on failure)
 * - cmd 02: search bus: a sequence of 0 or more 8-byte addresses, MSB first that were found on the bus
 */
cbox::CboxError
OneWireBusBlock::read(cbox::Command& cmd) const
{
    blox_OneWireBus_Block message = blox_OneWireBus_Block_init_zero;
    message.command = command;
    message.address.funcs.encode = nullptr;
    message.address.arg = &bus;
    switch (command.opcode) {
    case NO_OP:
        break;
    case RESET:
        bus.reset();
        break;
    case SEARCH:
        bus.reset_search();
        if (command.data) {
            bus.target_search(command.data);
        }
        message.address.funcs.encode = &streamAdresses;
        break;
    }
    // commands are one-shot - once the command is done clear it.
    command.opcode = NO_OP;
    command.data = 0;

    return writeProtoToCommand(cmd,
                               &message,
                               blox_OneWireBus_Block_fields,
                               100, // TODO(Bob): pick sensible value
                               objectId,
                               staticTypeId());
}

cbox::CboxError
OneWireBusBlock::readPersisted(cbox::Command&) const
{
    return cbox::CboxError::PERSISTING_NOT_NEEDED;
}

/**
 * Set the command to be executed next from the input stream
 * - byte 0: command
 *   00: no-op
 *   01: reset bus
 *   02: search bus:
 *   03: search the bus, limiting to the given family code byte passed as data
 *   (later: search bus alarm state?)
 *   (later: set bus power? (off if next byte is 00, on if it's 01) )
 */
cbox::CboxError
OneWireBusBlock::write(cbox::Command& cmd)
{
    blox_OneWireBus_Block message = blox_OneWireBus_Block_init_zero;
    auto res = readProtoFromCommand(cmd, &message, blox_OneWireBus_Block_fields);

    if (res == cbox::CboxError::OK) {
        command = message.command;
    }

    return res;
}

void* OneWireBusBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == brewblox_BlockType_OneWireBus) {
        return this; // me!
    }
    if (iface == cbox::interfaceId<OneWire>()) {
        // return the member that implements the interface in this case
        OneWire* owPtr = &bus;
        return owPtr;
    }
    return nullptr;
}

cbox::update_t OneWireBusBlock::update(const cbox::update_t& now)
{
    if (onShortDetected) {
        if (bus.shortDetected()) {
            onShortDetected();
            bus.init();
        }
    }
    return update_1s(now);
}

void (*OneWireBusBlock::onShortDetected)();
