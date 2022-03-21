#include "TestHelpers.hpp"
#include "TestObjects.hpp"
#include "cbox/Base64.hpp"
#include "cbox/Box.hpp"
#include <catch.hpp>
#include <string.h>

using namespace cbox;

SCENARIO("Base64 encoding/decoding")
{
    WHEN("Encoding ASCII bytes to base64")
    {
        const std::string base = "hello world";
        std::vector<uint8_t> in;

        in.assign(base.begin(), base.begin() + 6);
        CHECK(b64_encode(in) == "aGVsbG8g"); // no remainder

        in.assign(base.begin(), base.begin() + 10);
        CHECK(b64_encode(in) == "aGVsbG8gd29ybA=="); // 1 remainder byte

        in.assign(base.begin(), base.begin() + 11);
        CHECK(b64_encode(in) == "aGVsbG8gd29ybGQ="); // 2 remainder bytes

        CHECK(b64_encode({255, 255, 255}) == "////");
        CHECK(b64_encode({255, 255, 255, 255}) == "/////w==");
        CHECK(b64_encode({255, 255, 255, 255, 255}) == "//////8=");
    }

    WHEN("Decoding base64 to ASCII bytes")
    {
        std::vector<uint8_t> expected;

        // no remainder bytes
        expected = {'h', 'e', 'l', 'l', 'o', ' '};
        CHECK(b64_decode("aGVsbG8g") == expected);

        // unneccessary padding character
        expected = {'h', 'e', 'l', 'l', 'o', ' '};
        CHECK(b64_decode("aGVsbG8g=") == expected);

        // 1 remainder byte
        expected = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l'};
        CHECK(b64_decode("aGVsbG8gd29ybA==") == expected);

        // 2 remainder bytes
        expected = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
        CHECK(b64_decode("aGVsbG8gd29ybGQ=") == expected);

        // no remainder bytes, all bits set
        expected = {0xFF, 0xFF, 0xFF};
        CHECK(b64_decode("////") == expected);

        // 1 remainder byte, all bits set
        expected = {0xFF, 0xFF, 0xFF, 0xFF};
        CHECK(b64_decode("/////w==") == expected);

        // 2 remainder bytes, all bits set
        expected = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
        CHECK(b64_decode("//////8=") == expected);
    }
}
