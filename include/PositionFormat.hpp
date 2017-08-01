#ifndef POSITIONFORMAT_HPP
#define POSITIONFORMAT_HPP

#include "Position.hpp"
#include <string>

class PositionFormat {
public:
    static std::string formatPosition(const Position& position);
    static std::string formatColumnPosition(const int columnPosition);
    static std::string formatRowPosition(const int horizontalPosition);
    static Position parsePosition(const std::string& s);
    static int parseColumnPosition(const std::string& s);
    static int parseRowPosition(const std::string& s);
};

#endif
