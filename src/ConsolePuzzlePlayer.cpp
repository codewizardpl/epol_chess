#include "ConsolePuzzlePlayer.hpp"
#include "ConsoleDisplay.hpp"
#include "PositionFormat.hpp"
#include "IllegalMoveException.hpp"
#include <string>
#include <iostream>

using namespace std;

ConsolePuzzlePlayer::ConsolePuzzlePlayer(
        const shared_ptr<Puzzle> _puzzle):
    puzzle(_puzzle) {
}

void ConsolePuzzlePlayer::placeQueen() {
    while(1) {
        try {
            ConsoleDisplay display;
            display.show(puzzle->getBoard());

            string input;
            cin >> input;
            Position position(PositionFormat::parsePosition(input));

            puzzle->placeQueen(position);
            return;
        } catch (IllegalMoveException ex) {
            cout << "Bad position: ";
            cout << ex.getReason() << endl;
            cout << "Try again";
        }
    }
}

