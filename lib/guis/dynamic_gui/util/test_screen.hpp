#include "dynamic_gui/decode.hpp"

namespace gui::dynamic_interface {

tl::expected<Screen, DecodeError> testScreen()
{
    std::vector<ScreenConfig_LayoutNode> layoutNodes;
    layoutNodes.push_back({1, 2, ScreenConfig_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({0, 1, ScreenConfig_LayoutNode_Type_Row, 1});
    layoutNodes.push_back({1, 3, ScreenConfig_LayoutNode_Type_Column, 1});
    layoutNodes.push_back({3, 4, ScreenConfig_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({3, 5, ScreenConfig_LayoutNode_Type_Content, 1});

    std::vector<ScreenConfig_ContentNode> contentNodes;
    auto numericValueWidget1 = ScreenConfig_NumericValueWidget{ScreenConfig_Color{0, 255, 0}, 99, "proto"};
    auto node1 = ScreenConfig_ContentNode{2, ScreenConfig_ContentNode_numericValueWidget_tag, numericValueWidget1};
    contentNodes.push_back(node1);

    auto numericValueWidget2 = ScreenConfig_NumericValueWidget{ScreenConfig_Color{0, 255, 0}, 99, "proto"};
    auto node2 = ScreenConfig_ContentNode{5, ScreenConfig_ContentNode_numericValueWidget_tag, numericValueWidget2};
    contentNodes.push_back(node2);

    return decodeNodes(std::move(layoutNodes), std::move(contentNodes));
}
}
