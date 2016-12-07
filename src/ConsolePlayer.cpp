#include <iostream>

#include "ConsolePlayer.hpp"
#include "Move.hpp"
#include "Position.hpp"

Move
ConsolePlayer::getMove() {
  std::cout << getName() << " move:";
  std::string start, end;
  std::cin >> start >> end;
  return Move(parsePosition(start), parsePosition(end));
}

Position
ConsolePlayer::parsePosition(std::string input) {
  char x, y;
  std::sscanf(input.c_str(), "%c%c", &x, &y);
  return Position(x-'a', y-'1');
}
