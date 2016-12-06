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
    void setColour(FigureColour c) {
        colour = c;
    }

    void setType(FigureType t) {
        type = t;
    }

public:
    FigureColour getColour();
    FigureType getType();

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType) = 0;
};


class FigurePawn : public Figure {
public:
    FigurePawn(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Pawn);
    }

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureKnight : public Figure  {
public:
    FigureKnight(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Knight);
    }

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureBishop : public Figure  {
public:
    FigureBishop(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Bishop);
    }

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureRook : public Figure  {
public:
    FigureRook(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Rook);
    }

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureQueen : public Figure  {
public:
    FigureQueen(FigureColour colour) {
        setColour(colour);
        setType(FigureType::Queen);
    }

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureKing : public Figure  {
public:
    FigureKing(FigureColour colour) {
        setColour(colour);
        setType(FigureType::King);
    }

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


#endif
