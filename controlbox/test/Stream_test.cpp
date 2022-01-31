#include "DataStream.h"
#include "DataStreamConverters.h"

#include "testinfo.h"
#include <catch.hpp>
#include <string.h>

#include "TestHelpers.h"
#include "TestObjects.h"

using namespace cbox;

SCENARIO("An incoming base64 stream")
{
    WHEN("A stream is empty")
    {
        uint8_t encoded[] = "aGVsbG8gd29ybGQ=";
        uint8_t decoded[100] = "";
        std::string expected = "hello world";

        auto textIn = BufferDataIn(encoded, sizeof(encoded));
        auto in = Base64TextToBinaryIn(textIn);

        CHECK(in.peek() == 'h');
        CHECK(in.peek() == 'h');

        CHECK(in.readBytes(decoded, expected.length() + 1));
        CHECK(std::string((char*)decoded) == expected);
    }
}
