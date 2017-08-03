#ifndef BOARD_HPP
#define BOARD_HPP

#include "Figure.hpp"
#include "Position.hpp"

class Board {

public:
    static const int WIDTH = 8;
    static const int HEIGHT = 8;

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
    Figure figures[WIDTH][HEIGHT];
};

#endif
