#include "Figure.hpp"


AllowedFigureMove FigureNone::validateMove(Move move)
{
    return NoneFigureMove;
}


AllowedFigureMove FigurePawn::validateMove(Move move)
{
    return NoneFigureMove;
}


AllowedFigureMove FigureKnight::validateMove(Move move)
{
    return NoneFigureMove;
}


AllowedFigureMove FigureBishop::validateMove(Move move)
{
    return NoneFigureMove;
}


AllowedFigureMove FigureRook::validateMove(Move move)
{
    return NoneFigureMove;
}


AllowedFigureMove FigureQueen::validateMove(Move move)
{
    return NoneFigureMove;
}


AllowedFigureMove FigureKing::validateMove(Move move)
{
    return NoneFigureMove;
}

