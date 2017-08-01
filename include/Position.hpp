#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

class Position {

public:
    Position(const int _column, const int _row);

    int getColumn() const;

    int getRow() const;

    Position operator-(const Position &other) const;

    Position operator+(const Position &other) const;

    bool operator==(const Position &other) const;

    //bool operator<(const Position &other) const;

private:
    int column;
    int row;
};

std::ostream& operator<<(std::ostream& out, const Position& position);

#endif

