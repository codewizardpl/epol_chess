#include "Player.cpp"

Player::Player(const char* name, FigureColour colour) 
  : _name(name),
    _colour(colour)
{
}

FigureColour
Player::getColour() {
  return _colour;
}
