#pragma once
#include "dynamic_gui/decode.hpp"

namespace gui::dynamic_interface {

tl::expected<Screen, DecodeError> testScreen()
{
    std::vector<screen_LayoutNode> layoutNodes;
    layoutNodes.push_back({0, 1, screen_LayoutNode_Type_Row, 1});
    layoutNodes.push_back({1, 2, screen_LayoutNode_Type_Column, 1});
    layoutNodes.push_back({1, 3, screen_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({2, 4, screen_LayoutNode_Type_Content, 1});
    layoutNodes.push_back({2, 5, screen_LayoutNode_Type_Content, 2});

    std::vector<screen_ContentNode> contentNodes;
    auto numericValueWidget1 = screen_NumericValueWidget{screen_Color{0, 255, 0}, 3, ""};
    auto node1 = screen_ContentNode{3, screen_ContentNode_numericValueWidget_tag, numericValueWidget1};
    contentNodes.push_back(node1);

    auto numericValueWidget2 = screen_NumericValueWidget{screen_Color{0, 255, 0}, 4, ""};
    auto node2 = screen_ContentNode{4, screen_ContentNode_numericValueWidget_tag, numericValueWidget2};
    contentNodes.push_back(node2);

    auto numericValueWidget3 = screen_NumericValueWidget{screen_Color{0, 255, 0}, 5, ""};
    auto node3 = screen_ContentNode{5, screen_ContentNode_numericValueWidget_tag, numericValueWidget3};
    contentNodes.push_back(node3);

    return decodeNodes(std::move(layoutNodes), std::move(contentNodes));
}
}
