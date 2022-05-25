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

#include "control/Pid.hpp"

void Pid::update()
{
    auto input = _inputPtr.lock();
    auto setpoint = in_t{0};
    if (input && input->settingValid() && input->valueValid()) {
        if (enabler.get()) {
            active(true);
        }
        setpoint = input->setting();
        _boilModeActive = setpoint >= in_t{100} + _boilPointAdjust;
        _error = input->error();

        checkFilterLength();
        _derivative = input->readDerivative(_derivativeFilterNr);
    } else {
        if (active()) {
            active(false);
        }
        _integral = 0;
    }
    if (!active()) {
        return;
    }

    // calculate PID parts.

    _p = _kp * _error;

    // limit D +/- kp max to prevent large spikes
    auto derivative_val = fp12_t(_derivative * _td);
    if (derivative_val < fp12_t{-1}) {
        derivative_val = fp12_t{-1};
    } else if (derivative_val > fp12_t{1}) {
        derivative_val = fp12_t{1};
    }
    _d = -_kp * derivative_val;

    decltype(_integral) integral_increase = 0;
    if (_ti != 0 && _kp != 0 && !_boilModeActive) {
        integral_increase = cnl::quotient(_p + _d, _kp);
        _integral += integral_increase;
        _i = _integral * safe_elastic_fixed_point<4, 27>(cnl::quotient(_kp, _ti));
    } else {
        _integral = integral_t{0};
        _i = 0;
    }

    auto pidResult = _p + _i + _d;

    out_t outputValue = pidResult;

    if (_boilModeActive) {
        outputValue = std::max(outputValue, _boilMinOutput);
    }

    // try to set the output to the desired setting
    if (enabler.get()) {
        if (auto output = _outputPtr.lock()) {
            output->settingValid(true);
            output->setting(outputValue);

            if (_boilModeActive) {
                return;
            }

            // get the clipped setting from the actuator for anti-windup
            if (output->settingValid()) {
                auto outputSetting = output->setting();

                if (_ti != 0) { // 0 has been chosen to indicate that the integrator is disabled. This also prevents divide by zero.
                                // update integral with anti-windup back calculation
                                // pidResult - output is zero when actuator is not saturated

                    auto antiWindup = integral_t{0};
                    auto antiWindupValue = outputSetting; // P + I + D, clipped

                    if (_kp != 0) { // prevent divide by zero
                        if (pidResult == outputSetting && output->valueValid()) {
                            // Actuator could be set to desired value, but might not reach set value due to physics or limits in its target actuator
                            // Get the actual achieved value in actuator. This could differ due to slowness time/mutex limits
                            antiWindupValue = output->value();
                        } else {
                            // else: clipped to actuator min or max set in target actuator
                            // calculate anti-windup from setting instead of actual value, so it doesn't dip under the maximum
                            // make sure anti-windup is at least the integral increase when clipping to prevent further windup
                            // Extra anti-windup can still be added below to reduce integral quicker
                            antiWindup += integral_increase;
                        }

                        out_t excess = cnl::quotient(pidResult - antiWindupValue, _kp);
                        antiWindup += int8_t(3) * excess; // anti windup gain is 3
                    }
                    // make sure integral does not cross zero and does not increase by anti-windup
                    integral_t newIntegral = _integral - antiWindup;
                    if (_integral >= integral_t{0}) {
                        _integral = std::clamp(newIntegral, integral_t{0}, _integral);
                    } else {
                        _integral = std::clamp(newIntegral, _integral, integral_t{0});
                    }
                }
            }
        }
    }
}

void Pid::i(const out_t& arg)
{
    _i = arg;
}

void Pid::kp(const in_t& arg)
{
    if (arg != 0) {
        // scale integral history so integral action doesn't change
        _integral = _integral * safe_elastic_fixed_point<15, 15>(cnl::quotient(_kp, arg));
    }
    _kp = arg;
}

void Pid::ti(const uint16_t& arg)
{
    if (_ti != 0) {
        // scale integral history so integral action doesn't change
        _integral = cnl::wrap<integral_t>((int64_t(cnl::unwrap(_integral)) * arg) / _ti);
    }
    _ti = arg;
}

void Pid::td(const uint16_t& arg)
{
    _td = arg;
    _derivativeFilterNr = 0; // trigger automatic filter selection
    checkFilterLength();
}

void Pid::setIntegral(const out_t& newIntegratorPart)
{
    if (_kp == 0) {
        return;
    }
    _integral = _ti * safe_elastic_fixed_point<14, 16>(cnl::quotient(newIntegratorPart, _kp));
}

void Pid::checkFilterLength()
{

    // delay for each filter between input step and max derivative: 8, 34, 85, 188, 492, 1428
    const uint16_t limits[6] = {20, 89, 179, 359, 959, 1799};
    if (!_derivativeFilterNr) {
        if (auto input = _inputPtr.lock()) {
            // selected filter must use an update interval a lot faster than Td to be meaningful
            // The filter delay is roughly 6x the update rate.
            _derivativeFilterNr = 1;
            while (_derivativeFilterNr < 6) {
                if (limits[_derivativeFilterNr - 1] >= _td) {
                    break;
                }
                ++_derivativeFilterNr;
            };
            input->resizeFilterIfNeeded(_derivativeFilterNr);
        }
    }
}
