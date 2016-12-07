#include "PuzzleLogic.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Figure.hpp"
#include "FigureQueen.hpp"
#include "Position.hpp"
#include <iostream>

void PuzzleLogic::setFigure(Board& board, Player& player, FigureType ) {
  Position position = player.getPosition();
  Figure* figure = new FigureQueen(player.getColour());
  while (validatePosition(board, player, position, figure) == false) {
    position = player.getPosition();
  }
  updateBoard(board, position, figure);
}

void
PuzzleLogic::updateBoard(Board& board, Position& position, Figure* figure) {
  board.set(position.getHorizontal(), position.getVertical(), figure);
}

bool
PuzzleLogic::validatePosition(Board& board, Player& , Position& position, Figure* figure) {
  std::set<Position> possibleMoves = figure->getPossibleMoves(position);
  for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
    Position pos = *it;
    Figure& f = board.get(pos.getHorizontal(),
			  pos.getVertical());
    if (&f != nullptr) {
      return false;
    }
  }
  return true;
}
