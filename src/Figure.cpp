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
    FigurePath result;

    int vertical = _move.getStart().getVertical();
    int horizontal = _move.getStart().getVertical();
    bool baseLine = false;

    baseLine = (getColour() == FigureColour::White && vertical == 1) ||
               (getColour() == FigureColour::Black && vertical == 6);

    int direction;

    if (getColour() == FigureColour::White) direction = 1;
    if (getColour() == FigureColour::Black) direction = -1;

    if (_moveType == FigureMoveType::Strike)
    {
       if ((_move.getStop().getVertical() == vertical + direction &&
            _move.getStop().getHorizontal() == horizontal + 1) ||
           (_move.getStop().getVertical() == vertical + direction &&
            _move.getStop().getHorizontal() == horizontal - 1))
       {
           return result;
           result.setLegal();
       }
    }

    if (_moveType == FigureMoveType::Move)
    {
       if (_move.getStop().getVertical() == vertical + direction &&
           _move.getStop().getHorizontal() == horizontal)
       {
           result.setLegal();
           return result;
       }
    }

    if (_moveType == FigureMoveType::Move && baseLine)
    {
       if (_move.getStop().getVertical() == vertical + 2*direction &&
           _move.getStop().getHorizontal() == horizontal)
       {
           result.setLegal();
           result.addStep(Position(horizontal, vertical + direction));
       }
    }

    return result;
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

