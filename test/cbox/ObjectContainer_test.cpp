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

#include <catch.hpp>
#include <cstdio>

#include "TestApplication.hpp"
#include "TestHelpers.hpp"
#include "TestMatchers.hpp"
#include "TestObjects.hpp"
#include "cbox/DataStreamConverters.hpp"
#include "cbox/Object.hpp"
#include "cbox/ObjectContainer.hpp"
#include "cbox/ObjectStorage.hpp"

using namespace cbox;

SCENARIO("A container to hold objects")
{
    ObjectContainer container;

    WHEN("Some objects are added to the container")
    {
        obj_id_t id1 = container.add(std::shared_ptr<Object>(new LongIntObject(0x11111111)));
        obj_id_t id2 = container.add(std::shared_ptr<Object>(new LongIntObject(0x22222222)));
        obj_id_t id3 = container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)));

        THEN("They are assigned a valid unique ID")
        {
            CHECK(id1 != invalidId);
            CHECK(id2 != invalidId);
            CHECK(id3 != invalidId);

            CHECK(id1 != id2);
            CHECK(id1 != id3);
            CHECK(id2 != id3);
        }

        THEN("The objects can be fetched from the container")
        {
            auto obj2 = container.fetch(id2).lock();
            REQUIRE(obj2);
            CHECK(obj2->typeId() == LongIntObject::staticTypeId());
            // to be able to compare the value, we first dereference the smart pointer before typecasting
            CHECK(*static_cast<LongIntObject*>(&(*obj2)) == LongIntObject(0x22222222));
        }

        THEN("The objects can be removed from the container")
        {
            container.remove(id2);
            CHECK(!container.fetch(id2).lock()); // id2 now removed
            CHECK(container.fetch(id3).lock());  // id3 still exists
        }

        THEN("An object can be added with a specific id")
        {
            obj_id_t id4 = container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)), obj_id_t(123));
            CHECK(id4 == 123);
            CHECK(container.fetch(id4).lock());

            AND_WHEN("the id already exist, adding fails")
            {
                obj_id_t id5 = container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)), obj_id_t(123));
                CHECK(id5 == invalidId);
            }

            AND_WHEN("replace is used instead of add, it succeeds")
            {
                obj_id_t id6 = container.add(std::shared_ptr<Object>(new LongIntObject(0x44444444)), obj_id_t(123), true);
                CHECK(id6 == obj_id_t(123));
                auto obj6 = container.fetch(id6).lock();
                REQUIRE(obj6);
                CHECK(*static_cast<LongIntObject*>(&(*obj6)) == LongIntObject(0x44444444));
            }
        }

        THEN("Removing an object that doesn't exist returns invalid_object_id")
        {
            CHECK(container.remove(obj_id_t(10)) == CboxError::INVALID_BLOCK_ID);
        }

        THEN("A list of all object IDs can be created using the container's const iterators")
        {
            std::vector<obj_id_t> ids;
            for (auto it = container.cbegin(); it != container.cend(); it++) {
                ids.emplace_back(it->id());
            };
            std::vector<obj_id_t> correct_list = {id1, id2, id3};
            CHECK(ids == correct_list);
        }

        THEN("All contained objects can be streamed out using the container's const_iterators")
        {
            TestCommand cmd;
            CboxError res = CboxError::OK;

            for (auto it = container.cbegin(); it != container.cend() && res == CboxError::OK; it++) {
                res = it->read(cmd.callback);
            }

            CHECK(res == CboxError::OK);
        }
    }

    WHEN("Objects with out of order IDs are added to the container, the container stays sorted by id")
    {
        container.add(std::shared_ptr<Object>(new LongIntObject(0x11111111)), 20);
        container.add(std::shared_ptr<Object>(new LongIntObject(0x22222222)), 18);
        container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)), 23);
        container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)), 2);
        container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)), 19);
        container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)));
        uint16_t lastId = 0;
        uint16_t count = 0;
        for (auto it = container.cbegin(); it != container.cend(); it++) {
            CHECK(it->id() > lastId);
            INFO(it->id());
            lastId = it->id();
            ++count;
        };
        CHECK(count == 6);
        CHECK(lastId == 24); // new randomly assigned ID is always highest ID in the system
    }

    WHEN("Objects with an invalid object pointer are added")
    {
        container.add(std::shared_ptr<Object>(), 20);

        BlackholeDataOut out;
        EmptyDataIn in;
        TestCommand cmd;
        THEN("They generate the INVALID_OBJECT_PTR error on streaming functions")
        {
            auto cobj = container.fetchContained(20);
            auto res = cobj->read(cmd.callback);
            CHECK(res == CboxError::INVALID_BLOCK_ID);
            res = cobj->readStored(cmd.callback);
            CHECK(res == CboxError::INVALID_BLOCK_ID);
            res = cobj->write(cmd.request);
            CHECK(res == CboxError::INVALID_BLOCK_ID);
        }
    }
}

SCENARIO("A container with system objects")
{
    test::getStorage().clear();
    ObjectContainer container{ContainedObject(1, std::shared_ptr<Object>(new LongIntObject(0x11111111))),
                              ContainedObject(2, std::shared_ptr<Object>(new LongIntObject(0x22222222)))};

    container.setObjectsStartId(3); // this locks the system objects

    CHECK(obj_id_t(3) == container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)))); // will get next free ID (3)))
    CHECK(obj_id_t(4) == container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)))); // will get next free ID (4)))

    THEN("The system objects can be read like normal objects")
    {
        TestCommand cmd;
        auto spobj = container.fetch(1).lock();
        REQUIRE(spobj);
        spobj->read(cmd.callback);
        CHECK(hexed(cmd.responses.at(0).content) == "11111111");
    }

    THEN("The system objects can be read written")
    {
        TestCommand cmd(1, 1000, {0x44, 0x33, 0x22, 0x11}); // LSB first

        auto spobj = container.fetch(1).lock();
        REQUIRE(spobj);
        spobj->write(cmd.request);
        CHECK(*static_cast<LongIntObject*>(&(*spobj)) == LongIntObject(0x11223344));
    }

    THEN("The system objects cannot be deleted, but user objects can be deleted")
    {
        CHECK(container.remove(1) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.fetch(1).lock());

        CHECK(container.remove(2) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.fetch(2).lock());

        CHECK(container.fetch(3).lock());
        CHECK(container.remove(3) == CboxError::OK);
        CHECK(!container.fetch(3).lock());
    }

    THEN("No objects can be added in the system ID range")
    {
        container.setObjectsStartId(100);
        CHECK(invalidId == container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)), 99, true));
    }

    THEN("Objects added after construction can also be marked system by moving the start ID")
    {
        container.setObjectsStartId(100); // all objects with id  < 100 will now be system objects

        CHECK(container.remove(1) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.remove(2) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.remove(3) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.remove(4) == CboxError::BLOCK_NOT_DELETABLE);

        CHECK(obj_id_t(100) == container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)))); // will get start ID (100)
    }
}
