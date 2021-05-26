#include "include/arithmetic_problem.h"

extern bool result_mini_game;

    void GameArithmeticProblem::start_game () {
        it = std::rand() % static_cast<int>(j["number"]);

        // TODO show problem: cout << j[std::to_string(it)]["problem"];

        int ans = 0;
        // TODO player gives answer

        check_answer(ans);
    }

    void GameArithmeticProblem::check_answer(int ans) {
        if (ans != j[std::to_string(it)]["answer"]) {
            result_mini_game = false;
        }
    }