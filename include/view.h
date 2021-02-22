#pragma once

#include <string>
struct View {
public:
    void Start_game();
    void Start_move(std::string move);
    //TODO add a result_move inside main.cpp
    void Result_move(std::string result);
    void End_game(std::string end);
};