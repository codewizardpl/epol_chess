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


FigurePath FigureKnight::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath();
}


FigurePath FigureBishop::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath();
}


FigurePath FigureRook::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath();
}


FigurePath FigureQueen::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath();
}


FigurePath FigureKing::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath();
}

