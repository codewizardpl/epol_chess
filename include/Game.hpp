#ifndef GAME_HPP
#define GAME_HPP
#include "Board.hpp"

class Game {
    Board board;
public:
    Game(){};
    virtual void setupBoard(){};
    virtual void run(){};
};

#endif
