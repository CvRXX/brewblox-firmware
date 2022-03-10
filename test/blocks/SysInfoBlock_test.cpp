/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox.
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

#include <catch.hpp>

#include "TestHelpers.h"
#include "blocks/SysInfoBlock.h"
#include "cbox/Box.h"
#include "proto/SysInfo_test.pb.h"
#include "proto/proto_version.h"
#include "spark/Brewblox.h"

SCENARIO("SysInfo Block")
{
    std::string version = GIT_VERSION;
    std::string protocolVersion = COMPILED_PROTO_VERSION;
    std::string releaseDate = GIT_DATE;
    std::string protocolDate = COMPILED_PROTO_DATE;

    std::string replyWithoutTrace = std::string("deviceId: \"999999999999\"")
                                    + " version: \"" + version + "\" platform: PLATFORM_GCC protocolVersion: \"" + protocolVersion
                                    + "\" releaseDate: \"" + releaseDate + "\" protocolDate: \"" + protocolDate + "\"";

    auto sysInfoId = cbox::obj_id_t(2);

    WHEN("The SysInfo block is read")
    {
        auto cmd = cbox::TestCommand(sysInfoId, SysInfoBlock::staticTypeId());
        auto message = blox_test::SysInfo::Block();

        CHECK(cbox::readObject(cmd) == cbox::CboxError::OK);
        parseFromResponse(cmd, message);

        THEN("The system info is serialized correctly")
        {
            CHECK(message.ShortDebugString() == replyWithoutTrace);
        }
    }
}
