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

#include "cbox/CboxPtr.hpp"

#include "TestApplication.hpp"
#include "TestObjects.hpp"
#include "cbox/Box.hpp"
#include "cbox/CboxPtr.hpp"
#include <catch.hpp>

using namespace cbox;

SCENARIO("A CboxPtr is a dynamic lookup that checks type compatibility and works similar to a weak pointer")
{
    auto& objects = getObjects();
    test::getStorage().clear();
    objects.clearAll();
    objects.setObjectsStartId(systemStartId);
    objects.add(std::shared_ptr<Object>(new LongIntObject(0x11111111)), 1);
    objects.add(std::shared_ptr<Object>(new LongIntObject(0x11111111)), 2);
    objects.setObjectsStartId(userStartId);

    CboxPtr<LongIntObject> liPtr;
    CboxPtr<LongIntVectorObject> livPtr;

    WHEN("lock() is called on a CboxPtr that does not have a valid ID, it returns an empty shared pointer")
    {
        CHECK(!liPtr.lock());
        CHECK(!livPtr.lock());
    }

    WHEN("lock() is called on a CboxPtr that does not implement the requested type, it returns an empty shared pointer")
    {
        liPtr.setId(1);
        livPtr.setId(1);

        CHECK(liPtr.lock());
        CHECK(!livPtr.lock());

        CboxPtr<Nameable> nameablePtr;
        nameablePtr.setId(1);
        CHECK(!nameablePtr.lock());
    }

    WHEN("a CboxPtr of certain type is created, it can point to objects implementing that interface")
    {
        objects.remove(100);
        CHECK(objects.add(std::shared_ptr<Object>(new NameableLongIntObject(0x22222222)), 100) == CboxError::OK);

        CboxPtr<NameableLongIntObject> nameableLiPtr;
        CboxPtr<LongIntObject> liPtr;
        CboxPtr<Nameable> nameablePtr;

        nameableLiPtr.setId(100);
        liPtr.setId(100);
        nameablePtr.setId(100);

        REQUIRE(nameableLiPtr.lock());
        REQUIRE(liPtr.lock());
        REQUIRE(nameablePtr.lock());

        if (auto ptr = nameablePtr.lock()) {
            ptr->setName("Test!");
            CHECK(ptr->getName() == "Test!");
        }

        THEN("The use count is correct on all shared pointers")
        {
            {
                auto ptr1 = nameableLiPtr.lock();
                auto ptr2 = liPtr.lock();
                auto ptr3 = nameablePtr.lock();

                CHECK(ptr1.use_count() == 4); // 4 pointers in use(1 in the container)

                AND_THEN("The addresses match what static cast from most derived class would generate")
                {
                    // pointer 1 and 2 point to the same memory location, because they share a base
                    CHECK(ptr1.get() == ptr2.get());

                    // pointer 3 points to a different location in the same object, that implements the Nameable interface
                    CHECK(reinterpret_cast<void*>(ptr2.get()) != reinterpret_cast<void*>(ptr3.get()));

                    // The offset it got matches static cast
                    CHECK(static_cast<Nameable*>(ptr1.get()) == ptr3.get());
                }

                THEN("If an object is removed, the pointers are still valid, because they share ownership")
                {
                    objects.remove(100);
                    CHECK(ptr1.use_count() == 3); // objects doesn't share ownership anymore
                }
            }

            THEN("After all shared pointers go out of scope, we cannot get a new shared pointer from the CboxPtr class")
            {
                objects.remove(100);
                auto ptr4 = nameablePtr.lock();
                CHECK(!ptr4);

                objects.add(std::shared_ptr<Object>(new NameableLongIntObject(0x22222222)), 100);
                THEN("If a new compatible object is created with the same id, the CboxPtr can be locked again")
                {
                    auto ptr5 = nameablePtr.lock();
                    CHECK(ptr5);
                }
            }
        }

        THEN("A Cbox Ptr can be locked as a different type if it supports the interface")
        {
            auto ptr = liPtr.lock_as<Nameable>();
            CHECK(ptr != nullptr);

            // The offset it got matches static cast
            CHECK(static_cast<Nameable*>(nameableLiPtr.lock().get()) == ptr.get());

            auto const_ptr = liPtr.lock_as<Nameable>();
            CHECK(const_ptr != nullptr);

            // The offset it got matches static cast
            CHECK(static_cast<const Nameable*>(nameableLiPtr.lock().get()) == const_ptr.get());

            AND_THEN("A Cbox Ptr cannot be locked as a different type if it doesn't support the interface")
            {
                auto ptr = liPtr.lock_as<LongIntVectorObject>();
                CHECK(ptr == nullptr);
            }
        }

        THEN("A CboxPtr can persist its object to storage")
        {
            CHECK(liPtr.store() == CboxError::OK);

            AND_THEN("The object can be reloaded from storage")
            {
                if (auto ptr = liPtr.lock()) {
                    ptr->value(1); // change object without storing
                }
                auto res = objects.reloadStored(100);
                CHECK(res == CboxError::OK);
                if (auto ptr = liPtr.lock()) {
                    CHECK(uint32_t(*ptr) == uint32_t{0x22222222});
                }
            }
        }
    }
}
