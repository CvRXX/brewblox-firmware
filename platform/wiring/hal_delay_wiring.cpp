#include "delay_hal.h"
#include "platforms.h"

#if PLATFORM_ID == PLATFORM_GCC
#include "boost_posix_time_wrap.h"
#include "boost_thread_wrap.h"
#else
#include "concurrent_hal.h"
#endif

void hal_delay_us(uint32_t duration)
{
    HAL_Delay_Microseconds(duration);
}

void hal_delay_ms(uint32_t duration)
{
    HAL_Delay_Milliseconds(duration);
}

void hal_yield()
{

#if PLATFORM_ID == PLATFORM_GCC
    boost::this_thread::yield();
#else
    os_thread_yield();
#endif
}