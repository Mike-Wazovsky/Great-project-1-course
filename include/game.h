#pragma once

#include <utility>
#include <string>
#include <fstream>
#include <vector>
#include <climits>
#include "uml.h"
#include "json.hpp"

#include <iostream>

using json = nlohmann::json;

struct Game {
private:
    const int resource_high = 900;
    const int resource_low = -900;
    const int amount_of_resources = 4;
    std::vector<int> resource;
    std::vector<std::string> name_resource;
    json j;
    std::string it;
    std::string copy_it;
public:
    const int arithmetic_problem = 1;
    const int saper = 2;
    void loss_in_mini_game(int k);
    std::vector<int> resources();
    std::vector<std::string> name_resources();

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
        plots.close();
        resource.resize(amount_of_resources);
        name_resource.resize(amount_of_resources);
    }

    explicit Game() {
        std::string path;
        path = "../TESTS/myth_0.json";
        std::ifstream plots(path);
        plots >> j;
        plots.close();
        // TODO close and exceptions
        resource.resize(amount_of_resources);
        name_resource.resize(amount_of_resources);
    }

    void to_uml(int k);


    bool is_game_ended();
    void move(bool);
    std::string start_game();
    std::string get_story();
    void check_end();
    bool check_resources();
    void change_resources(bool f);

    int mini_game();



    void change_plot(int k);
};

