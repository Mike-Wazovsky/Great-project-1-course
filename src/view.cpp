#include "view.h"
#include <iostream>
#include <string>

void View::Start_game() {
    std::cout << std::endl;
}

void View::Start_move(std::string move) {
    std::cout << move << std::endl;
    // (y/N)
    std::cout << "What will you choose?" << std::endl;
    std::cout << "(y/N)" << std::endl;
}

void View::Result_move(std::string result) {
    std::cout << result << std::endl;
}

void View::End_game(std::string end) {
    std::cout << end << std::endl;
    std::cout << "Game over" << std::endl;
}
