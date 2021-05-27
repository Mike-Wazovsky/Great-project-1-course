#include "arithmetic_problem.h"

extern bool result_mini_game;

std::string GameArithmeticProblem::start_game () {
    it = std::rand() % static_cast<int>(j["number"]);
    return j[std::to_string(it)]["problem"];
    }

void GameArithmeticProblem::check_answer(int ans) {
    if (ans != j[std::to_string(it)]["answer"]) {
        result_mini_game = false;
    }
}
