#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Figure.hpp"

class Move;

class Player {
  public:
  Player(const char* name, FigureColour colour);
  FigureColour getColour();
  const char* getName();
  virtual Move getMove() = 0;
  virtual Position getPosition() = 0;

private:
  const char* m_name;
  FigureColour m_colour;

};

#endif
