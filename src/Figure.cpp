#include "Figure.hpp"

Figure::Figure() {
    type = FigureType::None;
    colour = FigureColour::None;
}

Figure::Figure(FigureType _type, FigureColour _colour) {
    type = _type;
    colour = _colour;
}

bool Figure::operator==(const Figure& other) {
    return type == other.type &&
           colour == other.colour;
}

bool Figure::operator!=(const Figure& other) {
    return !(*this==other);
}

FigureColour Figure::getColour() const {
    return colour;
}

FigureType Figure::getType() const {
    return type;
}

