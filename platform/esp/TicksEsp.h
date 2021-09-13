/*
 * Copyright 2020 BrewPi B.V./Elco Jacobs.
 *
 * This file is part of Brewblox.
 * 
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "TicksTypes.h"

/*
 * The Ticks class provides the time period since the device was powered up.
 */
class TicksEsp {
public:
    TicksEsp() {}
    ticks_millis_t millis() const;
    ticks_micros_t micros() const;

    utc_seconds_t utc() const;
    void setUtc(const utc_seconds_t& t);

    void delayMillis(const duration_millis_t& millis) const;
};
