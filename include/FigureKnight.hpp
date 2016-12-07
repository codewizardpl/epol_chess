/*
 * FigureKnight.hpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#ifndef INCLUDE_FIGUREKNIGHT_HPP_
#define INCLUDE_FIGUREKNIGHT_HPP_

#include "Figure.hpp"

class FigureKnight : public Figure  {
public:
    FigureKnight(FigureColour colour);
    virtual ~FigureKnight();

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};


#endif /* INCLUDE_FIGUREKNIGHT_HPP_ */
