/*
 * FigureBishop.hpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#ifndef INCLUDE_FIGUREBISHOP_HPP_
#define INCLUDE_FIGUREBISHOP_HPP_

#include "Figure.hpp"

class FigureBishop : public Figure  {
public:
    FigureBishop(FigureColour colour);
    ~FigureBishop();

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};

#endif /* INCLUDE_FIGUREBISHOP_HPP_ */
