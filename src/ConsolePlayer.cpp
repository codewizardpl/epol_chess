#include "ConsolePlayer.hpp"
#include "PositionFormat.hpp"
#include <string>
#include <iostream>

using namespace std;

ConsolePlayer::ConsolePlayer(const char* name):
    Player(name) {
}

Move ConsolePlayer::getMove() {
    cout << getName() << " move:";
    string start, end;
    cin >> start >> end;
    return Move(
            PositionFormat::parsePosition(start),
            PositionFormat::parsePosition(end));
}

Position ConsolePlayer::getPosition() {
    cout << getName() << " figure position:";
    string position;
    cin >> position;
    return PositionFormat::parsePosition(position);
}

