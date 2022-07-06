#include "dynamic_gui/encode.hpp"

namespace gui::dynamic_interface {
namespace detail {
    bool layoutNodeEncoder(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
    {
        for (auto node : *reinterpret_cast<std::vector<screen_LayoutNode>*>(*arg)) {
            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            }

            if (!pb_encode_submessage(stream, screen_LayoutNode_fields, &node)) {
                return false;
            }
        }
        return true;
    };

    bool contentNodeEncoder(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
    {
        for (auto node : *reinterpret_cast<std::vector<screen_ContentNode>*>(*arg)) {
            if (!pb_encode_tag_for_field(stream, field)) {
                return false;
            }

            if (!pb_encode_submessage(stream, screen_ContentNode_fields, &node)) {
                return false;
            }
        }
        return true;
    };
}

tl::expected<size_t, EncodeError> encodeNodes(std::vector<screen_LayoutNode>& layoutNodes, std::vector<screen_ContentNode>& contentNodes, uint8_t* buffer, size_t bufferSize)
{
    if (!buffer) {
        return tl::unexpected{EncodeError::bufferIsNullptr};
    }

    pb_ostream_t stream = pb_ostream_from_buffer(buffer, bufferSize);

    screen_Block protoMessage = screen_Block_init_default;

    protoMessage.layoutNodes.funcs.encode = detail::layoutNodeEncoder;
    protoMessage.layoutNodes.arg = reinterpret_cast<void*>(&layoutNodes);

    protoMessage.contentNodes.funcs.encode = detail::contentNodeEncoder;
    protoMessage.contentNodes.arg = reinterpret_cast<void*>(&contentNodes);

    if (!pb_encode(&stream, screen_Block_fields, &protoMessage)) {
        return tl::unexpected{EncodeError::PBError};
    }

    return stream.bytes_written;
}

tl::expected<size_t, EncodeError> encodeBuffer(Screen& screen, uint8_t* buffer, size_t bufferSize)
{
    auto layoutNodes = std::vector<screen_LayoutNode>{};
    auto contentNodes = std::vector<screen_ContentNode>{};

    if (!buffer) {
        return tl::unexpected{EncodeError::bufferIsNullptr};
    }
    screen.serialize(layoutNodes, contentNodes);

    return encodeNodes(layoutNodes, contentNodes, buffer, bufferSize);
}

}
