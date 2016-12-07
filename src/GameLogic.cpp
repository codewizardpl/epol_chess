#include "GameLogic.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Figure.hpp"
#include "Move.hpp"
#include <iostream>

void
GameLogic::startGame(Board& board, Player& white, Player& black) {
  while (1) {
    makeMove(board, white);
    makeMove(board, black);
  }
}

void GameLogic::makeMove(Board& board, Player& player) {
  Move move = player.getMove();
  while (validateMove(board, player, move) == false) {
    move = player.getMove();
  }
  updateBoard(board, move);
}

void
GameLogic::updateBoard(Board& board, Move& move) {
  board.moveFigure(move);
}

bool
GameLogic::validateMove(Board& board, Player& player, Move& move) {
  if (!move.validateCoordinates()) {
    return false;
  }
  Figure& figure = board.get(move.getStart().getHorizontal(),
			     move.getStart().getVertical());
  if (&figure == nullptr) {
    std::cout << "no figure at start position" << std::endl;
    return false; // no figure at start position
  }
  if (figure.getColour() != player.getColour()) {
    std::cout << "trying to move the oponent's figure" << std::endl;
    return false; // trying to move the oponent's figure
  }
 
  Figure& captured_figure = board.get(move.getStop().getHorizontal(),
				      move.getStop().getVertical());
  bool capture = (&captured_figure == nullptr ? false : true);
  if (capture && captured_figure.getColour() == player.getColour()) {
    std::cout << "trying to capture own figure" << std::endl;
    return false; // trying to capture own figure
  }
 
  FigurePath path = figure.validateMove(move,
					(capture ? FigureMoveType::Strike : FigureMoveType::Move));
  if (!path.isLegal()) {
    std::cout << "illegal move " << (figure.getType() == FigureType::Pawn ? "pawn" : "other")
	      << std::endl;
    return false; // incorrect move
  }
  //if (!board.figuresOnPath(path)) {
  //  return false; // move blocked by other figures
  //}

  return true;
}
