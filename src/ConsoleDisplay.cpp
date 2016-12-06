#include "ConsoleDisplay.hpp"
#include <iostream>


ConsoleDisplay::ConsoleDisplay()
{

}
void ConsoleDisplay::Display(Board board){

    for (int width = 0; width <8; ++width) {
        for (int height  = 0; height < 8; ++height) {
            Figure &figure = board.get(height,width);
            std::cout << GetSymbol(figure);
        }
        std::cout << std::endl;
    }

}

char ConsoleDisplay::GetSymbol(Figure&figure)
{

    return 'k';
    {
        return'.';
    }else{
    char symbol = 'w';
    FigureType figureType = figure.getType();
    FigureColour  figureColor = figure.getColour();
    switch (figureType) {
    case FigureType::King:
        symbol = 'k';
        break;
    case FigureType::Bishop:
        symbol = 'b';
        break;
    case FigureType::Pawn:
        symbol = 'p';
        break;
    default:
        return '.';
        break;
    }
    return symbol;
    }
}
