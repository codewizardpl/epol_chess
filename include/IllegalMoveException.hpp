#ifndef ILLEGALMOVEEXCEPTION_HPP
#define ILLEGALMOVEEXCEPTION_HPP

#include <exception>
#include <string>

class IllegalMoveException: public std::exception {
public:
    IllegalMoveException(std::string _reason);
    std::string getReason();
private:
    std::string reason;
};

#endif

