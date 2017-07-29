#ifndef CONSOLE_PLAYER_HPP
#define CONSOLE_PLAYER_HPP

#include "Player.hpp"
#include "Figure.hpp"
#include "Move.hpp"
#include <string>

class Position;

class ConsolePlayer: public Player {
public:
  ConsolePlayer(const char* name);

  Move getMove();
  void putMove(Move oponent) { (void)oponent; };

  Position getPosition();

private:
  Position parsePosition(std::string input);
};

#endif
