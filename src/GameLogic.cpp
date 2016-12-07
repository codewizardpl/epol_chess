#include "GameLogic.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Figure.hpp"
#include "Move.hpp"

void
GameLogic::startGame(Board& board, Player& white, Player& black) {
  while (1) {
    makeMove(board, white);
    makeMove(board, black);
  }
}

void GameLogic::makeMove(Board& board, Player& player) {
  Move move = player.getMove();
  validateMove(board, player, move);
  updateBoard(board, move);
}

void
GameLogic::updateBoard(Board& board, Move& move) {
  board.moveFigure(move);
}

bool
GameLogic::validateMove(Board& board, Player& player, Move& move) {
  Figure& figure = board.get(move.getStart().getHorizontal(),
			     move.getStart().getVertical());
  if (&figure == nullptr) { 
    return false; // no figure at start position
  }
  if (figure.getColour() != player.getColour()) {
    return false; // trying to move the oponent's figure
  }
 
  Figure& captured_figure = board.get(move.getStop().getHorizontal(),
				      move.getStop().getVertical());
  bool capture = (&captured_figure == nullptr ? false : true);
  if (capture && captured_figure.getColour() == player.getColour()) {
    return false; // trying to capture own figure
  }
 
  FigurePath path = figure.validateMove(move, (capture ? FigureMoveType::Strike : FigureMoveType::Move));
  if (!path.isLegal()) {
    return false; // incorrect move
  }
  //if (!board.figuresOnPath(path)) {
  //  return false; // move blocked by other figures
  //}

  return true;
}
