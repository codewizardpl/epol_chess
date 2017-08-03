#include <iostream>
#include "Board.hpp"
#include "InitialChessBoardSetup.hpp"
#include "Game.hpp"
#include "PuzzleGame.hpp"
#include "ChessGame.hpp"
#include "ConsoleChessPlayer.hpp"

using namespace std;

shared_ptr<ChessGame> setupChessGame() {

    shared_ptr<Chess> chess(new Chess(
                InitialChessBoardSetup::getBoard(),
                FigureColour::White));

    shared_ptr<ChessPlayer> whitePlayer(new ConsoleChessPlayer(
                chess,
                FigureColour::White));

    shared_ptr<ChessPlayer> blackPlayer(new ConsoleChessPlayer(
                chess,
                FigureColour::Black));

    shared_ptr<ChessGame> chessGame(
            new ChessGame(whitePlayer, blackPlayer));

    return chessGame;
}

int main() {

    int selection;
    cout << "Select game:" << endl;
    cout << "    1: Chess" << endl;
    cout << "    2: Puzzle" << endl;
    cin >> selection;
    
    shared_ptr<Game> game;
    switch (selection) {
        default:
        case 1: 
            game = setupChessGame();
            break;
        case 2:
            game.reset(new PuzzleGame());
            break;
    }
    game->run();
    
    return 0;
}


