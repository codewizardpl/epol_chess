#include "ChessGame.hpp"
#include <iostream>
#include <string>

using namespace std;

ChessGame::ChessGame(
        shared_ptr<ChessPlayer> _whitePlayer,
        shared_ptr<ChessPlayer> _blackPlayer):
    whitePlayer(_whitePlayer),
    blackPlayer(_blackPlayer) {
}

void ChessGame::run() {
    while (1) {
        whitePlayer->makeMove();
        blackPlayer->makeMove();
    }
}

