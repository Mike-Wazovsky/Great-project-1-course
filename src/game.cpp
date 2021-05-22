#include "include/game.h"

void Game::to_uml(int k) {
    std::string path = "../diagram_uml/myth_" + std::to_string(k) + ".txt";
    translation_from_json_to_uml(j, path);
}

void Game::change_resourses(bool f) {
    if (it.empty() || j["events"][it]["is_end"]){
        return;
    }
    if (f) {
        determination += static_cast<int>(j["events"][it]["routes"]["yes"]["resource_change"]["determination"]);
    } else {
        determination += static_cast<int>(j["events"][it]["routes"]["no"]["resource_change"]["determination"]);
    }
}

void Game::check_end() {
    if (determination >= j["resources"]["determination"]["highest_value"]) {
        it = "die_high";
    }
    if (determination <= j["resources"]["determination"]["lowest_value"]) {
        it = "die_low";
    }
}

bool Game::is_game_ended() const {
    return j["events"][it]["is_end"];
}

void Game::move(bool choice) {
    if (it.empty()) {
        it = "event1";
    }
    else {
        if (choice) {
            it = j["events"][it]["routes"]["yes"]["next_event"];
        }
        else {
            it = j["events"][it]["routes"]["no"]["next_event"];
        }
    }
}

std::string Game::start_game() {
    determination = j["resources"]["determination"]["start_value"];
    it = "event1";
    return j["declaring_character"];
}

std::string Game::get_story() {
    return j["events"][it]["text"];
}
