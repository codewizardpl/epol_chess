#include "ConsoleDisplay.hpp"
#include <iostream>


ConsoleDisplay::ConsoleDisplay()
{

}

ConsoleDisplay::ConsoleDisplay(Board board){
    using namespace std;
    for (int high = 0; high <8; ++high) {
        for (int width = 0; width < 8; ++width) {
            cout <<"";
        }
    }
}
