#pragma once

#include "blocks/TicksBlock.h"
#include "control/MockTicks.h"

using TicksClass = Ticks<MockTicks>;
extern TicksClass ticks;
