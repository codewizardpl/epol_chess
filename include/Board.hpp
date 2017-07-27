#ifndef BOARD
#define BOARD

#include <vector>
#include <memory>
#include "Figure.hpp"
#include "Move.hpp"
#include "Position.hpp"

class Board {

public:
    Board();

    Figure& get(const Position& position);
    void set(const Position& position, Figure *fig);

    void moveFigure(Move move);

private:
     const int size = 8*8;
     std::vector<std::unique_ptr<Figure> > m_figures;

     int calcIndex(const Position& position) const;
     std::unique_ptr<Figure> remove(const Position& position);
};

#endif
