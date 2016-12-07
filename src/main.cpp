#include <iostream>
#include "Board.hpp"
#include "Game.hpp"
#include "PuzzleGame.hpp"
#include "ChessGame.hpp"

int main() {

    Game *game;
    int game_selected;
    cout << "Select game: Chess (1) or Puzzle (2)" << endl;
    cin >> game_selected;
    
    switch (game_selected){
        case 1: { game = new ChessGame(); break; }
        case 2: { game = new PuzzleGame(); break; }
        default: game = new ChessGame();
    }
    game->setupBoard();
    game->run();
    
    delete game;
    
    return 0;
}

