#ifndef CHESSGAME_HPP
#define CHESSGAME_HPP
#include "Board.hpp"

class ChessGame {
    Board board;
public:
    ChessGame();
    void setupBoard();
    void run();
};

#endif
