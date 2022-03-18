/*
 * BuzzerClass.cpp
 *
 * Copyright 2015 BrewPi.
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

#include "spark/Buzzer.hpp"
#include "delay_hal.h"
#include "pwm_hal.h"
#include "spark/Board.hpp"

void BuzzerClass::setActive(bool active)
{
    switch (getSparkVersion()) {
    case SparkVersion::V1:
        digitalWriteFast(PIN_ALARM, !active);
        break;
    case SparkVersion::V2:
        digitalWriteFast(PIN_ALARM, active);
        break;
    case SparkVersion::V3:
        hal_pwm_write_with_frequency(PIN_ALARM, active ? 128 : 0, 3000);
        break;
    }
}

void BuzzerClass::beep(uint8_t numBeeps, uint16_t duration)
{
    for (uint8_t beepCount = 0; beepCount < numBeeps; beepCount++) {
        setActive(true);
        HAL_Delay_Milliseconds(duration);
        setActive(false);
        if (beepCount < numBeeps - 1) {
            HAL_Delay_Milliseconds(duration); // not the last beep
        }
    }
}

BuzzerClass&
buzzerRef()
{
    static BuzzerClass buzzer;
    return buzzer;
}
