#include "IllegalMoveException.hpp"

using namespace std;

IllegalMoveException::IllegalMoveException(string _reason):
    reason(_reason)
{}

string IllegalMoveException::getReason() {
    return reason;
}

