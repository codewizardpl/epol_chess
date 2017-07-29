#include <iostream>
#include "Board.hpp"

using namespace std;

Figure Board::get(const Position& position) const {
    return figures[position.getVertical()][position.getHorizontal()];
}

void Board::set(const Position& position, Figure figure) {
    figures[position.getVertical()][position.getHorizontal()] = figure;
}

bool Board::isEmpty(const Position& position) const {
    return get(position).getType() == FigureType::None;
}

void Board::setEmpty(const Position& position) {
    set(position, Figure(FigureType::None, FigureColour::None));
}
