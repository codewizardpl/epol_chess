#ifndef INCLUDE_FIGUREQUEEN_HPP_
#define INCLUDE_FIGUREQUEEN_HPP_


#include "Figure.hpp"


class FigureQueen : public Figure  {
public:
    FigureQueen(FigureColour colour);
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
    virtual std::set<Position> getPossibleMoves(Position start);
};


#endif

