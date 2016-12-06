#include "ConsoleDisplay.hpp"
#include <iostream>


ConsoleDisplay::ConsoleDisplay()
{

}
void ConsoleDisplay::Display(Board board){

    for (int width = 0; width <8; ++width) {
        for (int height  = 0; height < 8; ++height) {
            //Figure &figure = board.get(height,width);

            std::cout << GetSymbol(/*figure*/);
        }
        std::cout << std::endl;
    }

}

char ConsoleDisplay::GetSymbol(/*Figure&figure*/)
{

    //if(figure == nullptr){
    //}else{
    char color = 'w';
    FigureType fType = KingFigureType;
    char  symbol = 'p';
    switch (fType) {
    case KingFigureType:
        symbol = 'k';
        break;
    case BishopFigureType:
        symbol = 'b';
        break;
    case PawnFigureType:
        symbol = 'p';
        break;
    default:
        return '.';
        break;
    }
    return symbol;
    //}
}
