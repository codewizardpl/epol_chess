#include "Position.hpp"

Position::Position(const int _column, const int _row):
    column(_column),
    row(_row)
{}

int Position::getColumn() const {
    return column;
}

int Position::getRow() const {
    return row;
}

Position Position::operator-(const Position &other) const {
    return Position(column- other.column,
                    row - other.row);
}

Position Position::operator+(const Position &other) const {
    return Position(column + other.column,
                    row + other.row);
}

bool Position::operator==(const Position &other) const {
    return column == other.column &&
           row == other.row;
}
/*
bool Position::operator<(const Position &other) const {
    int v1 = column * 8 + row;
    int v2 = other.column * 8 + other.row;
    return v1 < v2;
}
*/
std::ostream& operator<<(std::ostream& out, const Position& position) {
    out << "[";
    out << position.getColumn();
    out <<  ",";
    out << position.getRow();
    out << "]";
    return out;
}

