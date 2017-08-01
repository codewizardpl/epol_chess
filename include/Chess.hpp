#ifndef CHESS_HPP
#define CHESS_HPP

#include "Move.hpp"
#include "Board.hpp"
#include "Figure.hpp"

class Chess {
public:
    Chess(const Board& _board, const FigureColour& _currentTurn);
    const Board& getBoard() const;
    const FigureColour& getCurrentTurn() const;
    void performMove(const Move& move);
private:
    void validateMove(const Move& move) const;
    void validatePawnMove(const Move& move) const;
    void validatePawnStrike(const Move& move) const;
    void updateBoard(const Move& move);
    void switchTurn();
    Board board;
    FigureColour currentTurn;
};

#endif

