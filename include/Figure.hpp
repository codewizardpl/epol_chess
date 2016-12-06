#ifndef FIGURE
#define FIGURE


#include "Move.hpp"


enum FigureType
{
    NoneFigureType,
    PawnFigureType,
    KnightFigureType,
    BishopFigureType,
    RookFigureType,
    QueenFigureType,
    KingFigureType
};


enum FigureColour
{
    WhiteFigureColour,
    BlackFigureColour
};


enum AllowedFigureMove
{
    NoneFigureMove,
    MoveFigureMove,
    StrikeFigureMove,
    MoveAndStrikeFigureMove
};


class Figure
{
public:
    FigureColour colour;
    FigureType type;
    virtual AllowedFigureMove validateMove(Move move) = 0;
};


class FigureNone {
    virtual AllowedFigureMove validateMove(Move move);
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
