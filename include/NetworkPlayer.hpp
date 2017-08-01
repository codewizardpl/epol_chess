#ifndef INCLUDE_NETWORKPLAYER_HPP_
#define INCLUDE_NETWORKPLAYER_HPP_

#include "Player.hpp"
#include "Figure.hpp"
#include "Move.hpp"
#include <string>

class NetworkPlayer: public Player {
public:
    NetworkPlayer(const char* name);
    Move getMove();
    Position getPosition();

private:
    Position parsePosition(std::string input);
    Move m_oponent_move;
};

#endif
