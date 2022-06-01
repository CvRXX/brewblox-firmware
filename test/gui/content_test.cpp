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
#include "dynamic_gui/elements/widgets/empty_widget.hpp"

using namespace gui::dynamic_interface;
SCENARIO("Content")
{
    GIVEN("A content node")
    {
        std::unique_ptr<Widget> widget = std::make_unique<EmptyWidget>(EmptyWidget{});
        auto content = Content(55, 12, std::move(widget));
        CHECK(content.getWeight() == 55);

        THEN("The content node can be serialised")
        {
            std::vector<screen_LayoutNode> layoutNodes = {};
            std::vector<screen_ContentNode> contentNodes = {};
            content.serialize(layoutNodes, contentNodes, 5);

            REQUIRE(layoutNodes.size() == 1);
            REQUIRE(contentNodes.size() == 0);

            auto layoutNode = layoutNodes.back();

            CHECK(layoutNode.parent == 5);
            CHECK(layoutNode.nodeId == 12);
            CHECK(layoutNode.type == screen_LayoutNode_Type_Content);
            CHECK(layoutNode.weight == 55);
        }
    }
}
