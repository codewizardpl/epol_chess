#ifndef CONSOLE_DISPLAY
#define CONSOLE_DISPLAY
#include "Board.hpp"
#include "Figure.hpp"

class ConsoleDisplay
{
public:
	ConsoleDisplay();
        void Display(Board board);
private:
        char GetSymbol(/*Figure &figure*/);
};
#endif
