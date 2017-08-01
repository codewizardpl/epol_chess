#ifndef CONSOLE_DISPLAY_HPP
#define CONSOLE_DISPLAY_HPP

#include <set>
#include "Board.hpp"
#include "Figure.hpp"
#include "Position.hpp"

class ConsoleDisplay {

public:
    void show(const Board &board);
};

#endif
