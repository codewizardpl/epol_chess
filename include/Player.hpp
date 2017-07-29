#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Figure.hpp"
#include "Move.hpp"

class Player {
public:
    Player(const char* name);
    virtual ~Player() {}

    const char* getName();
    virtual Move getMove() = 0;
    virtual void putMove(Move oponent) = 0;
    virtual Position getPosition() = 0;

private:
    const char* m_name;
};

#endif
