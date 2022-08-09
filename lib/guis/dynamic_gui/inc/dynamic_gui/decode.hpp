#pragma once
#include "elements/layout/content.hpp"
#include "elements/layout/horizontal_split.hpp"
#include "elements/layout/screen.hpp"
#include "elements/layout/vertical_split.hpp"
#include "elements/widgets/empty_widget.hpp"
#include "elements/widgets/numeric_value_widget.hpp"
#include "elements/widgets/temperature_widget.hpp"
#include "elements/widgets/widget.hpp"
#include "proto/Screen.pb.h"
#include "tl/expected.hpp"
#include <pb_decode.h>

namespace gui::dynamic_interface {

enum class DecodeError : uint8_t {
    success = 0,
    bufferIsNullptr = 1,
    unknownLayoutType = 2,
    pbError = 3,
    nodeIdsAreNotSequentialPerLevel = 4,

};

namespace detail {
    bool pageDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg);

    // Decode layoutNodes and push them to a vector passed in arg.
    bool layoutNodeDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg);

    // Decode contentNodes and push them to a vector passed in arg.
    bool contentNodeDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg);

    /**
     * Parse a row or collumn and add it to the buffer.
     * @param nodeToAdd The row or collumn to parse.
     * @param buffer The buffer with the children in it where the parse node will go into.
     */
    DecodeError parseRowCol(screen_LayoutNode& nodeToAdd, std::vector<std::pair<std::unique_ptr<LayoutNode>, uint8_t>>& buffer);

    /**
     * Parse a content node and add it to the buffer.
     * @param nodeToAdd The row or collumn to parse.
     * @param buffer The buffer with the children in it where the parse node will go into.
     * @param contentNodes The contentNodes list.
     */
    DecodeError parseContent(screen_LayoutNode& nodeToAdd, std::vector<std::pair<std::unique_ptr<LayoutNode>, uint8_t>>& buffer, std::vector<screen_ContentNode>& contentNodes);

}

/**
 * Decodes a set of layoutNodes and contentNodes and returns a screen.
 * @param layoutNodes The layoutNodes to be added to the screen.
 * @param contentNodes The contentNodes to be added to the screen.
 * @return An std::expected type containing either the screen or an error.
 */
tl::expected<Screen, DecodeError> decodeNodes(std::vector<screen_LayoutNode>&& layoutNodes, std::vector<screen_ContentNode>&& contentNodes);

/**
 * Decodes a protobuf screen message.
 * @param buffer A pointer to the buffer.
 * @param length The length of the message in the buffer.
 * @return An std::expected type containing either the screen or an error.
 */
tl::expected<Screen, DecodeError> decodeBuffer(uint8_t* buffer, size_t length);
}
