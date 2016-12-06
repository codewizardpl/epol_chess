#include <stdexcept>
#include "FigurePawn.hpp"


FigurePawn::FigurePawn(FigureColour colour) : Figure(FigureType::Pawn, colour)
{
}


FigurePath FigurePawn::validateMove(Move move, FigureMoveType moveType)
{

    switch(moveType)
    {
        case FigureMoveType::Strike:
            if (isLeftStrike(move) || isRightStrike(move))
                return FigurePath(true);

        case FigureMoveType::Move:
            if (isStep(move))
                return FigurePath(true);
            else if (isFromBaseline(move) && isDoubleStep(move))
                return FigurePath(true).addStep(move.getStart()+Position(0, forwardDirection()));
    }

    return FigurePath(false);
}


bool FigurePawn::isStep(Move move)
{
    Position step = Position(0, forwardDirection());
    return move.getRelative() == step;
}


bool FigurePawn::isDoubleStep(Move move)
{
    Position doubleStep = Position(0, 2*forwardDirection());
    return move.getRelative() == doubleStep;
}


bool FigurePawn::isLeftStrike(Move move)
{
    Position leftStrike =  Position(-1, forwardDirection());
    return move.getRelative() == leftStrike;
}


bool FigurePawn::isRightStrike(Move move)
{
    Position rightStrike = Position(1, forwardDirection());
    return move.getRelative() == rightStrike;
}


bool FigurePawn::isFromBaseline(Move move)
{
    switch(getColour())
    {
        case FigureColour::White: return move.getStart().getVertical() == 1;
        case FigureColour::Black: return move.getStart().getVertical() == 6;
    }
    throw std::invalid_argument("unknown colour"); 
}


int FigurePawn::forwardDirection() {
    switch(getColour())
    {
        case FigureColour::White: return 1;
        case FigureColour::Black: return -1;
    }
    throw std::invalid_argument("unknown colour"); 
}

