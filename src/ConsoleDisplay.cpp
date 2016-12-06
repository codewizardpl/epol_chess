#include "ConsoleDisplay.hpp"
#include <iostream>


ConsoleDisplay::ConsoleDisplay()
{

}
void ConsoleDisplay::Display(Board &board){
    std::cout<< "+ a b c d e f g h +" << std::endl;
    for (int width = 0; width <8; ++width) {
        std::cout<< width +1<<" ";
        for (int height  = 0; height < 8; ++height) {
            Figure &figure = board.get(height,width);
            std::cout << GetSymbol(figure)<<" ";
        }
        std::cout<< width +1;
        std::cout << std::endl;
    }
    std::cout<< "+ a b c d e f g h +" << std::endl;

}

char ConsoleDisplay::GetSymbol(Figure&figure)
{
    if(&figure == nullptr){
        return'.';
    }else{
        char symbol = 'w';
        FigureType figureType = figure.getType();
        FigureColour  figureColor = figure.getColour();
        switch (figureType) {
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
        default:
            return '.';
            break;
        }
        if(figureColor==FigureColour::White){
            return symbol -32;
        }
        return symbol;
    }

}
