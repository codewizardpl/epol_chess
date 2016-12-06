#include "Figure.hpp"


FigureColour Figure::getColour()
{
    return colour;
}


FigureType Figure::getType()
{
    return type;
}


FigurePath FigurePawn::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath();
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

