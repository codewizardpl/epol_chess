#ifndef INCLUDE_MOVE_HPP_
#define INCLUDE_MOVE_HPP_

#include "Position.hpp"

class Move {

public:
    Move(const Position& _start, const Position& _stop);
    Move();

    const Position getStart() const;
    const Position getStop() const;

    const Position getRelative() const;
    bool validateCoordinates() const;

private:
    Position start;
    Position stop;
};


#endif
