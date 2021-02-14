#include "view.h"
#include <iostream>
#include <string>

void macaftc::View::Start_game() {
    // TODO: "\n" >> std::endl;
    std::cout << "\n";
}

void macaftc::View::Start_move(std::string move) {
    std::cout << move << '\n';
    // (y/N)
    std::cout << "What will you choose?\nYes or No?\n";
}

void macaftc::View::Result_move(std::string result) {
    std::cout << result << '\n';
}

void macaftc::View::End_game(std::string end) {
    std::cout << end << '\n';
    std::cout << "Game over\n";
}
