#pragma once
#include "decoder.hpp"
#include "elements/core/screen.hpp"
#include "elements/layouts/horizontal-split.hpp"
#include "elements/layouts/vertical-split.hpp"
#include "elements/widgets/numeric_value.hpp"
#include "elements/widgets/widget.hpp"
#include "proto/guiMessage.pb.h"
#include "styles/styles.hpp"
#include <array>
#include <iostream>
#include <lvgl.h>
#include <memory>
#include <pb_encode.h>
uint8_t buffer[128];
size_t message_length;

namespace gui::dynamic_interface {
bool nodeReturner(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    {
        auto node = guiMessage_LayoutNode{0, 1, guiMessage_Type_Column, 1};
        if (!pb_encode_tag_for_field(stream, field))
            return false;

        if (!pb_encode_submessage(stream, guiMessage_LayoutNode_fields, &node))
            return false;
    }

    {
        auto node = guiMessage_LayoutNode{1, 2, guiMessage_Type_Row, 1};
        if (!pb_encode_tag_for_field(stream, field))
            return false;

        if (!pb_encode_submessage(stream, guiMessage_LayoutNode_fields, &node))
            return false;
    }

    {
        auto node = guiMessage_LayoutNode{1, 3, guiMessage_Type_Content, 1};
        if (!pb_encode_tag_for_field(stream, field))
            return false;

        if (!pb_encode_submessage(stream, guiMessage_LayoutNode_fields, &node))
            return false;
    }

    {
        auto node = guiMessage_LayoutNode{2, 4, guiMessage_Type_Content, 1};
        if (!pb_encode_tag_for_field(stream, field))
            return false;

        if (!pb_encode_submessage(stream, guiMessage_LayoutNode_fields, &node))
            return false;
    }

    {
        auto node = guiMessage_LayoutNode{2, 5, guiMessage_Type_Content, 1};
        if (!pb_encode_tag_for_field(stream, field))
            return false;

        if (!pb_encode_submessage(stream, guiMessage_LayoutNode_fields, &node))
            return false;
    }

    return true;
}

bool contentNodeReturner(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    {
        auto numericValue = guiMessage_NumericValue{guiMessage_Color{0, 255, 0}, 99, "proto"};
        auto node = guiMessage_ContentNode{3, guiMessage_ContentNode_numericValue_tag, numericValue};
        if (!pb_encode_tag_for_field(stream, field))
            return false;

        if (!pb_encode_submessage(stream, guiMessage_ContentNode_fields, &node))
            return false;
    }

    {
        auto widget = guiMessage_Widget{guiMessage_Color{255, 0, 0}};
        auto node = guiMessage_ContentNode{4, guiMessage_ContentNode_widget_tag, {.widget = widget}};
        if (!pb_encode_tag_for_field(stream, field))
            return false;

        if (!pb_encode_submessage(stream, guiMessage_ContentNode_fields, &node))
            return false;
    }

    {
        auto numericValue = guiMessage_NumericValue{guiMessage_Color{0, 0, 255}, 99, "proto2"};
        auto node = guiMessage_ContentNode{5, guiMessage_ContentNode_numericValue_tag, numericValue};
        if (!pb_encode_tag_for_field(stream, field))
            return false;

        if (!pb_encode_submessage(stream, guiMessage_ContentNode_fields, &node))
            return false;
    }
    return true;
}
/// A structure that holds the layout of the screen and its children.
class DynamicGui {
public:
    DynamicGui()
        : screen(Screen())
    {
        style::init();

        pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

        auto protoMessage = guiMessage_Gui{};
        protoMessage.layoutNodes.funcs.encode = nodeReturner;
        protoMessage.contentNodes.funcs.encode = contentNodeReturner;

        auto status = pb_encode(&stream, guiMessage_Gui_fields, &protoMessage);
        message_length = stream.bytes_written;

        auto newScreen = decoder(buffer, message_length);
        if (newScreen) {
            screen = std::move(*newScreen);
            screen.draw();
            std::vector<guiMessage_LayoutNode> layoutNodes;
            std::vector<guiMessage_ContentNode> contentNodes;

            auto decoded = screen.serialise(layoutNodes, contentNodes);

            for (auto& node : layoutNodes) {
                std::cout << "parent: " << +node.parent << std::endl;
                std::cout << "nodeId: " << +node.nodeId << std::endl;
                std::cout << "type: " << node.type << std::endl;
                std::cout << "weight: " << node.weight << std::endl
                          << std::endl;
            }

            for (auto& node : contentNodes) {
                std::cout << "layoutNodeId: " << +node.layoutNodeId << std::endl;
                std::cout << "which_Content: " << +node.which_Content << std::endl
                          << std::endl;
            }
        }
    }

    ~DynamicGui()
    {
    }

    /** Updates the following:
     *   - Checks if a new config is available the layout will be redrawn based on the new config.
     *   - Updates alle the widgets with the latest information about the objects they represent.
     *   - Updates the status bar with the current ip and network status.
     *   - Updates the status bar with the latest time.
     */
    void update()
    {
        screen.update();
    }

private:
    Screen screen;
};
}
