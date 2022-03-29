#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace cbox {

bool is_b64(uint8_t c);

std::string b64_encode(const std::vector<uint8_t>& in);

std::vector<uint8_t> b64_decode(const std::string& in);

} // end namespace cbox
