#include "ChessGame.hpp"

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
    string answer;
    cout <<  "Network player (y/n)?: ";
    cin >> answer;
    if (answer == "n") {
    	whitePlayer = unique_ptr<Player>(new ConsolePlayer("white player"));
    	blackPlayer = unique_ptr<Player>(new ConsolePlayer("black player"));
    } else {
    	cout <<  "Which side would you like to play (white/black)?: ";
    	cin >> answer;
    	if (answer == "white")
    	{
            whitePlayer = unique_ptr<Player>(new ConsolePlayer("white player"));
            blackPlayer = unique_ptr<Player>(new NetworkPlayer("black player"));
    	} else {
            whitePlayer = unique_ptr<Player>(new NetworkPlayer("white player"));
            blackPlayer = unique_ptr<Player>(new ConsolePlayer("black player"));
    	}
    }

    mainLoop();    
}

void ChessGame::mainLoop()
{
    setupBoard();
    while (1)
    {
        consoleDisplay.display(board);
        makeMove(board, *whitePlayer, FigureColour::White);
        consoleDisplay.display(board);
        makeMove(board, *blackPlayer, FigureColour::Black);
    }

}

void ChessGame::makeMove(Board& board, Player& player, FigureColour col) {
    Move move = player.getMove();
    while (validateMove(board, col, move) == false) {
        move = player.getMove();
    }
    updateBoard(board, move);
}

void ChessGame::updateBoard(Board& board, Move& move) {
    Figure tmpFig = board.get(move.getStart());
    board.set(move.getStop(), tmpFig);
    board.set(move.getStart(), Figure(FigureType::None, FigureColour::None));
}

bool ChessGame::validateMove(Board& board, const FigureColour col, Move& move) {
    if (!validateCoordinates(move)) {
        return false;
    }

    Figure figure = board.get(move.getStart());
    if (figure.getType()  == FigureType::None) {
        cout << "no figure at start position" << endl;
        return false; // no figure at start position
    }

    if (figure.getColour() != col) {
        cout << "trying to move the oponent's figure" << endl;
        return false; // trying to move the oponent's figure
    }
 
    Figure captured_figure = board.get(move.getStop());
    bool capture = (&captured_figure == nullptr ? false : true);
    if (capture && captured_figure.getColour() == col) {
        cout << "trying to capture own figure" << endl;
        return false; // trying to capture own figure
    }
 
//    FigurePath path = figure.validateMove(move,
//        (capture ? FigureMoveType::Strike : FigureMoveType::Move));

 //   if (!path.isLegal()) {
 //       cout << "illegal move ";
 //       cout << (figure.getType() == FigureType::Pawn ? "pawn" : "other");
 //       cout << endl;
 //       return false; // incorrect move
 //   }

    //if (!board.figuresOnPath(path)) {
    //  return false; // move blocked by other figures
    //}

    return true;
}

bool ChessGame::validateCoordinates(const Move& move) {
    return validateCoordinates(move.getStart()) &&
           validateCoordinates(move.getStop());
}

bool ChessGame::validateCoordinates(const Position& position) {
    return position.getHorizontal() >=0 && position.getHorizontal() < 8 &&
           position.getVertical()>= 0 && position.getVertical() < 8;
}

void ChessGame::setupBoard()
{
    board.set(Position(0, 0), Figure(FigureType::Rook, FigureColour::White));
    board.set(Position(1, 0), Figure(FigureType::Knight, FigureColour::White));
    board.set(Position(2, 0), Figure(FigureType::Bishop, FigureColour::White));
    board.set(Position(3, 0), Figure(FigureType::Queen, FigureColour::White));
    board.set(Position(4, 0), Figure(FigureType::King, FigureColour::White));
    board.set(Position(5, 0), Figure(FigureType::Bishop, FigureColour::White));
    board.set(Position(6, 0), Figure(FigureType::Knight, FigureColour::White));
    board.set(Position(7, 0), Figure(FigureType::Rook, FigureColour::White));

    board.set(Position(0, 1), Figure(FigureType::Pawn, FigureColour::White));
    board.set(Position(1, 1), Figure(FigureType::Pawn, FigureColour::White));
    board.set(Position(2, 1), Figure(FigureType::Pawn, FigureColour::White));
    board.set(Position(3, 1), Figure(FigureType::Pawn, FigureColour::White));
    board.set(Position(4, 1), Figure(FigureType::Pawn, FigureColour::White));
    board.set(Position(5, 1), Figure(FigureType::Pawn, FigureColour::White));
    board.set(Position(6, 1), Figure(FigureType::Pawn, FigureColour::White));
    board.set(Position(7, 1), Figure(FigureType::Pawn, FigureColour::White));

    board.set(Position(0, 7), Figure(FigureType::Rook, FigureColour::Black));
    board.set(Position(1, 7), Figure(FigureType::Knight, FigureColour::Black));
    board.set(Position(2, 7), Figure(FigureType::Bishop, FigureColour::Black));
    board.set(Position(3, 7), Figure(FigureType::Queen, FigureColour::Black));
    board.set(Position(4, 7), Figure(FigureType::King, FigureColour::Black));
    board.set(Position(5, 7), Figure(FigureType::Bishop, FigureColour::Black));
    board.set(Position(6, 7), Figure(FigureType::Knight, FigureColour::Black));
    board.set(Position(7, 7), Figure(FigureType::Rook, FigureColour::Black));

    board.set(Position(0, 6), Figure(FigureType::Pawn, FigureColour::Black));
    board.set(Position(1, 6), Figure(FigureType::Pawn, FigureColour::Black));
    board.set(Position(2, 6), Figure(FigureType::Pawn, FigureColour::Black));
    board.set(Position(3, 6), Figure(FigureType::Pawn, FigureColour::Black));
    board.set(Position(4, 6), Figure(FigureType::Pawn, FigureColour::Black));
    board.set(Position(5, 6), Figure(FigureType::Pawn, FigureColour::Black));
    board.set(Position(6, 6), Figure(FigureType::Pawn, FigureColour::Black));
    board.set(Position(7, 6), Figure(FigureType::Pawn, FigureColour::Black));
}
/*
FigurePath ChessGame::validatePawnMove(Move move, FigureMoveType moveType) {
    switch (moveType) {
        case FigureMoveType::Strike:
            if (isPawnLeftStrike(move) || isPawnRightStrike(move))
                return FigurePath(true);
            break;

        case FigureMoveType::Move:
            if (isPawnStep(move))
                return FigurePath(true);
            else if (isPawnFromBaseline(move) && isPawnDoubleStep(move))
                return FigurePath(true).addStep(
                        move.getStart()+Position(0, forwardDirection()));
            break;
    }
    return FigurePath(false);
}

bool ChessGame::isPawnStep(Move move) {
    Position step = Position(0, forwardDirection());
    return move.getRelative() == step;
}

bool ChessGame::isPawnDoubleStep(Move move) {
    Position doubleStep = Position(0, 2*forwardDirection());
    return move.getRelative() == doubleStep;
}

bool ChessGame::isPawnLeftStrike(Move move) {
    Position leftStrike =  Position(-1, forwardDirection());
    return move.getRelative() == leftStrike;
}

bool ChessGame::isPawnRightStrike(Move move) {
    Position rightStrike = Position(1, forwardDirection());
    return move.getRelative() == rightStrike;
}

bool ChessGame::isPawnFromBaseline(Move move) {
    switch(getColour()) {
        case FigureColour::White: return move.getStart().getVertical() == 1;
        case FigureColour::Black: return move.getStart().getVertical() == 6;
    }
    throw std::invalid_argument("unknown colour"); 
}

int ChessGame::forwardDirection() {
    switch(getColour()) {
        case FigureColour::White: return -1;
        case FigureColour::Black: return 1;
    }
    throw std::invalid_argument("unknown colour"); 
}
*/
