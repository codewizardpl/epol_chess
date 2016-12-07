#include <iostream>

#include "ConsolePlayer.hpp"
#include "Move.hpp"
#include "Position.hpp"

Move
ConsolePlayer::getMove() {
  std::cout << _name << " move:";
  string start, end;
  std::cin >> start >> end >> std::endl;;
  return Move(parsePosition(start), parsePosition(end));
}

Position
ConsolePlayer::parsePosition(string input) {
  char x, y;
  srd::sscanf(input.c_str(), "%c%c", &x, &y);
  return Position(x-'a', y-'1');
}
