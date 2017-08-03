#include "Figure.hpp"
#include "ConsolePlayer.hpp"
#include "ConsoleDisplay.hpp"
#include "PuzzleGame.hpp"
#include "Game.hpp"

void PuzzleGame::run() {
    auto consoleDisplay = ConsoleDisplay();
    ConsolePlayer player("puzzle player");
    int queensToPlace = 8;
    while (queensToPlace>0) {
        consoleDisplay.show(board);
        Position position = player.getPosition();
        Figure queenFigure(FigureType::Queen, FigureColour::White);
        if (validatePosition(position)) {
            board.set(position, queenFigure);
            queensToPlace--;
        }
    }
    consoleDisplay.show(board);
}

bool PuzzleGame::validatePosition(Position& position) {
    return
        board.isEmpty(position) &&
        validateDirection(position, Position(1,0)) &&
        validateDirection(position, Position(1,1)) &&
        validateDirection(position, Position(0,1)) &&
        validateDirection(position, Position(-1,1)) &&
        validateDirection(position, Position(-1,0)) &&
        validateDirection(position, Position(-1,-1)) &&
        validateDirection(position, Position(0,-1)) &&
        validateDirection(position, Position(1,-1));
}

bool PuzzleGame::validateDirection(
        const Position& current,
        const Position& step) {
    const Position next = current + step;
    return
        !validateCoordinates(next) ||
        (board.isEmpty(next) && validateDirection(next, step));
}

bool PuzzleGame::validateCoordinates(const Position& position) {
    return position.getColumn() >=0 && position.getColumn() < 8 &&
           position.getRow()>= 0 && position.getRow() < 8;
}

