#include "Figure.hpp"


Figure::Figure(FigureType _type, FigureColour _colour)
{
    type = _type;
    colour = _colour;
}


FigureColour Figure::getColour()
{
    return colour;
}


FigureType Figure::getType()
{
    return type;
}

