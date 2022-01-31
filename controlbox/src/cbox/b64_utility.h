#pragma once

#include <string>

namespace cbox {

static const std::string base64chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

inline bool
isbase64(int16_t c)
{
    return (isalnum(c) || (c == '+') || (c == '/') || (c == '='));
}

}