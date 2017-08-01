#include "PositionFormat.hpp"
#include "exception"

using namespace std;

string PositionFormat::formatPosition(const Position& position) {
    return formatRowPosition(position.getColumn()) +
        formatColumnPosition(position.getRow());
}

string PositionFormat::formatColumnPosition(const int columnPosition) {
    switch (columnPosition) {
        case 0: return string("a");
        case 1: return string("b");
        case 2: return string("c");
        case 3: return string("d");
        case 4: return string("e");
        case 5: return string("f");
        case 6: return string("g");
        case 7: return string("h");
    }
    throw invalid_argument("columnPosition must be in range [0..7]");
}

string PositionFormat::formatRowPosition(const int horizontalPosition) {
    switch (horizontalPosition) {
        case 0: return string("1");
        case 1: return string("2");
        case 2: return string("3");
        case 3: return string("4");
        case 4: return string("5");
        case 5: return string("6");
        case 6: return string("7");
        case 7: return string("8");
    }
    throw invalid_argument("horizontalPosition must be in range [0..7]");
}

Position PositionFormat::parsePosition(const string& s) {
    char column, row;
    sscanf(s.c_str(), "%c%c", &column, &row);
    return Position(column-'a', row-'1');
}

int PositionFormat::parseColumnPosition(const string& s) {
    return 0;
}

int PositionFormat::parseRowPosition(const string& s) {
    return 0;
}

