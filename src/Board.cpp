#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board() {
}

Board::Board(const Board& other) {
    *this = other;
}

const Board& Board::operator=(const Board& other) {
    for (int w=0; w<WIDTH; w++)
        for (int h=0; h<HEIGHT; h++)
            figures[w][h] = other.figures[w][h];
    return *this;
}

bool Board::operator==(const Board& other) {
    for (int w=0; w<WIDTH; w++)
        for (int h=0; h<HEIGHT; h++)
            if (figures[w][h] != other.figures[w][h])
                return false;
    return true;
}

bool Board::operator!=(const Board& other) {
    return !(*this==other);
}

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
