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

#include "dynamic_gui/elements/layout/content.hpp"
#include "dynamic_gui/elements/layout/vertical_split.hpp"
#include "dynamic_gui/elements/widgets/empty_widget.hpp"

using namespace gui::dynamic_interface;
SCENARIO("VerticalSplit")
{
    GIVEN("A verticalSplit node")
    {
        std::unique_ptr<Widget> widget1 = std::make_unique<EmptyWidget>(EmptyWidget{});
        std::unique_ptr<LayoutNode> content1 = std::make_unique<Content>(Content(55, 12, std::move(widget1)));
        std::unique_ptr<Widget> widget2 = std::make_unique<EmptyWidget>(EmptyWidget{});
        std::unique_ptr<LayoutNode> content2 = std::make_unique<Content>(Content(13, 15, std::move(widget2)));

        std::vector<std::unique_ptr<LayoutNode>> children = {};
        children.push_back(std::move(content1));
        children.push_back(std::move(content2));

        auto verticalSplit = VerticalSplit(std::move(children), 15, 33);

        CHECK(verticalSplit.getWeight() == 15);

        THEN("The horizontalsplit can be serialised")
        {
            std::vector<ScreenConfig_LayoutNode> layoutNodes = {};
            std::vector<ScreenConfig_ContentNode> contentNodes = {};
            verticalSplit.serialize(layoutNodes, contentNodes, 5);

            REQUIRE(layoutNodes.size() == 3);
            REQUIRE(contentNodes.size() == 0);

            auto widget2Serialized = layoutNodes.back();
            layoutNodes.pop_back();
            auto widget1Serialized = layoutNodes.back();
            layoutNodes.pop_back();
            auto verticalSplitSerialized = layoutNodes.back();

            CHECK(widget2Serialized.parent == 33);
            CHECK(widget2Serialized.nodeId == 15);
            CHECK(widget2Serialized.type == ScreenConfig_LayoutNode_Type_Content);
            CHECK(widget2Serialized.weight == 13);

            CHECK(widget1Serialized.parent == 33);
            CHECK(widget1Serialized.nodeId == 12);
            CHECK(widget1Serialized.type == ScreenConfig_LayoutNode_Type_Content);
            CHECK(widget1Serialized.weight == 55);

            CHECK(verticalSplitSerialized.parent == 5);
            CHECK(verticalSplitSerialized.nodeId == 33);
            CHECK(verticalSplitSerialized.type == ScreenConfig_LayoutNode_Type_Column);
            CHECK(verticalSplitSerialized.weight == 15);
        }
    }
}
