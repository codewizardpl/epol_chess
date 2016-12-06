#include "FigurePath.hpp"


FigurePath::FigurePath() : legal(false)
{ }


FigurePath::FigurePath(bool _legal) : legal(_legal)
{ }


FigurePath &FigurePath::addStep(Position step)
{
    steps.push_back(step);
    return *this;
}


int FigurePath::getLength()
{
    return steps.size();
}


Position FigurePath::getStep(int index)
{
    return steps[index];
}


void FigurePath::setLegal()
{
    legal = true;
}


bool FigurePath::isLegal()
{
    return legal;
}

