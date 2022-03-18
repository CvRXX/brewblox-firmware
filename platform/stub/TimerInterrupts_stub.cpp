#include "control/TimerInterrupts.hpp"
#include <functional>

void TimerInterrupts::init()
{
}

int16_t TimerInterrupts::add(std::function<void()>&& /*func*/)
{
    return 0;
}

void TimerInterrupts::remove(uint8_t /*id*/)
{
}
