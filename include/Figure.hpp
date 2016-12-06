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
protected:
    void setColour(FigureColour c) {
        colour = c;
    }

    void setType(FigureType t) {
        type = t;
    }

public:
    FigureColour getColour();
    FigureType getType();

    virtual AllowedFigureMove validateMove(Move move) = 0;
};


class FigurePawn : public Figure {
public:
    FigurePawn(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Pawn);
    }

    virtual AllowedFigureMove validateMove(Move move);
};


class FigureKnight : public Figure  {
public:
    FigureKnight(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Knight);
    }

    virtual AllowedFigureMove validateMove(Move move);
};


class FigureBishop : public Figure  {
public:
    FigureBishop(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Bishop);
    }

    virtual AllowedFigureMove validateMove(Move move);
};


class FigureRook : public Figure  {
public:
    FigureRook(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Rook);
    }

    virtual AllowedFigureMove validateMove(Move move);
};


class FigureQueen : public Figure  {
public:
    FigureQueen(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Queen);
    }

    virtual AllowedFigureMove validateMove(Move move);
};


class FigureKing : public Figure  {
public:
    FigureKing(FigureColour colour) {
        setColour(colour);
        setType(FigureType::King);
    }

    virtual AllowedFigureMove validateMove(Move move);
};


#endif
