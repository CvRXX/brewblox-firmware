# Dynamic interface
A dynamic interface build on top of lvgl.

This interface features:
   * A tiling layout system allowing for a very wide range of layouts.
   * Widgets for the brewblox blox aswell as some breblox agnostic widgets.
   * Configpanel support for some widget where touching the widget opens a configpanel for onsite changes.
   * Widgets scale the available space they are given.
   * Serialisation and deserialisation of the layout and widgets to a protobuf stream.

## Layout elements
Before widgets can be placed on the screen a layout must be defined so the widgets have a place and size in respect to each other. To do this multiple layout elements excist which are composed in a tree to form a layout.

### Screen element
The screen element is the top of the tree. This element represents the display in which all the other elements will be drawn. The screen element can hold one element as a child.

### Content element
A content element is a placeholder for content. This can be any type of widget. The content element does not know anything about its size of position. This is defered from it's parents. For instance if the content element has the screen as its parent the widget will be drawn fullscreen.

### Vertical split & horizontal split
Vertical splits and horizontal splits are used to be able to draw widgets next to eachother in different sizes. A split contains a set of other elements which will be positioned horizontaly or verticaly. Each of those elements must have a weight. When the weight of alle elements is the same all those elements will be spread evenly over the row or collum. If the weights differ the blocks will be drawn to ratio of their weight against the sum of all weights.

An example, a horizontalsplit is defined with two element with element A having a weight of 1 and element B with a weight of 2. When drawing this layout, the sum of all weights is taken, in this case 1+2=3. Then the elements are drawn against their ratio. So for element A it's 1/3 of the size of the screen and for element B it's 2/3.

## Widgets


## Configpanels

## Updating values

## Scaling

## Fonts

## Serialisation

## Test screen

## Unit tests
