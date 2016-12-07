#include <iostream>
#include "Board.hpp"
#include "ChessGame.hpp"

int main() {

    ChessGame game;
    game.setupBoard();
    game.run();
    
    return 0;
}

