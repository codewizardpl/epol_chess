#include "FigureBishop.hpp"


FigureBishop::FigureBishop(FigureColour colour) : Figure(FigureType::Bishop, colour)
{
}


FigurePath FigureBishop::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath(false);
}


std::set<Position> FigureBishop::getPossibleMoves(Position start)
{
    return std::set<Position>();
}

