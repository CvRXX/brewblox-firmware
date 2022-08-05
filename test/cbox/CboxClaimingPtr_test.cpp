/*
 * Copyright 2022 BrewPi B.V.
 *
 * This file is part of BrewBlox.
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

#include "cbox/CboxClaimingPtr.hpp"

#include "TestApplication.hpp"
#include "TestObjects.hpp"
#include "cbox/Box.hpp"
#include "cbox/CboxPtr.hpp"
#include <catch.hpp>
#include <optional>

using namespace cbox;

class ClaimableInt final : public cbox::ObjectBase<1007> {
private:
    Claimable claim;
    int val = 0;

public:
    [[nodiscard]] cbox::CboxError read(const cbox::PayloadCallback& callback) const override
    {
        return cbox::CboxError::OK;
    }

    [[nodiscard]] cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override
    {
        return cbox::CboxError::OK;
    }

    cbox::CboxError write(const cbox::Payload& payload) override
    {
        return cbox::CboxError::OK;
    }

    void* implements(cbox::obj_type_t iface) override
    {
        if (iface == staticTypeId()) {
            return this; // me!
        }
        if (iface == interfaceId<Claimable>()) {
            return &claim;
        }
        return nullptr;
    }

    auto value() const
    {
        return val;
    }

    void value(int v)
    {
        val = v;
    }

    auto claimedBy() const
    {
        return claim.claimedBy();
    }
};

class IntAccesser final : public cbox::ObjectBase<1008> {
private:
    // Unprotected ptr can be used by class itself, but is not given to control objects
    CboxPtr<ClaimableInt> _ptr;
    // Claimingptr is given to other objects that need unique access
    CboxClaimingPtr<ClaimableInt> _claimingPtr;
    // To test that disabling an object can release the claim in an update
    bool _enabled = true;
    const int _setTargetTo;
    std::optional<int> _value;
    std::optional<int> _lastApplied;

public:
    IntAccesser(int s)
        : _ptr{}
        , _claimingPtr{_ptr}
        , _setTargetTo(s)
    {
    }

    void setTarget(obj_id_t targetId)
    {
        _claimingPtr.setId(targetId, this->objectId());
    }

    update_t updateHandler(update_t now) override
    {
        if (!_enabled) {
            _claimingPtr.unlock();
        } else if (auto targetPtr = _claimingPtr.lock()) {
            // writabe access
            targetPtr->value(_setTargetTo);
            _lastApplied = _setTargetTo;
            _value = targetPtr->value();
        } else if (auto constTargetPtr = std::as_const(_claimingPtr).lock()) {
            // read only access
            _lastApplied = std::nullopt;
            _value = constTargetPtr->value();
        } else {
            _lastApplied = std::nullopt;
            _value = std::nullopt;
        }
        return now + 1;
    }

    [[nodiscard]] cbox::CboxError read(const cbox::PayloadCallback& callback) const override
    {
        return cbox::CboxError::OK;
    }

    [[nodiscard]] cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override
    {
        return cbox::CboxError::OK;
    }

    cbox::CboxError write(const cbox::Payload& payload) override
    {
        return cbox::CboxError::OK;
    }

    void enable(bool v)
    {
        _enabled = v;
    }

    auto applied() const
    {
        return _lastApplied;
    }
    auto val() const
    {
        return _value;
    }
};

SCENARIO("Test")
{
    auto& objects = getObjects();
    test::getStorage().clear();
    objects.clearAll();
    objects.setObjectsStartId(systemStartId);
    objects.setObjectsStartId(userStartId);
    objects.add(std::shared_ptr<Object>(new ClaimableInt()), 101);
    objects.add(std::shared_ptr<Object>(new IntAccesser(22)), 102);
    objects.add(std::shared_ptr<Object>(new IntAccesser(33)), 103);
    objects.add(std::shared_ptr<Object>(new IntAccesser(44)), 104);

    CboxPtr<ClaimableInt> targetLookup(101);
    CboxPtr<IntAccesser> claimer1Lookup(102);
    CboxPtr<IntAccesser> claimer2Lookup(103);
    CboxPtr<IntAccesser> claimer3Lookup(104);

    auto target = targetLookup.lock();
    auto claimer1 = claimer1Lookup.lock();
    auto claimer2 = claimer2Lookup.lock();
    auto claimer3 = claimer3Lookup.lock();

    WHEN("Two objects try to claim a claimable other object")
    {
        claimer1->setTarget(101);
        claimer2->setTarget(101);
        claimer3->setTarget(200); // nonexisting target

        objects.update(100);

        THEN("First claimer has the claim")
        {
            CHECK(target->claimedBy() == 102);
            AND_THEN("destroying the object releases the claim")
            {
                objects.remove(102);
                CHECK(target->claimedBy() == 102);
                claimer1.reset();
                CHECK(target->claimedBy() == 0);
            }
        }

        THEN("First claimer has set the value")
        {
            CHECK(target->value() == 22);
            CHECK(claimer1->applied().value() == 22);
            CHECK(claimer1->val().value() == 22);
        }

        THEN("The second claimer has not set a value, but can still read what was set by the other claimer")
        {
            CHECK(claimer2->applied().has_value() == false);
            CHECK(claimer2->val().value() == 22);

            AND_WHEN("the first claimer is disabled")
            {
                claimer1->enable(false);

                THEN("The second claimer gets access after an update tick")
                {
                    CHECK(target->claimedBy() == 102);
                    CHECK(target->value() == 22);
                    objects.update(200);
                    CHECK(target->claimedBy() == 103);
                    CHECK(target->value() == 33);
                }
            }
        }

        THEN("The third claimer (nonexisting target) has no values")
        {
            CHECK(claimer3->applied().has_value() == false);
            CHECK(claimer3->val().has_value() == false);
        }
    }
}
