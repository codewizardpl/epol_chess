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

    int slashStart = start.getVertical() + start.getHorizontal();
    int backslashStart = start.getVertical() - start.getHorizontal();

    for (int i=0; i<8; i++)
    {
        Position horizontalLine = Position(i, start.getVertical());
        if (!(horizontalLine == start))
            result.insert(horizontalLine);

        Position verticalLine = Position(start.getHorizontal(), i);
        if (!(verticalLine == start))
            result.insert(verticalLine);

        Position slashLine = Position(i, i-slashStart);
        if (slashLine.validateCoordinates() && !(slashLine == start))
            result.insert(slashLine);

        Position backslashLine = Position(i, i+backslashStart);
        if (backslashLine.validateCoordinates() && !(backslashLine == start))
            result.insert(backslashLine);

    }

    return result;
}

