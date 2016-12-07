#ifndef INCLUDE_FIGUREKNIGHT_HPP_
#define INCLUDE_FIGUREKNIGHT_HPP_


#include "Figure.hpp"


class FigureKnight : public Figure  {
public:
    FigureKnight(FigureColour colour);
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
    virtual std::set<Position> getPossibleMoves(Position start);
};


#endif

