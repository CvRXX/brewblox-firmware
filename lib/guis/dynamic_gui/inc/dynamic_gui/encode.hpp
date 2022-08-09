#pragma once
#include "elements/layout/screen.hpp"
#include "proto/Screen.pb.h"
#include "tl/expected.hpp"
#include <pb_encode.h>

namespace gui::dynamic_interface {
namespace detail {
    bool pageEncoder(pb_ostream_t* stream, const pb_field_t* field, void* const* arg);

    bool layoutNodeEncoder(pb_ostream_t* stream, const pb_field_t* field, void* const* arg);

    bool contentNodeEncoder(pb_ostream_t* stream, const pb_field_t* field, void* const* arg);

}
enum class EncodeError : uint8_t {
    success = 0,
    bufferIsNullptr = 1,
    PBError = 2,
};

/**
 * Encodes layoutNodes and contentNodes into a protobuf buffer.
 * @param layoutNodes The layoutNodes to be encoded.
 * @param contentNodes The contentNodes to be encoded.
 * @param buffer The buffer in which the layoutNodes and contentNodes will be encoded.
 * @param bufferSize The size of the buffer.
 * @return An std::expected type containing either the size of the protobuf message written or an error.
 */
tl::expected<size_t, EncodeError> encodeNodes(std::vector<screen_LayoutNode>& layoutNodes, std::vector<screen_ContentNode>& contentNodes, uint8_t* buffer, size_t bufferSize);

/**
 * Encodes a Screen into a protobuf buffer.
 * @param screen The screen to be encoded.
 * @param buffer The buffer in which the screen will be encoded.
 * @param bufferSize The size of the buffer.
 * @return An std::expected type containing either the size of the protobuf message written or an error.
 */
tl::expected<size_t, EncodeError> encodeBuffer(Screen& screen, uint8_t* buffer, size_t bufferSize);
}
