#ifndef CHESSGAME_HPP
#define CHESSGAME_HPP
#include "Game.hpp"
#include "Board.hpp"

class ChessGame: public Game {
    Board board;
    
public:
    ChessGame();
    virtual ~ChessGame();
    virtual void setupBoard();
    virtual void run();
};

#endif
