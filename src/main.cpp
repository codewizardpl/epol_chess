#include <iostream>
#include "Board.hpp"
#include "Game.hpp"
#include "PuzzleGame.hpp"
#include "ChessGame.hpp"
#include "PuzzleGame.hpp"
#include "FigureBishop.hpp"

using namespace std;

enum class GameType {

    CHESS = 1,
    PUZZLE
};

std::istream& operator>>( std::istream& is, GameType& gt )
{
    int tmp ;
    if ( is >> tmp )
        gt = static_cast<GameType>( tmp ) ;
    return is ;
}
 
int main() {

    Game *game;
    GameType game_selected;
    cout << "Select game: Chess (1) or Puzzle (2)" << endl;
    cin >> game_selected;
    
    switch (game_selected){
        case GameType::CHESS: { game = new ChessGame(); break; }
        case GameType::PUZZLE: { game = new PuzzleGame(); break; }
        default: game = new ChessGame();
    }
    game->setupBoard();
    game->run();
    
    delete game;
    
    return 0;
}

