#include <iostream>
#include "Board.hpp"
#include "ConsoleDisplay.hpp"
#include "Game.hpp"
#include "PuzzleGame.hpp"
#include "ChessGame.hpp"
#include "Player.hpp"
#include "ConsolePlayer.hpp"
#include "NetworkPlayer.hpp"

using namespace std;

shared_ptr<ChessGame> setupChessGame() {
    shared_ptr<Player> whitePlayer;
    shared_ptr<Player> blackPlayer;

    string answer;
    cout <<  "Network player (y/n)?: ";
    cin >> answer;

    if (answer == "n") {
    	whitePlayer.reset(new ConsolePlayer("white player"));
    	blackPlayer.reset(new ConsolePlayer("black player"));
    } else {
    	cout <<  "Which side would you like to play (white/black)?: ";
    	cin >> answer;
    	if (answer == "white")
    	{
            whitePlayer.reset(new ConsolePlayer("white player"));
            blackPlayer.reset(new NetworkPlayer("black player"));
    	} else {
            whitePlayer.reset(new NetworkPlayer("white player"));
            blackPlayer.reset(new ConsolePlayer("black player"));
    	}
    }

    shared_ptr<ConsoleDisplay> consoleDisplay(new ConsoleDisplay());

    shared_ptr<ChessGame> chessGame(
            new ChessGame(whitePlayer, blackPlayer, consoleDisplay));

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


