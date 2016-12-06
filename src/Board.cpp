#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board() {
    cout << "Board is ready!" << endl;
    m_figures.resize(size);
}

int Board::calcIndex(int x, int y) {
    return x + 8*y;
}

Figure& Board::get(int x, int y) {
    int index = calcIndex(x, y);

    return *m_figures[index].get();
}

Figure* Board::getAndRemove(int x, int y) {
    int index = calcIndex(x, y);

    return m_figures[index].release();
}

void Board::set(int x, int y, Figure *fig) {
    int index = calcIndex(x, y);

    m_figures[index].reset(fig);
}

void Board::moveFigure(Move m) {
    int startCol = m.getStart().getHorizontal(); // column
    int startRow = m.getStart().getVertical(); // row

    Figure* tmpFig = getAndRemove(startCol, startRow);

    int stopCol = m.getStop().getHorizontal(); // column
    int stopRow = m.getStop().getVertical(); // row

    set(stopCol, stopRow, tmpFig);
}
