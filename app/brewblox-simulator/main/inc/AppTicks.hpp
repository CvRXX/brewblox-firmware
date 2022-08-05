#pragma once

#include "control/MockTicks.hpp"
#include "control/Ticks.hpp"

using TicksClass = Ticks<MockTicks>;

extern TicksClass ticks;
