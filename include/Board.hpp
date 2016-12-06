#include "Figure.hpp"

class Board
{
  private:
	Figure *m_figure;


  public:
    Board();

    Figure &get(int x, int y);
    void set(int x, int y, Figure &fig);
};

