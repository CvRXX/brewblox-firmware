#pragma once

#include "blocks/TicksBlock.hpp"
#include "control/MockTicks.hpp"

using TicksClass = Ticks<MockTicks>;
extern TicksClass ticks;
