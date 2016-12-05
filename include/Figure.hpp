#include <Move.hpp>


enum FigureType
{
    None,
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};


enum FigureColour
{
    White,
    Black
};


enum AllowedFigureMove
{
    Move,
    Strike,
    MoveAndStrike
}


class Figure
{
public:
    int colour;
    FigureType type;
    AllowedFigureMove validateMove(Move move) = 0;
};


class FigureNone {
    AllowedFigureMove validateMove(Move move);
};


class FigurePawn {
    AllowedFigureMove validateMove(Move move);
};


class FigureKnight {
    AllowedFigureMove validateMove(Move move);
};


class FigureBishop {
    AllowedFigureMove validateMove(Move move);
};


class FigureRook {
    AllowedFigureMove validateMove(Move move);
};


class FigureQueen {
    AllowedFigureMove validateMove(Move move);
};


class FigureKing {
    AllowedFigureMove validateMove(Move move);
};

