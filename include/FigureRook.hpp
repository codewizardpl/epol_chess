/*
 * FigureRook.hpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#ifndef INCLUDE_FIGUREROOK_HPP_
#define INCLUDE_FIGUREROOK_HPP_

#include "Figure.hpp"

class FigureRook : public Figure  {
public:
    FigureRook(FigureColour colour);
    ~FigureRook();

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};

#endif /* INCLUDE_FIGUREROOK_HPP_ */
