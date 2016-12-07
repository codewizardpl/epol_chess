#ifndef INCLUDE_POSITION_HPP_
#define INCLUDE_POSITION_HPP_


class Position
{

public:

    Position(int horizontal, int vertical) : m_horizontal(horizontal), m_vertical(vertical)
    {
    }

    int getHorizontal() const
    {
        return m_horizontal;
    }


    int getVertical() const
    {
        return m_vertical;
    }

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

    bool operator<(const Position &other) const
    {
        int v1 = m_horizontal * 8 + m_vertical;
        int v2 = other.m_horizontal * 8 + other.m_vertical;
        return v1 < v2;
    }

    bool validateCoordinates()
    {
        return m_horizontal >=0 && m_horizontal < 8 &&
               m_vertical >= 0 && m_vertical < 8;
    }

private:

    int m_horizontal;
    int m_vertical;

};

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

#endif /* INCLUDE_POSITION_HPP_ */
