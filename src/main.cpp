#include <iostream>
#include "Board.hpp"
#include "Game.hpp"
#include "PuzzleGame.hpp"
#include "ChessGame.hpp"
#include "PuzzleGame.hpp"


#define    CHESS 1
#define    PUZZLE 2


int main() {


    Game *game;
    int game_selected;
    cout << "Select game: Chess (1) or Puzzle (2)" << endl;
    cin >> game_selected;
    
    switch (game_selected){
        case CHESS: { game = new ChessGame(); break; }
        case PUZZLE: { game = new PuzzleGame(); break; }
        default: game = new ChessGame();
    }
    game->setupBoard();
    game->run();
    
    delete game;

    
    return 0;
}

