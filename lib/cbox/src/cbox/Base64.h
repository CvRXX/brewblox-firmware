//
//  base64 encoding and decoding with C++.
//  Based on https://github.com/ReneNyffenegger/cpp-base64
//

#pragma once

#include <string>
#include <vector>

std::string base64_encode(uint8_t const* decoded, size_t length);
std::vector<uint8_t> base64_decode(const std::string& encoded);
