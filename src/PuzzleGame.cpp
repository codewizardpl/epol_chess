#include "Figures.hpp"
#include "ConsolePlayer.hpp"
#include "ConsoleDisplay.hpp"
#include "PuzzleGame.hpp"
#include "Game.hpp"

PuzzleGame::PuzzleGame() {}

PuzzleGame::~PuzzleGame() {}

void PuzzleGame::run()
{
    auto consoleDisplay = ConsoleDisplay();
    ConsolePlayer white("white player", FigureColour::White);
    consoleDisplay.Display(board);
    for (int i = 0; i < 8; ++i) {
        setFigure(board, white, FigureType::Queen);
        consoleDisplay.Display(board);
    }
}

void PuzzleGame::setFigure(Board& board, Player& player, FigureType ) {
    Position position = player.getPosition();
    Figure* figure = new FigureQueen(player.getColour());
    while (validatePosition(board, player, position, figure) == false) {
        position = player.getPosition();
    }
    updateBoard(board, position, figure);
}

void PuzzleGame::updateBoard(Board& board, Position& position, Figure* figure) {
    board.set(position, figure);
}

bool PuzzleGame::validatePosition(Board& board, Player& , Position& position, Figure* figure) {
    Figure& f1 = board.get(position);
    if (&f1 != nullptr) {
        return false;
    }
    std::set<Position> possibleMoves = figure->getPossibleMoves(position);
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        Position pos = *it;
        Figure& f = board.get(pos);
        if (&f != nullptr) {
            return false;
        }
    }
    return true;
}

