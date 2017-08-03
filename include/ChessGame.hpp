#ifndef CHESS_GAME_HPP
#define CHESS_GAME_HPP

#include "Game.hpp"
#include "Chess.hpp"
#include "ChessPlayer.hpp"
#include <memory>

class ChessGame: public Game {
    
public:
    ChessGame(
            std::shared_ptr<ChessPlayer> whitePlayer,
            std::shared_ptr<ChessPlayer> blackPlayer);
    virtual void run();

private:
    std::shared_ptr<ChessPlayer> whitePlayer;
    std::shared_ptr<ChessPlayer> blackPlayer;
};

#endif
