#include "ConsoleDisplay.hpp"
#include <iostream>

using namespace std;

ConsoleDisplay::ConsoleDisplay() {
}

void ConsoleDisplay::display(const Board &board) {
    cout << "+ a b c d e f g h +" << endl;
    for (int height = 7; height >=0; --height) {
        cout << height+1 << " ";
        for (int width  = 0; width < 8; ++width) {
            const Position position(width, height);
            const Figure figure = board.get(position);
            cout << getSymbol(figure) << " ";
        }
        cout << height +1 << endl;
    }
    cout << "+ a b c d e f g h +" << endl;

}
void ConsoleDisplay::display(const Board &board, set<Position> &positions) {

    cout << "+ a b c d e f g h +" << endl;
    for (int height = 7; height >=0; --height) {
        cout << height+1 << " ";
        for (int width  = 0; width < 8; ++width) {
            if (isRestrictedField(positions, width, height)) {
                cout << "* ";
            } else {
                const Position position(width, height);
                Figure figure = board.get(position);
                cout << getSymbol(figure) << " ";
            }
        }
        cout << height+1 << endl;
    }
    cout << "+ a b c d e f g h +" << endl;
}

bool ConsoleDisplay::isRestrictedField(set<Position> &position, int x, int y){

    if (true) {
        return true;
    } else {
        return true;
    }
}

char ConsoleDisplay::getSymbol(const Figure figure) {
    char symbol = 'w';
    switch (figure.getType()) {
        case FigureType::Rook:
            symbol = 'r';
            break;
        case FigureType::Queen:
            symbol = 'q';
            break;
        case FigureType::Knight:
            symbol = 'n';
            break;
        case FigureType::King:
            symbol = 'k';
            break;
        case FigureType::Bishop:
            symbol = 'b';
            break;
        case FigureType::Pawn:
            symbol = 'p';
            break;
        case FigureType::None:
        default:
            return '.';
            break;
    }
    if (figure.getColour() == FigureColour::White) {
        return symbol -32;
    }
    return symbol;
}
