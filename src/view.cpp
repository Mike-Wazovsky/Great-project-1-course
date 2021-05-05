#include "view.h"
#include <iostream>
#include <string>

void View::start_game(std::string text) {
    std::cout << text << std::endl;
}

void View::start_move(std::string move) {
    std::cout << move << std::endl;
    std::cout << "What will you choose?" << std::endl;
    std::cout << "(y/N)" << std::endl;
}
/*
void View::Result_move(std::string result) {
    std::cout << result << std::endl;
}
*/
void View::end_game(std::string end) {
    std::cout << end << std::endl;
    std::cout << "Game over" << std::endl;
}
