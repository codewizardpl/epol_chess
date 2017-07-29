#ifndef POSITION_HPP
#define POSITION_HPP

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

private:
    int horizontal;
    int vertical;
};

std::ostream& operator<<(std::ostream& out, const Position& position);

#endif

