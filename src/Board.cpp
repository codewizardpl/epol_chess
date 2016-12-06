#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board() : m_figure(nullptr) {
    cout << "Board is ready!" << endl;
}

Figure &Board::get(int x, int y) {

	return *m_figure;
}

void Board::set(int x, int y, Figure &fig) {

}
