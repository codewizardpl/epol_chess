#ifndef BOARD
#define BOARD

#include <vector>
#include <memory>
#include "Figure.hpp"
#include "Move.hpp"

class Board {

public:
    Board();

    Figure& get(int x, int y);
    void set(int x, int y, Figure *fig);

    void moveFigure(Move m);

private:
     const int size = 8*8;
     std::vector<std::unique_ptr<Figure> > m_figures;

     int calcIndex(int x, int y);
     std::unique_ptr<Figure> remove(int x, int y);
};

#endif
