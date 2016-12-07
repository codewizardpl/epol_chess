#ifndef CONSOLE_PLAYER_HPP
#define CONSOLE_PLAYER_HPP

#include "Player.hpp"
#include "Figure.hpp"
#include <string>

class Position;

class ConsolePlayer: public Player {
public:
  ConsolePlayer(const char* name, FigureColour colour) : Player(name, colour) {};
  Move getMove();
  Position getPosition();

private:
  Position parsePosition(std::string input);
};

#endif
