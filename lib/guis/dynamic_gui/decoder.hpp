#pragma once
#include "elements/core/screen.hpp"
#include "elements/layouts/content.hpp"
#include "elements/layouts/horizontal-split.hpp"
#include "elements/layouts/vertical-split.hpp"
#include "elements/widgets/numeric_value.hpp"
#include "elements/widgets/widget.hpp"
#include "proto/guiMessage.pb.h"
#include <iostream>
#include <optional>
#include <pb_decode.h>

namespace gui::dynamic_interface {
namespace detail {

    // Decode layoutNodes and push them to a vector passed in arg.
    bool layoutNodeDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg)
    {
        auto nodes = reinterpret_cast<std::vector<guiMessage_LayoutNode>*>(*arg);
        while (stream->bytes_left) {
            auto node = guiMessage_LayoutNode{};
            if (!pb_decode(stream, guiMessage_LayoutNode_fields, &node))
                return false;

            nodes->push_back(node);
        }
        return true;
    }

    // Decode contentNodes and push them to a vector passed in arg.
    bool contentNodeDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg)
    {
        auto nodes = reinterpret_cast<std::vector<guiMessage_ContentNode>*>(*arg);
        while (stream->bytes_left) {
            auto node = guiMessage_ContentNode{};
            if (!pb_decode(stream, guiMessage_ContentNode_fields, &node))
                return false;

            nodes->push_back(node);
        }
        return true;
    }

    bool parseRowCol(guiMessage_LayoutNode& nodeToAdd, std::vector<std::pair<std::unique_ptr<Element>, uint32_t>>& elements)
    {
        auto children = std::vector<std::unique_ptr<Element>>{};

        // Find all children of the max element.
        auto toAdd = std::stable_partition(elements.begin(), elements.end(), [nodeToAdd](auto const& a) {
            return a.second != nodeToAdd.nodeId;
        });

        // Move all children into the children vector.
        std::transform(toAdd, elements.end(), std::back_inserter(children), [](auto& a) {
            return std::move(a.first);
        });

        // Erase the empty moven elements from vector.
        elements.erase(toAdd, elements.end());

        // Construct the split with the found children and add it to elements.
        if (nodeToAdd.type == guiMessage_Type_Row) {
            std::unique_ptr<Element> newElement{new HorizontalSplit(std::move(children), nodeToAdd.weight, nodeToAdd.nodeId)};
            elements.push_back({std::move(newElement), nodeToAdd.parent});
        } else {
            std::unique_ptr<Element> newElement{new VerticalSplit(std::move(children), nodeToAdd.weight, nodeToAdd.nodeId)};
            elements.push_back({std::move(newElement), nodeToAdd.parent});
        }
        return true;
    }

    bool parseContent(guiMessage_LayoutNode& nodeToAdd, std::vector<std::pair<std::unique_ptr<Element>, uint32_t>>& elements, std::vector<guiMessage_ContentNode>& contentNodes)
    {
        // Find the content node with a layoutId that matches the id of the current node.
        auto content = std::find_if(contentNodes.begin(), contentNodes.end(), [nodeToAdd](const auto& node) {
            return nodeToAdd.nodeId == node.layoutNodeId;
        });
        if (content != std::end(contentNodes)) {
            if (content->which_Content == guiMessage_ContentNode_numericValue_tag) {
                std::unique_ptr<Widget> widget{new NumericValue(content->Content.numericValue)};
                std::unique_ptr<Element> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                elements.push_back({std::move(newElement), nodeToAdd.parent});
            }

            else if (content->which_Content == guiMessage_ContentNode_widget_tag) {
                std::unique_ptr<Widget> widget{new WidgetBase(content->Content.widget)};
                std::unique_ptr<Element> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                elements.push_back({std::move(newElement), nodeToAdd.parent});
            }

            // If the contentType is not known default to an empty widget.
            else {
                std::unique_ptr<Widget> widget{new WidgetBase()};
                std::unique_ptr<Element> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                elements.push_back({std::move(newElement), nodeToAdd.parent});
            }
        }

        else {
            // If no content is found for the block default to an empty widget.
            std::unique_ptr<Widget> widget{new WidgetBase()};
            std::unique_ptr<Element> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
            elements.push_back({std::move(newElement), nodeToAdd.parent});
        }
        return true;
    }
    std::optional<Screen> parseGui(std::vector<guiMessage_LayoutNode>& layoutNodes, std::vector<guiMessage_ContentNode> contentNodes)
    {
        // Temp storage of elements which are to be children of higher elements.
        auto elements = std::vector<std::pair<std::unique_ptr<Element>, uint32_t>>{};
        elements.reserve(layoutNodes.size());

        // Sort the layoutnodes in decending order of nodeId.
        std::sort(layoutNodes.begin(), layoutNodes.end(), [](auto& a, auto& b) {
            return a.nodeId > b.nodeId;
        });

        // We walk throught the list of nodes in decending order of nodeId.
        // This means that the children of a node are already created when the node is reached.
        for (auto nodeToAdd : layoutNodes) {
            if (nodeToAdd.type == guiMessage_Type_Row || nodeToAdd.type == guiMessage_Type_Column) {
                if (!parseRowCol(nodeToAdd, elements))
                    return std::nullopt;
            } else if (nodeToAdd.type == guiMessage_Type_Content) {
                if (!parseContent(nodeToAdd, elements, contentNodes))
                    return std::nullopt;
            } else {
                return std::nullopt;
            }
        }

        // The only element left should have a parent of id: 0.
        if (elements.size() != 1 || elements.back().second != 0)
            return std::nullopt;

        auto screen = Screen{std::move(elements.back().first)};
        return std::move(screen);
    }
}
std::optional<Screen> decoder(uint8_t* buffer, size_t length)
{
    auto protoMessage = guiMessage_Gui{};

    protoMessage.layoutNodes.funcs.decode = detail::layoutNodeDecoder;
    auto layoutNodes = std::vector<guiMessage_LayoutNode>{};
    protoMessage.layoutNodes.arg = reinterpret_cast<void*>(&layoutNodes);

    protoMessage.contentNodes.funcs.decode = detail::contentNodeDecoder;
    auto contentNodes = std::vector<guiMessage_ContentNode>{};
    protoMessage.contentNodes.arg = reinterpret_cast<void*>(&contentNodes);

    pb_istream_t stream = pb_istream_from_buffer(buffer, length);
    auto status = pb_decode(&stream, guiMessage_Gui_fields, &protoMessage);

    return detail::parseGui(layoutNodes, contentNodes);
}
}
