
#include "Chess.hpp"
#include "IllegalMoveException.hpp"

using namespace std;

Chess::Chess(const Board& _board, const FigureColour& _currentTurn):
    board(_board),
    currentTurn(_currentTurn)
{}

const Board& Chess::getBoard() const {
    return board;
}

const FigureColour& Chess::getCurrentTurn() const {
    return currentTurn;
}

void Chess::performMove(const Move& move) {
    validateMove(move);
    updateBoard(move);
    switchTurn();
}

void Chess::validateMove(const Move& move) const {
    const Figure figure = board.get(move.getStart());
    if (figure.getType()  == FigureType::None)
        throw IllegalMoveException("No figure");
    if (figure.getColour() != currentTurn)
        throw IllegalMoveException("Wrong figure colour");
    const Figure strikedFigure = board.get(move.getStop());
    if (strikedFigure.getType() == FigureType::None)
        switch (figure.getType()) {
            case FigureType::Pawn:
                validatePawnMove(move);
                break;
            case FigureType::Knight:
                throw IllegalMoveException("Can't move Knight");
                break;
            case FigureType::Bishop:
                throw IllegalMoveException("Can't move Bishop");
                break;
            case FigureType::Rook:
                throw IllegalMoveException("Can't move Rook");
                break;
            case FigureType::Queen:
                throw IllegalMoveException("Can't move Queen");
                break;
            case FigureType::King:
                throw IllegalMoveException("Can't move King");
                break;
            default:
                throw IllegalMoveException("Illegal figure type");
        }
    else {
        switch (figure.getType()) {
            case FigureType::Pawn:
                validatePawnStrike(move);
                break;
            case FigureType::Knight:
                throw IllegalMoveException("Can't strike with Knight");
                break;
            case FigureType::Bishop:
                throw IllegalMoveException("Can't strike with Bishop");
                break;
            case FigureType::Rook:
                throw IllegalMoveException("Can't strike with Rook");
                break;
            case FigureType::Queen:
                throw IllegalMoveException("Can't strike with Queen");
                break;
            case FigureType::King:
                throw IllegalMoveException("Can't strike with King");
                break;
            default:
                throw IllegalMoveException("Illegal figure type");
        }
    }
}

void Chess::validatePawnMove(const Move& move) const {
    Position delta = move.getStop() - move.getStart();
    if (delta.getHorizontal() != 0)
        throw IllegalMoveException("Pawn can't move vertically");
    int steps = delta.getVertical();
    if (currentTurn == FigureColour::White) {
        if (steps < 0) throw IllegalMoveException(
                "Wite Pawn can only move up");
    }
    if (currentTurn == FigureColour::Black) {
        if (steps > 0) throw IllegalMoveException(
                "Black Pawn can only move down");
        steps = -steps;
    }
    int baseline = 1;
    if (currentTurn == FigureColour::Black)
        baseline = 6;
    if (move.getStart().getVertical()  == baseline) {
        if (steps>2)
            throw IllegalMoveException(
                    "Pawn can move at most 2 steps in first move");
    } else {
        if (steps>1)
            throw IllegalMoveException(
                    "Pawn can move at most 1 step after first move");
    }
}

void Chess::validatePawnStrike(const Move& move) const {
    Position delta = move.getStop() - move.getStart();
    int sideStep = delta.getHorizontal();
    if (sideStep != 1 && sideStep != -1)
        throw IllegalMoveException(
                "Pawn can only strike 1 step to left or right");
    int step = 1;
    if (currentTurn == FigureColour::Black)
        step = -1;
    if (delta.getVertical() != step)
        throw IllegalMoveException(
                "Pawn can only strike 1 step forward");
}

void Chess::updateBoard(const Move& move) {
    Figure figure = board.get(move.getStart());
    board.setEmpty(move.getStart());
    board.set(move.getStop(), figure);
}

void Chess::switchTurn() {
    if (currentTurn == FigureColour::White)
        currentTurn = FigureColour::Black;
    else
        currentTurn = FigureColour::White;
}

