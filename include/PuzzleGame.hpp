#ifndef PUZZLEGAME_HPP
#define PUZZLEGAME_HPP
#include "Board.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Position.hpp"

class PuzzleGame: public Game {
    
public:
    PuzzleGame();
    virtual ~PuzzleGame();
    virtual void run();

private:
    bool validatePosition(
            Board& board,
            Position& position);

    std::set<Position> getQueenPossibleMoves(Position start);

    Board board;
};

#endif
