#include "cbox/Box.hpp"

#include <catch.hpp>
#include <iomanip>
#include <iostream>

#include "LongIntScanningFactory.hpp"
#include "TestApplication.hpp"
#include "TestHelpers.hpp"
#include "TestObjects.hpp"
#include "cbox/Box.hpp"
#include "cbox/Crc.hpp"
#include "cbox/Object.hpp"
#include "cbox/ObjectContainer.hpp"
#include "cbox/ObjectFactory.hpp"

using namespace cbox;

SCENARIO("Box commands")
{
    objects.clearAll();
    test::getStorage().clear();

    objects.setObjectsStartId(systemStartId);
    objects.add(std::shared_ptr<Object>(new LongIntObject(0x11111111)), 2);
    objects.add(std::shared_ptr<Object>(new LongIntObject(0x22222222)), 3);
    objects.setObjectsStartId(userStartId);

    WHEN("Read object")
    {
        TestCommand cmd(2, 0);
        CHECK(readBlock(cmd.request, cmd.callback) == CboxError::OK);

        CHECK(cmd.responses.size() == 1);
        auto& resp = cmd.responses.at(0);
        CHECK(resp.blockId == 2);
        CHECK(resp.blockType == 1000);

        CHECK(hexed(resp.content) == "11111111");
    }

    WHEN("Read non-existent object")
    {
        TestCommand cmd(8, 0);
        CHECK(readBlock(cmd.request, cmd.callback) == CboxError::INVALID_BLOCK_ID);
        CHECK(cmd.responses.size() == 0);
    }

    WHEN("Read non-existent stored object")
    {
        TestCommand cmd(8, 0);
        CHECK(readStoredBlock(cmd.request, cmd.callback) == CboxError::INVALID_STORED_BLOCK_ID);
        CHECK(cmd.responses.size() == 0);
    }

    WHEN("Write object")
    {
        TestCommand cmd(2, 1000, {0x33, 0x33, 0x33, 0x33});
        CHECK(writeBlock(cmd.request, cmd.callback) == CboxError::OK);

        CHECK(cmd.responses.size() == 1);
        auto& resp = cmd.responses.at(0);
        CHECK(resp.blockId == 2);
        CHECK(resp.blockType == 1000);

        std::vector<uint8_t> expected{0x33, 0x33, 0x33, 0x33};
        CHECK(std::equal(resp.content.begin(), resp.content.end(), expected.begin()));

        AND_WHEN("Write object with the wrong object type")
        {
            TestCommand cmd2(2, 10001, {0x44, 0x44, 0x44, 0x44});
            CHECK(writeBlock(cmd2.request, cmd2.callback) == CboxError::INVALID_BLOCK_TYPE);

            CHECK(cmd2.responses.size() == 0);
        }
    }

    WHEN("Create object")
    {
        TestCommand createCmd(0,
                              1000,
                              {0x44, 0x44, 0x44, 0x44});

        CHECK(createBlock(createCmd.request, createCmd.callback) == CboxError::OK);
        CHECK(createCmd.responses.at(0).blockId == 100);
        REQUIRE(objects.fetch(100));

        WHEN("The object is modified by the application, not by an incoming command")
        {
            auto objLookup = CboxPtr<LongIntObject>(100);
            auto obj = objLookup.lock();
            REQUIRE(obj);
            obj->value(0x22222222);

            auto checkEepromVal = [](std::string eepromVal) -> void {
                TestCommand storeCmd(100, 1000);
                CHECK(readStoredBlock(storeCmd.request, storeCmd.callback) == CboxError::OK);
                CHECK(storeCmd.responses.size() == 1);
                CHECK(hexed(storeCmd.responses.at(0).content) == eepromVal);
            };

            THEN("The data in eeprom is not changed")
            {
                CHECK(obj->value() == 0x22222222);
                checkEepromVal("44444444");

                AND_THEN("The eeprom data can be reloaded")
                {
                    CHECK(objects.reloadStored(100) == CboxError::OK);
                    CHECK(obj->value() == 0x44444444);
                }
            }

            AND_WHEN("objects.store() is invoked, the object is written to eeprom")
            {
                CHECK(objects.store(100) == CboxError::OK);
                checkEepromVal("22222222");
                objects.reloadStored(100);
                CHECK(obj->value() == 0x22222222);

                AND_WHEN("objects.store() is called with a non-existing id, an error is returned")
                {
                    CHECK(objects.store(200) == CboxError::INVALID_BLOCK_ID);
                }
                AND_WHEN("objects.reloadStored() is called with a non-existing id, an error is returned")
                {
                    CHECK(objects.reloadStored(200) == CboxError::INVALID_BLOCK_ID);
                }
            }
        }

        AND_WHEN("Delete user object")
        {
            TestCommand deleteCmd(100, 1000);
            CHECK(deleteBlock(deleteCmd.request) == CboxError::OK);
            REQUIRE(!objects.fetch(100));
            CHECK(objects.reloadStored(100) == CboxError::INVALID_BLOCK_ID);
        }
    }

    WHEN("Create system object is refused with INVALID_OBJECT_ID")
    {
        TestCommand cmd(5, 1000, {0x11, 0x11, 0x11, 0x11});
        CHECK(createBlock(cmd.request, cmd.callback) == CboxError::INVALID_BLOCK_ID);
    }

    WHEN("Delete system object is refused with OBJECT_NOT_DELETABLE")
    {
        TestCommand cmd(2, 0);
        CHECK(deleteBlock(cmd.request) == CboxError::BLOCK_NOT_DELETABLE);
    }

    WHEN("Delete non-existent object is refused with INVALID_OBJECT_ID")
    {
        TestCommand cmd(256, 0);
        CHECK(deleteBlock(cmd.request) == CboxError::INVALID_BLOCK_ID);
    }

    WHEN("List objects")
    {
        TestCommand cmd;
        CHECK(readAllBlocks(cmd.callback) == CboxError::OK);
        CHECK(cmd.responses.size() == 2);

        auto& resp1 = cmd.responses.at(0);
        CHECK(resp1.blockId == 2);
        CHECK(hexed(resp1.content) == "11111111");

        auto& resp2 = cmd.responses.at(1);
        CHECK(resp2.blockId == 3);
        CHECK(hexed(resp2.content) == "22222222");
    }

    THEN("Objects update at their requested interval")
    {
        update(0);

        // create 2 counter objects with different update intervals
        // object creation and write also triggers an object update

        TestCommand create1(100,
                            1002,        // Counter
                            {0xe8, 0x03} // interval 1000
        );
        CHECK(createBlock(create1.request, create1.callback) == CboxError::OK);

        TestCommand create2(101,
                            1002,                    // Counter
                            {0xd0, 0x07, 0x01, 0x00} // interval 2000, count 1
        );
        CHECK(createBlock(create2.request, create2.callback) == CboxError::OK);

        auto counterObjPtr1 = objects.fetch(100);
        auto counterObjPtr2 = objects.fetch(101);

        REQUIRE(counterObjPtr1);
        REQUIRE(counterObjPtr2);

        // cast the Object pointers to the actual type for easier testing
        auto counter1 = static_cast<UpdateCounter*>(counterObjPtr1.value().get());
        auto counter2 = static_cast<UpdateCounter*>(counterObjPtr2.value().get());

        THEN("Update was called once on each object when they were created")
        {
            CHECK(counter1->count() == 1);
            CHECK(counter2->count() == 1);
            CHECK(counter1->interval() == 1000);
            CHECK(counter2->interval() == 2000);
        }

        for (uint32_t now = 1; now <= 10001; now += 1) {
            update(now);
        }

        THEN("After simulating 10 seconds, counter1 was updated 10 more times and counter2 was updated 5 more times")
        {
            CHECK(counter1->count() == 1 + 10);
            CHECK(counter2->count() == 1 + 5);
        }

        update(10500); // update just before write
        TestCommand writeCmd(100,
                             1002,
                             {0xa0, 0x0f} // interval 4000
        );
        CHECK(writeBlock(writeCmd.request, writeCmd.callback) == CboxError::OK);
        CHECK(counter1->interval() == 4000);

        THEN("Writing a new interval (4000) to counter 1 has triggered an update of the object")
        {
            CHECK(counter1->count() == 10 + 1 + 1);
            CHECK(counter2->count() == 5 + 1);
        }

        THEN("It is updated 4000 ms after the write and 4000 ms after that")
        {
            uint32_t now;

            for (now = 10500; now <= 20000; now += 1) {
                update(now);
                if (counter1->count() > 12) {
                    break;
                }
            }
            CHECK(now == 14500);

            for (now = 14500; now <= 20000; now += 1) {
                update(now);
                if (counter1->count() > 13) {
                    break;
                }
            }
            CHECK(now == 18500);
        }

        THEN("An overflowing time is handled correctly")
        {
            update_t tenSecondsBeforeOverflow = std::numeric_limits<update_t>::max() - 10000;
            update_t now = tenSecondsBeforeOverflow;

            forcedUpdate(now);
            auto count = counter1->count();

            // run for 20 seconds
            for (; now != 10000; ++now) {
                update(now);
            }

            CHECK(counter1->count() == count + 20000 / counter1->interval());
        }
    }

    WHEN("An object with links to other objects is created, it can use data from those other objects")
    {
        TestCommand createCmd(100,
                              1005,
                              {0x02, 0x00, // ptr 1 points to object 2
                               0x03, 0x00} // ptr 2 points to object 3
        );

        CHECK(createBlock(createCmd.request, createCmd.callback) == CboxError::OK);
        CHECK(hexed(createCmd.responses.at(0).content) ==
              "0200"     // ptr 1 points to ID 2
              "0300"     // ptr 2 points to ID 3
              "01"       // ptr1 OK
              "01"       // ptr2 OK
              "11111111" // value 1
              "22222222" // value 2
        );

        AND_THEN("If the links change and point to an invalid object, the output is correct")
        {
            TestCommand writeCmd(100,
                                 1005,
                                 {0x03, 0x00, // ptr 1 points to object 3
                                  0x04, 0x00} // ptr 2 points to object 4
            );
            CHECK(writeBlock(writeCmd.request, writeCmd.callback) == CboxError::OK);

            CHECK(hexed(writeCmd.responses.at(0).content) ==
                  "0300"     // ptr 1 points to ID 3
                  "0400"     // ptr 2 points to ID 4
                  "01"       // ptr1 OK
                  "00"       // ptr2 not OK
                  "22222222" // value 1
                  "00000000" // value 2 is default value 0
            );
        }
    }

    WHEN("A device discovery command is received")
    {
        TestCommand cmd;
        CHECK(discoverBlocks(cmd.callback) == CboxError::OK);

        THEN("A list of IDs of newly created objects is returned")
        {
            // we expect this command to create 3 new objects, with values 0x33333333, 0x44444444, 0x55555555
            // 0x11111111 and 0x22222222 already exist
            CHECK(cmd.responses.size() == 3);
            CHECK(cmd.responses.at(0).blockId == 100);
            CHECK(cmd.responses.at(1).blockId == 101);
            CHECK(cmd.responses.at(2).blockId == 102);
        }

        THEN("The objects that didn't exist yet but where provided by the scanner have been created")
        {
            cmd.responses.clear();
            readAllBlocks(cmd.callback);
            CHECK(cmd.responses.size() == 5);

            CHECK(cmd.responses.at(0).blockId == 2);
            CHECK(cmd.responses.at(1).blockId == 3);
            CHECK(cmd.responses.at(2).blockId == 100);
            CHECK(cmd.responses.at(3).blockId == 101);
            CHECK(cmd.responses.at(4).blockId == 102);

            CHECK(hexed(cmd.responses.at(0).content) == "11111111");
            CHECK(hexed(cmd.responses.at(1).content) == "22222222");
            CHECK(hexed(cmd.responses.at(2).content) == "33333333");
            CHECK(hexed(cmd.responses.at(3).content) == "44444444");
            CHECK(hexed(cmd.responses.at(4).content) == "55555555");
        }

        THEN("The newly discovered objects are persisted")
        {
            cmd.responses.clear();
            readAllStoredBlocks(cmd.callback);

            CHECK(cmd.responses.at(0).blockId == 100);
            CHECK(cmd.responses.at(1).blockId == 101);
            CHECK(cmd.responses.at(2).blockId == 102);

            CHECK(hexed(cmd.responses.at(0).content) == "33333333");
            CHECK(hexed(cmd.responses.at(1).content) == "44444444");
            CHECK(hexed(cmd.responses.at(2).content) == "55555555");
        }
    }
}
