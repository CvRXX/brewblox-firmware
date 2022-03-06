#include "cbox/Box.h"

#include "testinfo.h"
#include <catch.hpp>
#include <iomanip>
#include <iostream>

#include "CboxApplicationExtended.h"
#include "LongIntScanningFactory.hpp"
#include "TestHelpers.h"
#include "TestObjects.h"
#include "cbox/ArrayEepromAccess.h"
#include "cbox/Box.h"
#include "cbox/Connections.h"
#include "cbox/ConnectionsStringStream.h"
#include "cbox/Crc.h"
#include "cbox/DataStreamConverters.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/Object.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "cbox/Tracing.h"

using namespace cbox;

SCENARIO("A controlbox Box")
{
    objects.clearAll();
    test::getStorage().clear();

    objects.init({
        ContainedObject(2, std::shared_ptr<Object>(new LongIntObject(0x11111111))),
        ContainedObject(3, std::shared_ptr<Object>(new LongIntObject(0x22222222))),
    });
    objects.setObjectsStartId(cbox::userStartId);

    WHEN("A connection sends a read object command, it is processed by the Box")
    {
        TestCommand cmd(CboxOpcode::READ_OBJECT, 2, 0);
        CHECK(cbox::readObject(cmd) == CboxError::OK);

        CHECK(cmd.responses.size() == 1);
        auto& resp = cmd.responses.at(0);
        CHECK(resp.blockId == 2);
        CHECK(resp.blockType == 1000);

        std::vector<uint8_t> expected{0x11, 0x11, 0x11, 0x11};
        CHECK(std::equal(resp.content.begin(), resp.content.end(), expected.begin()));
    }

    WHEN("A connection sends a read object command for a non-existing object, INVALID_OBJECT_ID is returned")
    {
        TestCommand cmd(CboxOpcode::READ_OBJECT, 8, 0);
        CHECK(cbox::readObject(cmd) == CboxError::INVALID_OBJECT_ID);
        CHECK(cmd.responses.size() == 0);
    }

    WHEN(
        "A connection sends a read stored object command for a non-existing object, "
        "status PERSISTED_OBJECT_NOT_FOUND is returned")
    {
        TestCommand cmd(CboxOpcode::READ_OBJECT, 8, 0);
        CHECK(cbox::readStoredObject(cmd) == CboxError::PERSISTED_OBJECT_NOT_FOUND);
        CHECK(cmd.responses.size() == 0);
    }

    WHEN("A connection sends a write object command, it is processed by the Box")
    {
        TestCommand cmd(CboxOpcode::WRITE_OBJECT, 2, 1000);
        cmd.requestPayload.value().content.assign({0x33, 0x33, 0x33, 0x33});
        CHECK(cbox::writeObject(cmd) == CboxError::OK);

        CHECK(cmd.responses.size() == 1);
        auto& resp = cmd.responses.at(0);
        CHECK(resp.blockId == 2);
        CHECK(resp.blockType == 1000);

        std::vector<uint8_t> expected{0x33, 0x33, 0x33, 0x33};
        CHECK(std::equal(resp.content.begin(), resp.content.end(), expected.begin()));

        AND_WHEN("A connection sends a write object command with a wrong object type, INVALID_OBJECT_TYPE is returned and the object unchanged")
        {
            TestCommand cmd2(CboxOpcode::WRITE_OBJECT, 2, 10001);
            cmd2.requestPayload.value().content.assign({0x44, 0x44, 0x44, 0x44});
            CHECK(cbox::writeObject(cmd2) == CboxError::INVALID_OBJECT_TYPE);

            CHECK(cmd2.responses.size() == 0);
        }
    }

    // WHEN("A connection sends a create object command, it is processed by the Box")
    // {
    //     *in << "000003"    // create object
    //         << "0000"      // ID assigned by box
    //         << "7F"        // groups 7F
    //         << "E803"      // type 1000
    //         << "44444444"; // value 44444444
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("00000300007FE80344444444") << "|"
    //              << addCrc(
    //                     "00"        // status
    //                     "6400"      // id
    //                     "7F"        // groups
    //                     "E803"      // type
    //                     "44444444") // data
    //              << "\n";
    //     CHECK(out->str() == expected.str());
    //     CHECK(box.getObject(100).lock());

    //     WHEN("The object is modified by the application, not by an incoming command")
    //     {

    //         auto objLookup = CboxPtr<LongIntObject>(100);
    //         auto obj = objLookup.lock();
    //         REQUIRE(obj);
    //         obj->value(0x22222222);

    //         auto checkEepromVal = [&box, &clearStreams, &in, &out, &expected](std::string eepromVal) -> void {
    //             clearStreams();

    //             *in << "0000066400"; // read stored object 100
    //             *in << crc(in->str()) << "\n";
    //             box.hexCommunicate();

    //             // Objects are stored with a CRC in EEPROM.
    //             // The message will have 2 CRCs appended.
    //             // This allows to distinguish between an error in EEPROM or a communication error.

    //             expected << addCrc("0000066400") << "|"
    //                      << addCrc(
    //                             "00"         // status
    //                             "6400"       // id
    //                             "7F"         // stored groups
    //                             "E803"       // stored type
    //                             + eepromVal) // stored data
    //                      << "\n";

    //             CHECK(out->str() == expected.str());
    //         };

    //         THEN("The data in eeprom is not changed")
    //         {
    //             CHECK(obj->value() == 0x22222222);
    //             checkEepromVal("44444444");

    //             AND_THEN("The eeprom data can be reloaded")
    //             {
    //                 box.reloadStoredObject(100);
    //                 CHECK(obj->value() == 0x44444444);
    //             }
    //         }

    //         AND_WHEN("storeUpdatedObject is invoked, the object is written to eeprom")
    //         {

    //             CHECK(box.storeUpdatedObject(obj_id_t(100)) == CboxError::OK);
    //             checkEepromVal("22222222");
    //             box.reloadStoredObject(100);
    //             CHECK(obj->value() == 0x22222222);

    //             AND_WHEN("storeUpdatedObject is called with a non-existing id, an error is returned")
    //             {
    //                 CHECK(box.storeUpdatedObject(obj_id_t(200)) == CboxError::INVALID_OBJECT_ID);
    //             }
    //             AND_WHEN("reloadStoredObject is called with a non-existing id, an error is returned")
    //             {
    //                 CHECK(box.reloadStoredObject(obj_id_t(200)) == CboxError::INVALID_OBJECT_ID);
    //             }
    //         }
    //     }

    //     AND_WHEN("A connection sends a delete object command for a user object, it is processed by the Box")
    //     {
    //         clearStreams();

    //         *in << "000004"
    //             << "6400"; // ID 100
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("0000046400")
    //                  << "|" << addCrc("00")
    //                  << "\n";
    //         CHECK(out->str() == expected.str());
    //         CHECK(!box.getObject(100).lock());
    //     }
    // }

    // WHEN("A connection sends a create object command with an ID in the system range, it is refused with INVALID_OBJECT_ID")
    // {
    //     *in << "000003"    // create object
    //         << "0500"      // ID 5
    //         << "7F"        // groups 7F
    //         << "E803"      // type 1000
    //         << "44444444"; // value 44444444
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("00000305007FE80344444444") << "|" << addCrc("40") << "\n";
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("A connection sends a delete object command for system object, it is refused with status object_not_deletable (35)")
    // {
    //     *in << "000004"
    //         << "0200"; // delete object, ID 2
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("0000040200")
    //              << "|" << addCrc("23") // error code for object_not_deletable
    //              << "\n";
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("A connection sends a delete object command for a non-existing object, it is refused with status invalid_object_id (65)")
    // {
    //     *in << "000004"
    //         << "0001"; // delete object, ID 256
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("0000040001")
    //              << "|" << addCrc("40") << "\n"; // error code for invalid object id
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("A connection sends a list objects command, all objects are sent out")
    // {
    //     *in << "000005"; // list all objects
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("000005")
    //              << "|" << addCrc("00")
    //              << "," << addCrc("020080E80311111111")
    //              << "," << addCrc("030080E80322222222")
    //              << "\n";
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("A connection sends a list compatible objects command, ids of only compatible objects are returned")
    // {
    //     *in << "000003"    // create object
    //         << "6400"      // ID 100
    //         << "7F"        // groups 7F
    //         << "E903"      // type 1001, LongIntVector
    //         << "0200"      // size 2
    //         << "33333333"  // value 33333333
    //         << "44444444"; // value 44444444
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("00000364007FE90302003333333344444444") << "|"
    //              << addCrc(
    //                     "00"        // status
    //                     "6400"      // id 100
    //                     "7F"        // groups
    //                     "E903"      // type 1001, LongIntVector
    //                     "0200"      // size 2
    //                     "33333333"  // value 33333333
    //                     "44444444") // value 44444444
    //              << "\n";
    //     CHECK(out->str() == expected.str());
    //     CHECK(box.getObject(100).lock());

    //     clearStreams();

    //     *in << "000003"    // create object
    //         << "6500"      // ID 101
    //         << "7F"        // groups 7F
    //         << "EB03"      // type 1003, NameableLongIntObject
    //         << "44444444"; // value 44444444
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("00000365007FEB0344444444") << "|"
    //              << addCrc(
    //                     "00"        // status
    //                     "6500"      // id
    //                     "7F"        // groups
    //                     "EB03"      // type
    //                     "44444444") // data
    //              << "\n";
    //     CHECK(out->str() == expected.str());
    //     CHECK(box.getObject(101).lock());

    //     clearStreams();

    //     *in << "00000B"; // list compatible objects
    //     *in << "E803";   // typeid for LongIntObject
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("00000BE803")
    //              << "|" << addCrc("00")
    //              << "," << addCrc("0200") // id 2
    //              << "," << addCrc("0300") // id 3
    //              << "," << addCrc("6500") // id 101
    //              << "\n";
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("A connection sends a noop command, it receives a reply.")
    // {
    //     *in << "000000"; // noop command
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("000000")
    //              << "|" << addCrc("00")
    //              << "\n";
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("A connection sends an invalid command, it receives a reply with error code invalid command.")
    // {
    //     *in << "000099";
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("000099")
    //              << "|" << addCrc("3F")
    //              << "\n";
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("An object is created with a profile that is not active, it's value is written to storage, but the runtime object is still inactive")
    // {
    //     clearStreams();

    //     *in << "000003"    // create object
    //         << "0000"      // id assigned by box
    //         << "00"        // active in no groups
    //         << "E803"      // typeid 1000
    //         << "44444444"; // value
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("000003000000E80344444444") << "|" // command repetition
    //              << addCrc(
    //                     "00"    // status OK
    //                     "6400"  // id 100
    //                     "00"    // groups 0x00
    //                     "FFFF"  // type InactiveObject
    //                     "E803") // actual type 1000
    //              << "\n";

    //     CHECK(out->str() == expected.str());
    //     CHECK(box.getObject(100).lock());

    //     THEN("The stored settings can still be read with the READ_STORED_OBJECT command")
    //     {
    //         clearStreams();

    //         *in << "0000066400"; // read stored object 100
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         // Objects are stored with a CRC in EEPROM.
    //         // The message will have 2 CRCs appended.
    //         // This allows to distinguish between an error in EEPROM or a communication error.

    //         expected << addCrc("0000066400") << "|"
    //                  << addCrc(
    //                         "00"        // status
    //                         "6400"      // id
    //                         "00"        // stored groups
    //                         "E803"      // stored type
    //                         "44444444") // stored data
    //                  << "\n";
    //         CHECK(out->str() == expected.str());
    //     }

    //     THEN("An inactive object is never persisted")
    //     {
    //         CHECK(box.storeUpdatedObject(100) == CboxError::PERSISTING_TO_INACTIVE_OBJECT);
    //     }

    //     THEN("Writing an inactive object as the actual object it replaces, gives invalid object type error")
    //     {
    //         clearStreams();

    //         *in << "000002"    // write object
    //             << "6400"      // id 100
    //             << "00"        // active in no groups
    //             << "E803"      // typeid 1000
    //             << "14141414"; // value
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("000002640000E80314141414") << "|" // command repetition
    //                  << addCrc("41")                              // status invalid object type
    //                  << "\n";

    //         CHECK(out->str() == expected.str());

    //         AND_THEN("The stored data will be unchanged")
    //         {
    //             clearStreams();

    //             *in << "0000066400"; // read stored object 100
    //             *in << crc(in->str()) << "\n";
    //             box.hexCommunicate();

    //             expected << addCrc("0000066400") << "|"
    //                      << addCrc(
    //                             "00"        // status
    //                             "6400"      // id
    //                             "00"        // stored groups
    //                             "E803"      // stored type
    //                             "44444444") // stored data
    //                      << "\n";
    //             CHECK(out->str() == expected.str());
    //         }
    //     }

    //     THEN("Writing groups of an inactive object can re-activate it")
    //     {
    //         clearStreams();

    //         *in << "000002" // write object
    //             << "6400"   // id 100
    //             << "FF"     // active in all groups
    //             << "FFFF"   // typeid 1000
    //             << "0000";  // actual type doesn't matter
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("0000026400FFFFFF0000") << "|" // command repetition
    //                  << addCrc(
    //                         "00"        // status OK
    //                         "6400"      // id
    //                         "7F"        // groups, system group is allowed to be set
    //                         "E803"      // stored type
    //                         "44444444") // stored data
    //                  << "\n";

    //         CHECK(out->str() == expected.str());

    //         AND_THEN("The stored data will be contain the new groups")
    //         {
    //             clearStreams();

    //             *in << "0000066400"; // read stored object 100
    //             *in << crc(in->str()) << "\n";
    //             box.hexCommunicate();

    //             expected << addCrc("0000066400") << "|"
    //                      << addCrc(
    //                             "00"        // status
    //                             "6400"      // id
    //                             "7F"        // stored groups
    //                             "E803"      // stored type
    //                             "44444444") // stored data
    //                      << "\n";
    //             CHECK(out->str() == expected.str());
    //         }
    //     }
    // }

    // WHEN("Objects are created in different groups")
    // {
    //     CHECK(box.getActiveGroups() == 0x81); // default is only profile 1 active and system profile

    //     *in << "000003"
    //         << "6400"
    //         << "01"
    //         << "E803"
    //         << "44444444"; // create object, ID 100, groups 01, type 1000, value 44444444
    //     *in << crc(in->str()) << "\n";

    //     box.hexCommunicate();
    //     clearStreams();

    //     *in << "000003"
    //         << "6500"
    //         << "02"
    //         << "E803"
    //         << "44444444"; // create object, ID 101, groups 04, type 1000, value 55555555
    //     *in << crc(in->str()) << "\n";

    //     box.hexCommunicate();
    //     clearStreams();

    //     *in << "000003"
    //         << "6600"
    //         << "03"
    //         << "E803"
    //         << "44444444"; // create object, ID 102, groups 06, type 1000, value 66666666
    //     *in << crc(in->str()) << "\n";

    //     box.hexCommunicate();
    //     clearStreams();

    //     *in << "000002"
    //         << "0300"
    //         << "00"
    //         << "E803"
    //         << "12341234"; // write system object 3 (including 00 for groups)
    //     *in << crc(in->str()) << "\n";

    //     box.hexCommunicate();
    //     clearStreams();

    //     REQUIRE(box.getObject(100).lock());
    //     REQUIRE(box.getObject(101).lock());
    //     REQUIRE(box.getObject(102).lock());

    //     THEN("System object 3 was written, but it is not deactivated, because it is a system object)")
    //     {
    //         *in << "0000010300"; // read object 03
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("0000010300") << "|" << addCrc("00030080E80312341234") << "\n";
    //         CHECK(out->str() == expected.str());
    //     }

    //     THEN("Only objects in an active profile are active, the others have the InactiveObject placeholder")
    //     {
    //         CHECK(box.getObject(100).lock()->typeId() == LongIntObject::staticTypeId());
    //         CHECK(box.getObject(101).lock()->typeId() == InactiveObject::staticTypeId());
    //         CHECK(box.getObject(102).lock()->typeId() == LongIntObject::staticTypeId());
    //     }

    //     WHEN("An object is given an active groups value that would disable it, it is replaced by InactiveObject")
    //     {
    //         *in << "000002"    // command
    //             << "6400"      // id
    //             << "00"        // groups of object
    //             << "E803"      // type
    //             << "12341234"; // value
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();
    //         CHECK(box.getObject(100).lock()->typeId() == InactiveObject::staticTypeId());
    //     }

    //     THEN("When list stored objects command is received, eeprom data for all objects is streamed")
    //     {
    //         clearStreams();
    //         *in << "000007"; // list stored objects
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         // each object has 2 CRCs: one from EEPROM and from the message part
    //         expected << addCrc("000007") << "|" << addCrc("00")
    //                  << "," << addCrc("640001E80344444444")
    //                  << "," << addCrc("650002E80344444444")
    //                  << "," << addCrc("660003E80344444444")
    //                  << "," << addCrc("030080E80312341234") // modified system object is also persisted
    //                  << "\n";

    //         CHECK(out->str() == expected.str());
    //     }

    //     THEN("When the clear objects command is received, all user objects are removed, system objects remain")
    //     {
    //         clearStreams();
    //         *in << "000008"; // clear all objects
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("000008") << "|"
    //                  << addCrc("00") << "\n";
    //         CHECK(out->str() == expected.str());

    //         clearStreams();
    //         *in << "000005"; // list all objects
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("000005") << "|" << addCrc("00") // status OK
    //                  << "," << addCrc("020080E80311111111")     // obj 2
    //                  << "," << addCrc("030080E80312341234")     // obj 3
    //                  << "\n";
    //         CHECK(out->str() == expected.str());
    //     }
    // }

    // THEN("Objects update at their requested interval")
    // {
    //     tracing::unpause();
    //     box.update(0);
    //     // create 2 counter objects with different update intervals
    //     // object creation and write also triggers an object update

    //     clearStreams();
    //     *in << "000003" // create counter object
    //         << "6400"   // ID 100
    //         << "7F"     // groups FF
    //         << "EA03"   // type 1002
    //         << "E803";  // interval 1000
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("00000364007FEA03E803") << "|" // command repetition
    //              << addCrc(
    //                     "00"    // status OK
    //                     "6400"  // id 100
    //                     "7F"    // groups 0x7F (system profile not set)
    //                     "EA03"  // type 1002
    //                     "E803"  // interval 1000
    //                     "0100") // count 1
    //              << "\n";

    //     CHECK(out->str() == expected.str());

    //     clearStreams();
    //     *in << "000003" // create counter object
    //         << "6500"   // ID 101
    //         << "7F"     // groups FF
    //         << "EA03"   // type 1002
    //         << "D007";  // interval 2000
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("00000365007FEA03D007") << "|" // command repetition
    //              << addCrc(
    //                     "00"    // status OK
    //                     "6500"  // id 101
    //                     "7F"    // groups 0xFF
    //                     "EA03"  // type 1002
    //                     "D007"  // interval 2000
    //                     "0100") // count 1
    //              << "\n";

    //     THEN("Last actions performed on objects are traced")
    //     {

    //         auto it = tracing::history().cbegin();

    //         CHECK(it->action == tracing::Action::UPDATE_OBJECT);
    //         CHECK(it->id == 2);
    //         CHECK(it->type == LongIntObject::staticTypeId());
    //         ++it; // 1
    //         CHECK(it->action == tracing::Action::UPDATE_OBJECT);
    //         CHECK(it->id == 3);
    //         CHECK(it->type == LongIntObject::staticTypeId());
    //         ++it; // 2
    //         CHECK(it->action == tracing::Action::UPDATE_CONNECTIONS);
    //         CHECK(it->id == 0);
    //         CHECK(it->type == 0);
    //         ++it; // 3
    //         CHECK(it->action == tracing::Action::CREATE_OBJECT);
    //         CHECK(it->id == 0);
    //         CHECK(it->type == 0);
    //         ++it; // 4
    //         CHECK(it->action == tracing::Action::CONSTRUCT_OBJECT);
    //         CHECK(it->id == 100);
    //         CHECK(it->type == 1002);
    //         ++it; // 5
    //         CHECK(it->action == tracing::Action::PERSIST_OBJECT);
    //         CHECK(it->id == 100);
    //         CHECK(it->type == 1002);
    //         ++it; // 6
    //         CHECK(it->action == tracing::Action::UPDATE_CONNECTIONS);
    //         CHECK(it->id == 0);
    //         CHECK(it->type == 0);
    //         ++it; // 7
    //         CHECK(it->action == tracing::Action::CREATE_OBJECT);
    //         CHECK(it->id == 0);
    //         CHECK(it->type == 0);
    //         ++it; // 8
    //         CHECK(it->action == tracing::Action::CONSTRUCT_OBJECT);
    //         CHECK(it->id == 101);
    //         CHECK(it->type == 1002);
    //         ++it; // 9
    //         CHECK(it->action == tracing::Action::PERSIST_OBJECT);
    //         CHECK(it->id == 101);
    //         CHECK(it->type == 1002);
    //     }

    //     auto counterObjPtr1 = box.getObject(100).lock();
    //     auto counterObjPtr2 = box.getObject(101).lock();

    //     REQUIRE(counterObjPtr1);
    //     REQUIRE(counterObjPtr2);

    //     // cast the Object pointers to the actual type for easier testing
    //     auto counter1 = static_cast<UpdateCounter*>(counterObjPtr1.get());
    //     auto counter2 = static_cast<UpdateCounter*>(counterObjPtr2.get());

    //     THEN("Update was called once on each object when they were created")
    //     {
    //         CHECK(counter1->count() == 1);
    //         CHECK(counter2->count() == 1);
    //         CHECK(counter1->interval() == 1000);
    //         CHECK(counter2->interval() == 2000);
    //     }

    //     for (uint32_t now = 1; now <= 10001; now += 1) {
    //         box.update(now);
    //     }

    //     THEN("After simulating 10 seconds, counter1 was updated 10 more times and counter2 was updated 5 more times")
    //     {
    //         CHECK(counter1->count() == 1 + 10);
    //         CHECK(counter2->count() == 1 + 5);
    //     }

    //     box.update(10500); // update just before write
    //     clearStreams();
    //     *in << "000002" // write counter object
    //         << "6400"   // ID 100
    //         << "7F"     // groups FF
    //         << "EA03"   // type 1002
    //         << "A00F";  // interval 4000
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     CHECK(counter1->interval() == 4000);

    //     THEN("Writing a new interval (4000) to counter 1 has triggered an update of the object")
    //     {
    //         CHECK(counter1->count() == 10 + 1 + 1);
    //         CHECK(counter2->count() == 5 + 1);
    //     }

    //     THEN("It is updated 4000 ms after the write and 4000 ms after that")
    //     {
    //         uint32_t now;

    //         for (now = 10500; now <= 20000; now += 1) {
    //             box.update(now);
    //             if (counter1->count() > 12) {
    //                 break;
    //             }
    //         }
    //         CHECK(now == 14500);

    //         for (now = 14500; now <= 20000; now += 1) {
    //             box.update(now);
    //             if (counter1->count() > 13) {
    //                 break;
    //             }
    //         }
    //         CHECK(now == 18500);
    //     }

    //     THEN("An overflowing time is handled correctly")
    //     {
    //         update_t tenSecondsBeforeOverflow = std::numeric_limits<update_t>::max() - 10000;
    //         update_t now = tenSecondsBeforeOverflow;

    //         box.forcedUpdate(now);
    //         auto count = counter1->count();

    //         // run for 20 seconds
    //         for (; now != 10000; ++now) {
    //             box.update(now);
    //         }

    //         CHECK(counter1->count() == count + 20000 / counter1->interval());
    //     }
    // }

    // WHEN("An object with links to other objects is created, it can use data from those other objects")
    // {
    //     *in << "000003" // create object
    //         << "6400"   // ID 100
    //         << "7F"     // groups FF
    //         << "ED03"   // type 1005
    //         << "0200"   // ptr 1 points to object 2
    //         << "0300";  // ptr 2 points to object 3

    //     std::string command = in->str();

    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected
    //         << addCrc(command) << "|" // command repetition
    //         << addCrc(
    //                "00"       // status OK
    //                "6400"     // id 100
    //                "7F"       // groups 0xFF
    //                "ED03"     // type 1002
    //                "0200"     // ptr 1 points to ID 2
    //                "0300"     // ptr 2 points to ID 3
    //                "01"       // ptr1 OK
    //                "01"       // ptr2 OK
    //                "11111111" // value 1
    //                "22222222" // value 2
    //                )
    //         << "\n";

    //     CHECK(out->str() == expected.str());

    //     AND_THEN("If the links change and point to an invalid object, the output is correct")
    //     {
    //         clearStreams();

    //         *in << "000002" // write object
    //             << "6400"   // ID 100
    //             << "7F"     // groups 7F
    //             << "ED03"   // type 1005
    //             << "0300"   // ptr 1 points to object 3
    //             << "0400";  // ptr 2 points to object 4

    //         std::string command = in->str();

    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected
    //             << addCrc(command) << "|" // command repetition
    //             << addCrc(
    //                    "00"       // status OK
    //                    "6400"     // id 100
    //                    "7F"       // groups 0x7F
    //                    "ED03"     // type 1002
    //                    "0300"     // ptr 1 points to ID 3
    //                    "0400"     // ptr 2 points to ID 4
    //                    "01"       // ptr1 OK
    //                    "00"       // ptr2 not OK
    //                    "22222222" // value 1
    //                    "00000000" // value 2 is default value 0
    //                    )
    //             << "\n";

    //         CHECK(out->str() == expected.str());
    //     }
    // }

    // WHEN("A connection sends only a partial message, a CRC error is returned")
    // {
    //     *in << "000003" // create object
    //         << "0000"   // ID assigned by box
    //         << "7F";    // groups 7F
    //                     //<< "E803"      // type 1000
    //                     //<< "44444444"; // value 44444444
    //                     // *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << "00000300007F"
    //              << "|"
    //              << addCrc("43") << "\n";
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("A connection sends only a partial message with half a hex encoded byte (1 nibble), a CRC error is returned")
    // {
    //     *in << "000003" // create object
    //         << "0";     // ID with a nibble missing

    //     box.hexCommunicate();

    //     expected << "000003"
    //              << "|"
    //              << addCrc("43") << "\n";
    //     CHECK(out->str() == expected.str());
    // }

    // WHEN("All commands are sent with invalid CRC, CRC errors are returned")
    // {
    //     for (uint8_t c = 1; c <= 10; ++c) {
    //         clearStreams();
    //         *in << "0000"; // msg id
    //         *in << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << +c;
    //         *in << "0000000000";
    //         *in << crc(in->str() + "10");

    //         box.hexCommunicate();
    //         INFO(out->str());
    //         CHECK(out->str().find("|43") != std::string::npos);
    //     }
    // }

    // WHEN("A reboot command is sent, the reset handler is called")
    // {
    //     CHECK(testInfo.rebootCount == 0);

    //     *in << "000009" // reboot
    //         << crc(in->str()) << "\n";

    //     box.hexCommunicate();

    //     CHECK(testInfo.rebootCount == 1);
    // }

    // WHEN("a factory reset command is sent, EEPROM is reinitialized, followed by a system reboot")
    // {
    //     auto rebootCountBeforeCommand = testInfo.rebootCount;

    //     *in << "000003"    // create object
    //         << "0000"      // ID assigned by box
    //         << "7F"        // groups 7F
    //         << "E803"      // type 1000
    //         << "44444444"; // value 44444444
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     clearStreams();

    //     auto countNonZeroBytes = []() {
    //         uint16_t nonZeroBytesInEeprom = 0;
    //         for (uint16_t i = 32; i < test::getEeprom().length(); ++i) {
    //             if (test::getEeprom().readByte(i) != 0) {
    //                 ++nonZeroBytesInEeprom;
    //             }
    //         }
    //         return nonZeroBytesInEeprom;
    //     };

    //     CHECK(test::getStorage().freeSpace() < 2000);
    //     CHECK(countNonZeroBytes() > 10);

    //     *in << "00000A" // factory reset
    //         << crc(in->str()) << "\n";

    //     box.hexCommunicate();

    //     CHECK(countNonZeroBytes() == 3); // just the disposed block header
    //     CHECK(test::getStorage().freeSpace() == 2013);

    //     CHECK(testInfo.rebootCount == rebootCountBeforeCommand + 1);
    // }

    // WHEN("A device discovery command is received")
    // {
    //     *in << "00000C"; // discover new objects
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     // we expect this command to create 3 new objects, with values 0x33333333, 0x44444444, 0x55555555
    //     // 0x11111111 and 0x22222222 already exist

    //     THEN("A list of IDs of newly created objects is returned")
    //     {
    //         expected << addCrc("00000C") << "|"
    //                  << addCrc("00")              // status
    //                  << "," << addCrc("6400E803") // new object id 100
    //                  << "," << addCrc("6500E803") // new object id 101
    //                  << "," << addCrc("6600E803") // new object id 102
    //                  << "\n";
    //         CHECK(out->str() == expected.str());
    //     }

    //     THEN("The objects that didn't exist yet but where provided by the scanner have been created")
    //     {
    //         clearStreams();
    //         *in << "000005"; // list all objects
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("000005")
    //                  << "|" << addCrc("00")
    //                  << "," << addCrc("020080E80311111111")
    //                  << "," << addCrc("030080E80322222222")
    //                  << "," << addCrc("640001E80333333333")
    //                  << "," << addCrc("650001E80344444444")
    //                  << "," << addCrc("660001E80355555555")
    //                  << "\n";
    //         CHECK(out->str() == expected.str());
    //     }

    //     THEN("The newly discovered objects are persisted")
    //     {
    //         clearStreams();
    //         *in << "000007"; // list stored objects
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("000007")
    //                  << "|" << addCrc("00")
    //                  << "," << addCrc("640001E80333333333")
    //                  << "," << addCrc("650001E80344444444")
    //                  << "," << addCrc("660001E80355555555")
    //                  << "\n";
    //         CHECK(out->str() == expected.str());
    //     }

    //     clearStreams();
    // }

    // WHEN("The application implements a custom command")
    // {
    //     *in << "000064"; // discover new objects
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     // we expect this command to return a single byte (100, 64 hex)
    //     THEN("The command is executed correctly")
    //     {
    //         expected << addCrc("000064") << "|"
    //                  << addCrc("0064") // CboxError OK + 100
    //                  << "\n";
    //         CHECK(out->str() == expected.str());
    //     }
    // }

    // WHEN("An object generates an error while it streams its values")
    // {
    //     *in << "000003" // create object
    //         << "0000"   // ID assigned by box
    //         << "7F"     // groups 7F
    //         << "EE03";  // type 1006 MockStreamObject
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("00000300007FEE03") << "|"
    //              << "00"   // status
    //                 "6400" // id 100
    //                 "7F"   // groups
    //                 "EE03" // type
    //                 "F5"   // CRC
    //              << "\n";
    //     CHECK(out->str() == expected.str());

    //     auto lookup = CboxPtr<MockStreamObject>(100);
    //     auto obj = lookup.lock();
    //     REQUIRE(obj);

    //     clearStreams();

    //     *in << "0000016400"; // read object 100
    //     *in << crc(in->str()) << "\n";
    //     box.hexCommunicate();

    //     expected << addCrc("0000016400")
    //              << "|0064007FEE03F5"
    //              << "\n";
    //     CHECK(out->str() == expected.str());

    //     THEN("An error event annotation is inserted and the message ends in an invalid CRC (1 off)")
    //     {
    //         // because the error occurs after the status code 00 has been sent, a CRC error is generated to invalidate the message
    //         obj->streamToFunc = [](DataOut& out) {
    //             return CboxError::OUTPUT_STREAM_WRITE_ERROR;
    //         };

    //         clearStreams();

    //         *in << "0000016400"; // read object 100
    //         *in << crc(in->str()) << "\n";
    //         box.hexCommunicate();

    //         expected << addCrc("0000016400")
    //                  << "|0064007FEE03<!CBOXERROR:09>F6"
    //                  << "\n";
    //         CHECK(out->str() == expected.str());
    //     }
    // }
}
