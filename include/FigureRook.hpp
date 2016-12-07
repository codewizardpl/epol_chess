#ifndef INCLUDE_FIGUREROOK_HPP_
#define INCLUDE_FIGUREROOK_HPP_


#include "Figure.hpp"


class FigureRook : public Figure  {
public:
    FigureRook(FigureColour colour);
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
    virtual std::set<Position> getPossibleMoves(Position start);
};


#endif

