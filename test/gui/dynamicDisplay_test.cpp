/*
 * Copyright 2020 BrewPi B.V.
 *
 * This file is part of Brewblox.
 *
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <catch.hpp>

#include "dynamic_gui/decode.hpp"
#include "dynamic_gui/dynamicGui.hpp"
#include "dynamic_gui/encode.hpp"
#include <pb_encode.h>

SCENARIO("DynamicGui")
{
    GIVEN("A gui proto stream")
    {
        uint8_t buffer[128];
        // size_t message_length;
        std::vector<ScreenConfig_LayoutNode> layoutNodes;
        layoutNodes.push_back({1, 2, ScreenConfig_LayoutNode_Type_Content, 1});
        layoutNodes.push_back({0, 1, ScreenConfig_LayoutNode_Type_Row, 1});
        layoutNodes.push_back({1, 3, ScreenConfig_LayoutNode_Type_Content, 1});

        std::vector<ScreenConfig_ContentNode> contentNodes;
        auto numericValueWidget = ScreenConfig_NumericValueWidget{ScreenConfig_Color{0, 255, 0}, 99, "proto"};
        auto node = ScreenConfig_ContentNode{2, ScreenConfig_ContentNode_numericValueWidget_tag, numericValueWidget};
        contentNodes.push_back(node);

        auto encodeResult = gui::dynamic_interface::encodeNodes(layoutNodes, contentNodes, buffer, sizeof(buffer));
        REQUIRE(encodeResult);
        auto message_length = *encodeResult;

        WHEN("Decoding")
        {
            auto newScreen = gui::dynamic_interface::decodeBuffer(buffer, message_length);

            THEN("Decoding should return a Screen")
            {
                REQUIRE(newScreen);

                // Validate assumption of the GIVEN clause
                WHEN("Serialising the screen")
                {
                    std::vector<ScreenConfig_LayoutNode> layoutNodesBack;
                    std::vector<ScreenConfig_ContentNode> contentNodesBack;
                    newScreen->serialize(layoutNodesBack, contentNodesBack);

                    std::sort(layoutNodes.begin(), layoutNodes.end(), [](const auto& a, const auto& b) {
                        return a.nodeId < b.nodeId;
                    });

                    std::sort(layoutNodesBack.begin(), layoutNodesBack.end(), [](const auto& a, const auto& b) {
                        return a.nodeId < b.nodeId;
                    });

                    std::sort(contentNodes.begin(), contentNodes.end(), [](const auto& a, const auto& b) {
                        return a.layoutNodeId < b.layoutNodeId;
                    });

                    std::sort(contentNodesBack.begin(), contentNodesBack.end(), [](const auto& a, const auto& b) {
                        return a.layoutNodeId < b.layoutNodeId;
                    });

                    THEN("The output should be the same as the original input.")
                    {
                        CHECK(
                            std::mismatch(layoutNodes.begin(), layoutNodes.end(), layoutNodesBack.begin(), layoutNodesBack.end(), [](const auto& a, const auto& b) {
                                return a.parent == b.parent && a.nodeId == b.nodeId && a.type == b.type && a.weight == b.weight;
                            }).first
                            == layoutNodes.end());

                        CHECK(
                            std::mismatch(contentNodes.begin(), contentNodes.end(), contentNodesBack.begin(), contentNodesBack.end(), [](const auto& a, const auto& b) {
                                return a.layoutNodeId == b.layoutNodeId && a.which_content == b.which_content;
                            }).first
                            == contentNodes.end());
                    }
                }
            }
        }
    }
}
