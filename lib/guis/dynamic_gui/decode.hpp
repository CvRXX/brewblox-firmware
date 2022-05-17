#pragma once
#include "elements/layout/content.hpp"
#include "elements/layout/horizontal_split.hpp"
#include "elements/layout/screen.hpp"
#include "elements/layout/vertical_split.hpp"
#include "elements/widgets/empty_widget.hpp"
#include "elements/widgets/numeric_value_widget.hpp"
#include "elements/widgets/widget.hpp"
#include "proto/ScreenConfig.pb.h"
#include "tl/expected.hpp"
#include <iostream>
#include <optional>
#include <pb_decode.h>

namespace gui::dynamic_interface {

enum class DecodeError : uint8_t {
    success = 0,
    bufferIsNullptr = 1,
    unknownLayoutType = 2,
    PBError = 3,
    nodeIdsAreNotSequentialPerLevel = 4,

};

namespace detail {

    // Decode layoutNodes and push them to a vector passed in arg.
    bool layoutNodeDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg)
    {
        auto nodes = reinterpret_cast<std::vector<blox_ScreenConfig_LayoutNode>*>(*arg);
        while (stream->bytes_left) {
            auto node = blox_ScreenConfig_LayoutNode{};
            if (!pb_decode(stream, blox_ScreenConfig_LayoutNode_fields, &node)) {
                return false;
            }

            nodes->push_back(node);
        }
        return true;
    }

    // Decode contentNodes and push them to a vector passed in arg.
    bool contentNodeDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg)
    {
        auto nodes = reinterpret_cast<std::vector<blox_ScreenConfig_ContentNode>*>(*arg);
        while (stream->bytes_left) {
            auto node = blox_ScreenConfig_ContentNode{};
            if (!pb_decode(stream, blox_ScreenConfig_ContentNode_fields, &node)) {
                return false;
            }

            nodes->push_back(node);
        }
        return true;
    }

    DecodeError parseRowCol(blox_ScreenConfig_LayoutNode& nodeToAdd, std::vector<std::pair<std::unique_ptr<LayoutNode>, uint32_t>>& elements)
    {
        auto children = std::vector<std::unique_ptr<LayoutNode>>{};

        // Move the children of nodeToAdd to the end of the vector and return the pivot point.
        auto toAdd = std::stable_partition(elements.begin(), elements.end(), [nodeToAdd](auto const& a) {
            return a.second != nodeToAdd.nodeId;
        });

        // Move all children into the children vector.
        std::transform(toAdd, elements.end(), std::back_inserter(children), [](auto& a) {
            return std::move(a.first);
        });

        // Erase the empty moved elements from vector.
        elements.erase(toAdd, elements.end());

        // Construct the split with the found children and add it to elements.
        if (nodeToAdd.type == blox_ScreenConfig_Type_Row) {
            std::unique_ptr<LayoutNode> newElement{new HorizontalSplit(std::move(children), nodeToAdd.weight, nodeToAdd.nodeId)};
            elements.push_back({std::move(newElement), nodeToAdd.parent});
        } else {
            std::unique_ptr<LayoutNode> newElement{new VerticalSplit(std::move(children), nodeToAdd.weight, nodeToAdd.nodeId)};
            elements.push_back({std::move(newElement), nodeToAdd.parent});
        }
        return DecodeError::success;
    }

    DecodeError parseContent(blox_ScreenConfig_LayoutNode& nodeToAdd, std::vector<std::pair<std::unique_ptr<LayoutNode>, uint32_t>>& elements, std::vector<blox_ScreenConfig_ContentNode>& contentNodes)
    {
        // Find the content node with a layoutId that matches the id of the current node.
        auto content = std::find_if(contentNodes.begin(), contentNodes.end(), [nodeToAdd](const auto& node) {
            return nodeToAdd.nodeId == node.layoutNodeId;
        });
        if (content != std::end(contentNodes)) {
            if (content->which_Content == blox_ScreenConfig_ContentNode_numericValueWidget_tag) {
                std::unique_ptr<Widget> widget{new NumericValueWidget(content->Content.numericValueWidget)};
                std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                elements.push_back({std::move(newElement), nodeToAdd.parent});
            }

            else if (content->which_Content == blox_ScreenConfig_ContentNode_colorWidget_tag) {
                std::unique_ptr<Widget> widget{new ColorWidget(content->Content.colorWidget)};
                std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                elements.push_back({std::move(newElement), nodeToAdd.parent});
            }

            // If the contentType is not known default to an empty widget.
            else {
                std::unique_ptr<Widget> widget{new EmptyWidget()};
                std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                elements.push_back({std::move(newElement), nodeToAdd.parent});
            }
        }

        else {
            // If no content is found for the block default to an empty widget.
            std::unique_ptr<Widget> widget{new EmptyWidget()};
            std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
            elements.push_back({std::move(newElement), nodeToAdd.parent});
        }
        return DecodeError::success;
    }
    tl::expected<Screen, DecodeError> decodeNodes(std::vector<blox_ScreenConfig_LayoutNode>& layoutNodes, std::vector<blox_ScreenConfig_ContentNode> contentNodes)
    {
        // Temp storage of elements which are to be children of higher elements.
        auto elements = std::vector<std::pair<std::unique_ptr<LayoutNode>, uint32_t>>{};
        elements.reserve(layoutNodes.size());

        // Sort the layoutnodes in decending order of nodeId.
        std::sort(layoutNodes.begin(), layoutNodes.end(), [](auto& a, auto& b) {
            return a.nodeId > b.nodeId;
        });

        // Walk through the list of nodes in decending order of nodeId.
        // This means that the children of a node are already created when the node is reached.
        for (auto& nodeToAdd : layoutNodes) {
            if (nodeToAdd.type == blox_ScreenConfig_Type_Row || nodeToAdd.type == blox_ScreenConfig_Type_Column) {
                auto status = parseRowCol(nodeToAdd, elements);
                if (status != DecodeError::success) {
                    return tl::unexpected{status};
                }
            } else if (nodeToAdd.type == blox_ScreenConfig_Type_Content) {
                auto status = parseContent(nodeToAdd, elements, contentNodes);
                if (status != DecodeError::success) {
                    return tl::unexpected{status};
                }
            } else {
                return tl::unexpected{DecodeError::unknownLayoutType};
            }
        }

        // The only element left should have a parent of id: 0.
        if (elements.size() != 1 || elements.back().second != 0) {
            return tl::unexpected{DecodeError::nodeIdsAreNotSequentialPerLevel};
        }

        return Screen{std::move(elements.back().first)};
    }
}

tl::expected<Screen, DecodeError> decodeBuffer(uint8_t* buffer, size_t length)
{
    if (!buffer) {
        return tl::unexpected{DecodeError::bufferIsNullptr};
    }

    blox_ScreenConfig_ScreenConfig protoMessage = blox_ScreenConfig_ScreenConfig_init_default;

    protoMessage.layoutNodes.funcs.decode = detail::layoutNodeDecoder;
    auto layoutNodes = std::vector<blox_ScreenConfig_LayoutNode>{};
    protoMessage.layoutNodes.arg = reinterpret_cast<void*>(&layoutNodes);

    protoMessage.contentNodes.funcs.decode = detail::contentNodeDecoder;
    auto contentNodes = std::vector<blox_ScreenConfig_ContentNode>{};
    protoMessage.contentNodes.arg = reinterpret_cast<void*>(&contentNodes);

    pb_istream_t stream = pb_istream_from_buffer(buffer, length);
    if (!pb_decode(&stream, blox_ScreenConfig_ScreenConfig_fields, &protoMessage)) {
        return tl::unexpected{DecodeError::PBError};
    }

    return detail::decodeNodes(layoutNodes, contentNodes);
}
}
