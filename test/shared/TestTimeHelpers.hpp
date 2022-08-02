#pragma once

#include "AppTicks.hpp"
#include "cbox/Application.hpp"
#include "cbox/Box.hpp"
#include "control/TicksTypes.hpp"

namespace test {

inline void resetTime(utc_seconds_t utc, ticks_millis_t now)
{
    auto& ticksImpl = ticks.ticksImpl();
    ticksImpl.reset(now);
    ticksImpl.setUtc(utc);
}

inline void update(ticks_millis_t now)
{
    ticks.ticksImpl().reset(now);
    cbox::update(now);
}

} // end namespace test
