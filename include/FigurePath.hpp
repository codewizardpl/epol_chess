#ifndef FIGUREPATH 
#define FIGUREPATH


#include <vector>
#include "Position.hpp"


class FigurePath
{
private:
    bool legal;
    std::vector<Position> steps;
public:
    FigurePath();
    FigurePath(bool legal);
    FigurePath &addStep(Position step);
    int getLength();
    Position getStep(int index);
    void setLegal();
    bool isLegal();
};


#endif
