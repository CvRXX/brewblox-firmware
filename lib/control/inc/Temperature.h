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

#include "FixedPoint.h"
#include <cstdint>
#include <string>

using temp_t = fp12_t;

enum class TempUnit : uint8_t {
    Celsius = 0,
    Fahrenheit = 1,
};

std::string
tempDiff_to_string(const temp_t& t, uint8_t decimals, const TempUnit& unit);

std::string
temp_to_string(const temp_t& t, uint8_t decimals, const TempUnit& unit);