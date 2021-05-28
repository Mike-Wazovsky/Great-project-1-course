#pragma once

#include <string>
struct View {
public:
  std::string start_game(std::string);
  std::string start_move(std::string move);
  std::string end_game(std::string end);
};
