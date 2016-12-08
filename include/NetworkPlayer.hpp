/*
 * NetworkPlayer.hpp
 *
 *  Created on: 8 gru 2016
 *      Author: student
 */

#ifndef INCLUDE_NETWORKPLAYER_HPP_
#define INCLUDE_NETWORKPLAYER_HPP_

#include "Player.hpp"
#include "Figure.hpp"
#include <string>

class Position;

class NetworkPlayer: public Player {
public:
NetworkPlayer(const char* name, FigureColour colour) : Player(name, colour) {};
  Move getMove();
  Position getPosition();

private:
  Position parsePosition(std::string input);
};

#endif /* INCLUDE_NETWORKPLAYER_HPP_ */
