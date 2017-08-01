#ifndef BOARD_HPP
#define BOARD_HPP

#include "Figure.hpp"
#include "Position.hpp"

class Board {

public:
    const int WIDTH = 8;
    const int HEIGHT = 8;

    Board();
    Board(const Board& other);

    const Board& operator=(const Board& other);
    bool operator==(const Board& other);
    bool operator!=(const Board& other);

    Figure get(const Position& position) const;
    void set(const Position& position, Figure figure);

    bool isEmpty(const Position& position) const;
    void setEmpty(const Position& position);

private:
    Figure figures[8][8];
};

#endif
