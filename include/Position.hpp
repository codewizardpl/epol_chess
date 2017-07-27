#ifndef INCLUDE_POSITION_HPP_
#define INCLUDE_POSITION_HPP_

#include <iostream>

class Position {

public:
    Position(const int _horizontal, const int _vertical);

    int getHorizontal() const;

    int getVertical() const;

    Position operator-(const Position &other) const;

    Position operator+(const Position &other) const;

    bool operator==(const Position &other) const;

    bool operator<(const Position &other) const;

    bool validateCoordinates() const;

private:
    int horizontal;
    int vertical;

};

std::ostream& operator<<(std::ostream& out, const Position& position);

class PositionValidator
{
public:
	PositionValidator(int min_h, int max_h, int min_v, int max_v)
		: m_min_h(min_h), m_max_h(max_h), m_min_v(min_v), m_max_v(max_v)
	{}

	bool operator() (const Position& p)
	{
		return ((p.getHorizontal() >= m_min_h) &&
			    (p.getHorizontal() <= m_max_h) &&
			    (p.getVertical() >= m_min_v) &&
			    (p.getVertical() <= m_max_v));
	}

private:
	int m_min_h, m_max_h, m_min_v, m_max_v;

};

#endif
