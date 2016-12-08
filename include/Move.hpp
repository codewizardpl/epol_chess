/*
 * Move.hpp
 *
 *  Created on: 5 gru 2016
 *      Author: student
 */

#ifndef INCLUDE_MOVE_HPP_
#define INCLUDE_MOVE_HPP_

#include "Position.hpp"

class Move
{
public:
	Move(Position start, Position stop)
		: m_start(start), m_stop(stop)
	{}
	Move() : Move(Position(0,0), Position(0,0))
	{}


	Position getStart() { return m_start; }
	Position getStop() { return m_stop; }

        Position getRelative() { return m_start - m_stop; }
        bool validateCoordinates() {return m_start.validateCoordinates() &&
                                            m_stop.validateCoordinates();};
private:

	Position m_start;
	Position m_stop;
};


#endif /* INCLUDE_MOVE_HPP_ */
