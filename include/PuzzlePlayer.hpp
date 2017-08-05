#ifndef PUZZLE_PLAYER_HPP
#define PUZZLE_PLAYER_HPP

#include "Figure.hpp"
#include "Move.hpp"

class PuzzlePlayer {
public:
    virtual void placeQueen() = 0;
};

#endif
