//
//  base64 encoding and decoding with C++.
//  Based on https://github.com/ReneNyffenegger/cpp-base64
//

#pragma once

#include <string>
#include <vector>

size_t base64_encode(const std::vector<uint8_t>& in, std::vector<uint8_t>& out);

size_t base64_decode(const std::vector<uint8_t>& in, std::vector<uint8_t>& out);
