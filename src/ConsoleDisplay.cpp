#include "ConsoleDisplay.hpp"
#include "FigureSymbol.hpp"
#include "PositionFormat.hpp"
#include <iostream>

using namespace std;

void ConsoleDisplay::show(const Board& board) {
    showVerticalPositionSymbolsRow();
    for (int row = 7; row >=0; row--)
        showBoardRow(board, row);
    showVerticalPositionSymbolsRow();
}

void ConsoleDisplay::showVerticalPositionSymbolsRow() {
    cout << "+";
    cout << " ";
    for (int column=0; column<=7; column++) {
        cout << PositionFormat::formatColumnPosition(column);
        cout << " ";
    }
    cout << "+";
    cout << endl;
}

void ConsoleDisplay::showBoardRow(const Board& board, const int row) {
    cout << PositionFormat::formatRowPosition(row);
    cout << " ";
    for (int column = 0; column < 8; column++) {
        const Position position(column, row);
        const Figure figure = board.get(position);
        cout << FigureSymbol::get(figure) << " ";
    }
    cout << PositionFormat::formatRowPosition(row);
    cout << endl;
}

