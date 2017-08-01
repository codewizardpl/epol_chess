#ifndef CONSOLE_PLAYER_HPP
#define CONSOLE_PLAYER_HPP

#include "Player.hpp"
#include "Position.hpp"
#include "Move.hpp"

class ConsolePlayer: public Player {
public:
    ConsolePlayer(const char* name);
    Move getMove();
    Position getPosition();
};

#endif
