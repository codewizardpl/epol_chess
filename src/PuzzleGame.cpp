#include "Figure.hpp"
#include "ConsolePuzzlePlayer.hpp"
#include "ConsoleDisplay.hpp"
#include "PuzzleGame.hpp"
#include "Game.hpp"
#include <memory>

using namespace std;

void PuzzleGame::run() {

    shared_ptr<Puzzle> puzzle(new Puzzle());
    ConsolePuzzlePlayer player(puzzle);
    while (puzzle->getQueensToPlace() > 0) {
        player.placeQueen();
    }
    ConsoleDisplay consoleDisplay;
    consoleDisplay.show(puzzle->getBoard());
}
