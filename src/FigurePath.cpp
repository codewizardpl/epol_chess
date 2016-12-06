#include "FigurePath.hpp"


FigurePath::FigurePath() : legal(false)
{ }


void FigurePath::addPosition(Position _position)
{
    steps.push_back(_position);
}


int FigurePath::getLength()
{
    return steps.size();
}


Position FigurePath::getStep(int _index)
{
    return steps[_index];
}


void FigurePath::setLegal()
{
    legal = true;
}


bool FigurePath::isLegal()
{
    return legal;
}

