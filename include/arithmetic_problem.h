#pragma once

#include <string>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

namespace mini_games {
    struct GameArithmeticProblem {
    private:
        json j;
        std::size_t it = 0;
    public:
        GameArithmeticProblem(int k) {
            k = k % 3;
            std::string path;
            if (k == 0) {
                path = "../PROBLEM_FOR_MINI_GAMES/task_easy.json";
            }
            else if (k == 1) {
                path = "../PROBLEM_FOR_MINI_GAMES/task_normal.json";
            }
            else {
                path = "../PROBLEM_FOR_MINI_GAMES/task_hard.json";
            }

            std::ifstream problems(path);
            problems >> j;
            // TODO close and exceptions
        }

        std::string start_game ();

        bool check_answer(int ans);
    };
}