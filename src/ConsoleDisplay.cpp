#include "ConsoleDisplay.hpp"
#include <iostream>


ConsoleDisplay::ConsoleDisplay()
{

}
void ConsoleDisplay::Display(Board &board){
    std::cout<< "\033[1;31m" << "+ a b c d e f g h +" << "\033[1;37m" << std::endl;
    for (int width = 7; width >=0; --width) {
        std::cout<<  "\033[1;31m" << width +1<<" " << "\033[1;37m";
        for (int height  = 7; height >= 0; --height) {
            Figure &figure = board.get(height,width);

            std::cout << GetSymbol(figure)<<" ";
        }
        std::cout<< "\033[1;32m" << width +1 << "\033[1;37m";
        std::cout << std::endl;
    }
    std::cout<< "\033[1;32m" << "+ a b c d e f g h +" << "\033[0;37m" << std::endl;

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
