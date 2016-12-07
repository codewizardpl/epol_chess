#include "FigureKnight.hpp"


FigureKnight::FigureKnight(FigureColour colour) : Figure(FigureType::Knight, colour)
{
}


FigurePath FigureKnight::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath(false);
}


std::set<Position> FigureKnight::getPossibleMoves(Position start)
{
    return std::set<Position>();
}

