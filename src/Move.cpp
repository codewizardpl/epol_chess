#include "Move.hpp"

Move::Move(const Position& _start, const Position& _stop):
    start(_start),
    stop(_stop)
{}

Move::Move():
    Move(Position(0,0), Position(0,0))
{}

const Position Move::getStart() const {
    return start;
}

const Position Move::getStop() const {
    return stop;
}

