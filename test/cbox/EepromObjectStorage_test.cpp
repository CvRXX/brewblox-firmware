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

#include "TestObjects.hpp"
#include "cbox/EepromAccess.hpp"
#include "cbox/EepromObjectStorage.hpp"
#include "cbox/Object.hpp"
#include <catch.hpp>
#include <cstdio>

using namespace cbox;

SCENARIO("Storing and retrieving blocks with EEPROM storage")
{
    ArrayEepromAccess<2048> eeprom;
    EepromObjectStorage storage(eeprom);

    stream_size_t totalSpace = storage.freeSpace();

    // storage doesn't know about the Object class, these functors handle the conversion to payload
    auto loadObjectFromStorage = [&storage](const obj_id_t& id, const std::shared_ptr<Object>& target) -> CboxError {
        return storage.loadObject(id, [&target](const Payload& stored) {
            return target->write(stored);
        });
    };

    auto saveObjectToStorage = [&storage](const obj_id_t& id, const std::shared_ptr<Object>& source) -> CboxError {
        return source->readStored([&storage, &id](const Payload& stored) {
            auto contentCopy = std::vector<uint8_t>();
            std::copy(stored.content.begin(), stored.content.end(), std::back_inserter(contentCopy));
            return storage.saveObject(Payload(id,
                                              stored.blockType,
                                              0,
                                              std::move(contentCopy)));
        });
    };

    THEN("Storage is one big disposed block initially")
    {
        CHECK(totalSpace == storage.continuousFreeSpace());
    }

    WHEN("An object is created")
    {
        auto obj = std::make_shared<LongIntObject>(0x33333333);
        obj->setObjectId(1);

        THEN("It can be saved to EEPROM")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);

            THEN("Return value is success")
            {
                CHECK(res == CboxError::OK);
            }

            THEN(
                "Free space has decreased by 19 bytes"
                ", 1 byte flags (previously groups)"
                ", 2 bytes object type"
                ", 4 bytes object data"
                ", 2 bytes object id"
                ", 4 bytes overprovision"
                ", 5 bytes object header"
                ", 1 byte CRC")
            {
                CHECK(storage.freeSpace() == totalSpace - 19);
            }

            THEN("The data can be streamed back from EEPROM")
            {
                auto received = std::make_shared<LongIntObject>(0xFFFFFFFF);
                auto res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(obj->value() == received->value());
            }

            THEN("It can be changed and rewritten to EEPROM")
            {
                obj->value(0xAAAAAAAA);
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                auto received = std::make_shared<LongIntObject>(0xFFFFFFFF);
                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(obj->value() == received->value());
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
                    auto received = std::make_shared<LongIntObject>(0xFFFFFFFF);
                    auto res = loadObjectFromStorage(obj_id_t(1), received);
                    CHECK(res == CboxError::INVALID_STORED_BLOCK_ID);
                    CHECK(0xFFFFFFFF == received->value()); // received is unchanged
                }
                THEN("The id can be re-used to store another object")
                {
                    auto otherObject = std::make_shared<LongIntObject>(0xAAAAAAAA);
                    auto res = saveObjectToStorage(obj_id_t(1), otherObject);

                    THEN("Return value is success")
                    {
                        CHECK(res == CboxError::OK);
                    }

                    AND_THEN("The id returns the new object's data")
                    {
                        auto received = std::make_shared<LongIntObject>(0xFFFFFFFF);
                        auto res = loadObjectFromStorage(obj_id_t(1), received);
                        CHECK(res == CboxError::OK);
                        CHECK(uint32_t(0xAAAAAAAA) == received->value());
                    }
                }
            }
        }
    }

    WHEN("An variable size object is created")
    {
        auto obj = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject({0x11111111, 0x22222222}));
        auto received = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject());

        THEN("It can be saved to EEPROM")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);
            THEN("Return value is success")
            {
                CHECK(res == CboxError::OK);
            }

            THEN("The data can be streamed back from EEPROM")
            {
                auto res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
            }

            THEN("It can be changed and rewritten to EEPROM, same size")
            {
                obj->values = {0x22222222, 0x33333333};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
            }

            THEN("It can be changed and rewritten to EEPROM, 4 bytes bigger size")
            {
                obj->values = {0x22222222, 0x33333333, 0x44444444};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
            }

            THEN("It can be changed and rewritten to EEPROM, 16 bytes bigger size")
            {
                obj->values = {0x22222222, 0x33333333, 0x44444444, 0x55555555, 0x66666666, 0x77777777};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
            }

            THEN("It can be changed and rewritten to EEPROM, 4 bytes smaller size")
            {
                obj->values = {0x22222222};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
            }

            THEN("It can be changed and rewritten to EEPROM, 8 bytes smaller size (empty vector)")
            {
                obj->values.clear();
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
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
                    auto res = loadObjectFromStorage(obj_id_t(1), received);
                    CHECK(uint8_t(res) == uint8_t(CboxError::INVALID_STORED_BLOCK_ID));
                }
                THEN("The id can be re-used, for a different object type")
                {
                    auto otherObject = std::make_shared<LongIntObject>(0xAAAAAAAA);
                    auto res = saveObjectToStorage(obj_id_t(1), otherObject);

                    THEN("Return value is success")
                    {
                        CHECK(res == CboxError::OK);
                    }

                    AND_THEN("The id returns the new object's data")
                    {
                        auto received = std::make_shared<LongIntObject>(0xFFFFFFFF);
                        auto res = loadObjectFromStorage(obj_id_t(1), received);
                        CHECK(res == CboxError::OK);
                        CHECK(uint32_t(0xAAAAAAAA) == received->value());
                    }
                }
            }
        }
    }

    WHEN("Multiple objects are created and saved to eeprom")
    {
        auto obj1 = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject({0x11111111, 0x22222222}));
        auto obj2 = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject({0x11111111, 0x22222222, 0x33333333}));
        auto obj3 = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject({0x11111111, 0x22222222, 0x33333333, 0x44444444}));
        auto obj4 = std::make_shared<LongIntObject>(0x11111111);

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
                auto received = std::make_shared<LongIntVectorObject>();
                CHECK(CboxError::OK == loadObjectFromStorage(obj_id_t(1), received));
                CHECK(*obj1 == *received);
                CHECK(CboxError::OK == loadObjectFromStorage(obj_id_t(2), received));
                CHECK(*obj2 == *received);
                CHECK(CboxError::OK == loadObjectFromStorage(obj_id_t(3), received));
                CHECK(*obj3 == *received);
                auto received2 = std::make_shared<LongIntObject>();
                CHECK(CboxError::OK == loadObjectFromStorage(obj_id_t(4), received2));
                CHECK(*obj4 == *received2);
            }

            AND_THEN("They can be updated in EEPROM")
            {
                obj2->values = {0x33333333, 0x33333333};
                CHECK(CboxError::OK == saveObjectToStorage(obj_id_t(2), obj2));
                auto received = std::make_shared<LongIntVectorObject>();
                CHECK(CboxError::OK == loadObjectFromStorage(obj_id_t(2), received));
                CHECK(*obj2 == *received);
            }

            AND_THEN("If one is deleted, it doesn't affect the others")
            {
                storage.disposeObject(obj_id_t(2));
                auto received = std::make_shared<LongIntVectorObject>();
                CHECK(CboxError::OK == loadObjectFromStorage(obj_id_t(1), received));
                CHECK(*obj1 == *received);
                CHECK(CboxError::INVALID_STORED_BLOCK_ID == loadObjectFromStorage(obj_id_t(2), received));
                CHECK(CboxError::OK == loadObjectFromStorage(obj_id_t(3), received));
                CHECK(*obj3 == *received);
                auto received2 = std::make_shared<LongIntObject>();
                CHECK(CboxError::OK == loadObjectFromStorage(obj_id_t(4), received2));
                CHECK(*obj4 == *received2);

                AND_THEN("A handler handling all objects does not see the deleted object")
                {
                    std::vector<obj_id_t> ids;
                    auto idCollector = [&ids](const Payload& stored) -> CboxError {
                        ids.push_back(stored.blockId);
                        return CboxError::OK;
                    };
                    CHECK(storage.loadAllObjects(idCollector) == CboxError::OK);
                    CHECK(ids == std::vector<obj_id_t>({1, 3, 4}));
                }
            }

            AND_THEN("When a storage stream error occurs when handling a block, blocks processing is stopped")
            {
                std::vector<obj_id_t> ids;
                auto errorOn3 = [&ids](const Payload& stored) -> CboxError {
                    if (stored.blockId == 3) {
                        return CboxError::STORAGE_READ_ERROR;
                    }
                    ids.push_back(stored.blockId);
                    return CboxError::OK;
                };

                CHECK(storage.loadAllObjects(errorOn3) == CboxError::STORAGE_READ_ERROR);
                CHECK(ids == std::vector<obj_id_t>({1, 2}));
            }
        }
    }

    WHEN("A lot of big and small objects are created until EEPROM is full, alternating big and small")
    {
        // 18*4 = 72 bytes
        auto big = std::make_shared<LongIntVectorObject>();
        big->values = {
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
        auto small = std::make_shared<LongIntVectorObject>();
        small->values = {0x11111111, 0x22222222};

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

        CHECK(res == CboxError::INSUFFICIENT_STORAGE);
        uint16_t bigSize = 2 + big->values.size() * sizeof(uint32_t);     // 2 bytes (number of elements) + vector
        uint16_t smallSize = 2 + small->values.size() * sizeof(uint32_t); // 2 bytes (number of elements) + vector

        uint16_t bigSizeReserved = bigSize + (bigSize / 8);
        uint16_t smallSizeReserved = smallSize + 4;

        uint16_t metadataSize = 0
                                + 1 // eeprom block type
                                + 2 // reserved size
                                + 2 // actual size
                                + 2 // blockId
                                + 1 // flags
                                + 2 // blockType
                                + 1 // CRC
            ;

        // last id was not successfully created
        THEN("26 objects have been created")
        {
            CHECK(id == 27); // failed to create id 27
        }

        stream_size_t expectedFreeSpace = originalSpace - (13 * bigSizeReserved + 13 * smallSizeReserved + 26 * metadataSize);

        THEN("Free space left is as expected")
        {
            CHECK(storage.freeSpace() == expectedFreeSpace);
        }

        THEN("Continuous free space left is the same, which is too small for another big object")
        {
            CHECK(storage.continuousFreeSpace() == expectedFreeSpace);
            CHECK(expectedFreeSpace < bigSizeReserved + metadataSize);
        }

        THEN("Last object has not been stored")
        {
            CboxError res;
            res = loadObjectFromStorage(id, big);
            CHECK(res == CboxError::INVALID_STORED_BLOCK_ID);
        }

        THEN("But we can still create a small object")
        {
            CHECK(CboxError::OK == saveObjectToStorage(id, small));
        }

        THEN("We can still create a small variable size object")
        {

            auto obj = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject({0x11111111, 0x22222222}));

            auto res = saveObjectToStorage(obj_id_t(id), obj);
            CHECK(res == CboxError::OK);

            AND_WHEN("the same object grows within the reserved space, it can be stored and retrieved")
            {
                obj->values = {0x22222222, 0x33333333, 0x44444444};
                auto res = saveObjectToStorage(obj_id_t(id), obj);
                CHECK(res == CboxError::OK);

                auto received = std::make_shared<LongIntVectorObject>();
                res = loadObjectFromStorage(obj_id_t(id), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);

                auto spaceBefore = storage.freeSpace();

                AND_WHEN("the object grows beyond the reserved space, we get an error")
                {
                    auto res = saveObjectToStorage(obj_id_t(id), big);
                    CHECK(uint8_t(res) == uint8_t(CboxError::INSUFFICIENT_STORAGE));

                    AND_THEN("the original object is unchanged in eeprom")
                    {
                        auto received = std::make_shared<LongIntVectorObject>();
                        res = loadObjectFromStorage(obj_id_t(id), received);
                        CHECK(res == CboxError::OK);
                        CHECK(*obj == *received);
                    }

                    AND_THEN("The free space is unchanged")
                    {
                        CHECK(storage.freeSpace() == spaceBefore);
                    }

                    AND_WHEN("We delete a big object allocated near the start of EEPROM")
                    {
                        CHECK(storage.disposeObject(3));
                        auto spaceAfterDelete = spaceBefore + bigSizeReserved + metadataSize; // freed up 1 big object of bytes
                        CHECK(storage.freeSpace() == spaceAfterDelete);

                        THEN("We can store the grown object again, it is relocated")
                        {
                            auto res = saveObjectToStorage(obj_id_t(id), big);
                            CHECK(res == CboxError::OK);
                            CHECK(storage.freeSpace() == spaceAfterDelete - bigSizeReserved + smallSizeReserved);

                            auto received = std::make_shared<LongIntVectorObject>();
                            res = loadObjectFromStorage(obj_id_t(id), received);
                            CHECK(res == CboxError::OK);
                            CHECK(*big == *received);
                        }
                    }
                }
            }
        }

        AND_WHEN("Only the small objects are deleted")
        {
            obj_id_t id;
            for (id = 1; id <= 26; id++) {
                if (id % 2 == 0) {
                    bool deleted = storage.disposeObject(id);
                    CHECK(deleted);
                }
            }
            THEN("Continuous free space has increased by size of 1 small object + metadata")
            {
                CHECK(storage.continuousFreeSpace() == expectedFreeSpace + smallSizeReserved + metadataSize);
            }
            THEN("But free space has increased by the size of all small objects combined")
            {
                CHECK(storage.freeSpace() == expectedFreeSpace + 13 * (smallSizeReserved + metadataSize));
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
                        auto received = std::make_shared<LongIntVectorObject>();
                        CHECK(CboxError::OK == loadObjectFromStorage(id, received));
                        CHECK(*received == *big);
                    }
                }
            }
        }
    }

    WHEN("An object is stored with id 0")
    {
        auto obj = std::make_shared<LongIntObject>(0x33333333);

        auto res = saveObjectToStorage(obj_id_t(0), obj);

        THEN("an error is returned")
        {
            CHECK(res == CboxError::INVALID_BLOCK_ID);
        }

        THEN("free space is unaffected")
        {
            CHECK(storage.freeSpace() == totalSpace);
        }
    }

    WHEN("An error occurs when an object is persisted")
    {
        auto obj = std::make_shared<MockStreamObject>();

        WHEN("The error occurs during test serialization, the error raised is returned")
        {
            obj->readStoredFunc = [](const PayloadCallback&) { return CboxError::NETWORK_WRITE_ERROR; };
            auto res = saveObjectToStorage(obj_id_t(1234), obj);
            CHECK(int(res) == int(CboxError::NETWORK_WRITE_ERROR));

            obj->readStoredFunc = [](const PayloadCallback&) { return CboxError::NETWORK_ENCODING_ERROR; };
            res = saveObjectToStorage(obj_id_t(1234), obj);
            CHECK(int(res) == int(CboxError::NETWORK_ENCODING_ERROR));
        }

        WHEN("The object is too big to fit in eeprom, INSUFFICIENT_PERSISTENT_STORAGE is returned")
        {
            obj->readStoredFunc = [&obj](const PayloadCallback& callback) {
                Payload payload(obj->objectId(), obj->typeId(), 0);
                payload.content.resize(2000);
                return callback(payload);
            };
            auto res = saveObjectToStorage(obj_id_t(1234), obj);
            CHECK(int(res) == int(CboxError::INSUFFICIENT_STORAGE));
        }
    }

    WHEN("An object indicates it does not need persistence")
    {
        auto obj = std::make_shared<MockStreamObject>();
        obj->readStoredFunc = [](const PayloadCallback&) {
            return CboxError::OK;
        };

        THEN("The object does not end up in eeprom")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);
            CHECK(res == CboxError::OK);

            CHECK(CboxError::INVALID_STORED_BLOCK_ID == loadObjectFromStorage(1, obj));
        }
    }
}
