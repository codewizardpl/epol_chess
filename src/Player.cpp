#include "Player.hpp"

Player::Player(const char* name, FigureColour colour) 
  : m_name(name),
    m_colour(colour)
{
}

FigureColour
Player::getColour() {
  return m_colour;
}

const char*
Player::getName() {
  return m_name;
}
