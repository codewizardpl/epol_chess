#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include "Position.hpp"
#include "Board.hpp"
class Puzzle {
public:
    Puzzle();
    int getQueensToPlace() const;
    const Board getBoard() const;
    void placeQueen(const Position& position);

private:
    bool validatePosition(const Position& position);

    bool validateDirection(
        const Position& current,
        const Position& step);

    bool validateCoordinates(const Position& position);

    Board board;
    int queensToPlace;
};

#endif
