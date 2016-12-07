#ifndef INCLUDE_FIGUREKING_HPP_
#define INCLUDE_FIGUREKING_HPP_

#include <set>
#include "Figure.hpp"

class FigureKing : public Figure  {
public:
    FigureKing(FigureColour colour);
    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
    virtual std::set<Position> getPossibleMoves(Position start);
};


#endif

