#include "cbox/Base64.hpp"

namespace cbox {

static constexpr char chars[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

constexpr char b64_to_char(uint8_t b)
{
    return chars[b];
}

// ASCII -> byte lookup table
static constexpr int16_t bytes[] = {
    62,                                                 // +
    -1, -1, -1,                                         //
    63,                                                 // /
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61,             // 0-9
    -1, -1, -1, -1, -1, -1, -1,                         //
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,           // A-M
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // n-Z
    -1, -1, -1, -1, -1, -1,                             //
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, // a-M
    39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51  // n-z
};

constexpr int16_t b64_to_byte(uint8_t c) // uint8_t or -1
{
    if (c >= '+' && c <= 'z') {
        return bytes[c - '+'];
    } else {
        return -1;
    }
}

bool is_b64(uint8_t c)
{
    return b64_to_byte(c) != -1;
}

std::string b64_encode(const std::vector<uint8_t>& in)
{
    size_t length = in.size();
    uint8_t groupIdx = 0;
    uint8_t decodedBytes[3];
    std::string out;
    out.reserve(length * 4 / 3 + 2);

    for (auto& inByte : in) {
        decodedBytes[groupIdx] = inByte;
        groupIdx++;

        if (groupIdx == 3) {
            groupIdx = 0;

            out.push_back(b64_to_char((decodedBytes[0] & 0xfc) >> 2));
            out.push_back(b64_to_char(((decodedBytes[0] & 0x03) << 4) + ((decodedBytes[1] & 0xf0) >> 4)));
            out.push_back(b64_to_char(((decodedBytes[1] & 0x0f) << 2) + ((decodedBytes[2] & 0xc0) >> 6)));
            out.push_back(b64_to_char((decodedBytes[2] & 0x3f)));
        }
    }

    // If input length is not a multiple of 3, we should partially encode the last group.
    // Output data should be padded with 1 or 2 '=' characters (length % 3).
    if (groupIdx) {
        // Replace decoded bytes from previous groups with 0
        for (auto i = groupIdx; i < 3; i++) {
            decodedBytes[i] = 0;
        }

        out.push_back(b64_to_char((decodedBytes[0] & 0xfc) >> 2));
        out.push_back(b64_to_char(((decodedBytes[0] & 0x03) << 4) + ((decodedBytes[1] & 0xf0) >> 4)));

        if (groupIdx > 1) {
            out.push_back(b64_to_char(((decodedBytes[1] & 0x0f) << 2) + ((decodedBytes[2] & 0xc0) >> 6)));
        }

        out.insert(out.end(), 3 - groupIdx, '=');
    }

    return out;
}

std::vector<uint8_t> b64_decode(const std::string& in)
{
    size_t length = in.size();
    uint8_t groupIdx = 0;
    uint8_t encodedBytes[4];
    std::vector<uint8_t> out;
    out.reserve(length * 3 / 4 + 2);

    for (auto inByte : in) {
        auto byte = b64_to_byte(inByte);

        if (byte < 0) {
            // Break on invalid characters (includes '\n' and '=').
            // Technically this makes padding optional.
            break;
        }

        encodedBytes[groupIdx] = byte;
        groupIdx++;

        if (groupIdx == 4) {
            groupIdx = 0;

            out.push_back((encodedBytes[0] << 2) + ((encodedBytes[1] & 0x30) >> 4));
            out.push_back(((encodedBytes[1] & 0xf) << 4) + ((encodedBytes[2] & 0x3c) >> 2));
            out.push_back(((encodedBytes[2] & 0x3) << 6) + encodedBytes[3]);
        }
    }

    // If encoded data length is not a multiple of 4 we need to handle the remainder
    if (groupIdx) {
        // Replace encoded bytes from previous groups with 0
        for (auto i = groupIdx; i < 4; i++) {
            encodedBytes[i] = 0;
        }

        out.push_back((encodedBytes[0] << 2) + ((encodedBytes[1] & 0x30) >> 4));

        if (groupIdx > 2) {
            out.push_back(((encodedBytes[1] & 0xf) << 4) + ((encodedBytes[2] & 0x3c) >> 2));
        }
    }

    return out;
}

} // end namespace cbox
