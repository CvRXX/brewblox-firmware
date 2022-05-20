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
#include "cbox/Object.hpp"
#include "cbox/ObjectContainer.hpp"
#include "cbox/ObjectStorage.hpp"

using namespace cbox;

SCENARIO("A container to hold objects")
{
    ObjectContainer container;

    WHEN("Some objects are added to the container")
    {
        auto add1 = std::shared_ptr<Object>(new LongIntObject(0x11111111));
        auto add2 = std::shared_ptr<Object>(new LongIntObject(0x22222222));
        auto add3 = std::shared_ptr<Object>(new LongIntObject(0x33333333));

        CHECK(container.add(add1) == CboxError::OK);
        CHECK(container.add(add2) == CboxError::OK);
        CHECK(container.add(add3) == CboxError::OK);

        obj_id_t id1 = add1->objectId();
        obj_id_t id2 = add2->objectId();
        obj_id_t id3 = add3->objectId();

        THEN("They are assigned a valid unique ID")
        {
            CHECK(id1 != id2);
            CHECK(id1 != id3);
            CHECK(id2 != id3);
        }

        THEN("The objects can be fetched from the container")
        {
            auto fetched2 = container.fetch(id2);
            REQUIRE(fetched2);
            CHECK(fetched2.value()->typeId() == LongIntObject::staticTypeId());
            // to be able to compare the value, we first dereference the smart pointer before typecasting
            CHECK(*static_cast<LongIntObject*>(fetched2.value().get()) == LongIntObject(0x22222222));
        }

        THEN("The objects can be removed from the container")
        {
            container.remove(id2);
            CHECK(!container.fetch(id2)); // id2 now removed
            CHECK(container.fetch(id3));  // id3 still exists
        }

        THEN("An object can be added with a specific id")
        {
            auto add4 = std::shared_ptr<Object>(new LongIntObject(0x33333333));
            CHECK(container.add(add4, 123) == CboxError::OK);
            obj_id_t id4 = add4->objectId();
            CHECK(container.fetch(id4));

            AND_WHEN("the id already exist, adding fails")
            {
                CHECK(container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)), 123) == CboxError::INVALID_BLOCK_ID);
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
                ids.emplace_back((*it)->objectId());
            };
            std::vector<obj_id_t> correct_list = {id1, id2, id3};
            CHECK(ids == correct_list);
        }

        THEN("All contained objects can be streamed out using the container's const_iterators")
        {
            TestCommand cmd;
            CboxError res = CboxError::OK;

            for (auto it = container.cbegin(); it != container.cend() && res == CboxError::OK; it++) {
                res = (*it)->read(cmd.callback);
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
            CHECK((*it)->objectId() > lastId);
            lastId = (*it)->objectId();
            ++count;
        };
        CHECK(count == 6);
        CHECK(lastId == 24); // new randomly assigned ID is always highest ID in the system
    }

    WHEN("Objects with an invalid object pointer are added")
    {
        CHECK(container.add(std::shared_ptr<Object>(), 20) == CboxError::INVALID_BLOCK);
    }
}

SCENARIO("A container with system objects")
{
    test::getStorage().clear();
    ObjectContainer container;

    container.setObjectsStartId(1);
    container.add(std::shared_ptr<Object>(new LongIntObject(0x11111111)), 1);
    container.add(std::shared_ptr<Object>(new LongIntObject(0x22222222)), 2);
    container.setObjectsStartId(3); // this locks the system objects

    auto obj3 = std::shared_ptr<Object>(new LongIntObject(0x33333333));
    auto obj4 = std::shared_ptr<Object>(new LongIntObject(0x33333333));

    CHECK(container.add(obj3) == CboxError::OK);
    CHECK(container.add(obj4) == CboxError::OK);

    CHECK(obj3->objectId() == 3); // will get next free ID (3)))
    CHECK(obj4->objectId() == 4); // will get next free ID (4)))

    THEN("The system objects can be read like normal objects")
    {
        TestCommand cmd;
        auto fetched = container.fetch(1);
        REQUIRE(fetched);
        CHECK(fetched.value()->read(cmd.callback) == CboxError::OK);
        CHECK(hexed(cmd.responses.at(0).content) == "11111111");
    }

    THEN("The system objects can be read written")
    {
        TestCommand cmd(1, 1000, {0x44, 0x33, 0x22, 0x11}); // LSB first

        auto fetched = container.fetch(1);
        REQUIRE(fetched);
        CHECK(fetched.value()->write(cmd.request) == CboxError::OK);
        CHECK(*static_cast<LongIntObject*>(fetched.value().get()) == LongIntObject(0x11223344));
    }

    THEN("The system objects cannot be deleted, but user objects can be deleted")
    {
        CHECK(container.remove(1) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.fetch(1));

        CHECK(container.remove(2) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.fetch(2));

        CHECK(container.fetch(3));
        CHECK(container.remove(3) == CboxError::OK);
        CHECK(!container.fetch(3));
    }

    THEN("No objects can be added in the system ID range")
    {
        container.setObjectsStartId(userStartId);
        CHECK(container.add(std::shared_ptr<Object>(new LongIntObject(0x33333333)), 99) == CboxError::INVALID_BLOCK_ID);
    }

    THEN("Objects added after construction can also be marked system by moving the start ID")
    {
        container.setObjectsStartId(userStartId); // all objects with id  < 100 will now be system objects

        CHECK(container.remove(1) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.remove(2) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.remove(3) == CboxError::BLOCK_NOT_DELETABLE);
        CHECK(container.remove(4) == CboxError::BLOCK_NOT_DELETABLE);

        auto added = std::shared_ptr<Object>(new LongIntObject(0x33333333));
        CHECK(container.add(added) == CboxError::OK);
        CHECK(added->objectId() == userStartId); // will get start ID (100)
    }
}
