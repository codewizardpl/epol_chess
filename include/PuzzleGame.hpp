#ifndef PUZZLEGAME_HPP
#define PUZZLEGAME_HPP
#include "Board.hpp"
#include "Game.hpp"

class PuzzleGame: public Game{
    
public:
    PuzzleGame();
    virtual ~PuzzleGame();
    virtual void run();

private:
    void setupBoard();
    Board board;
};

#endif
