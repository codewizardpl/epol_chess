#ifndef PUZZLE_LOGIC_HPP
#define PUZZLE_LOGIC_HPP

#include "Figure.hpp"

class Board;
class Player;
class Position;

class PuzzleLogic {
public: PuzzleLogic() {};
  void setFigure(Board& board, Player& player, FigureType figure);
private:
  
  bool validatePosition(Board& board, Player& player, Position& position, Figure* figure);
  void updateBoard(Board& board, Position& position, Figure* figure);
};

#endif
