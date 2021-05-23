#pragma once

#include <utility>
#include <string>
#include <fstream>
#include <climits>
#include "uml.h"
#include "json.hpp"

using json = nlohmann::json;

struct Game {
private:
    const int resource_high = INT_MAX / 2;
    const int resource_low = INT_MIN / 2;
    int resource1 = 0;
    int resource2 = 0;
    int resource3 = 0;
    int resource4 = 0;
    json j;
    std::string it;
    std::string copy_it;
public:
    explicit Game(int k) {
        std::string path;
        if (k == -1) {
            path = "../TESTS/plot_selection.json";
        }
        else {
            path = "../TESTS/myth_" + std::to_string(k) + ".json";
        }
        std::ifstream plots(path);
        plots >> j;
        // TODO close and exceptions
    }

    void to_uml(int k);

    bool is_game_ended();
    void move(bool);
    std::string start_game();
    std::string get_story();
    void check_end();
    bool check_resources();
    void change_resources(bool f);
};

