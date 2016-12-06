#ifndef POSITION
#define POSITION


#include <vector>
#include "Position.hpp"


class FigurePath
{
private:
    bool legal;
    std::vector<Position> steps;
public:
    FigurePath();
    void addPosition(Position _position);
    int getLength();
    Position getStep(int _index);
    void setLegal();
    bool isLegal();
};


#endif
