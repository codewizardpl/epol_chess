#include "ChessGame.hpp"

#include "ConsolePlayer.hpp"
#include "NetworkPlayer.hpp"

#include <iostream>
#include <string>

using namespace std;

void ChessGame::run() {
    Board startBoard;
    setupBoard(startBoard);
    FigureColour startTurn = FigureColour::White;
    Chess chess(startBoard, startTurn);
    while (1) {
        display->show(chess.getBoard());
        makeMove(chess, *whitePlayer);
        display->show(chess.getBoard());
        makeMove(chess, *blackPlayer);
    }
}

ChessGame::ChessGame(
        shared_ptr<Player> _whitePlayer,
        shared_ptr<Player> _blackPlayer,
        shared_ptr<ConsoleDisplay> _display) {
    whitePlayer = _whitePlayer;
    blackPlayer = _blackPlayer;
    display = _display;
}

void ChessGame::makeMove(Chess& chess, Player& player) {
    while (1) {
        const Move move = player.getMove();
        try {
            chess.performMove(move);
            return;
        } catch (IllegalMoveException ex) {
            cout << ex.getReason() << endl;
        }
    }
}

void ChessGame::setupBoard(Board& board)
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

