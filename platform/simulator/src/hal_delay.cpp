#include "blox_hal/hal_delay.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

void hal_delay_us(uint32_t micros)
{
    boost::this_thread::sleep(boost::posix_time::microsec(micros));
}

void hal_delay_ms(uint32_t millis)
{
    boost::this_thread::sleep(boost::posix_time::milliseconds(millis));
}

void hal_yield()
{
    boost::this_thread::yield();
}
