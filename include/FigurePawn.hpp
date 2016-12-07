#ifndef INCLUDE_FIGUREPAWN_HPP_
#define INCLUDE_FIGUREPAWN_HPP_


#include "Figure.hpp"


class FigurePawn : public Figure {
public:
    FigurePawn(FigureColour colour);
    virtual FigurePath validateMove(Move move, FigureMoveType moveType);
    virtual std::set<Position> getPossibleMoves(Position start);
private:
    bool isStep(Move move);
    bool isDoubleStep(Move move);
    bool isLeftStrike(Move move);
    bool isRightStrike(Move move);
    bool isFromBaseline(Move move);
    int forwardDirection();
};


#endif

