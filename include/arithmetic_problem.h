#pragma once

#include "json.hpp"
#include <fstream>
#include <string>

using json = nlohmann::json;

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
    } else if (k == 1) {
      path = "../PROBLEM_FOR_MINI_GAMES/task_normal.json";
    } else {
      path = "../PROBLEM_FOR_MINI_GAMES/task_hard.json";
    }

    std::ifstream problems(path);
    problems >> j;
    problems.close();
  }

  std::string start_game();

  void check_answer(int ans);
};
