#include <iostream>
#include "Board.hpp"
#include "Game.hpp"
#include "PuzzleGame.hpp"
#include "ChessGame.hpp"
#include "PuzzleGame.hpp"
#include "FigureBishop.hpp"

using namespace std;

int main() {

    int selection;
    cout << "Select game:" << endl;
    cout << "    1: Chess" << endl;
    cout << "    2: Puzzle" << endl;
    cin >> selection;
    
    Game *game;
    switch (selection) {
        case 1: 
            game = new ChessGame();
            break;
        case 2:
            game = new PuzzleGame();
            break;
        default:
            game = new ChessGame();
    }
    game->run();
    delete game;
    
    return 0;
}

