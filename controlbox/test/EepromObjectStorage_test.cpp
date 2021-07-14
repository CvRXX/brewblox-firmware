/*
 * Copyright 2018 BrewPi
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

#include "ArrayEepromAccess.h"
#include "EepromObjectStorage.h"
#include "Object.h"
#include "TestObjects.h"
#include <catch.hpp>
#include <cstdio>

using namespace cbox;

SCENARIO("Storing and retreiving blocks with EEPROM storage")
{
    ArrayEepromAccess<2048> eeprom;
    EepromObjectStorage storage(eeprom);

    stream_size_t totalSpace = storage.freeSpace();

    // storage doesn't know about the Object class, these functors handle the conversion to streams
    auto retreiveObjectFromStorage = [&storage](const obj_id_t& id, Object& target) -> CboxError {
        auto dataHandler = [&target](DataIn& in) -> CboxError {
            return target.streamFrom(in);
        };
        return storage.retrieveObject(id, dataHandler);
    };

    auto saveObjectToStorage = [&storage](const obj_id_t& id, const Object& source) -> CboxError {
        auto dataHandler = [&source](DataOut& out) -> CboxError {
            return source.streamPersistedTo(out);
        };
        return storage.storeObject(id, dataHandler);
    };

    THEN("Storage is one big disposed block initially")
    {
        CHECK(totalSpace == storage.continuousFreeSpace());
    }

    WHEN("An object is created")
    {
        LongIntObject obj(0x33333333);

        THEN("It can be saved to EEPROM")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);

            THEN("Return value is success")
            {
                CHECK(res == CboxError::OK);
            }

            THEN(
                "Free space has decreased by 16 bytes "
                "(4 bytes object data + 2 bytes object id + 4 bytes overprovision + 5 bytes object header + 1 byte CRC")
            {
                CHECK(storage.freeSpace() == totalSpace - 16);
            }

            THEN("The data can be streamed back from EEPROM")
            {
                LongIntObject target(0xFFFFFFFF);
                auto res = retreiveObjectFromStorage(obj_id_t(1), target);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(uint32_t(obj) == uint32_t(target));
            }

            THEN("It can be changed and rewritten to EEPROM")
            {
                obj = 0xAAAAAAAA;
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));

                LongIntObject received(0xFFFFFFFF);
                res = retreiveObjectFromStorage(obj_id_t(1), received);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(uint32_t(obj) == uint32_t(received));
            }

            THEN("It can be disposed")
            {
                bool success = storage.disposeObject(obj_id_t(1));
                THEN("Which returns true for success")
                {
                    CHECK(success);
                }

                THEN("Free space equals total space again")
                {
                    CHECK(storage.freeSpace() == totalSpace);
                }

                THEN("It cannot be retrieved anymore")
                {
                    LongIntObject received(0xFFFFFFFF);
                    auto res = retreiveObjectFromStorage(obj_id_t(1), received);
                    CHECK(uint8_t(res) == uint8_t(CboxError::PERSISTED_OBJECT_NOT_FOUND));
                    CHECK(0xFFFFFFFF == uint32_t(received)); // received is unchanged
                }
                THEN("The id can be re-used to store another object")
                {
                    LongIntObject otherObject(0xAAAAAAAA);
                    auto res = saveObjectToStorage(obj_id_t(1), otherObject);

                    THEN("Return value is success")
                    {
                        CHECK(res == CboxError::OK);
                    }

                    AND_THEN("The id returns the new object's data")
                    {
                        LongIntObject received(0xFFFFFFFF);
                        auto res = retreiveObjectFromStorage(obj_id_t(1), received);
                        CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                        CHECK(uint32_t(0xAAAAAAAA) == uint32_t(received));
                    }
                }
            }
        }
    }

    WHEN("An variable size object is created")
    {
        LongIntVectorObject obj = {0x11111111, 0x22222222};

        THEN("It can be saved to EEPROM")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);
            THEN("Return value is success")
            {
                CHECK(res == CboxError::OK);
            }

            THEN("The data can be streamed back from EEPROM")
            {
                LongIntVectorObject target;
                auto res = retreiveObjectFromStorage(obj_id_t(1), target);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(obj == target);
            }

            THEN("It can be changed and rewritten to EEPROM, same size")
            {
                obj = {0x22222222, 0x33333333};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));

                LongIntVectorObject received;
                res = retreiveObjectFromStorage(obj_id_t(1), received);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(obj == received);
            }

            THEN("It can be changed and rewritten to EEPROM, 4 bytes bigger size")
            {
                obj = {0x22222222, 0x33333333, 0x44444444};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));

                LongIntVectorObject received;
                res = retreiveObjectFromStorage(obj_id_t(1), received);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(obj == received);
            }

            THEN("It can be changed and rewritten to EEPROM, 16 bytes bigger size")
            {
                obj = {0x22222222, 0x33333333, 0x44444444, 0x55555555, 0x66666666, 0x77777777};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));

                LongIntVectorObject received;
                res = retreiveObjectFromStorage(obj_id_t(1), received);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(obj == received);
            }

            THEN("It can be changed and rewritten to EEPROM, 4 bytes smaller size")
            {
                obj = {0x22222222};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));

                LongIntVectorObject received;
                res = retreiveObjectFromStorage(obj_id_t(1), received);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(obj == received);
            }

            THEN("It can be changed and rewritten to EEPROM, 8 bytes smaller size (empty vector)")
            {
                obj = {};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));

                LongIntVectorObject received;
                res = retreiveObjectFromStorage(obj_id_t(1), received);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(obj == received);
            }

            THEN("It can be disposed")
            {
                bool success = storage.disposeObject(obj_id_t(1));
                THEN("Which returns true for success")
                {
                    CHECK(success);
                }

                THEN("It cannot be retrieved anymore")
                {
                    LongIntVectorObject received;
                    auto res = retreiveObjectFromStorage(obj_id_t(1), received);
                    CHECK(uint8_t(res) == uint8_t(CboxError::PERSISTED_OBJECT_NOT_FOUND));
                }
                THEN("The id can be re-used, for a different object type")
                {
                    LongIntObject otherObject(0xAAAAAAAA);
                    auto res = saveObjectToStorage(obj_id_t(1), otherObject);

                    THEN("Return value is success")
                    {
                        CHECK(res == CboxError::OK);
                    }

                    AND_THEN("The id returns the new object's data")
                    {
                        LongIntObject received(0xFFFFFFFF);
                        auto res = retreiveObjectFromStorage(obj_id_t(1), received);
                        CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                        CHECK(uint32_t(0xAAAAAAAA) == uint32_t(received));
                    }
                }
            }
        }
    }

    WHEN("Multiple objects are created and saved to eeprom")
    {
        LongIntVectorObject obj1 = {0x11111111, 0x22222222};
        LongIntVectorObject obj2 = {0x11111111, 0x22222222, 0x33333333};
        LongIntVectorObject obj3 = {0x11111111, 0x22222222, 0x33333333, 0x44444444};
        LongIntObject obj4 = 0x11111111;

        auto res1 = saveObjectToStorage(obj_id_t(1), obj1);
        auto res2 = saveObjectToStorage(obj_id_t(2), obj2);
        auto res3 = saveObjectToStorage(obj_id_t(3), obj3);
        auto res4 = saveObjectToStorage(obj_id_t(4), obj4);

        THEN("They are stored successfully")
        {
            CHECK(res1 == CboxError::OK);
            CHECK(res2 == CboxError::OK);
            CHECK(res3 == CboxError::OK);
            CHECK(res4 == CboxError::OK);

            AND_THEN("They can be retrieved successfully")
            {
                LongIntVectorObject received;
                CHECK(CboxError::OK == retreiveObjectFromStorage(obj_id_t(1), received));
                CHECK(obj1 == received);
                CHECK(CboxError::OK == retreiveObjectFromStorage(obj_id_t(2), received));
                CHECK(obj2 == received);
                CHECK(CboxError::OK == retreiveObjectFromStorage(obj_id_t(3), received));
                CHECK(obj3 == received);
                LongIntObject received2;
                CHECK(CboxError::OK == retreiveObjectFromStorage(obj_id_t(4), received2));
                CHECK(obj4 == received2);
            }

            AND_THEN("They can be updated in EEPROM")
            {
                obj2 = {0x33333333, 0x33333333};
                CHECK(CboxError::OK == saveObjectToStorage(obj_id_t(2), obj2));
                LongIntVectorObject received;
                CHECK(CboxError::OK == retreiveObjectFromStorage(obj_id_t(2), received));
                CHECK(obj2 == received);
            }

            AND_THEN("If one is deleted, it doesn't affect the others")
            {
                storage.disposeObject(obj_id_t(2));
                LongIntVectorObject received;
                CHECK(CboxError::OK == retreiveObjectFromStorage(obj_id_t(1), received));
                CHECK(obj1 == received);
                CHECK(CboxError::PERSISTED_OBJECT_NOT_FOUND == retreiveObjectFromStorage(obj_id_t(2), received));
                CHECK(CboxError::OK == retreiveObjectFromStorage(obj_id_t(3), received));
                CHECK(obj3 == received);
                LongIntObject received2;
                CHECK(CboxError::OK == retreiveObjectFromStorage(obj_id_t(4), received2));
                CHECK(obj4 == received2);

                AND_THEN("A handler handling all objects does not see the deleted object")
                {
                    std::vector<obj_id_t> ids;
                    auto idCollector = [&ids](const storage_id_t& id, DataIn& objInStorage) -> CboxError {
                        CHECK(objInStorage.streamType() == StreamType::Eeprom); // for test coverage
                        ids.push_back(id);
                        return CboxError::OK;
                    };
                    CHECK(storage.retrieveObjects(idCollector) == CboxError::OK);
                    CHECK(ids == std::vector<obj_id_t>({1, 3, 4}));
                }
            }

            AND_THEN("When a storage stream error occurs when handling a block, blocks processing is stopped")
            {
                std::vector<obj_id_t> ids;
                auto errorOn3 = [&ids](const storage_id_t& id, DataIn& objInStorage) -> CboxError {
                    if (id == 3) {
                        return CboxError::PERSISTED_BLOCK_STREAM_ERROR;
                    }
                    ids.push_back(id);
                    return CboxError::OK;
                };

                CHECK(storage.retrieveObjects(errorOn3) == CboxError::PERSISTED_BLOCK_STREAM_ERROR);
                CHECK(ids == std::vector<obj_id_t>({1, 2}));
            }
        }
    }

    WHEN("A lot of big and small objects are created until EEPROM is full, alternating big and small")
    {
        // 18*4 = 72 bytes
        LongIntVectorObject big = {
            0x22222222,
            0x33333333,
            0x44444444,
            0x55555555,
            0x66666666,
            0x77777777,
            0x22222222,
            0x33333333,
            0x44444444,
            0x55555555,
            0x66666666,
            0x77777777,
            0x22222222,
            0x33333333,
            0x44444444,
            0x55555555,
            0x66666666,
            0x77777777,
            0x22222222,
            0x33333333,
            0x44444444,
            0x55555555,
            0x66666666,
            0x77777777,
        };

        // 2*4 = 8 bytes
        LongIntVectorObject small = {0x11111111, 0x22222222};

        uint16_t originalSpace = storage.freeSpace();

        THEN("The free space is as expected before adding any objects")
        {
            CHECK(originalSpace == 2048 - 32 - 3); // 32 bytes reserved for non-object data. 3 bytes for the block header of a new block
        }

        CboxError res = CboxError::OK;
        obj_id_t id = 0; // first id will be 1, 0 is an invalid id
        while (true) {
            ++id;
            if (id % 2 == 0) {
                res = saveObjectToStorage(id, small);
            } else {
                res = saveObjectToStorage(id, big);
            }
            if (res != CboxError::OK) {
                break;
            }
        }

        uint16_t bigSize = 2 + 24 * sizeof(uint32_t) + 1;  // 2 bytes (number of elements) + vector + CRC
        uint16_t smallSize = 2 + 2 * sizeof(uint32_t) + 1; // 2 bytes (number of elements) + vector + CRC

        uint16_t bigSizeReserved = bigSize + (bigSize >> 3);
        uint16_t smallSizeReserved = smallSize + 4;

        uint16_t headerSize = 7; // blocktype(1) + blocksize(2) + obj_id(2) + obj_actual_size(2)

        THEN("Retreiving objects gives a reader of the actually written size")
        {
            uint16_t readSize;
            auto readSizeFetcher = [&readSize](RegionDataIn& in) -> CboxError {
                readSize = in.available();
                return CboxError::OK;
            };
            storage.retrieveObject(1, readSizeFetcher);
            CHECK(readSize == bigSize);
            storage.retrieveObject(2, readSizeFetcher);
            CHECK(readSize == smallSize);
        }

        // checking the write size is more difficult, because there is no limit. If it doesn't fit, the object will be reallocated.

        // last id was not successfully created
        THEN("28 objects have been created")
        {
            CHECK(id == 29); // failed to create id 29
        }

        uint16_t expectedFreeSpace = originalSpace - (14 * bigSizeReserved + 14 * smallSizeReserved + 28 * headerSize); // header is 5 bytes

        THEN("Free space left is as expected")
        {
            CHECK(storage.freeSpace() == expectedFreeSpace);
        }

        THEN("Continuous free space left is the same, which is too small for another big object")
        {
            CHECK(storage.continuousFreeSpace() == expectedFreeSpace);
            CHECK(expectedFreeSpace < bigSizeReserved);
        }

        THEN("Last object has not been stored")
        {
            CboxError res;
            res = retreiveObjectFromStorage(id, big);
            CHECK(res == CboxError::PERSISTED_OBJECT_NOT_FOUND);
        }

        THEN("But we can still create a small object")
        {
            CHECK(CboxError::OK == saveObjectToStorage(id, small));
        }

        THEN("We can still create a small variable size object")
        {

            LongIntVectorObject obj = {0x11111111, 0x22222222};

            auto res = saveObjectToStorage(obj_id_t(id), obj);
            CHECK(res == CboxError::OK);

            AND_WHEN("the same object grows within the reserved space, it can be stored and retreived")
            {
                obj = {0x22222222, 0x33333333, 0x44444444};
                auto res = saveObjectToStorage(obj_id_t(id), obj);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));

                LongIntVectorObject received;
                res = retreiveObjectFromStorage(obj_id_t(id), received);
                CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                CHECK(obj == received);

                auto spaceBefore = storage.freeSpace();

                AND_WHEN("the object grows beyond the reserved space, we get an error")
                {
                    auto res = saveObjectToStorage(obj_id_t(id), big);
                    CHECK(uint8_t(res) == uint8_t(CboxError::INSUFFICIENT_PERSISTENT_STORAGE));

                    AND_THEN("the original object is unchanged in eeprom")
                    {
                        LongIntVectorObject received;
                        res = retreiveObjectFromStorage(obj_id_t(id), received);
                        CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                        CHECK(obj == received);
                    }

                    AND_THEN("The free space is unchanged")
                    {
                        CHECK(storage.freeSpace() == spaceBefore);
                    }

                    AND_WHEN("We delete a big object allocated near the start of EEPROM")
                    {
                        CHECK(storage.disposeObject(3));
                        auto spaceAfterDelete = spaceBefore + bigSizeReserved + headerSize; // freed up 1 big object of bytes
                        CHECK(storage.freeSpace() == spaceAfterDelete);

                        THEN("We can store the grown object again, it is relocated")
                        {
                            auto res = saveObjectToStorage(obj_id_t(id), big);
                            CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                            CHECK(storage.freeSpace() == spaceAfterDelete - bigSizeReserved + smallSizeReserved);

                            LongIntVectorObject received;
                            res = retreiveObjectFromStorage(obj_id_t(id), received);
                            CHECK(uint8_t(res) == uint8_t(CboxError::OK));
                            CHECK(big == received);
                        }
                    }
                }
            }
        }

        AND_WHEN("Only the small objects are deleted")
        {
            obj_id_t id;
            for (id = 1; id <= 28; id++) {
                if (id % 2 == 0) {
                    bool deleted = storage.disposeObject(id);
                    CHECK(deleted);
                }
            }
            THEN("Continuous free space has increased by size of 1 small object + header")
            {
                CHECK(storage.continuousFreeSpace() == expectedFreeSpace + smallSizeReserved + 7);
            }
            THEN("But free space has increased by the size of all small objects combined")
            {
                CHECK(storage.freeSpace() == expectedFreeSpace + 14 * (smallSizeReserved + 7));
            }

            AND_WHEN("We create 2 big objects again")
            {
                auto res1 = saveObjectToStorage(obj_id_t(1000), big);
                auto res2 = saveObjectToStorage(obj_id_t(1001), big);
                THEN("It succeeds")
                {
                    CHECK(res1 == CboxError::OK);
                    CHECK(res2 == CboxError::OK);
                }

                THEN("Eeprom was defragmented and continuous free space equals free space")
                {
                    INFO("Continuous free space after defrag: " << storage.continuousFreeSpace());
                    CHECK(storage.freeSpace() == storage.continuousFreeSpace());
                }

                THEN("All big objects still have the right value")
                {
                    for (id = 1; id < 10; id = id + 2) {
                        LongIntVectorObject received;
                        CHECK(CboxError::OK == retreiveObjectFromStorage(id, received));
                        CHECK(received == big);
                    }
                }
            }
        }
    }

    WHEN("An object is stored with id 0")
    {
        LongIntObject obj(0x33333333);

        auto res = saveObjectToStorage(obj_id_t(0), obj);

        THEN("an error is returned")
        {
            CHECK(res == CboxError::INVALID_OBJECT_ID);
        }

        THEN("free space is unaffected")
        {
            CHECK(storage.freeSpace() == totalSpace);
        }
    }

    WHEN("An error occurs when an object is persisted")
    {
        MockStreamObject obj;

        WHEN("The error occurs during test serialization, the error raised is returned")
        {
            obj.streamPersistedToFunc = [](cbox::DataOut& out) { return CboxError::OUTPUT_STREAM_WRITE_ERROR; };
            auto res = saveObjectToStorage(obj_id_t(1234), obj);
            CHECK(int(res) == int(CboxError::OUTPUT_STREAM_WRITE_ERROR));

            obj.streamPersistedToFunc = [](cbox::DataOut& out) { return CboxError::OUTPUT_STREAM_ENCODING_ERROR; };
            res = saveObjectToStorage(obj_id_t(1234), obj);
            CHECK(int(res) == int(CboxError::OUTPUT_STREAM_ENCODING_ERROR));
        }

        WHEN("The object is too big to fit in eeprom, INSUFFICIENT_PERSISTENT_STORAGE is returned")
        {
            obj.streamPersistedToFunc = [](cbox::DataOut& out) {
                for (uint16_t i = 0; i < 2000; i++) {
                    bool written = out.write(0);
                    if (!written) {
                        return CboxError::OUTPUT_STREAM_WRITE_ERROR;
                    }
                }
                return CboxError::OK;
            };
            auto res = saveObjectToStorage(obj_id_t(1234), obj);
            CHECK(int(res) == int(CboxError::INSUFFICIENT_PERSISTENT_STORAGE));
        }
    }

    WHEN("An object indicates it does not need persistence")
    {
        MockStreamObject obj;
        obj.streamPersistedToFunc = [](cbox::DataOut& out) {
            return CboxError::PERSISTING_NOT_NEEDED;
        };

        THEN("The object does not end up in eeprom")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);
            CHECK(res == CboxError::OK);

            CHECK(CboxError::PERSISTED_OBJECT_NOT_FOUND == retreiveObjectFromStorage(1, obj));
        }
    }
}
