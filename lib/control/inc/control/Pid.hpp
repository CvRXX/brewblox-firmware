/*
 * Copyright 2015 BrewPi / Elco Jacobs
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

#pragma once

#include "control/ActuatorAnalogConstrained.hpp"
#include "control/ControlPtr.hpp"
#include "control/Enabler.hpp"
#include "control/ProcessValue.hpp"
#include "control/SetpointSensorPair.hpp"
#include <cstring>
#include <functional>

class Pid {
public:
    using in_t = fp12_t;
    using out_t = fp12_t;
    using integral_t = safe_elastic_fixed_point<18, 12>;
    using derivative_t = SetpointSensorPair::derivative_t;

private:
    ControlPtr<SetpointSensorPair>& _inputPtr;
    ControlPtr<ProcessValue<Pid::out_t>>& _outputPtr;

    // state
    in_t _error = in_t{0};
    out_t _p = out_t{0};
    out_t _i = out_t{0};
    out_t _d = out_t{0};
    integral_t _integral = integral_t{0};
    derivative_t _derivative = derivative_t{0};
    uint8_t _derivativeFilterNr = 0;

    // settings
    in_t _kp = in_t{0};   // proportional gain
    uint16_t _ti = 0;     // integral time constant
    uint16_t _td = 0;     // derivative time constant
    bool _active = false; // automatically set when input is invalid

    in_t _boilPointAdjust = in_t{0}; // offset from 100C for lower limit to activate boil mode

    out_t _boilMinOutput = out_t{0}; // minimum output when boiling (to control boil intensity)

    bool _boilModeActive = false;

public:
    Enabler enabler;

    explicit Pid(
        ControlPtr<SetpointSensorPair>& input,
        ControlPtr<ProcessValue<Pid::out_t>>& output)
        : _inputPtr(input)
        , _outputPtr(output)
        , enabler(false, [this](bool arg) {active(arg); return arg; })
    {
    }

    Pid(const Pid&) = delete;
    Pid& operator=(const Pid&) = delete;

    ~Pid() = default;

    void init();

    void update();

    // state
    auto error() const
    {
        return _error;
    }

    integral_t integral() const
    {
        return _integral;
    }

    auto derivative() const
    {
        return _derivative;
    }

    auto p() const
    {
        return _p;
    }

    auto i() const
    {
        return _i;
    }

    void i(const out_t& arg);

    auto d() const
    {
        return _d;
    }

    // settings
    auto kp() const
    {
        return _kp;
    }

    void kp(const in_t& arg);

    auto ti() const
    {
        return _ti;
    }

    void ti(const uint16_t& arg);

    auto td() const
    {
        return _td;
    }

    void td(const uint16_t& arg);

    auto active() const
    {
        return _active;
    }

    void setIntegral(const out_t& newIntegratorPart);

    bool boilModeActive() const
    {
        return _boilModeActive;
    }

    in_t boilPointAdjust() const
    {
        return _boilPointAdjust;
    }

    void boilPointAdjust(const in_t& v)
    {
        _boilPointAdjust = v;
    }

    out_t boilMinOutput() const
    {
        return _boilMinOutput;
    }

    void boilMinOutput(const out_t& v)
    {
        _boilMinOutput = v;
    }

    uint8_t derivativeFilterNr() const
    {
        return _derivativeFilterNr;
    }

private:
    void active(bool state)
    {
        if (enabler.get() && _active && !state) {
            if (auto ptr = _outputPtr.lock()) {
                ptr->setting(0);
                ptr->settingValid(false);
            }
        }
        _active = state;
    }
    void checkFilterLength();
};
