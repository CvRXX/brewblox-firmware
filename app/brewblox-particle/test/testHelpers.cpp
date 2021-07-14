/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of BrewBlox.
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

#include "testHelpers.h"
#include <google/protobuf/message.h>

void ProtoDataOut::put(const ::google::protobuf::Message& message)
{
    for (auto& c : message.SerializeAsString()) {
        out.write(c);
    }
    out.write(0); // zero terminate protobuf message
}

void decodeProtoFromReply(std::stringstream& ss, ::google::protobuf::Message& message)
{
    cbox::IStreamDataIn hex(ss);
    cbox::HexTextToBinaryIn decoder(hex);
    while (hex.read() != '|') { // spool command echo
    }
    // spool status, id, groups and object type
    uint8_t header[6];
    decoder.readBytes(header, 6);

    // pass the rest to the protobuf decoder
    std::stringstream ssProto;
    cbox::OStreamDataOut protoData(ssProto);
    decoder.push(protoData);
    message.ParseFromIstream(&ssProto);
}
