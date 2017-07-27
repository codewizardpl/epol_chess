#ifndef PUZZLEGAME_HPP
#define PUZZLEGAME_HPP
#include "Board.hpp"
#include "Game.hpp"
#include "Player.hpp"

class PuzzleGame: public Game {
    
public:
    PuzzleGame();
    virtual ~PuzzleGame();
    virtual void run();

private:
    void setFigure(
            Board& board,
            Player& player,
            FigureType figure);
  
    bool validatePosition(
            Board& board,
            Player& player,
            Position& position,
            Figure* figure);

    void updateBoard(
            Board& board,
            Position& position,
            Figure* figure);

    Board board;
};

#endif
