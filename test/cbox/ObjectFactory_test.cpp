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
#include "cbox/Object.h"
#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "cbox/ObjectStorage.h"
#include <catch.hpp>
#include <tuple>

using namespace cbox;

SCENARIO("An object can be created by an ObjectFactory by resolving the type id")
{
    static const auto outOfMemoryTester = []() {
        return std::shared_ptr<Object>{}; // return nullptr
    };

    ObjectFactory factory = {
        makeFactoryEntry<LongIntObject>(),
        makeFactoryEntry<LongIntVectorObject>(),
        {1234, outOfMemoryTester}};

    const obj_type_t longIntType = LongIntObject::staticTypeId();
    const obj_type_t longIntVectorType = LongIntVectorObject::staticTypeId();

    WHEN("The factory is given a valid type ID, the object with type ID is created")
    {
        std::shared_ptr<Object> obj1;
        CboxError status1;
        std::tie(status1, obj1) = factory.make(longIntType);
        CHECK(status1 == CboxError::OK);
        CHECK(obj1->typeId() == longIntType);

        CboxError status2;
        std::shared_ptr<Object> obj2;
        std::tie(status2, obj2) = factory.make(longIntVectorType);

        CHECK(status2 == CboxError::OK);
        CHECK(obj2->typeId() == longIntVectorType);
    }

    WHEN("The factory is given an invalid type ID, nullptr is returned with status object_not_creatable")
    {
        std::shared_ptr<Object> obj;
        CboxError status;
        std::tie(status, obj) = factory.make(9999);
        CHECK(status == CboxError::OBJECT_NOT_CREATABLE);
        CHECK(obj == nullptr);
    }

    WHEN("Object creation for a valid object type fails, error INSUFFICIENT_HEAP is returned")
    {
        std::shared_ptr<Object> obj;
        CboxError status;
        std::tie(status, obj) = factory.make(1234);
        CHECK(status == CboxError::INSUFFICIENT_HEAP);
        CHECK(obj == nullptr);
    }
}
