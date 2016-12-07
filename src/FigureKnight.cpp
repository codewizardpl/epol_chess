/*
 * FigureKinght.cpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#include "FigureKnight.hpp"


FigureKnight::FigureKnight(FigureColour colour) : Figure(FigureType::Knight, colour)
{ };

FigureKnight::~FigureKnight() {}

FigurePath FigureKnight::validateMove(Move _move, FigureMoveType _moveType)
{
	return FigurePath(false);
}




