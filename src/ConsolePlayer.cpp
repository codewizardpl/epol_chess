#include <iostream>

#include "ConsolePlayer.hpp"
#include "Move.hpp"
#include "Position.hpp"

using namespace std;

ConsolePlayer::ConsolePlayer(const char* name):
    Player(name)
{}

Move ConsolePlayer::getMove() {
    cout << getName() << " move:";
    string start, end;
    cin >> start >> end;
    return Move(parsePosition(start), parsePosition(end));
}

Position ConsolePlayer::getPosition() {
    cout << getName() << " figure position:";
    string position;
    cin >> position;
    return parsePosition(position);
}

Position ConsolePlayer::parsePosition(string input) {
    char x, y;
    sscanf(input.c_str(), "%c%c", &x, &y);
    return Position(x-'a', y-'1');
}
