#include "dynamic_gui/decode.hpp"

namespace gui::dynamic_interface {
namespace detail {
    bool pageDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg)
    {
        auto pages = reinterpret_cast<std::vector<std::pair<std::vector<screen_LayoutNode>, std::vector<screen_ContentNode>>>*>(*arg);
        while (stream->bytes_left) {
            screen_Page page = screen_Page_init_default;
            std::pair<std::vector<screen_LayoutNode>, std::vector<screen_ContentNode>> decodedPage;

            page.layoutNodes.funcs.decode = detail::layoutNodeDecoder;
            page.layoutNodes.arg = reinterpret_cast<void*>(&(decodedPage.first));

            page.contentNodes.funcs.decode = detail::contentNodeDecoder;
            page.contentNodes.arg = reinterpret_cast<void*>(&(decodedPage.second));

            if (!pb_decode(stream, screen_Page_fields, &page)) {
                return false;
            }

            pages->push_back(decodedPage);
        }
        return true;
    }

    bool layoutNodeDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg)
    {
        auto nodes = reinterpret_cast<std::vector<screen_LayoutNode>*>(*arg);
        while (stream->bytes_left) {
            screen_LayoutNode node = screen_LayoutNode_init_default;
            if (!pb_decode(stream, screen_LayoutNode_fields, &node)) {
                return false;
            }

            nodes->push_back(node);
        }
        return true;
    }

    bool contentNodeDecoder(pb_istream_t* stream, const pb_field_t* field, void** arg)
    {
        auto nodes = reinterpret_cast<std::vector<screen_ContentNode>*>(*arg);
        while (stream->bytes_left) {
            auto node = screen_ContentNode{};
            if (!pb_decode(stream, screen_ContentNode_fields, &node)) {
                return false;
            }

            nodes->push_back(node);
        }
        return true;
    }
    DecodeError parseRowCol(screen_LayoutNode& nodeToAdd, std::vector<std::pair<std::unique_ptr<LayoutNode>, uint8_t>>& buffer)
    {
        auto children = std::vector<std::unique_ptr<LayoutNode>>{};

        // Move the children of nodeToAdd to the end of the vector and return the pivot point.
        auto toAdd = std::stable_partition(buffer.begin(), buffer.end(), [nodeToAdd](auto const& a) {
            return a.second != nodeToAdd.nodeId;
        });

        // Move all children into the children vector.
        std::transform(toAdd, buffer.end(), std::back_inserter(children), [](auto& a) {
            return std::move(a.first);
        });

        // Erase the empty moved layoutNodes from vector.
        buffer.erase(toAdd, buffer.end());

        // Construct the split with the found children and add it to the buffer.
        if (nodeToAdd.type == screen_LayoutNode_Type_Row) {
            std::unique_ptr<LayoutNode> newElement{new HorizontalSplit(std::move(children), nodeToAdd.weight, nodeToAdd.nodeId)};
            buffer.push_back({std::move(newElement), nodeToAdd.parent});
        } else {
            std::unique_ptr<LayoutNode> newElement{new VerticalSplit(std::move(children), nodeToAdd.weight, nodeToAdd.nodeId)};
            buffer.push_back({std::move(newElement), nodeToAdd.parent});
        }
        return DecodeError::success;
    }

    DecodeError parseContent(screen_LayoutNode& nodeToAdd, std::vector<std::pair<std::unique_ptr<LayoutNode>, uint8_t>>& buffer, std::vector<screen_ContentNode>& contentNodes)
    {
        // Find the content node with a layoutId that matches the id of the current node.
        auto content = std::find_if(contentNodes.begin(), contentNodes.end(), [nodeToAdd](const auto& node) {
            return nodeToAdd.nodeId == node.layoutNodeId;
        });
        if (content != std::end(contentNodes)) {
            if (content->which_content == screen_ContentNode_numericValueWidget_tag) {
                std::unique_ptr<Widget> widget{new NumericValueWidget(content->content.numericValueWidget)};
                std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                buffer.push_back({std::move(newElement), nodeToAdd.parent});
            }

            else if (content->which_content == screen_ContentNode_colorWidget_tag) {
                std::unique_ptr<Widget> widget{new ColorWidget(content->content.colorWidget)};
                std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                buffer.push_back({std::move(newElement), nodeToAdd.parent});
            }

            else if (content->which_content == screen_ContentNode_temperatureWidget_tag) {
                std::unique_ptr<Widget> widget{new TemperatureWidget(content->content.temperatureWidget)};
                std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                buffer.push_back({std::move(newElement), nodeToAdd.parent});
            }

            // If the contentType is not known default to an empty widget.
            else {
                std::unique_ptr<Widget> widget{new EmptyWidget()};
                std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
                buffer.push_back({std::move(newElement), nodeToAdd.parent});
            }
        }

        else {
            // If no content is found for the block default to an empty widget.
            std::unique_ptr<Widget> widget{new EmptyWidget()};
            std::unique_ptr<LayoutNode> newElement{new Content(nodeToAdd.weight, nodeToAdd.nodeId, std::move(widget))};
            buffer.push_back({std::move(newElement), nodeToAdd.parent});
        }
        return DecodeError::success;
    }
}

tl::expected<Screen, DecodeError> decodeNodes(std::vector<screen_LayoutNode>&& layoutNodes, std::vector<screen_ContentNode>&& contentNodes)
{
    // Temp storage of elements which are to be children of higher elements.
    auto buffer = std::vector<std::pair<std::unique_ptr<LayoutNode>, uint8_t>>{};
    buffer.reserve(layoutNodes.size());

    // Sort the layoutnodes in decending order of nodeId.
    std::sort(layoutNodes.begin(), layoutNodes.end(), [](auto& a, auto& b) {
        return a.nodeId > b.nodeId;
    });

    // Walk through the list of nodes in decending order of nodeId.
    // This means that the children of a node are already created when the node is reached.
    for (auto& nodeToAdd : layoutNodes) {
        if (nodeToAdd.type == screen_LayoutNode_Type_Row || nodeToAdd.type == screen_LayoutNode_Type_Column) {
            auto status = detail::parseRowCol(nodeToAdd, buffer);
            if (status != DecodeError::success) {
                return tl::unexpected{status};
            }
        } else if (nodeToAdd.type == screen_LayoutNode_Type_Content) {
            auto status = detail::parseContent(nodeToAdd, buffer, contentNodes);
            if (status != DecodeError::success) {
                return tl::unexpected{status};
            }
        } else {
            return tl::unexpected{DecodeError::unknownLayoutType};
        }
    }

    // The only element left should have a parent of id: 0.
    if (buffer.size() != 1 || buffer.back().second != 0) {
        return tl::unexpected{DecodeError::nodeIdsAreNotSequentialPerLevel};
    }
    return Screen{std::move(buffer.back().first)};
}

tl::expected<Screen, DecodeError> decodeBuffer(uint8_t* buffer, size_t length)
{
    if (!buffer) {
        return tl::unexpected{DecodeError::bufferIsNullptr};
    }

    screen_Block protoMessage = screen_Block_init_default;
    std::vector<std::pair<std::vector<screen_LayoutNode>, std::vector<screen_ContentNode>>> pages;

    protoMessage.pages.funcs.decode = detail::pageDecoder;
    protoMessage.pages.arg = reinterpret_cast<void*>(&pages);

    // protoMessage.layoutNodes.funcs.decode = detail::layoutNodeDecoder;
    // auto layoutNodes = std::vector<screen_LayoutNode>{};
    // protoMessage.layoutNodes.arg = reinterpret_cast<void*>(&layoutNodes);

    // protoMessage.contentNodes.funcs.decode = detail::contentNodeDecoder;
    // auto contentNodes = std::vector<screen_ContentNode>{};
    // protoMessage.contentNodes.arg = reinterpret_cast<void*>(&contentNodes);

    pb_istream_t stream = pb_istream_from_buffer(buffer, length);
    if (!pb_decode(&stream, screen_Block_fields, &protoMessage)) {
        return tl::unexpected{DecodeError::pbError};
    }

    if (pages.size() < 1) {
        return tl::unexpected{DecodeError::pbError};
    }

    return decodeNodes(std::move(pages[0].first), std::move(pages[0].second));
}
}
