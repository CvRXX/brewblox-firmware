/*
 * Copyright 2018 BrewPi B.V.
 *
 * This file is part of Brewblox.
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

// control/Ticks.h includes a forward declaration of 'TicksClass'
// Various time-related blocks include 'AppTicks.h',
// and expect it to define the forward declared TicksClass,
// for use in TicksBlock<TicksClass>

#pragma once

#include "blocks/TicksBlock.hpp"

#if defined(SPARK)
#include "spark/TicksWiring.hpp"
using TicksClass = Ticks<platform::particle::TicksWiring>;
#else
#include <control/MockTicks.h>
using TicksClass = Ticks<MockTicks>;
#endif

extern TicksClass ticks;
