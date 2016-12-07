#ifndef INCLUDE_POSITION_HPP_
#define INCLUDE_POSITION_HPP_


class Position
{

public:

    Position(int horizontal, int vertical) : m_horizontal(horizontal), m_vertical(vertical)
    {
    }

    int getHorizontal()
    {
        return m_horizontal;
    }


    int getVertical()
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


#endif

