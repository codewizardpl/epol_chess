/*
 * FigureBishop.cpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#include "FigureBishop.hpp"

FigureBishop::FigureBishop(FigureColour colour) : Figure(FigureType::Bishop, colour) { };

FigureBishop::~FigureBishop() {}

FigurePath FigureBishop::validateMove(Move _move, FigureMoveType _moveType)
{
	return FigurePath(false);
}



