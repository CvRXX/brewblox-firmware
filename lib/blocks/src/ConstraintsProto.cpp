

#include "cbox/CboxPtr.h"
#include "control/ActuatorAnalogConstrained.h"
#include "control/ActuatorDigitalConstrained.h"
#include "control/Balancer.h"
#include "proto/Constraints.pb.h"

using Minimum = AAConstraints::Minimum<blox_Constraints_AnalogConstraint_min_tag>;
using Maximum = AAConstraints::Maximum<blox_Constraints_AnalogConstraint_max_tag>;

using Balanced_t = AAConstraints::Balanced<blox_Constraints_AnalogConstraint_balanced_tag>;
using Balancer_t = Balancer<blox_Constraints_AnalogConstraint_balanced_tag>;

class CboxBalanced : public AAConstraints::Base {
private:
    // CboxBalanced does not use Balanced_t as base, becaue it needs to initialize the lookup
    // before initializing the Balanced_t
    cbox::CboxPtr<Balancer_t> lookup;
    Balanced_t m_balanced;

public:
    CboxBalanced(cbox::ObjectContainer& objects, const cbox::obj_id_t& objId)
        : lookup(cbox::CboxPtr<Balancer_t>(objects, objId))
        , m_balanced(lookup.lockFunctor())
    {
    }

    cbox::obj_id_t balancerId() const
    {
        return lookup.getId();
    }

    uint8_t requesterId() const
    {
        return m_balanced.requesterId();
    }

    virtual uint8_t id() const override final
    {
        return m_balanced.id();
    }

    virtual AAConstraints::value_t constrain(const AAConstraints::value_t& val) const override final
    {
        return m_balanced.constrain(val);
    }

    AAConstraints::value_t granted() const
    {
        return m_balanced.granted();
    }

    virtual uint8_t order() const override final
    {
        return m_balanced.order();
    }
};

void setAnalogConstraints(const blox_Constraints_AnalogConstraints& msg, ActuatorAnalogConstrained& act, cbox::ObjectContainer& objects)
{
    act.removeAllConstraints();
    pb_size_t numConstraints = std::min(msg.constraints_count, pb_size_t(sizeof(msg.constraints) / sizeof(msg.constraints[0])));
    for (pb_size_t i = 0; i < numConstraints; ++i) {
        blox_Constraints_AnalogConstraint constraintDfn = msg.constraints[i];
        switch (constraintDfn.which_constraint) {
        case blox_Constraints_AnalogConstraint_min_tag:
            act.addConstraint(std::make_unique<Minimum>(
                cnl::wrap<ActuatorAnalog::value_t>(constraintDfn.constraint.min)));
            break;
        case blox_Constraints_AnalogConstraint_max_tag:
            act.addConstraint(std::make_unique<Maximum>(
                cnl::wrap<ActuatorAnalog::value_t>(constraintDfn.constraint.max)));
            break;
        case blox_Constraints_AnalogConstraint_balanced_tag:
            act.addConstraint(std::make_unique<CboxBalanced>(objects, constraintDfn.constraint.balanced.balancerId));
            break;
        }
    }
}

void getAnalogConstraints(blox_Constraints_AnalogConstraints& msg, const ActuatorAnalogConstrained& act)
{
    auto& constraints = act.constraintsList();
    auto it = constraints.cbegin();
    msg.constraints_count = 0;
    pb_size_t numConstraints = pb_size_t(sizeof(msg.constraints) / sizeof(msg.constraints[0]));
    for (pb_size_t i = 0; i < numConstraints; ++i, ++it) {
        if (it == constraints.cend()) {
            break;
        }
        auto constraintId = (*it)->id();
        msg.constraints[i].which_constraint = constraintId;
        switch (constraintId) {
        case blox_Constraints_AnalogConstraint_min_tag: {
            auto obj = reinterpret_cast<Minimum*>((*it).get());
            msg.constraints[i].constraint.min = cnl::unwrap(obj->min());
        } break;
        case blox_Constraints_AnalogConstraint_max_tag: {
            auto obj = reinterpret_cast<Maximum*>((*it).get());
            msg.constraints[i].constraint.max = cnl::unwrap(obj->max());
        } break;
        case blox_Constraints_AnalogConstraint_balanced_tag: {
            auto obj = reinterpret_cast<CboxBalanced*>((*it).get());
            msg.constraints[i].constraint.balanced.id = obj->requesterId();
            msg.constraints[i].constraint.balanced.balancerId = obj->balancerId();
            msg.constraints[i].constraint.balanced.granted = cnl::unwrap(obj->granted());
        } break;
        }
        msg.constraints[i].limiting = act.limiting() & (uint8_t(1) << i);
        msg.constraints_count++;
    }
}

using MinOff = ADConstraints::MinOffTime<blox_Constraints_DigitalConstraint_minOff_tag>;
using MinOn = ADConstraints::MinOnTime<blox_Constraints_DigitalConstraint_minOn_tag>;
using DelayedOn = ADConstraints::DelayedOn<blox_Constraints_DigitalConstraint_delayedOn_tag>;
using DelayedOff = ADConstraints::DelayedOff<blox_Constraints_DigitalConstraint_delayedOff_tag>;
using Mutex_t = ADConstraints::Mutex<blox_Constraints_DigitalConstraint_mutexed_tag>;
using Base_t = ADConstraints::Base;

class CboxMutex : public ADConstraints::Base {
    using State = ActuatorDigitalBase::State;

private:
    cbox::CboxPtr<MutexTarget> lookup;
    Mutex_t m_mutexConstraint;

public:
    CboxMutex(cbox::ObjectContainer& objects, const cbox::obj_id_t& objId, duration_millis_t extraHoldTime, bool customHoldTime)
        : lookup(cbox::CboxPtr<MutexTarget>(objects, objId))
        , m_mutexConstraint(lookup.lockFunctor(), extraHoldTime, customHoldTime)
    {
    }

    virtual uint8_t id() const override final
    {
        return m_mutexConstraint.id();
    }

    cbox::obj_id_t mutexId()
    {
        return lookup.getId();
    }

    virtual duration_millis_t allowedImpl(const State& newState, const ticks_millis_t& now, const ActuatorDigitalChangeLogged& act) override final
    {
        return m_mutexConstraint.allowedImpl(newState, now, act);
    }

    virtual uint8_t order() const override final
    {
        return m_mutexConstraint.order();
    }

    auto holdAfterTurnOff()
    {
        return m_mutexConstraint.holdAfterTurnOff();
    }

    void holdAfterTurnOff(duration_millis_t v)
    {
        m_mutexConstraint.holdAfterTurnOff(v);
    }

    bool useCustomHoldDuration()
    {
        return m_mutexConstraint.useCustomHoldDuration();
    }

    void useCustomHoldDuration(bool v)
    {
        m_mutexConstraint.useCustomHoldDuration(v);
    }

    bool hasLock()
    {
        return m_mutexConstraint.hasLock();
    }
};

void setDigitalConstraints(const blox_Constraints_DigitalConstraints& msg, ActuatorDigitalConstrained& act, cbox::ObjectContainer& objects)
{
    auto oldConstraints = act.removeAllConstraints();
    pb_size_t numConstraints = std::min(msg.constraints_count, pb_size_t(sizeof(msg.constraints) / sizeof(msg.constraints[0])));

    // for mutexes, find existing constraint in old constraints and re-use to avoid losing lock
    auto addMutex = [&oldConstraints, &objects, &act](uint16_t id, duration_millis_t holdTime, bool customHoldTime) {
        auto it = oldConstraints.begin();
        for (; it < oldConstraints.end(); it++) {
            if ((*it)->id() == blox_Constraints_DigitalConstraint_mutexed_tag) {
                auto oldConstraint = reinterpret_cast<CboxMutex*>((*it).get());
                if (oldConstraint->mutexId() == id) {
                    oldConstraint->holdAfterTurnOff(holdTime);
                    oldConstraint->useCustomHoldDuration(customHoldTime);
                    auto newConstraint = std::move(*it);
                    *it = std::make_unique<CboxMutex>(objects, 0, 0, false); // replace with dummy in old vector
                    act.addConstraint(std::move(newConstraint));             // place modified existing mutex back
                    break;
                }
            }
        }
        if (it == oldConstraints.end()) {
            // no matching existing mutex constraint, create new
            act.addConstraint(
                std::make_unique<CboxMutex>(objects, id, holdTime, customHoldTime));
        }
    };

    for (pb_size_t i = 0; i < numConstraints; ++i) {
        blox_Constraints_DigitalConstraint constraintDfn = msg.constraints[i];
        switch (constraintDfn.which_constraint) {
        case blox_Constraints_DigitalConstraint_minOff_tag:
            act.addConstraint(std::make_unique<MinOff>(constraintDfn.constraint.minOff));
            break;
        case blox_Constraints_DigitalConstraint_minOn_tag:
            act.addConstraint(std::make_unique<MinOn>(constraintDfn.constraint.minOn));
            break;
        case blox_Constraints_DigitalConstraint_mutex_tag: // deprecated mutex type, convert to new type
            addMutex(constraintDfn.constraint.mutex, 0, false);
            break;
        case blox_Constraints_DigitalConstraint_mutexed_tag:
            addMutex(constraintDfn.constraint.mutexed.mutexId, constraintDfn.constraint.mutexed.extraHoldTime, constraintDfn.constraint.mutexed.hasCustomHoldTime);
            break;
        case blox_Constraints_DigitalConstraint_delayedOn_tag:
            act.addConstraint(std::make_unique<DelayedOn>(constraintDfn.constraint.delayedOn));
            break;
        case blox_Constraints_DigitalConstraint_delayedOff_tag:
            act.addConstraint(std::make_unique<DelayedOff>(constraintDfn.constraint.delayedOff));
            break;
        }
    }
}

void getDigitalConstraints(blox_Constraints_DigitalConstraints& msg, const ActuatorDigitalConstrained& act)
{
    auto& constraints = act.constraintsList();
    auto it = constraints.cbegin();
    msg.constraints_count = 0;
    pb_size_t numConstraints = sizeof(msg.constraints) / sizeof(msg.constraints[0]);
    for (pb_size_t i = 0; i < numConstraints; ++i, ++it) {
        if (it == constraints.cend()) {
            break;
        }
        auto constraintId = (*it)->id();
        msg.constraints[i].which_constraint = constraintId;
        switch (constraintId) {
        case blox_Constraints_DigitalConstraint_minOff_tag: {
            auto obj = reinterpret_cast<MinOff*>((*it).get());
            msg.constraints[i].constraint.minOff = obj->limit();
        } break;
        case blox_Constraints_DigitalConstraint_minOn_tag: {
            auto obj = reinterpret_cast<MinOn*>((*it).get());
            msg.constraints[i].constraint.minOn = obj->limit();
        } break;
        case blox_Constraints_DigitalConstraint_mutexed_tag: {
            auto obj = reinterpret_cast<CboxMutex*>((*it).get());
            msg.constraints[i].constraint.mutexed.mutexId = obj->mutexId();
            msg.constraints[i].constraint.mutexed.extraHoldTime = obj->holdAfterTurnOff();
            msg.constraints[i].constraint.mutexed.hasCustomHoldTime = obj->useCustomHoldDuration();
            msg.constraints[i].constraint.mutexed.hasLock = obj->hasLock();
        } break;
        case blox_Constraints_DigitalConstraint_delayedOn_tag: {
            auto obj = reinterpret_cast<DelayedOn*>((*it).get());
            msg.constraints[i].constraint.delayedOn = obj->limit();
        } break;
        case blox_Constraints_DigitalConstraint_delayedOff_tag: {
            auto obj = reinterpret_cast<DelayedOff*>((*it).get());
            msg.constraints[i].constraint.delayedOff = obj->limit();
        } break;
        }
        msg.constraints[i].remaining = (*it)->timeRemaining();
        msg.constraints_count++;
    }
}
