#include "include/arithmetic_problem.h"

namespace mini_games {
    bool GameArithmeticProblem::start_game () {
        it = std::rand() % static_cast<int>(j["number"]);
        // TODO show problem
        int ans = 0; // TODO player gives answer
        return check_answer(ans);
    }

    bool GameArithmeticProblem::check_answer(int ans) {
        return ans == j[std::to_string(it)]["answer"];
    }
}