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

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType) = 0;
};


class FigureKnight : public Figure  {
public:
    FigureKnight(FigureColour colour) : Figure(FigureType::Knight, colour) { };
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureBishop : public Figure  {
public:
    FigureBishop(FigureColour colour) : Figure(FigureType::Bishop, colour) { };
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureRook : public Figure  {
public:
    FigureRook(FigureColour colour) : Figure(FigureType::Rook, colour) { };
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureQueen : public Figure  {
public:
    FigureQueen(FigureColour colour) : Figure(FigureType::Queen, colour) { };
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


class FigureKing : public Figure  {
public:
    FigureKing(FigureColour colour) : Figure(FigureType::King, colour) { };
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


#endif
