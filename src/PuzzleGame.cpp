#include "Figure.hpp"
#include "ConsolePlayer.hpp"
#include "ConsoleDisplay.hpp"
#include "PuzzleGame.hpp"
#include "Game.hpp"

PuzzleGame::PuzzleGame()
{}

PuzzleGame::~PuzzleGame()
{}

void PuzzleGame::run() {
    auto consoleDisplay = ConsoleDisplay();
    ConsolePlayer player("puzzle player");
    int queensToPlace = 8;
    while (queensToPlace>0) {
        consoleDisplay.show(board);
        Position position = player.getPosition();
        Figure queenFigure(FigureType::Queen, FigureColour::White);
        if (validatePosition(board, position)) {
            board.set(position, queenFigure);
            queensToPlace--;
        }
    }
    consoleDisplay.show(board);
}

bool PuzzleGame::validatePosition(
        Board& board,
        Position& position) {
    
    if (!board.isEmpty(position)) {
        return false;
    }
    std::set<Position> possibleMoves = getQueenPossibleMoves(position);
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        Position pos = *it;
        if (!board.isEmpty(pos)) {
            return false;
        }
    }
    return true;
}

std::set<Position> PuzzleGame::getQueenPossibleMoves(Position start)
{
    std::set<Position> result;

    int slashStart = start.getVertical() + start.getHorizontal();
    int backslashStart = start.getVertical() - start.getHorizontal();

    for (int i=0; i<8; i++)
    {
        Position horizontalLine = Position(i, start.getVertical());
        if (!(horizontalLine == start))
            result.insert(horizontalLine);

        Position verticalLine = Position(start.getHorizontal(), i);
        if (!(verticalLine == start))
            result.insert(verticalLine);

        Position slashLine = Position(i, i-slashStart);
        if (validateCoordinates(slashLine) && !(slashLine == start))
            result.insert(slashLine);

        Position backslashLine = Position(i, i+backslashStart);
        if (validateCoordinates(backslashLine) && !(backslashLine == start))
            result.insert(backslashLine);

    }

    return result;
}

bool PuzzleGame::validateCoordinates(const Position& position) {
    return position.getHorizontal() >=0 && position.getHorizontal() < 8 &&
           position.getVertical()>= 0 && position.getVertical() < 8;
}
