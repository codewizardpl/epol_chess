#include "Puzzle.hpp"
#include "IllegalMoveException.hpp"

Puzzle::Puzzle():
        queensToPlace(8) {
}

const Board Puzzle::getBoard() const {
    return board;
}

int Puzzle::getQueensToPlace() const {
    return queensToPlace;
}

void Puzzle::placeQueen(const Position& position) {
    if (queensToPlace == 0) {
        throw IllegalMoveException("all queens placed");
    }
    if (!validateCoordinates(position)) {
        throw IllegalMoveException("invalid position");
    }
    if (!validatePosition(position)) {
        throw IllegalMoveException("invalid position");
    }
    Figure queenFigure(FigureType::Queen, FigureColour::White);
    board.set(position, queenFigure);
    queensToPlace--;
}

bool Puzzle::validatePosition(const Position& position) {
    return
        board.isEmpty(position) &&
        validateDirection(position, Position(1,0)) &&
        validateDirection(position, Position(1,1)) &&
        validateDirection(position, Position(0,1)) &&
        validateDirection(position, Position(-1,1)) &&
        validateDirection(position, Position(-1,0)) &&
        validateDirection(position, Position(-1,-1)) &&
        validateDirection(position, Position(0,-1)) &&
        validateDirection(position, Position(1,-1));
}

bool Puzzle::validateDirection(
        const Position& current,
        const Position& step) {
    const Position next = current + step;
    return
        !validateCoordinates(next) ||
        (board.isEmpty(next) && validateDirection(next, step));
}

bool Puzzle::validateCoordinates(const Position& position) {
    return position.getColumn() >=0 && position.getColumn() < 8 &&
           position.getRow()>= 0 && position.getRow() < 8;
}

