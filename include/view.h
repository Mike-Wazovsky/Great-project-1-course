#pragma once

#include <string>
struct View {
public:
    void start_game(std::string);
    void start_move(std::string move);
    //TODO add a result_move inside main.cpp
   // void Result_move(std::string result);
    void end_game(std::string end);
};