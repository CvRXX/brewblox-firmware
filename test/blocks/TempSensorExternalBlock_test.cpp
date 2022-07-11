#include <catch.hpp>
#include <cstdio>
#include <iomanip>
#include <iostream>

#include "TestHelpers.hpp"
#include "TestTimeHelpers.hpp"
#include "blocks/TempSensorExternalBlock.hpp"
#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/Temperature.hpp"
#include "proto/TempSensorExternal_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A TempSensorExternal block")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    test::resetTime(MIN_VALID_UTC + 1, 0);
    test::update(0);

    auto sensorId = cbox::obj_id_t(100);

    // Create block
    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorExternalBlock::staticTypeId());
        auto request = blox_test::TempSensorExternal::Block();
        auto response = blox_test::TempSensorExternal::Block();

        request.set_enabled(true);
        request.set_timeout(60);
        request.set_setting(cnl::unwrap(temp_t(21.0)));

        messageToPayload(cmd, request);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);

        payloadToMessage(cmd, response);

        CHECK(response.ShortDebugString() ==
              "enabled: true "
              "timeout: 60 "
              "setting: 86016 "
              "lastUpdated: 1000000001 "
              "value: 86016");
    }

    WHEN("UTC is invalid, value is excluded")
    {
        test::resetTime(0, 0);
        test::update(1000);

        auto cmd = cbox::TestCommand(sensorId, TempSensorExternalBlock::staticTypeId());
        auto response = blox_test::TempSensorExternal::Block();

        CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        payloadToMessage(cmd, response);

        REQUIRE(cmd.responses[0].maskMode == cbox::MaskMode::EXCLUSIVE);
        REQUIRE(cmd.responses[0].mask == std::vector<cbox::obj_field_tag_t>{
                    blox_test::TempSensorExternal::Block::kValueFieldNumber,
                });

        CHECK(response.ShortDebugString() ==
              "enabled: true "
              "timeout: 60 "
              "setting: 86016 "
              "lastUpdated: 1000000001");
    }

    WHEN("Block is disabled, value is excluded")
    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorExternalBlock::staticTypeId());
        auto request = blox_test::TempSensorExternal::Block();
        auto response = blox_test::TempSensorExternal::Block();

        request.set_enabled(false);

        messageToPayload(cmd,
                         request,
                         {
                             blox_test::TempSensorExternal::Block::kEnabledFieldNumber,
                         });

        CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        payloadToMessage(cmd, response);

        REQUIRE(cmd.responses[0].maskMode == cbox::MaskMode::EXCLUSIVE);
        REQUIRE(cmd.responses[0].mask == std::vector<cbox::obj_field_tag_t>{
                    blox_test::TempSensorExternal::Block::kValueFieldNumber,
                });

        CHECK(response.ShortDebugString() ==
              "timeout: 60 "
              "setting: 86016 "
              "lastUpdated: 1000000001");
    }

    WHEN("Timeout is exceeded, value is excluded")
    {
        test::update(60'001);

        auto cmd = cbox::TestCommand(sensorId, TempSensorExternalBlock::staticTypeId());
        auto response = blox_test::TempSensorExternal::Block();

        CHECK(cbox::readBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        payloadToMessage(cmd, response);

        REQUIRE(cmd.responses[0].maskMode == cbox::MaskMode::EXCLUSIVE);
        REQUIRE(cmd.responses[0].mask == std::vector<cbox::obj_field_tag_t>{
                    blox_test::TempSensorExternal::Block::kValueFieldNumber,
                });

        CHECK(response.ShortDebugString() ==
              "enabled: true "
              "timeout: 60 "
              "setting: 86016 "
              "lastUpdated: 1000000001");
    }

    WHEN("timeout is 0, the timeout check is skipped")
    {
        test::resetTime(MIN_VALID_UTC + 1000, 0);

        auto cmd = cbox::TestCommand(sensorId, TempSensorExternalBlock::staticTypeId());
        auto request = blox_test::TempSensorExternal::Block();
        auto response = blox_test::TempSensorExternal::Block();

        request.set_setting(cnl::unwrap(temp_t(30.0)));
        request.set_timeout(0);

        messageToPayload(cmd,
                         request,
                         {
                             blox_test::TempSensorExternal::Block::kSettingFieldNumber,
                             blox_test::TempSensorExternal::Block::kLastUpdatedFieldNumber,
                             blox_test::TempSensorExternal::Block::kTimeoutFieldNumber,
                         });

        CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
        payloadToMessage(cmd, response);

        CHECK(response.ShortDebugString() ==
              "enabled: true "
              "setting: 122880 "
              "lastUpdated: 1000001000 "
              "value: 122880");
    }
}
