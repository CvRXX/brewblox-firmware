/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of the BrewBlox Control Library.
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

#pragma once

#include "control/ActuatorAnalog.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "control/ControlPtr.hpp"
#include <functional>
#include <vector>

namespace AAConstraints {
template <uint8_t ID>
class Balanced;
}

class BalancerImpl {
public:
    using value_t = ActuatorAnalog::value_t;
    BalancerImpl() = default;
    virtual ~BalancerImpl() = default;

    struct Request {
        uint8_t id;
        value_t requested;
        value_t granted;
    };

    const value_t available = 100;

    std::vector<Request> requesters;

    uint8_t registerEntry();

    void unregisterEntry(const uint8_t& requester_id);

    value_t constrain(uint8_t& requester_id, const value_t& val);

    value_t granted(const uint8_t& requester_id) const;

    void update();

    const std::vector<Request>& clients() const
    {
        return requesters;
    }
};

template <uint8_t ID>
class Balancer : public BalancerImpl {
private:
    using Balanced = AAConstraints::Balanced<ID>;

public:
    Balancer() = default;
    virtual ~Balancer() = default;
};

namespace AAConstraints {

template <uint8_t ID>
class Balanced : public Base {
private:
    ControlPtr<Balancer<ID>>& m_balancer;
    mutable uint8_t m_req_id; // can be updated by balancer in request

public:
    explicit Balanced(
        ControlPtr<Balancer<ID>>& balancer)
        : m_balancer(balancer)
    {
        if (auto balancerPtr = m_balancer.lock()) {
            m_req_id = balancerPtr->registerEntry();
        }
    }

    Balanced(const Balanced&) = delete;
    Balanced& operator=(const Balanced&) = delete;

    virtual ~Balanced()
    {
        if (auto balancerPtr = m_balancer.lock()) {
            balancerPtr->unregisterEntry(m_req_id);
        }
    }

    value_t constrain(const value_t& val) const final
    {
        if (auto balancerPtr = m_balancer.lock()) {
            return balancerPtr->constrain(m_req_id, val);
        }
        return val;
    }

    uint8_t id() const final
    {
        return ID;
    }

    uint8_t requesterId() const
    {
        return m_req_id;
    }

    value_t granted() const
    {
        if (auto balancerPtr = m_balancer.lock()) {
            return balancerPtr->granted(m_req_id);
        }
        return 0;
    }
    uint8_t order() const final
    {
        return 2;
    }
};
}
