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

#include "TestObjects.h"
#include "cbox/FileObjectStorage.h"
#include "cbox/Object.h"
#include "cbox/ObjectStream.h"
#include <algorithm>
#include <catch.hpp>
#include <cstdio>
#include <filesystem>

using namespace cbox;

SCENARIO("Storing and retreiving blocks with file storage")
{
    auto tmpPath = std::filesystem::temp_directory_path() / "cbox-test" / "blocks";
    std::error_code err;
    std::filesystem::create_directories(tmpPath, err);
    REQUIRE(!err);

    FileObjectStorage storage(tmpPath.string());

    // storage doesn't know about the Object class, these functors handle the conversion to streams
    auto retrieveObjectFromStorage = [&storage](const obj_id_t& id, const std::shared_ptr<Object>& target) -> CboxError {
        auto dataHandler = [&target](RegionDataIn& in) -> CboxError {
            return loadFromStream(in, target);
        };
        return storage.retrieveObject(id, dataHandler);
    };

    auto saveObjectToStorage = [&storage](const obj_id_t& id, const std::shared_ptr<Object>& source) -> CboxError {
        auto dataHandler = [&source](DataOut& out) -> CboxError {
            return saveToStream(out, source);
        };
        return storage.storeObject(id, dataHandler);
    };

    WHEN("An object is created")
    {
        auto obj = std::make_shared<LongIntObject>(0x33333333);

        THEN("It is saved to a file")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);

            THEN("Return value is success")
            {
                CHECK(res == CboxError::OK);
            }

            THEN("A file with block ID as file name was created")
            {
                auto file = fopen((tmpPath / "1").c_str(), "r");
                REQUIRE(file);

                AND_THEN(
                    "The file size is 7 bytes "
                    "(2 bytes object id, 4 bytes object data + 1 byte CRC")
                {
                    fseek(file, 0, SEEK_END); // seek to end of file
                    auto size = ftell(file);  // get current file pointer

                    CHECK(size == 7);
                }
            }

            THEN("The data can be streamed back from file")
            {
                auto target = std::make_shared<LongIntObject>(0xFFFFFFFF);
                auto res = retrieveObjectFromStorage(obj_id_t(1), target);
                CHECK(res == CboxError::OK);
                CHECK(obj->value() == target->value());
            }

            THEN("It can be changed and rewritten to file")
            {
                obj->value(0xAAAAAAAA);
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                auto received = std::shared_ptr<LongIntObject>(new LongIntObject((0xFFFFFFFF)));
                res = retrieveObjectFromStorage(obj_id_t(1), received);
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

                THEN("It cannot be retrieved anymore")
                {
                    auto received = std::shared_ptr<LongIntObject>(new LongIntObject((0xFFFFFFFF)));
                    auto res = retrieveObjectFromStorage(obj_id_t(1), received);
                    CHECK(res == CboxError::PERSISTED_OBJECT_NOT_FOUND);
                    CHECK(0xFFFFFFFF == received->value()); // received is unchanged
                }
                THEN("The id can be re-used to store another object")
                {
                    auto otherObject = std::shared_ptr<LongIntObject>(new LongIntObject((0xFFFFFFFF)));
                    auto res = saveObjectToStorage(obj_id_t(1), otherObject);

                    THEN("Return value is success")
                    {
                        CHECK(res == CboxError::OK);
                    }

                    AND_THEN("The id returns the new object's data")
                    {
                        auto received = std::shared_ptr<LongIntObject>(new LongIntObject((0xFFFFFFFF)));
                        auto res = retrieveObjectFromStorage(obj_id_t(1), received);
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
        auto target = std::shared_ptr<LongIntVectorObject>(new LongIntVectorObject());

        THEN("It can be saved to file")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);
            THEN("Return value is success")
            {
                CHECK(res == CboxError::OK);
            }

            THEN("The data can be streamed back from file")
            {
                target = std::make_shared<LongIntVectorObject>();
                auto res = retrieveObjectFromStorage(obj_id_t(1), target);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *target);
            }

            THEN("It can be changed and rewritten to file, same size")
            {
                obj->values = {0x22222222, 0x33333333};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                target = std::make_shared<LongIntVectorObject>();
                res = retrieveObjectFromStorage(obj_id_t(1), target);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *target);
            }

            THEN("It can be changed and rewritten to file, 4 bytes bigger size")
            {
                obj->values = {0x22222222, 0x33333333, 0x44444444};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                target = std::make_shared<LongIntVectorObject>();
                res = retrieveObjectFromStorage(obj_id_t(1), target);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *target);
            }

            THEN("It can be changed and rewritten to file, 16 bytes bigger size")
            {
                obj->values = {0x22222222, 0x33333333, 0x44444444, 0x55555555, 0x66666666, 0x77777777};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                target = std::make_shared<LongIntVectorObject>();
                res = retrieveObjectFromStorage(obj_id_t(1), target);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *target);
            }

            THEN("It can be changed and rewritten to file, 4 bytes smaller size")
            {
                obj->values = {0x22222222};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                target = std::make_shared<LongIntVectorObject>();
                res = retrieveObjectFromStorage(obj_id_t(1), target);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *target);
            }

            THEN("It can be changed and rewritten to file, 8 bytes smaller size (empty vector)")
            {
                obj->values = {};
                auto res = saveObjectToStorage(obj_id_t(1), obj);
                CHECK(res == CboxError::OK);

                target = std::make_shared<LongIntVectorObject>();
                res = retrieveObjectFromStorage(obj_id_t(1), target);
                CHECK(res == CboxError::OK);
                CHECK(*obj == *target);
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
                    target = std::make_shared<LongIntVectorObject>();
                    auto res = retrieveObjectFromStorage(obj_id_t(1), target);
                    CHECK(res == CboxError::PERSISTED_OBJECT_NOT_FOUND);
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
                        auto received = std::make_shared<LongIntObject>(0xAAAAAAAA);
                        auto res = retrieveObjectFromStorage(obj_id_t(1), received);
                        CHECK(res == CboxError::OK);
                        CHECK(uint32_t(0xAAAAAAAA) == received->value());
                    }
                }
            }
        }
    }

    WHEN("Multiple objects are created and saved to file")
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
                CHECK(CboxError::OK == retrieveObjectFromStorage(obj_id_t(1), received));
                CHECK(*obj1 == *received);
                CHECK(CboxError::OK == retrieveObjectFromStorage(obj_id_t(2), received));
                CHECK(*obj2 == *received);
                CHECK(CboxError::OK == retrieveObjectFromStorage(obj_id_t(3), received));
                CHECK(*obj3 == *received);
                auto received2 = std::make_shared<LongIntObject>();
                CHECK(CboxError::OK == retrieveObjectFromStorage(obj_id_t(4), received2));
                CHECK(*obj4 == *received2);
            }

            AND_THEN("They can be updated in EEPROM")
            {
                obj2->values = {0x33333333, 0x33333333};
                CHECK(CboxError::OK == saveObjectToStorage(obj_id_t(2), obj2));
                auto received = std::make_shared<LongIntVectorObject>();
                CHECK(CboxError::OK == retrieveObjectFromStorage(obj_id_t(2), received));
                CHECK(*obj2 == *received);
            }

            AND_THEN("If one is deleted, it doesn't affect the others")
            {
                storage.disposeObject(obj_id_t(2));
                auto received = std::make_shared<LongIntVectorObject>();
                CHECK(CboxError::OK == retrieveObjectFromStorage(obj_id_t(1), received));
                CHECK(obj1 == received);
                CHECK(CboxError::PERSISTED_OBJECT_NOT_FOUND == retrieveObjectFromStorage(obj_id_t(2), received));
                CHECK(CboxError::OK == retrieveObjectFromStorage(obj_id_t(3), received));
                CHECK(obj3 == received);
                auto received2 = std::make_shared<LongIntObject>();
                CHECK(CboxError::OK == retrieveObjectFromStorage(obj_id_t(4), received2));
                CHECK(obj4 == received2);

                AND_THEN("A handler handling all objects does not see the deleted object")
                {
                    std::vector<obj_id_t> ids;
                    auto idCollector = [&ids](const storage_id_t& id, DataIn& objInStorage) -> CboxError {
                        ids.push_back(id);
                        return CboxError::OK;
                    };
                    CHECK(storage.retrieveObjects(idCollector) == CboxError::OK);
                    std::sort(ids.begin(), ids.end()); // sort ids because the files are loaded in random order
                    CHECK(ids == std::vector<obj_id_t>({1, 3, 4}));
                }
            }

            AND_THEN("When a storage stream error occurs when handling a block, the block is skipped")
            {
                std::vector<obj_id_t> ids;
                auto errorOn3 = [&ids](const storage_id_t& id, DataIn& objInStorage) -> CboxError {
                    if (id == 3) {
                        return CboxError::PERSISTED_BLOCK_STREAM_ERROR;
                    }
                    ids.push_back(id);
                    return CboxError::OK;
                };

                CHECK(storage.retrieveObjects(errorOn3) == CboxError::OK);
                // files are not processed in order
                // sort the ids first
                std::sort(ids.begin(), ids.end(), [](const obj_id_t& a, const obj_id_t& b) { return (a < b); });
                CHECK(ids == std::vector<obj_id_t>({1, 2, 4}));
            }
        }
    }

    WHEN("An object is stored with id 0")
    {
        auto obj = std::make_shared<LongIntObject>(0x33333333);

        auto res = saveObjectToStorage(obj_id_t(0), obj);

        THEN("an error is returned")
        {
            CHECK(res == CboxError::INVALID_OBJECT_ID);
        }
    }

    WHEN("An error occurs when an object is persisted")
    {
        auto obj = std::make_shared<MockStreamObject>();

        WHEN("The error occurs during test serialization, the error raised is returned")
        {
            obj->readPersistedFunc = [](Command& cmd) { return CboxError::OUTPUT_STREAM_WRITE_ERROR; };
            auto res = saveObjectToStorage(obj_id_t(1234), obj);
            CHECK(res == CboxError::OUTPUT_STREAM_WRITE_ERROR);

            obj->readPersistedFunc = [](Command& cmd) { return CboxError::OUTPUT_STREAM_ENCODING_ERROR; };
            res = saveObjectToStorage(obj_id_t(1234), obj);
            CHECK(res == CboxError::OUTPUT_STREAM_ENCODING_ERROR);
        }
    }

    WHEN("An object indicates it does not need persistence")
    {
        storage.clear();
        auto obj = std::make_shared<MockStreamObject>();
        obj->readPersistedFunc = [](Command& cmd) {
            return CboxError::PERSISTING_NOT_NEEDED;
        };

        THEN("The file is not created")
        {
            auto res = saveObjectToStorage(obj_id_t(1), obj);
            CHECK(res == CboxError::OK);

            CHECK(CboxError::PERSISTED_OBJECT_NOT_FOUND == retrieveObjectFromStorage(1, obj));

            CHECK(fopen((tmpPath / "1").c_str(), "r") == nullptr);
        }
    }
}
