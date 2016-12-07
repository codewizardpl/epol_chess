#include <iostream>
#include "Board.hpp"
#include "ConsoleDisplay.hpp"
//#include "Figures.hpp"
#include "GameLogic.hpp"
#include "ConsolePlayer.hpp"

#include "Figure.hpp"
#include "FigurePawn.hpp"
#include "FigureKnight.hpp"
#include "FigureBishop.hpp"
#include "FigureRook.hpp"
#include "FigureQueen.hpp"
#include "FigureKing.hpp"


using namespace std;

//rook, knight, bishop, queen, king, bishop, knight, and rook; second row: pawns

void setupBoard(Board& board) {

    board.set(0, 0, new FigureRook(FigureColour::White));
    board.set(1, 0, new FigureKnight(FigureColour::White));
    board.set(2, 0, new FigureBishop(FigureColour::White));
    board.set(3, 0, new FigureQueen(FigureColour::White));
    board.set(4, 0, new FigureKing(FigureColour::White));
    board.set(5, 0, new FigureBishop(FigureColour::White));
    board.set(6, 0, new FigureKnight(FigureColour::White));
    board.set(7, 0, new FigureRook(FigureColour::White));

    board.set(0, 1, new FigurePawn(FigureColour::White));
    board.set(1, 1, new FigurePawn(FigureColour::White));
    board.set(2, 1, new FigurePawn(FigureColour::White));
    board.set(3, 1, new FigurePawn(FigureColour::White));
    board.set(4, 1, new FigurePawn(FigureColour::White));
    board.set(5, 1, new FigurePawn(FigureColour::White));
    board.set(6, 1, new FigurePawn(FigureColour::White));
    board.set(7, 1, new FigurePawn(FigureColour::White));

    board.set(0, 7, new FigureRook(FigureColour::Black));
    board.set(1, 7, new FigureKnight(FigureColour::Black));
    board.set(2, 7, new FigureBishop(FigureColour::Black));
    board.set(3, 7, new FigureQueen(FigureColour::Black));
    board.set(4, 7, new FigureKing(FigureColour::Black));
    board.set(5, 7, new FigureBishop(FigureColour::Black));
    board.set(6, 7, new FigureKnight(FigureColour::Black));
    board.set(7, 7, new FigureRook(FigureColour::Black));

    board.set(0, 6, new FigurePawn(FigureColour::Black));
    board.set(1, 6, new FigurePawn(FigureColour::Black));
    board.set(2, 6, new FigurePawn(FigureColour::Black));
    board.set(3, 6, new FigurePawn(FigureColour::Black));
    board.set(4, 6, new FigurePawn(FigureColour::Black));
    board.set(5, 6, new FigurePawn(FigureColour::Black));
    board.set(6, 6, new FigurePawn(FigureColour::Black));
    board.set(7, 6, new FigurePawn(FigureColour::Black));
}

int main() {

    cout << "Helloo!!!" << endl;

    Board board{};
    setupBoard(board);


    auto consoleDisplay = ConsoleDisplay();
    consoleDisplay.Display(board);

    ConsolePlayer white("white player", FigureColour::White);
    ConsolePlayer black("black player", FigureColour::Black);
    GameLogic logic;

    while (1) {
      logic.makeMove(board, white);
      consoleDisplay.Display(board);
      logic.makeMove(board, black);
      consoleDisplay.Display(board);
    }
    
    return 0;
}
