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
    std::set<Position> result;

    for (int i=0; i<8; i++)
    {
        Position horizontalLine = Position(i, start.getVertical());
        if (!(horizontalLine == start))
            result.insert(horizontalLine);
        Position verticalLine = Position(start.getHorizontal(), i);
        if (!(verticalLine == start))
            result.insert(verticalLine);
    }

    return result;
}

