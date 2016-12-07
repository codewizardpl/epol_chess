#ifndef PUZZLEGAME_HPP
#define PUZZLEGAME_HPP
#include "Board.hpp"
#include "Game.hpp"

class PuzzleGame: public Game{
    Board board;
    
public:
    PuzzleGame();
    virtual ~PuzzleGame();
    virtual void setupBoard();
    virtual void run();
};

#endif
