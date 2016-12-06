#include "ConsoleDisplay.hpp"
#include <iostream>


ConsoleDisplay::ConsoleDisplay()
{

}

void ConsoleDisplay::Display(Board board) {
    for (int high = 0; high <8; ++high) {
        for (int width = 0; width < 8; ++width) {
            std::cout <<"";
        }
    }
}
