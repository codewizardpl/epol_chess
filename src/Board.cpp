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

unique_ptr<Figure> Board::remove(int x, int y) {
    int index = calcIndex(x, y);

    return unique_ptr<Figure>(move(m_figures[index]));
}

void Board::set(int x, int y, Figure *fig) {
    int index = calcIndex(x, y);

    m_figures[index] = move(unique_ptr<Figure>(fig)); //.reset(fig);
}

void Board::moveFigure(Move m) {
    int startCol = m.getStart().getHorizontal(); // column
    int startRow = m.getStart().getVertical(); // row

    unique_ptr<Figure> tmpFig = remove(startCol, startRow);

    int stopCol = m.getStop().getHorizontal(); // column
    int stopRow = m.getStop().getVertical(); // row

    m_figures[calcIndex(stopCol, stopRow)] = move(tmpFig);
}
