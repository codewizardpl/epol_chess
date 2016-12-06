#include "Figure.hpp"


FigureColour Figure::getColour()
{
    return colour;
}


FigureType Figure::getType()
{
    return type;
}


AllowedFigureMove FigurePawn::validateMove(Move move)
{
    return AllowedFigureMove::Move;
}


AllowedFigureMove FigureKnight::validateMove(Move move)
{
    return AllowedFigureMove::Move;
}


AllowedFigureMove FigureBishop::validateMove(Move move)
{
    return AllowedFigureMove::Move;
}


AllowedFigureMove FigureRook::validateMove(Move move)
{
    return AllowedFigureMove::Move;
}


AllowedFigureMove FigureQueen::validateMove(Move move)
{
    return AllowedFigureMove::Move;
}


AllowedFigureMove FigureKing::validateMove(Move move)
{
    return AllowedFigureMove::Move;
}

