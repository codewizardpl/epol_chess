#ifndef FIGURE_HPP
#define FIGURE_HPP

enum class FigureType {
    None,
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};

enum class FigureColour {
    None,
    White,
    Black
};

class Figure {

public:
    Figure();
    Figure(FigureType type, FigureColour colour);

    bool operator==(const Figure& other);
    bool operator!=(const Figure& other);

    FigureColour getColour() const;
    FigureType getType() const;
private:
    FigureColour colour;
    FigureType type;
};

#endif

