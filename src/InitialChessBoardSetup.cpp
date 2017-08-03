#include "InitialChessBoardSetup.hpp"

const Board InitialChessBoardSetup::getBoard() {
    Board board;
    setBoard(board);
    return board;
}

void InitialChessBoardSetup::setBoard(Board& board) {
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

