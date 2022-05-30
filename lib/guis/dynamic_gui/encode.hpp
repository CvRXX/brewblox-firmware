#pragma once
#include "elements/layout/screen.hpp"
#include "proto/ScreenConfig.pb.h"
#include "tl/expected.hpp"
#include <pb_encode.h>

namespace gui::dynamic_interface {
namespace detail {
    auto layoutNodeEncoder = [](pb_ostream_t* stream, const pb_field_t* field, void* const* arg) -> bool {
        for (auto node : *reinterpret_cast<std::vector<ScreenConfig_LayoutNode>*>(*arg)) {
            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            }

            if (!pb_encode_submessage(stream, ScreenConfig_LayoutNode_fields, &node)) {
                return false;
            }
        }
        return true;
    };

    auto contentNodeEncoder = [](pb_ostream_t* stream, const pb_field_t* field, void* const* arg) -> bool {
        for (auto node : *reinterpret_cast<std::vector<ScreenConfig_ContentNode>*>(*arg)) {
            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            }

            if (!pb_encode_submessage(stream, ScreenConfig_ContentNode_fields, &node)) {
                return false;
            }
        }
        return true;
    };
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
tl::expected<size_t, EncodeError> encodeNodes(std::vector<ScreenConfig_LayoutNode>& layoutNodes, std::vector<ScreenConfig_ContentNode>& contentNodes, uint8_t* buffer, size_t bufferSize)
{
    if (!buffer) {
        return tl::unexpected{EncodeError::bufferIsNullptr};
    }

    pb_ostream_t stream = pb_ostream_from_buffer(buffer, bufferSize);

    ScreenConfig_ScreenConfig protoMessage = ScreenConfig_ScreenConfig_init_default;

    protoMessage.layoutNodes.funcs.encode = detail::layoutNodeEncoder;
    protoMessage.layoutNodes.arg = reinterpret_cast<void*>(&layoutNodes);

    protoMessage.contentNodes.funcs.encode = detail::contentNodeEncoder;
    protoMessage.contentNodes.arg = reinterpret_cast<void*>(&contentNodes);

    if (!pb_encode(&stream, ScreenConfig_ScreenConfig_fields, &protoMessage)) {
        return tl::unexpected{EncodeError::PBError};
    }

    return stream.bytes_written;
}

/**
 * Encodes a Screen into a protobuf buffer.
 * @param screen The screen to be encoded.
 * @param buffer The buffer in which the screen will be encoded.
 * @param bufferSize The size of the buffer.
 * @return An std::expected type containing either the size of the protobuf message written or an error.
 */
tl::expected<size_t, EncodeError> encodeBuffer(Screen& screen, uint8_t* buffer, size_t bufferSize)
{
    auto layoutNodes = std::vector<ScreenConfig_LayoutNode>{};
    auto contentNodes = std::vector<ScreenConfig_ContentNode>{};

    if (!buffer) {
        return tl::unexpected{EncodeError::bufferIsNullptr};
    }
    screen.serialize(layoutNodes, contentNodes);

    return encodeNodes(layoutNodes, contentNodes, buffer, bufferSize);
}
}
