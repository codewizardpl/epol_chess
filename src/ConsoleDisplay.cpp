#include "ConsoleDisplay.hpp"
#include "FigureSymbol.hpp"
#include <iostream>

using namespace std;

void ConsoleDisplay::show(const Board &board) {
    cout << "+ a b c d e f g h +" << endl;
    for (int height = 7; height >=0; --height) {
        cout << height+1 << " ";
        for (int width  = 0; width < 8; ++width) {
            const Position position(width, height);
            const Figure figure = board.get(position);
            cout << FigureSymbol::get(figure) << " ";
        }
        cout << height +1 << endl;
    }
    cout << "+ a b c d e f g h +" << endl;

}

