#include "ConsoleDisplay.hpp"
#include <iostream>

ConsloleDisplay::ConsloleDisplay(){

}
ConsloleDisplay::Display(Board board){
    using::std;
    for (int high = 0; high <8; ++high) {
        for (int width = 0; width < 8; ++width) {
            cout <<"";
        }
    }
}
