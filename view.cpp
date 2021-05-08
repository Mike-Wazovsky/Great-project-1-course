#include "view.h"
#include <iostream>
#include <string>

std::string View::start_game(std::string text) {
    return text;
}

std::string View::start_move(std::string move) {
    //std::cout << move << std::endl;
    //std::cout << "What will you choose?" << std::endl;
    //std::cout << "(y/N)" << std::endl;
    return move;
}
/*
void View::Result_move(std::string result) {
    std::cout << result << std::endl;
}
*/
std::string View::end_game(std::string end) {
    //std::cout << end << std::endl;
    //std::cout << "Game over" << std::endl;
    return "Game over";
}
