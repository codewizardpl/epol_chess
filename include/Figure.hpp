#ifndef FIGURE
#define FIGURE


#include "Move.hpp"


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


enum class AllowedFigureMove
{
    Move,
    Strike,
    MoveAndStrike
};


class Figure
{
private:
    FigureColour colour;
    FigureType type;
public:
    FigureColour getColour();
    FigureType getType();

    virtual AllowedFigureMove validateMove(Move move) = 0;
};


class FigurePawn {
    virtual AllowedFigureMove validateMove(Move move);
};


class FigureKnight {
    virtual AllowedFigureMove validateMove(Move move);
};


class FigureBishop {
    virtual AllowedFigureMove validateMove(Move move);
};


class FigureRook {
    virtual AllowedFigureMove validateMove(Move move);
};


class FigureQueen {
    virtual AllowedFigureMove validateMove(Move move);
};


class FigureKing {
    virtual AllowedFigureMove validateMove(Move move);
};


#endif
