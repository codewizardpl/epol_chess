/*
 * Position.hpp
 *
 *  Created on: 5 gru 2016
 *      Author: student
 */

#ifndef INCLUDE_POSITION_HPP_
#define INCLUDE_POSITION_HPP_

class Position
{
public:
    Position(int horizontal, int vertical) : m_horizontal(horizontal), m_vertical(vertical) {}

    int getHorizontal() { return m_horizontal; }
    int getVertical() { return m_vertical; }

    Position operator-(const Position &other) const
    {
        return Position(m_horizontal - other.m_horizontal,
                        m_vertical - other.m_vertical);
    }

    Position operator+(const Position &other) const
    {
        return Position(m_horizontal + other.m_horizontal,
                        m_vertical + other.m_vertical);
    }

    bool operator==(const Position &other) const
    {
        return m_horizontal == other.m_horizontal &&
               m_vertical == other.m_vertical;
    }

private:
    int m_horizontal;
    int m_vertical;
};

#endif /* INCLUDE_POSITION_HPP_ */
