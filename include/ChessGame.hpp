#ifndef CHESSGAME_HPP
#define CHESSGAME_HPP

#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "ConsoleDisplay.hpp"
#include "Chess.hpp"
#include "IllegalMoveException.hpp"
#include <memory>

class ChessGame: public Game {
    
public:
    ChessGame(
            std::shared_ptr<Player> whitePlayer,
            std::shared_ptr<Player> blackPlayer,
            std::shared_ptr<ConsoleDisplay> _display);
    virtual void run();

private:
    void setupBoard(Board& board);
    void makeMove(Chess& chess, Player& player);

    std::shared_ptr<Player> whitePlayer;
    std::shared_ptr<Player> blackPlayer;
    std::shared_ptr<ConsoleDisplay> display;
};

#endif
