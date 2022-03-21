#pragma once

#include <cstdint>
#include <utility>

namespace cbox {

constexpr bool isdigit(char c)
{
    return c >= '0' && c <= '9';
}

constexpr bool isxdigit(char c)
{
    return isdigit(c) || (c >= 'A' && c <= 'F');
}

/**
 * Converts a hex digit to the corresponding binary value.
 */
constexpr uint8_t _h2d(char hex)
{
    if (hex > '9') {
        hex -= 7; // 'A' is 0x41, 'a' is 0x61. -7 =  0x3A, 0x5A
    }
    return uint8_t(hex & 0xf);
}

constexpr uint8_t h2d(char c1, char c2)
{
    return (_h2d(c1) << 4) | _h2d(c2);
}

constexpr char _d2h(uint8_t bin)
{
    return char(bin + (bin > 9 ? 'A' - 10 : '0'));
}

constexpr std::pair<char, char> d2h(uint8_t bin)
{
    return std::make_pair(
        _d2h(uint8_t(bin & 0xF0) >> 4),
        _d2h(uint8_t(bin & 0xF)));
}

}
