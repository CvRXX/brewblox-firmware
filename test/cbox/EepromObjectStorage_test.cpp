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

#include "TestHelpers.hpp"
#include "TestObjects.hpp"
#include "cbox/EepromAccess.hpp"
#include "cbox/EepromObjectStorage.hpp"
#include "cbox/Object.hpp"
#include <catch.hpp>
#include <cstdio>

using namespace cbox;

class EepromOjectStorageTester : public EepromObjectStorage {
public:
    using EepromObjectStorage::EepromObjectStorage;
    using EepromObjectStorage::getExistingBlock;
    using EepromObjectStorage::getExistingObject;
    using EepromObjectStorage::getNewObject;
};

SCENARIO("Low level functions test", "[eeprom]")
{
    ArrayEepromAccess<2048> eeprom;
    EepromOjectStorageTester storage(eeprom);

    WHEN("A block is split")
    {
        auto block1Opt = storage.getExistingBlock(EepromBlockType::disposed_block, 0, EepromLocation(objects));
        REQUIRE(block1Opt.has_value());
        auto& block1 = block1Opt.value();
        CHECK(block1.length() == 2013);
        CHECK(block1.block_size() == 2016);
        CHECK(block1.object_pos() == EepromLocation(objects) + 3);
        CHECK(block1.object_data_pos() == EepromLocation(objects) + 3 + 4);
        CHECK(block1.end() == EepromLocation(objects) + 2016);
        CHECK(block1.remaining() == 2013);
        CHECK(storage.freeSpace().continuous == 2013);
        CHECK(storage.freeSpace().total == 2013);

        block1.split(100);
        CHECK(block1.remaining() == 100);
        CHECK(block1.end() == EepromLocation(objects) + 3 + 100);
        auto blockOpt2 = storage.getExistingBlock(EepromBlockType::disposed_block, 0, block1.end());
        REQUIRE(blockOpt2.has_value());
        auto block2 = blockOpt2.value();

        THEN("The new blocks have the expected length and size")
        {
            CHECK(block1.length() == 100);
            CHECK(block1.block_size() == 100 + EepromBlock::blockHeaderLength);
            CHECK(block2.length() == 2013 - block1.block_size());
            CHECK(block1.block_size() + block2.block_size() == 2016);
            CHECK(storage.freeSpace().continuous == block2.length());
            CHECK(storage.freeSpace().total == 2013);
        }
        AND_WHEN("When the blocks are joined again")
        {
            block1.join(block2);
            THEN("block 1 has the original size")
            {
                CHECK(block1.length() == 2013);
                CHECK(storage.freeSpace().continuous == 2013);
                CHECK(storage.freeSpace().total == 2013);
            }
        }
    }

    WHEN("A new object block is created")
    {
        auto objBlockOpt = storage.getNewObject(100);
        REQUIRE(objBlockOpt.has_value());
        auto& objBlock = objBlockOpt.value();

        THEN("The properties are as expected")
        {
            CHECK(objBlock.object_data_length() == 112);
            CHECK(objBlock.block_size() == 119);
            CHECK(objBlock.remaining() == 112); // pos starts at object data
            // object id is 0 until set
            CHECK(objBlock.getObjectId() == 0);
            objBlock.setObjectId(1);
            CHECK(objBlock.getObjectId() == 1);

            objBlock.setWrittenLength(50);
            CHECK(objBlock.getWrittenLength() == 50);

            AND_THEN("It can be retrieved from storage")
            {
                auto obj2Opt = storage.getExistingObject(1, true);
                REQUIRE(obj2Opt.has_value());
                auto obj2 = obj2Opt.value();
                CHECK(obj2.remaining() == 50);
                CHECK(obj2.object_data_length() == 112);
            }
        }
    }
}

SCENARIO("Storing and retrieving blocks with EEPROM storage")
{
    ArrayEepromAccess<2048> eeprom;
    EepromOjectStorageTester storage(eeprom);

    auto totalSpace = storage.freeSpace().total;

    // storage doesn't know about the Object class, these functors handle the conversion to payload
    auto loadObjectFromStorage = [&storage](obj_id_t id, const std::shared_ptr<Object>& target) -> CboxError {
        return storage.loadObject(id, [&target](const Payload& stored) {
            return target->write(stored);
        });
    };

    auto saveObjectToStorage = [&storage](obj_id_t id, const std::shared_ptr<Object>& source) -> CboxError {
        return source->readStored([&storage, &id](const Payload& stored) {
            // make a new Payload because we cannot set id in const Payload
            auto contentCopy = stored.content;
            return storage.saveObject(Payload(id,
                                              stored.blockType,
                                              0,
                                              std::move(contentCopy)));
        });
    };

    THEN("Storage is one big disposed block initially")
    {
        auto space = storage.freeSpace();
        CHECK(totalSpace == space.total);
        CHECK(totalSpace == space.continuous);
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
                ", 1 byte eeprom block type"
                ", 2 bytes eeprom size"
                ", 2 bytes actual object size incl id and flags"
                ", 2 bytes object id"
                ", 1 byte flags (previously groups)"
                ", 2 bytes object type"
                ", 4 bytes object data"
                ", 1 byte CRC"
                ", 4 bytes overprovision")
            {
                CHECK(storage.freeSpace().total == totalSpace - 19);
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
                    CHECK(storage.freeSpace().total == totalSpace);
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
                *obj = {0x22222222, 0x33333333};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
            }

            THEN("It can be changed and rewritten to EEPROM, 4 bytes bigger size")
            {
                *obj = {0x22222222, 0x33333333, 0x44444444};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
            }

            THEN("It can be changed and rewritten to EEPROM, 16 bytes bigger size")
            {
                *obj = {0x22222222, 0x33333333, 0x44444444, 0x55555555, 0x66666666, 0x77777777};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                res = loadObjectFromStorage(obj_id_t(1), received);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *received);
            }

            THEN("It can be changed and rewritten to EEPROM, 4 bytes smaller size")
            {
                *obj = {0x22222222};
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
        auto obj4 = std::shared_ptr<LongIntObject>(new LongIntObject(uint32_t{0x11111111}));

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
                *obj2 = {0x33333333, 0x33333333};
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
        *big = {
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
        *small = {0x11111111, 0x22222222};

        uint16_t originalSpace = storage.freeSpace().total;

        THEN("The free space is as expected before adding any objects")
        {
            CHECK(originalSpace == 2048 - 32 - 3); // 32 bytes reserved for non-object data. 3 bytes for the block header of a new block
        }

        CboxError res = CboxError::OK;
        obj_id_t id = 0; // first id will be 1, 0 is an invalid id
        while (true) {
            ++id;
            if (id % 20 == 0) {
                res = saveObjectToStorage(id, big);
            } else {
                res = saveObjectToStorage(id, small);
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

        uint16_t bigSizeTotal = bigSizeReserved + metadataSize;
        uint16_t smallSizeTotal = smallSizeReserved + metadataSize;

        // last id was not successfully created
        THEN("The expected number of objects have been created")
        {
            CHECK(bigSizeTotal == 121);
            CHECK(smallSizeTotal == 25);
            CHECK(3 * bigSizeTotal + 66 * smallSizeTotal == originalSpace); // exactly fits
            CHECK(id == 70);                                                // failed to create id 70. 3 big and 66 small objects
        }

        THEN("Last object has not been stored")
        {
            CboxError res;
            res = loadObjectFromStorage(id, big);
            CHECK(res == CboxError::INVALID_STORED_BLOCK_ID);
        }

        THEN("Free space left is 0")
        {
            auto space = storage.freeSpace();
            CHECK(space.total == 0);
            CHECK(space.continuous == 0);
        }

        AND_THEN("When we delete 6 small objects, adjacent per 2")
        {

            REQUIRE(storage.disposeObject(3));
            REQUIRE(storage.disposeObject(4));
            REQUIRE(storage.disposeObject(7));
            REQUIRE(storage.disposeObject(8));
            REQUIRE(storage.disposeObject(10));
            REQUIRE(storage.disposeObject(11));

            THEN("Continuous is 2 small objects and total is 6 small objects")
            {
                auto space = storage.freeSpace();
                CHECK(space.total == 6 * smallSizeTotal - 3U); // subtract 3 bytes needed for block header
                CHECK(space.continuous == 2 * smallSizeTotal - 3U);
            }

            THEN("When we create a small variable size object in that space")
            {
                auto obj = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject({0x11111111, 0x22222222}));

                auto res = saveObjectToStorage(obj_id_t(id), obj);
                CHECK(res == CboxError::OK);

                auto blockOpt = storage.getExistingObject(id, true);
                REQUIRE(blockOpt.has_value());
                auto originalPos = (*blockOpt).header_pos();
                auto originalProvisioned = (*blockOpt).length();

                AND_WHEN("the same object grows beyond the reserved space, increasing less the size of 2 small objecs")
                {
                    *obj = {0x22222222, 0x33333333, 0x44444444,
                            0x22222222, 0x33333333, 0x44444444};
                    auto res = saveObjectToStorage(obj_id_t(id), obj);
                    CHECK(res == CboxError::OK);

                    auto received = std::make_shared<LongIntVectorObject>();
                    res = loadObjectFromStorage(obj_id_t(id), received);
                    CHECK(res == CboxError::OK);
                    CHECK(*obj == *received);

                    THEN("It is not relocated, but merges with the adjecent disposed block")
                    {
                        auto blockOpt = storage.getExistingObject(id, true);
                        REQUIRE(blockOpt.has_value());
                        CHECK(originalPos == (*blockOpt).header_pos());
                        CHECK((*blockOpt).length() > originalProvisioned);
                    }
                }

                AND_WHEN("the same object grows beyond the reserved space, increasing more than continuous free space")
                {
                    *obj = {
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                    };
                    CHECK(storage.freeSpace().continuous != storage.freeSpace().total); // free space is fragmented
                    auto res = saveObjectToStorage(obj_id_t(id), obj);
                    CHECK(res == CboxError::OK);

                    auto received = std::make_shared<LongIntVectorObject>();
                    res = loadObjectFromStorage(obj_id_t(id), received);
                    CHECK(res == CboxError::OK);
                    CHECK(*obj == *received);

                    THEN("It is relocated")
                    {
                        auto blockOpt = storage.getExistingObject(id, true);
                        REQUIRE(blockOpt.has_value());
                        CHECK(originalPos != (*blockOpt).header_pos());
                    }

                    THEN("Disposed blocks have been merged during a defragmentation")
                    {
                        CHECK(storage.freeSpace().continuous == storage.freeSpace().total);
                    }

                    AND_WHEN("The object shrinks again by over 16 bytes")
                    {
                        *obj = {
                            0x22222222,
                            0x33333333,
                            0x44444444,
                        };
                        CHECK(CboxError::OK == saveObjectToStorage(obj_id_t(id), obj));
                        auto received = std::make_shared<LongIntVectorObject>();

                        THEN("Its size is reduced if needed to create a new object")
                        {
                            auto blockOpt = storage.getExistingObject(id, true);
                            REQUIRE(blockOpt.has_value());
                            CHECK((*blockOpt).length() == 60);
                            uint16_t expectedWrittenLength = 2 + 3 * 4 + 4; // data + flags + type + crc
                            CHECK((*blockOpt).getWrittenLength() == expectedWrittenLength);

                            auto res = saveObjectToStorage(obj_id_t(id + 1), big);
                            CHECK(res == CboxError::OK);

                            auto blockOpt2 = storage.getExistingObject(id, true);
                            REQUIRE(blockOpt2.has_value());
                            CHECK((*blockOpt2).length() == 26);
                            CHECK((*blockOpt2).getWrittenLength() == expectedWrittenLength);

                            auto received = std::make_shared<LongIntVectorObject>();
                            res = loadObjectFromStorage(obj_id_t(id), received);
                            CHECK(res == CboxError::OK);
                            CHECK(*obj == *received);
                        }
                    }
                }
                AND_WHEN("the object grows beyond the available total space, we get an error")
                {
                    auto spaceBefore = storage.freeSpace();
                    auto tooBig = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject{
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                        0x44444444,
                        0x22222222,
                        0x33333333,
                    });
                    auto res = saveObjectToStorage(obj_id_t(id), tooBig);

                    THEN("An error is returned and the original object is unchanged in eeprom")
                    {
                        CHECK(uint8_t(res) == uint8_t(CboxError::INSUFFICIENT_STORAGE));
                        auto received = std::make_shared<LongIntVectorObject>();
                        res = loadObjectFromStorage(obj_id_t(id), received);
                        CHECK(res == CboxError::OK);
                        CHECK(*obj == *received);
                    }

                    THEN("The free space is unchanged")
                    {
                        CHECK(storage.freeSpace().total == spaceBefore.total);
                    }
                }
            }
        }

        AND_WHEN("All the small objects are deleted")
        {
            for (obj_id_t id = 1; id <= 69; id++) {
                if (id % 20 != 0) {
                    bool deleted = storage.disposeObject(id);
                    REQUIRE(deleted);
                }
            }

            THEN("Continuous free space is size of 19 small objects")
            {
                CHECK(storage.freeSpace().continuous == 19 * smallSizeTotal - 3U);
            }

            THEN("Total free space has increased by the size of all small objects combined")
            {
                CHECK(storage.freeSpace().total == 66 * smallSizeTotal);
            }

            AND_WHEN("We create 100 big objects again")
            {
                for (obj_id_t newId = 1000; newId <= 1009; newId++) {
                    auto res = saveObjectToStorage(newId, big);
                    INFO(newId);
                    REQUIRE(res == CboxError::OK);
                }

                THEN("They just fitted in the merged disposed blocks")
                {
                    auto space = storage.freeSpace();
                    CHECK(space.continuous != space.total);
                    CHECK(space.continuous < bigSizeTotal - 3U);
                }

                AND_WHEN("Another big object is created")
                {
                    auto res = saveObjectToStorage(1010, big);
                    REQUIRE(res == CboxError::OK);

                    THEN("Eeprom was defragmented and continuous free space equals free space")
                    {
                        auto space = storage.freeSpace();
                        INFO("Continuous free space after defrag: " << space.continuous);
                        CHECK(space.total == space.continuous);
                    }

                    AND_THEN("All relocated big objects still have the right value")
                    {
                        for (id = 20; id < 70; id = id + 20) {
                            auto received = std::make_shared<LongIntVectorObject>();
                            CHECK(CboxError::OK == loadObjectFromStorage(id, received));
                            CHECK(*received == *big);
                        }
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
            CHECK(storage.freeSpace().total == totalSpace);
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
