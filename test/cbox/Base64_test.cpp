#include "TestHelpers.h"
#include "TestObjects.h"
#include "cbox/Base64.h"
#include "cbox/Box.h"
#include <catch.hpp>
#include <string.h>

using namespace cbox;

std::string vstring(const std::vector<uint8_t>& vec)
{
    return std::string(vec.begin(), vec.end());
}

SCENARIO("Base64 encoding/decoding")
{
    WHEN("Encoding ASCII bytes to base64")
    {
        const std::string base = "hello world";
        std::vector<uint8_t> in;
        std::vector<uint8_t> out;

        in.assign(base.begin(), base.begin() + 6);
        base64_encode(in, out); // no remainder
        CHECK(vstring(out) == "aGVsbG8g");
        out.clear();

        in.assign(base.begin(), base.begin() + 10);
        base64_encode(in, out); // 1 remainder byte
        CHECK(vstring(out) == "aGVsbG8gd29ybA==");
        out.clear();

        in.assign(base.begin(), base.begin() + 11);
        base64_encode(in, out); // 2 remainder bytes
        CHECK(vstring(out) == "aGVsbG8gd29ybGQ=");
        out.clear();

        base64_encode({255, 255, 255}, out);
        CHECK(vstring(out) == "////");
        out.clear();

        base64_encode({255, 255, 255, 255}, out);
        CHECK(vstring(out) == "/////w==");
        out.clear();

        base64_encode({255, 255, 255, 255, 255}, out);
        CHECK(vstring(out) == "//////8=");
        out.clear();
    }

    WHEN("Decoding base64 to ASCII bytes")
    {
        std::vector<uint8_t> in;
        std::vector<uint8_t> out;
        std::vector<uint8_t> expected;

        // no remainder bytes
        // in = "aGVsbG8g";
        in = {'a', 'G', 'V', 's', 'b', 'G', '8', 'g'};
        out.clear();
        expected = {'h', 'e', 'l', 'l', 'o', ' '};
        base64_decode(in, out);
        CHECK(out == expected);

        // unneccessary padding character
        // in = "aGVsbG8g=";
        in = {'a', 'G', 'V', 's', 'b', 'G', '8', 'g', '='};
        out.clear();
        expected = {'h', 'e', 'l', 'l', 'o', ' '};
        base64_decode(in, out);
        CHECK(out == expected);

        // 1 remainder byte
        // in = "aGVsbG8gd29ybA==";
        in = {'a', 'G', 'V', 's', 'b', 'G', '8', 'g', 'd', '2', '9', 'y', 'b', 'A', '=', '='};
        out.clear();
        expected = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l'};
        base64_decode(in, out);
        CHECK(out == expected);

        // 2 remainder bytes
        // in = "aGVsbG8gd29ybGQ=";
        in = {'a', 'G', 'V', 's', 'b', 'G', '8', 'g', 'd', '2', '9', 'y', 'b', 'G', 'Q', '='};
        out.clear();
        expected = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
        base64_decode(in, out);
        CHECK(out == expected);

        // no remainder bytes, all bits set
        // in = "////";
        in = {'/', '/', '/', '/'};
        out.clear();
        expected = {0xFF, 0xFF, 0xFF};
        base64_decode(in, out);
        CHECK(out == expected);

        // 1 remainder byte, all bits set
        // in = "/////w==";
        in = {'/', '/', '/', '/', '/', 'w', '=', '='};
        out.clear();
        expected = {0xFF, 0xFF, 0xFF, 0xFF};
        base64_decode(in, out);
        CHECK(out == expected);

        // 2 remainder bytes, all bits set
        // in = "//////8=";
        in = {'/', '/', '/', '/', '/', '/', '8', '='};
        out.clear();
        expected = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
        base64_decode(in, out);
        CHECK(out == expected);
    }
}
