#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board() {
}

int Board::calcIndex(const Position& position) const {
    return position.getHorizontal() +
        WIDTH * position.getVertical();
}

bool Board::hasFigure(const Position& position) const {
    return getFigure(position) != FigureType::None;
}

FigureType Board::getFigure(const Position& position) const {
    int index = calcIndex(position);
    return m_figures[index].getType();
}

FigureColour Board::getFigureColour(const Position& position) const {
    int index = calcIndex(position);
    return m_figures[index].getColour();
}

Figure Board::get(const Position& position) const {
    int index = calcIndex(position);
    return m_figures[index];
}

void Board::set(const Position& position, Figure fig) {
    int index = calcIndex(position);
    m_figures[index] = fig;
}

void Board::moveFigure(Move move) {
    Figure tmpFig = get(move.getStart());
    set(move.getStop(), tmpFig);
    set(move.getStart(), Figure(FigureType::None, FigureColour::None));
}

