#ifndef MOVE_HPP
#define MOVE_HPP

#include "Position.hpp"

class Move {

public:
    Move(const Position& _start, const Position& _stop);
    Move();

    const Position getStart() const;
    const Position getStop() const;

private:
    Position start;
    Position stop;
};

#endif

