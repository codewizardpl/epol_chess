#ifndef INITIAL_CHESS_BOARD_SETUP_HPP
#define INITIAL_CHESS_BOARD_SETUP_HPP

#include "Board.hpp"

class InitialChessBoardSetup {
public:
    static const Board getBoard();
    static void setBoard(Board& board);
};

#endif

