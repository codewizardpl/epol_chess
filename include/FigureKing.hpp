/*
 * FigureKing.hpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#ifndef INCLUDE_FIGUREKING_HPP_
#define INCLUDE_FIGUREKING_HPP_

#include "Figure.hpp"

class FigureKing : public Figure  {
public:
    FigureKing(FigureColour colour);
    virtual ~FigureKing();

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};

#endif /* INCLUDE_FIGUREKING_HPP_ */
