#ifndef PUZZLEGAME_HPP
#define PUZZLEGAME_HPP

#include "Board.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Position.hpp"
#include <set>

class PuzzleGame: public Game {
    
public:
    virtual void run();

private:
    bool validatePosition(Position& position);

    bool validateDirection(
        const Position& current,
        const Position& step);

    bool validateCoordinates(const Position& position);

    Board board;
};

#endif
