/*
 * FigureRook.cpp
 *
 *  Created on: 7 gru 2016
 *      Author: student
 */

#include "FigureRook.hpp"


FigureRook::FigureRook(FigureColour colour) : Figure(FigureType::Rook, colour) { };

FigureRook::~FigureRook()
{}

FigurePath FigureRook::validateMove(Move _move, FigureMoveType _moveType)
{
	return FigurePath(false);
}




