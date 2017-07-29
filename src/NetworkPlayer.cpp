#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#include "NetworkPlayer.hpp"
#include "Move.hpp"
#include "Position.hpp"
#include "move.pb.h"

NetworkPlayer::NetworkPlayer(const char* name):
    Player(name)
{};

Move NetworkPlayer::getMove() {
    std::cout << getName() << " move:";
    std::string start, end;
    std::cin >> start >> end;
    return Move(parsePosition(start), parsePosition(end));
}

Position NetworkPlayer::getPosition() {
    std::cout << getName() << " figure position:";
    std::string position;
    std::cin >> position;
    return parsePosition(position);
}

Position NetworkPlayer::parsePosition(std::string input) {
    char x, y;
    std::sscanf(input.c_str(), "%c%c", &x, &y);
    return Position(x-'a', y-'1');
}
