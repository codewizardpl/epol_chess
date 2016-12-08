#include <iostream>

#include "ConsolePlayer.hpp"
#include "Move.hpp"
#include "Position.hpp"

ConsolePlayer::ConsolePlayer(const char* name, FigureColour colour) : Player(name, colour) {};

Move
ConsolePlayer::getMove() {
  std::cout << getName() << " move:";
  std::string start, end;
  std::cin >> start >> end;
  return Move(parsePosition(start), parsePosition(end));
}

Position
ConsolePlayer::getPosition() {
  std::cout << getName() << " figure position:";
  std::string position;
  std::cin >> position;
  return parsePosition(position);
}

Position
ConsolePlayer::parsePosition(std::string input) {
  char x, y;
  std::sscanf(input.c_str(), "%c%c", &x, &y);
  return Position(x-'a', y-'1');
}
