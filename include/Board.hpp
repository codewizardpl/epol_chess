#include "Figure.hpp"
#include "Move.hpp"
#include <vector>
#include <memory>

using namespace std;

class Board
{
  private:
     const int size = 8*8;
     vector<unique_ptr<Figure> > m_figures;

     int calcIndex(int x, int y);
     Figure* getAndRemove(int x, int y);

  public:
    Board();

    Figure& get(int x, int y);
    void set(int x, int y, Figure *fig);

    void moveFigure(Move m);
};

