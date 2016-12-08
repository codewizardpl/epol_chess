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
#include "Move.hpp"
#include <string>

class Position;

class NetworkPlayer: public Player {
public:
	NetworkPlayer(const char* name, FigureColour colour);

	Move getMove();
	void putMove(Move oponent) { m_oponent_move = oponent; };

  Position getPosition();

private:
  Position parsePosition(std::string input);
  Move m_oponent_move;
};

#endif /* INCLUDE_NETWORKPLAYER_HPP_ */
