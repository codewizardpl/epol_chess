#ifndef INCLUDE_FIGUREBISHOP_HPP_
#define INCLUDE_FIGUREBISHOP_HPP_


#include "Figure.hpp"


class FigureBishop : public Figure  {
public:
    FigureBishop(FigureColour colour);
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
    virtual std::set<Position> getPossibleMoves(Position start);
};


#endif

