#pragma once

#include "blocks/TicksBlock.hpp"
#include "control/MockTicks.h"

using TicksClass = Ticks<MockTicks>;

extern TicksClass ticks;
