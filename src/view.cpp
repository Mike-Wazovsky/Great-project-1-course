#include "include/view.h"
#include <iostream>
#include <string>

std::string View::start_game(std::string text) {
    return text;
}

std::string View::start_move(std::string move) {
    return move;
}

std::string View::end_game(std::string end) {
    return (end + "\n\nКонец игры");
}
