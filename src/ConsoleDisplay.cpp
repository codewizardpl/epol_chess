#include "ConsoleDisplay.hpp"
#include <iostream>


ConsoleDisplay::ConsoleDisplay()
{

}
ConsloleDisplay::Display(Board board){
    using::std;
    for (int high = 0; high <8; ++high) {
        for (int width = 0; width < 8; ++width) {
            board.get(high,width);
            cout <<"";
        }
        cout << endl;
    }
}
