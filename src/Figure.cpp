#include "Figure.hpp"

Figure::Figure() {
    type = FigureType::None;
    colour = FigureColour::None;
}

Figure::Figure(FigureType _type, FigureColour _colour) {
    type = _type;
    colour = _colour;
}

FigureColour Figure::getColour() const {
    return colour;
}

FigureType Figure::getType() const {
    return type;
}

