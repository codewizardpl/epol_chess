#include "FigureQueen.hpp"


FigureQueen::FigureQueen(FigureColour colour) : Figure(FigureType::Queen, colour)
{
}


FigurePath FigureQueen::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath(false);
}


std::set<Position> FigureQueen::getPossibleMoves(Position start)
{
    return std::set<Position>();
}

