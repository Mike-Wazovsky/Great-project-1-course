#pragma once

#include <utility>
#include <string>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

struct Game {
private:
    int determination = 0; // resources
    json j;
    std::string it;
public:
    explicit Game(int k) {
        std::string path = "/home/osboxes/Desktop/Me/lab/2/Great-project-1-course/TESTS/myth_" + std::to_string(k) + ".json";
        std::ifstream plots(path);
        plots >> j;
    }
    bool is_game_ended() const;
    void move(bool);
    std::string start_game();
    std::string get_story();
    void check_end();
    void change_resourses(bool f);
};

