#ifndef CONSOLE_DISPLAY_HPP
#define CONSOLE_DISPLAY_HPP

#include <set>
#include "Board.hpp"
#include "Figure.hpp"
#include "Position.hpp"


class ConsoleDisplay
{
public:
	ConsoleDisplay();
        void Display(Board &board);
        void Display(Board &board, set<Position> position);
private:
        char GetSymbol(Figure &figure);
};
#endif
