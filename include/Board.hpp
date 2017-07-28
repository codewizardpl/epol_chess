#ifndef BOARD
#define BOARD

#include <vector>
#include <memory>
#include "Figure.hpp"
#include "Move.hpp"
#include "Position.hpp"

class Board {

public:
    const int WIDTH = 8;
    const int HEIGHT = 8;

    Board();

    bool hasFigure(const Position& position) const;
    FigureType getFigure(const Position& position) const;
    FigureColour getFigureColour(const Position& position) const;

    //void setEmpty(const Position& position)

    Figure get(const Position& position) const;
    void set(const Position& position, Figure fig);

    void moveFigure(Move move);

private:
    Figure m_figures[64];
    int calcIndex(const Position& position) const;
};

#endif
