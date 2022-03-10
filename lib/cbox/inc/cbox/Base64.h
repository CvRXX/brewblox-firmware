//
//  base64 encoding and decoding with C++.
//  Based on https://github.com/ReneNyffenegger/cpp-base64
//

#pragma once

#include <string>
#include <vector>

std::string base64_encode(const std::vector<uint8_t>& decoded);
std::string base64_encode(const uint8_t* decoded, size_t length);

std::vector<uint8_t> base64_decode(const std::string& encoded);
std::vector<uint8_t> base64_decode(const std::vector<uint8_t>& encoded);
std::vector<uint8_t> base64_decode(const uint8_t* encoded, size_t length);
