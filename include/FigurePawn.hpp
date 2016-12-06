#ifndef FIGURE_PAWN
#define FIGURE_PAWN


#include "Figure.hpp"


class FigurePawn : public Figure {
public:
    FigurePawn(FigureColour colour);
    virtual FigurePath validateMove(Move move, FigureMoveType moveType);
private:
    bool isStep(Move move);
    bool isDoubleStep(Move move);
    bool isLeftStrike(Move move);
    bool isRightStrike(Move move);
    bool isFromBaseline(Move move);
    int forwardDirection();
};

#endif
