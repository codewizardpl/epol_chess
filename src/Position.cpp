#include "Position.hpp"

Position::Position(const int _horizontal, const int _vertical):
    horizontal(_horizontal),
    vertical(_vertical)
{}

int Position::getHorizontal() const {
    return horizontal;
}

int Position::getVertical() const {
    return vertical;
}

Position Position::operator-(const Position &other) const {
    return Position(horizontal - other.horizontal,
                    vertical - other.vertical);
}

Position Position::operator+(const Position &other) const {
    return Position(horizontal + other.horizontal,
                    vertical + other.vertical);
}

bool Position::operator==(const Position &other) const {
    return horizontal == other.horizontal &&
           vertical == other.vertical;
}

bool Position::operator<(const Position &other) const {
    int v1 = horizontal * 8 + vertical;
    int v2 = other.horizontal * 8 + other.vertical;
    return v1 < v2;
}

std::ostream& operator<<(std::ostream& out, const Position& position) {
    out << "[";
    out << position.getHorizontal();
    out <<  ",";
    out << position.getVertical();
    out << "]";
    return out;
}

