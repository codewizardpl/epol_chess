#include "PuzzleLogic.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Figure.hpp"
#include "Position.hpp"
#include <iostream>

void PuzzleLogic::setFigure(Board& board, Player& player, FigureType ) {
  Position position = player.getPosition();
  Figure* figure = new FigureQueen(FigureColour::White);
  //  while (validateMove(board, player, move) == false) {
  //  move = player.getMove();
  //}
  updateBoard(board, position, figure);
}

void
PuzzleLogic::updateBoard(Board& board, Position& position, Figure* figure) {
  board.set(position.getHorizontal(), position.getVertical(), figure);
}

bool
PuzzleLogic::validatePosition(Board& , Player& , Position& ) {
  return true;
}
