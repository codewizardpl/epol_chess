#ifndef CHESSGAME_HPP
#define CHESSGAME_HPP
#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "ConsoleDisplay.hpp"

class ChessGame: public Game {
    
public:
    ChessGame();
    virtual ~ChessGame();
    virtual void run();

private:
    void setupBoard();
    void mainLoop();
    void makeMove(Board& board, Player& player);
    void updateBoard(Board& board, Move&  move);
    bool validateMove(Board& board, Player& player, Move& move);
/*
    virtual FigurePath validatePawnMove(Move move, FigureMoveType moveType);
    bool isPawnStep(Move move);
    bool isPawnDoubleStep(Move move);
    bool isPawnLeftStrike(Move move);
    bool isPawnRightStrike(Move move);
    bool isPawnFromBaseline(Move move);
    int forwardDirection();
*/
    Board board;
    std::unique_ptr<Player> whitePlayer;
    std::unique_ptr<Player> blackPlayer;
    ConsoleDisplay consoleDisplay;
};

#endif
