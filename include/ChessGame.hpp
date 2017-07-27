#ifndef CHESSGAME_HPP
#define CHESSGAME_HPP
#include "Game.hpp"
#include "Board.hpp"

class ChessGame: public Game {
    
public:
    ChessGame();
    virtual ~ChessGame();
    virtual void run();

private:
    void setupBoard();
    Board board;
};

#endif
