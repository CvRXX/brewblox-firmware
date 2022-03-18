//
//  base64 encoding and decoding with C++.
//  Based on https://github.com/ReneNyffenegger/cpp-base64
//

#pragma once

#include <string>
#include <vector>

bool is_base64(uint8_t c);

void base64_encode(const std::vector<uint8_t>& in, std::vector<uint8_t>& out);

void base64_decode(const std::vector<uint8_t>& in, std::vector<uint8_t>& out);
