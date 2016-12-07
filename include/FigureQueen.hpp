/*
 * FigureQueen.hpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#ifndef INCLUDE_FIGUREQUEEN_HPP_
#define INCLUDE_FIGUREQUEEN_HPP_

#include "Figure.hpp"

class FigureQueen : public Figure  {
public:
    FigureQueen(FigureColour colour);
    ~FigureQueen();

    virtual FigurePath validateMove(Move _move, FigureMoveType _moveType);
};

#endif /* INCLUDE_FIGUREQUEEN_HPP_ */
