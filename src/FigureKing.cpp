/*
 * FigureKing.cpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#include "FigureKing.hpp"


FigureKing::FigureKing(FigureColour colour) : Figure(FigureType::King, colour) { }

FigureKing::~FigureKing() {}

FigurePath FigureKing::validateMove(Move _move, FigureMoveType _moveType)
{
	return FigurePath(false);
}



