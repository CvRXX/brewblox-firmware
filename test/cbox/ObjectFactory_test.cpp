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
 * along with BrewPi. If not, see <http://www.gnu.org/licenses/>.
 */

#include "TestObjects.hpp"
#include "cbox/Object.hpp"
#include "cbox/ObjectContainer.hpp"
#include "cbox/ObjectFactory.hpp"
#include "cbox/ObjectStorage.hpp"
#include <catch.hpp>
#include <tuple>

using namespace cbox;

SCENARIO("An object can be created by an ObjectFactory by resolving the type id")
{
    static const auto outOfMemoryTester = []() -> Object* {
        return nullptr;
    };

    ObjectFactory factory = {
        makeFactoryEntry<LongIntObject>(),
        makeFactoryEntry<LongIntVectorObject>(),
        {1234, outOfMemoryTester}};

    const obj_type_t longIntType = LongIntObject::staticTypeId();
    const obj_type_t longIntVectorType = LongIntVectorObject::staticTypeId();

    WHEN("The factory is given a valid type ID, the object with type ID is created")
    {
        auto result1 = factory.make(longIntType);
        CHECK(result1.value()->typeId() == longIntType);

        auto result2 = factory.make(longIntVectorType);
        CHECK(result2.value()->typeId() == longIntVectorType);
    }

    WHEN("The factory is given an invalid type ID, nullptr is returned with status object_not_creatable")
    {
        auto result = factory.make(9999);
        CHECK(result.error() == CboxError::BLOCK_NOT_CREATABLE);
    }

    WHEN("Object creation for a valid object type fails, error INSUFFICIENT_HEAP is returned")
    {
        auto result = factory.make(1234);
        CHECK(result.error() == CboxError::INSUFFICIENT_HEAP);
    }
}
