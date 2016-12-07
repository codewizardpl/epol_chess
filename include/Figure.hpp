#ifndef FIGURE
#define FIGURE


#include "Move.hpp"
#include "FigurePath.hpp"


enum class FigureType
{
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};


enum class FigureColour
{
    White,
    Black
};


enum class FigureMoveType
{
    Move,
    Strike
};


class Figure
{
private:
    FigureColour colour;
    FigureType type;
protected:
    Figure(FigureType type, FigureColour colour);
public:

    FigureColour getColour();
    FigureType getType();

    virtual ~Figure() {}

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType) = 0;
};

#endif
