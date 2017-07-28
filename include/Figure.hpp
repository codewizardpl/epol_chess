#ifndef FIGURE
#define FIGURE

#include <set>
#include "Move.hpp"
#include "FigurePath.hpp"
#include "Position.hpp"

enum class FigureType {
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King,
    None
};

enum class FigureColour {
    White,
    Black,
    None
};

enum class FigureMoveType {
    Move,
    Strike
};


class Figure {

public:
    FigureColour getColour() const;
    FigureType getType() const;
    Figure();
    Figure(FigureType type, FigureColour colour);
    virtual ~Figure() {}


private:
    FigureColour colour;
    FigureType type;

};

#endif

