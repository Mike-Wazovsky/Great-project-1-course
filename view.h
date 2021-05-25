#pragma once

#include <string>
struct View {
public:
    std::string start_game(std::string);
    std::string start_move(std::string move);
    //TODO add a result_move inside main.cpp
   // void Result_move(std::string result);
    std::string end_game(std::string end);
};
