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
        std::vector<guiMessage_LayoutNode> layoutNodes;
        layoutNodes.push_back({1, 2, guiMessage_Type_Content, 1});
        layoutNodes.push_back({0, 1, guiMessage_Type_Row, 1});
        layoutNodes.push_back({1, 3, guiMessage_Type_Content, 1});

        std::vector<guiMessage_ContentNode> contentNodes;
        auto numericValue = guiMessage_NumericValue{guiMessage_Color{0, 255, 0}, 99, "proto"};
        auto node = guiMessage_ContentNode{2, guiMessage_ContentNode_numericValue_tag, numericValue};
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
                    std::vector<guiMessage_LayoutNode> layoutNodesBack;
                    std::vector<guiMessage_ContentNode> contentNodesBack;
                    REQUIRE(newScreen->serialise(layoutNodesBack, contentNodesBack));

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
                        REQUIRE(
                            std::mismatch(layoutNodes.begin(), layoutNodes.end(), layoutNodesBack.begin(), layoutNodesBack.end(), [](const auto& a, const auto& b) {
                                return a.parent == b.parent && a.nodeId == b.nodeId && a.type == b.type && a.weight == b.weight;
                            }).first
                            == layoutNodes.end());

                        REQUIRE(
                            std::mismatch(contentNodes.begin(), contentNodes.end(), contentNodesBack.begin(), contentNodesBack.end(), [](const auto& a, const auto& b) {
                                return a.layoutNodeId == b.layoutNodeId && a.which_Content == b.which_Content;
                            }).first
                            == contentNodes.end());
                    }
                }
            }
        }
    }
}
