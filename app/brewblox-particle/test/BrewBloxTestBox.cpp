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

#include "BrewBloxTestBox.h"
#include "Board.h"
#include "blox/Spark3PinsBlock.h"
#include "cbox/CboxPtr.h"
#include "cbox/ConnectionsStringStream.h"

std::shared_ptr<std::stringstream> BrewBloxTestBox::in = std::make_shared<std::stringstream>();
std::shared_ptr<std::stringstream> BrewBloxTestBox::out = std::make_shared<std::stringstream>();
cbox::OStreamDataOut BrewBloxTestBox::inOs(*in);
cbox::EncodedDataOut BrewBloxTestBox::toHex(inOs);
cbox::EncodedDataOut BrewBloxTestBox::inEncoder(toHex);
ProtoDataOut BrewBloxTestBox::inProto(inEncoder);

BrewBloxTestBox::BrewBloxTestBox()
    : ticks(brewbloxBox().makeCboxPtr<TicksBlock<TicksClass>>(3).lock()->get())
{
    static bool connectionAdded = false;
    boardInit(); // simulate board init
    if (!connectionAdded) {
        // only one connection is shared by all tests
        testConnectionSource().add(in, out);
        connectionAdded = true;
    }
    clearStreams();
}

void
BrewBloxTestBox::clearStreams()
{
    in->str("");
    in->clear();
    out->str("");
    out->clear();
}

void
BrewBloxTestBox::reset()
{
    clearStreams();
    inEncoder.put(uint16_t(0)); // msg id
    inEncoder.put(cbox::Box::CommandID::CLEAR_OBJECTS);
    inEncoder.endMessage();
    brewbloxBox().hexCommunicate();
    clearStreams();
    brewbloxBox().update(0);
}

bool
BrewBloxTestBox::lastReplyHasStatusOk()
{
    return lastReplyOk;
}

std::string
BrewBloxTestBox::processInput()
{
    endInput();
    brewbloxBox().hexCommunicate();
    lastReplyOk = out->str().find("|00") != std::string::npos; // no errors
    auto retv = out->str();
    clearStreams();
    return retv;
}

void
BrewBloxTestBox::processInputToProto(::google::protobuf::Message& message)
{
    endInput();
    brewbloxBox().hexCommunicate();
    lastReplyOk = out->str().find("|00") != std::string::npos; // no errors
    decodeProtoFromReply(*out, message);
    clearStreams();
}

void
BrewBloxTestBox::put(const ::google::protobuf::Message& message)
{
    inProto.put(message);
}

void
BrewBloxTestBox::endInput()
{
    inEncoder.endMessage();
}

void
BrewBloxTestBox::update(const cbox::update_t& now)
{
    ticks.ticksImpl().reset(now);

    brewbloxBox().update(now);
}
