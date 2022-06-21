#pragma once

#include "cbox/CboxError.hpp"
#include <functional>
#include <memory>
#include <vector>

namespace cbox {

using obj_type_t = uint16_t;
using obj_id_t = uint16_t;
using obj_subtype_t = uint16_t;
using obj_field_tag_t = uint16_t;

enum class MaskMode : uint8_t {
    /// All fields (including defaults) are valid.
    NO_MASK = 0,

    /// Only fields where the tag is in `mask` are valid.
    INCLUSIVE = 1,

    /// Only fields where the tag is not in `mask` are valid.
    EXCLUSIVE = 2,
};

class Payload final {
public:
    const obj_id_t blockId;
    const obj_type_t blockType;
    const obj_subtype_t subtype;
    std::vector<uint8_t> content;

    MaskMode maskMode;
    std::vector<obj_field_tag_t> mask;

    Payload(obj_id_t blockId_,
            obj_type_t blockType_,
            obj_subtype_t subtype_,
            MaskMode maskMode_,
            std::vector<uint8_t>&& content_,
            std::vector<obj_field_tag_t>&& mask_)
        : blockId(blockId_)
        , blockType(blockType_)
        , subtype(subtype_)
        , content(std::move(content_))
        , maskMode(maskMode_)
        , mask(std::move(mask_))
    {
    }

    Payload(obj_id_t blockId_,
            obj_type_t blockType_,
            obj_subtype_t subtype_)
        : blockId(blockId_)
        , blockType(blockType_)
        , subtype(subtype_)
        , content{}
        , maskMode(MaskMode::NO_MASK)
        , mask{}
    {
    }
};

using PayloadCallback = std::function<CboxError(const Payload&)>;

} // end namespace cbox
