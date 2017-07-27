#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board() {
    cout << "Board is ready!" << endl;
    m_figures.resize(size);
}

int Board::calcIndex(const Position& position) const {
    return position.getHorizontal() + 8*position.getVertical();
}

Figure& Board::get(const Position& position) {
    int index = calcIndex(position);

    return *m_figures[index];
}

unique_ptr<Figure> Board::remove(const Position& position) {
    int index = calcIndex(position);

    return unique_ptr<Figure>(move(m_figures[index]));
}

void Board::set(const Position& position, Figure *fig) {
    int index = calcIndex(position);

    m_figures[index] = move(unique_ptr<Figure>(fig)); //.reset(fig);
}

void Board::moveFigure(Move move) {
    unique_ptr<Figure> tmpFig = remove(move.getStart());

    m_figures[calcIndex(move.getStop())] = std::move(tmpFig);
}
