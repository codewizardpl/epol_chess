#include "ConsoleChessPlayer.hpp"
#include "ConsoleDisplay.hpp"
#include "PositionFormat.hpp"
#include "IllegalMoveException.hpp"
#include <iostream>

using namespace std;

ConsoleChessPlayer::ConsoleChessPlayer(
        const shared_ptr<Chess> _chess,
        const FigureColour& _colour):
    chess(_chess),
    colour(_colour) {
}

void ConsoleChessPlayer::makeMove() {
    while (1) {
        try {

            ConsoleDisplay display;
            display.show(chess->getBoard());

            cout << getName() << " move:";
            string start;
            cin >> start;
            string end;
            cin >> end;
            Move move(
                    PositionFormat::parsePosition(start),
                    PositionFormat::parsePosition(end));

            chess->performMove(move);
            return;
        } catch (IllegalMoveException ex) {
            cout << "Bad move: ";
            cout << ex.getReason() << endl;
            cout << "Try again";
        }
    }
}

string ConsoleChessPlayer::getName() {
    switch(colour) {
        case FigureColour::White:
            return "white player";
        case FigureColour::Black:
            return "black player";
    }
}

