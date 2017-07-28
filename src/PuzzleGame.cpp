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
    ConsolePlayer white("white player", FigureColour::White);
    consoleDisplay.display(board);
    for (int i = 0; i < 8; ++i) {
        setFigure(board, white, FigureType::Queen);
        consoleDisplay.display(board);
    }
}

void PuzzleGame::setFigure(Board& board, Player& player, FigureType ) {
    Position position = player.getPosition();
    Figure figure(FigureType::Queen, player.getColour());
    while (validatePosition(board, position) == false) {
        position = player.getPosition();
    }
    board.set(position, figure);
}


bool PuzzleGame::validatePosition(
        Board& board,
        Position& position) {
    
    Figure f1 = board.get(position);
    if (board.hasFigure(position)) {
        return false;
    }
    std::set<Position> possibleMoves = getQueenPossibleMoves(position);
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it) {
        Position pos = *it;
        if (board.hasFigure(pos)) {
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
        if (slashLine.validateCoordinates() && !(slashLine == start))
            result.insert(slashLine);

        Position backslashLine = Position(i, i+backslashStart);
        if (backslashLine.validateCoordinates() && !(backslashLine == start))
            result.insert(backslashLine);

    }

    return result;
}

