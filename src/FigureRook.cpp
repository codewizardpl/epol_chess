#include "FigureRook.hpp"


FigureRook::FigureRook(FigureColour colour) : Figure(FigureType::Rook, colour)
{
}


FigurePath FigureRook::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath(false);
}


std::set<Position> FigureRook::getPossibleMoves(Position start)
{
    return std::set<Position>();
}

