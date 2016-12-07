#include "FigureKing.hpp"


FigureKing::FigureKing(FigureColour colour) : Figure(FigureType::King, colour)
{
}


FigurePath FigureKing::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath(false);
}


std::set<Position> FigureKing::getPossibleMoves(Position start)
{
    return std::set<Position>();
}

