#include "include/arithmetic_problem.h"

namespace mini_games {
    std::string GameArithmeticProblem::start_game () {
        it = std::rand() % static_cast<int>(j["number"]);
        return j[std::to_string(it)]["problem"];
    }

    bool GameArithmeticProblem::check_answer(int ans) {
        return ans == j[std::to_string(it)]["answer"];
    }
}