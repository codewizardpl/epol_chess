#include "Figures.hpp"
#include "ConsolePlayer.hpp"
#include "GameLogic.hpp"
#include "ConsoleDisplay.hpp"
#include "PuzzleGame.hpp"
#include "Game.hpp"
#include "PuzzleLogic.hpp"

PuzzleGame::PuzzleGame() {}

PuzzleGame::~PuzzleGame() {}

void PuzzleGame::run()
{
    setupBoard();
    PuzzleLogic puzzle;
    auto consoleDisplay = ConsoleDisplay();
    ConsolePlayer white("white player", FigureColour::White);
    consoleDisplay.Display(board);
    for (int i = 0; i < 8; ++i) {
        puzzle.setFigure(board, white, FigureType::Queen);
        consoleDisplay.Display(board);
    }
}

void PuzzleGame::setupBoard()
{

}


