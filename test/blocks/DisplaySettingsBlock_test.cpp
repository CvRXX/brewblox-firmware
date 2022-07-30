#include <catch.hpp>

#include "TestHelpers.hpp"
#include "blocks/DisplaySettingsBlock.hpp"
#include "blocks/TempSensorMockBlock.hpp"
#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "control/Temperature.hpp"
#include "proto/DisplaySettings_test.pb.h"
#include "proto/TempSensorMock_test.pb.h"
#include "spark/Brewblox.hpp"

SCENARIO("A DisplaySettings block is present as system block")
{
    cbox::getObjects().clearAll();
    platform::particle::setupSystemBlocks();
    cbox::update(0);

    auto sensorId = cbox::obj_id_t(100);
    auto displaySettingsId = cbox::obj_id_t(7); // system object

    // Create mock sensor
    {
        auto cmd = cbox::TestCommand(sensorId, TempSensorMockBlock::staticTypeId());
        auto message = blox_test::TempSensorMock::Block();

        message.set_setting(cnl::unwrap(temp_t(20.0)));
        message.set_connected(true);

        messageToPayload(cmd, message);
        CHECK(cbox::createBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);
    }

    // Add sensor widget to DisplaySettings
    {
        auto cmd = cbox::TestCommand(displaySettingsId, DisplaySettingsBlock::staticTypeId());
        auto message = blox_test::DisplaySettings::Block();
        auto response = blox_test::DisplaySettings::Block();

        message.set_name("blox inc");

        auto* widget = message.add_widgets();
        widget->set_tempsensor(sensorId);
        widget->set_name("sensor");
        widget->set_color("123");
        widget->set_pos(2);

        messageToPayload(cmd, message);
        CHECK(cbox::writeBlock(cmd.request, cmd.callback) == cbox::CboxError::OK);

        payloadToMessage(cmd, response);
        CHECK(message.ShortDebugString() ==
              "widgets { pos: 2 color: \"123\" name: \"sensor\" tempSensor: 100 } "
              "name: \"blox inc\"");
    }
}
