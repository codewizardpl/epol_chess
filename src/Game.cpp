#include <iostream>
#include <Board.hpp>
#include "ConsoleDisplay.hpp"

using namespace std;

int main() {

    cout << "Helloo!!!" << endl;

    Board board{};
    auto consoleDisplay = ConsoleDisplay();
    consoleDisplay.Display(board);


    return 0;
}
