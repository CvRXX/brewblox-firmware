#pragma once
#include "elements/core/screen.hpp"
#include "proto/ScreenConfig.pb.h"
#include "tl/expected.hpp"
#include <iostream>
#include <optional>
#include <pb_encode.h>

namespace gui::dynamic_interface {
namespace detail {
    auto nodeReturner = [](pb_ostream_t* stream, const pb_field_t* field, void* const* arg) -> bool {
        for (auto node : *reinterpret_cast<std::vector<blox_ScreenConfig_LayoutNode>*>(*arg)) {
            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            }

            if (!pb_encode_submessage(stream, blox_ScreenConfig_LayoutNode_fields, &node)) {
                return false;
            }
        }
        return true;
    };

    auto contentNodeReturner = [](pb_ostream_t* stream, const pb_field_t* field, void* const* arg) -> bool {
        for (auto node : *reinterpret_cast<std::vector<blox_ScreenConfig_ContentNode>*>(*arg)) {
            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            }

            if (!pb_encode_submessage(stream, blox_ScreenConfig_ContentNode_fields, &node)) {
                return false;
            }
        }
        return true;
    };
}
enum class EncodeError : uint8_t {
    success = 0,
    bufferIsNullptr = 1,
    screenDecomposingError = 2,
    PBError = 3,
};

tl::expected<size_t, EncodeError> encodeNodes(std::vector<blox_ScreenConfig_LayoutNode>& layoutNodes, std::vector<blox_ScreenConfig_ContentNode>& contentNodes, uint8_t* buffer, size_t bufferSize)
{
    if (!buffer) {
        return tl::unexpected{EncodeError::bufferIsNullptr};
    }

    pb_ostream_t stream = pb_ostream_from_buffer(buffer, bufferSize);

    blox_ScreenConfig_ScreenConfig protoMessage = blox_ScreenConfig_ScreenConfig_init_default;

    protoMessage.layoutNodes.funcs.encode = detail::nodeReturner;
    protoMessage.layoutNodes.arg = reinterpret_cast<void*>(&layoutNodes);

    protoMessage.contentNodes.funcs.encode = detail::contentNodeReturner;
    protoMessage.contentNodes.arg = reinterpret_cast<void*>(&contentNodes);

    if (!pb_encode(&stream, blox_ScreenConfig_ScreenConfig_fields, &protoMessage)) {
        return tl::unexpected{EncodeError::PBError};
    }

    return stream.bytes_written;
}

tl::expected<size_t, EncodeError> encodeBuffer(Screen& screen, uint8_t* buffer, size_t bufferSize)
{
    auto layoutNodes = std::vector<blox_ScreenConfig_LayoutNode>{};
    auto contentNodes = std::vector<blox_ScreenConfig_ContentNode>{};

    if (!buffer) {
        return tl::unexpected{EncodeError::bufferIsNullptr};
    }
    if (!screen.serialise(layoutNodes, contentNodes)) {
        return tl::unexpected{EncodeError::screenDecomposingError};
    }

    return encodeNodes(layoutNodes, contentNodes, buffer, bufferSize);
}
}
