#ifndef CONSOLE_PUZZLE_PLAYER_HPP
#define CONSOLE_PUZZLE_PLAYER_HPP

#include "PuzzlePlayer.hpp"
#include "Position.hpp"
#include "Puzzle.hpp"
#include <memory>

class ConsolePuzzlePlayer: public PuzzlePlayer {
public:
    ConsolePuzzlePlayer(
            const std::shared_ptr<Puzzle> _puzzle);
    virtual void placeQueen();
private:
    const std::shared_ptr<Puzzle> puzzle;
};

#endif
