#include "FigureSymbol.hpp"

char FigureSymbol::get(const Figure& figure) {
    char symbol = 'w';
    switch (figure.getType()) {
        case FigureType::Rook:
            symbol = 'r';
            break;
        case FigureType::Queen:
            symbol = 'q';
            break;
        case FigureType::Knight:
            symbol = 'n';
            break;
        case FigureType::King:
            symbol = 'k';
            break;
        case FigureType::Bishop:
            symbol = 'b';
            break;
        case FigureType::Pawn:
            symbol = 'p';
            break;
        case FigureType::None:
        default:
            return '.';
            break;
    }
    if (figure.getColour() == FigureColour::White) {
        return symbol -32;
    }
    return symbol;
}
