#ifndef CONSOLE_CHESS_PLAYER_HPP
#define CONSOLE_CHESS_PLAYER_HPP

#include "ChessPlayer.hpp"
#include "Figure.hpp"
#include <memory>

class ConsoleChessPlayer : public ChessPlayer {
public:
    ConsoleChessPlayer(
            const std::shared_ptr<Chess> _chess,
            const FigureColour& _colour);
    virtual void makeMove();
private:
    std::string getName();
    const std::shared_ptr<Chess> chess;
    const FigureColour colour;
};

#endif

