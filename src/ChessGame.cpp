#include "ChessGame.hpp"

#include "Figures.hpp"
#include "ConsolePlayer.hpp"
#include "NetworkPlayer.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Figure.hpp"
#include "Move.hpp"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

ChessGame::ChessGame()
{}

ChessGame::~ChessGame()
{}

void ChessGame::run() {
    std::string answer;
    std::cout <<  "Network player (y/n)?: ";
    std::cin >> answer;
    if (answer == "n") {
    	whitePlayer = unique_ptr<Player>(new ConsolePlayer("white player", FigureColour::White));
    	blackPlayer = unique_ptr<Player>(new ConsolePlayer("black player", FigureColour::Black));
    } else {
    	std::cout <<  "Which side would you like to play (white/black)?: ";
    	std::cin >> answer;
    	if (answer == "white")
    	{
            whitePlayer = unique_ptr<Player>(new ConsolePlayer("white player", FigureColour::White));
            blackPlayer = unique_ptr<Player>(new NetworkPlayer("black player", FigureColour::Black));
    	} else {
            whitePlayer = unique_ptr<Player>(new NetworkPlayer("white player", FigureColour::White));
            blackPlayer = unique_ptr<Player>(new ConsolePlayer("black player", FigureColour::Black));
    	}
    }

    mainLoop();    
}

void ChessGame::mainLoop()
{
    setupBoard();
    while (1)
    {
        consoleDisplay.Display(board);
        makeMove(board, *whitePlayer);
        consoleDisplay.Display(board);
        makeMove(board, *blackPlayer);
    }

}

void ChessGame::makeMove(Board& board, Player& player) {
    Move move = player.getMove();
    while (validateMove(board, player, move) == false) {
        move = player.getMove();
    }
    updateBoard(board, move);
}

void ChessGame::updateBoard(Board& board, Move& move) {
    board.moveFigure(move);
}

bool ChessGame::validateMove(Board& board, Player& player, Move& move) {
    if (!move.validateCoordinates()) {
        return false;
    }
    Figure& figure = board.get(move.getStart());
    if (&figure == nullptr) {
        std::cout << "no figure at start position" << std::endl;
        return false; // no figure at start position
    }
    if (figure.getColour() != player.getColour()) {
        std::cout << "trying to move the oponent's figure" << std::endl;
        return false; // trying to move the oponent's figure
    }
 
    Figure& captured_figure = board.get(move.getStop());
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

void ChessGame::setupBoard()
{
    board.set(Position(0, 0), new FigureRook(FigureColour::White));
    board.set(Position(1, 0), new FigureKnight(FigureColour::White));
    board.set(Position(2, 0), new FigureBishop(FigureColour::White));
    board.set(Position(3, 0), new FigureQueen(FigureColour::White));
    board.set(Position(4, 0), new FigureKing(FigureColour::White));
    board.set(Position(5, 0), new FigureBishop(FigureColour::White));
    board.set(Position(6, 0), new FigureKnight(FigureColour::White));
    board.set(Position(7, 0), new FigureRook(FigureColour::White));

    board.set(Position(0, 1), new FigurePawn(FigureColour::White));
    board.set(Position(1, 1), new FigurePawn(FigureColour::White));
    board.set(Position(2, 1), new FigurePawn(FigureColour::White));
    board.set(Position(3, 1), new FigurePawn(FigureColour::White));
    board.set(Position(4, 1), new FigurePawn(FigureColour::White));
    board.set(Position(5, 1), new FigurePawn(FigureColour::White));
    board.set(Position(6, 1), new FigurePawn(FigureColour::White));
    board.set(Position(7, 1), new FigurePawn(FigureColour::White));

    board.set(Position(0, 7), new FigureRook(FigureColour::Black));
    board.set(Position(1, 7), new FigureKnight(FigureColour::Black));
    board.set(Position(2, 7), new FigureBishop(FigureColour::Black));
    board.set(Position(3, 7), new FigureQueen(FigureColour::Black));
    board.set(Position(4, 7), new FigureKing(FigureColour::Black));
    board.set(Position(5, 7), new FigureBishop(FigureColour::Black));
    board.set(Position(6, 7), new FigureKnight(FigureColour::Black));
    board.set(Position(7, 7), new FigureRook(FigureColour::Black));

    board.set(Position(0, 6), new FigurePawn(FigureColour::Black));
    board.set(Position(1, 6), new FigurePawn(FigureColour::Black));
    board.set(Position(2, 6), new FigurePawn(FigureColour::Black));
    board.set(Position(3, 6), new FigurePawn(FigureColour::Black));
    board.set(Position(4, 6), new FigurePawn(FigureColour::Black));
    board.set(Position(5, 6), new FigurePawn(FigureColour::Black));
    board.set(Position(6, 6), new FigurePawn(FigureColour::Black));
    board.set(Position(7, 6), new FigurePawn(FigureColour::Black));
}

