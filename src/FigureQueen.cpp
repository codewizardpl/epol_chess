/*
 * FigureQueen.cpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#include "FigureQueen.hpp"


FigureQueen::FigureQueen(FigureColour colour) : Figure(FigureType::Queen, colour) { };

FigureQueen::~FigureQueen() {}

FigurePath FigureQueen::validateMove(Move _move, FigureMoveType _moveType)
{
	return FigurePath(false);
}



