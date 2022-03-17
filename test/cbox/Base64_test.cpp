#include "cbox/Base64.h"

#include "testinfo.h"
#include <catch.hpp>
#include <string.h>

#include "TestHelpers.h"
#include "TestObjects.h"

using namespace cbox;

SCENARIO("Base64 encoding/decoding")
{
    WHEN("Encoding ASCII bytes to base64")
    {
        const uint8_t buffer[] = "hello world";
        CHECK(base64_encode(buffer, 6) == "aGVsbG8g");          // no remainder
        CHECK(base64_encode(buffer, 10) == "aGVsbG8gd29ybA=="); // 1 remainder byte
        CHECK(base64_encode(buffer, 11) == "aGVsbG8gd29ybGQ="); // 2 remainder bytes
    }

    WHEN("Decoding base64 to ASCII bytes")
    {
        std::vector<uint8_t> decoded;

        // no remainder bytes
        decoded = {'h', 'e', 'l', 'l', 'o', ' '};
        CHECK(base64_decode("aGVsbG8g") == decoded);

        // 1 remainder byte
        decoded = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l'};
        CHECK(base64_decode("aGVsbG8gd29ybA==") == decoded);

        // 2 remainder bytes
        decoded = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
        CHECK(base64_decode("aGVsbG8gd29ybGQ=") == decoded);
    }
}
