#include "include/game.h"

#include <iostream>

bool result_mini_game = true;

void Game::to_uml(int k) {
  std::string path = "../diagram_uml/myth_" + std::to_string(k) + ".txt";
  translation_from_json_to_uml(j, path);
}

void Game::change_resources(bool f) {
  if (it.empty() || j["events"][it]["is_end"]) {
    return;
  }
  std::string b;
  if (f) {
    b = "yes";
  } else {
    b = "no";
  }
  for (std::size_t i = 0; i < resource.size(); i++) {
    resource[i] +=
        static_cast<int>(j["events"][it]["routes"][b]["resource_change"]
                          ["resource" + std::to_string(i + 1)]);
  }
  for (std::size_t i = 0; i < resource.size(); i++) {
    if (resource[i] > resource_high || resource[i] < resource_low) {
      resource[i] =
          j["resources"]["resource" + std::to_string(i + 1)]["start_value"];
    }
  }
}

bool Game::check_resources() {
  for (std::size_t i = 0; i < resource.size(); i++) {
    if (resource[i] >=
        j["resources"]["resource" + std::to_string(i + 1)]["highest_value"]) {
      copy_it = it;
      it = "chance_to_change_resource" + std::to_string(i + 1) + "_high";
      return false;
    }
  }
  for (std::size_t i = 0; i < resource.size(); i++) {
    if (resource[i] <=
        j["resources"]["resource" + std::to_string(i + 1)]["lowest_value"]) {
      copy_it = it;
      it = "chance_to_change_resource" + std::to_string(i + 1) + "_low";
      return false;
    }
  }

  return true;
}

void Game::check_end() {
  for (std::size_t i = 0; i < resource.size(); i++) {
    if (resource[i] >=
        j["resources"]["resource" + std::to_string(i + 1)]["highest_value"]) {
      it = "die_resource" + std::to_string(i + 1) + "_high";
      return;
    }
  }
  for (std::size_t i = 0; i < resource.size(); i++) {
    if (resource[i] <=
        j["resources"]["resource" + std::to_string(i + 1)]["lowest_value"]) {
      it = "die_resource" + std::to_string(i + 1) + "_low";
      return;
    }
  }

  if (!copy_it.empty()) {
    it = copy_it;
    copy_it.clear();
  }
}

bool Game::is_game_ended() {
  if (it.empty()) {
    it = "event1";
  }
  return j["events"][it]["is_end"];
}

void Game::move(bool choice) {
  if (it.empty()) {
    it = "event1";
  } else {
    if (choice) {
      it = j["events"][it]["routes"]["yes"]["next_event"];
    } else {
      it = j["events"][it]["routes"]["no"]["next_event"];
    }
  }
}

std::string Game::start_game() {
  for (std::size_t i = 0; i < resource.size(); i++) {
    resource[i] =
        j["resources"]["resource" + std::to_string(i + 1)]["start_value"];
  }
  for (std::size_t i = 0; i < resource.size(); i++) {
    name_resource[i] =
        j["resources"]["resource" + std::to_string(i + 1)]["name"];
  }
  it = "event1";
  return j["declaring_character"];
}

std::string Game::get_story() { return j["events"][it]["text"]; }

int Game::mini_game() { return j["events"][it]["mini_game"]; }

void Game::loss_in_mini_game(int k) {
  if (k == arithmetic_problem) {
    it = "die_arithmetic_problem";
  } else if (k == saper) {
    it = "die_saper";
  }
}

void Game::change_plot(int k) {
  std::string path;
  if (k == -1) {
    path = "../TESTS/plot_selection.json";
  } else {
    path = "../TESTS/myth_" + std::to_string(k) + ".json";
  }
  std::ifstream plots(path);
  plots >> j;
  plots.close();
}

std::vector<int> Game::resources() { return resource; }

std::vector<std::string> Game::name_resources() { return name_resource; }
