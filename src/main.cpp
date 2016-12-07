#include <iostream>
#include "Board.hpp"
#include "ChessGame.hpp"
#include "PuzzleGame.hpp"

int main() {

    // ChessGame game;
  PuzzleGame game;
  game.setupBoard();
   game.run();
  
    
    return 0;
}

