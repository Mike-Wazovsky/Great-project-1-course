#include "include/game.h"

void Game::to_uml(int k) {
    std::string path = "../diagram_uml/myth_" + std::to_string(k) + ".txt";
    translation_from_json_to_uml(j, path);
}

void Game::change_resources(bool f) {
    if (it.empty() || j["events"][it]["is_end"]){
        return;
    }
    if (f) {
        resource1 += static_cast<int>(j["events"][it]["routes"]["yes"]["resource_change"]["resource1"]);
        resource2 += static_cast<int>(j["events"][it]["routes"]["yes"]["resource_change"]["resource2"]);
        resource3 += static_cast<int>(j["events"][it]["routes"]["yes"]["resource_change"]["resource3"]);
        resource4 += static_cast<int>(j["events"][it]["routes"]["yes"]["resource_change"]["resource4"]);
    } else {
        resource1 += static_cast<int>(j["events"][it]["routes"]["no"]["resource_change"]["resource1"]);
        resource2 += static_cast<int>(j["events"][it]["routes"]["no"]["resource_change"]["resource2"]);
        resource3 += static_cast<int>(j["events"][it]["routes"]["no"]["resource_change"]["resource3"]);
        resource4 += static_cast<int>(j["events"][it]["routes"]["no"]["resource_change"]["resource4"]);
    }
}

void Game::check_end() {
    if (resource1 >= j["resources"]["resource1"]["highest_value"]) {
        it = "die_resource1_high";
    }
    if (resource1 <= j["resources"]["resource1"]["lowest_value"]) {
        it = "die_resource1_low";
    }

    if (resource2 >= j["resources"]["resource2"]["highest_value"]) {
        it = "die_resource2_high";
    }
    if (resource2 <= j["resources"]["resource2"]["lowest_value"]) {
        it = "die_resource2_low";
    }

    if (resource3 >= j["resources"]["resource3"]["highest_value"]) {
        it = "die_resource3_high";
    }
    if (resource3 <= j["resources"]["resource3"]["lowest_value"]) {
        it = "die_resource3_low";
    }

    if (resource4 >= j["resources"]["resource4"]["highest_value"]) {
        it = "die_resource4_high";
    }
    if (resource4 <= j["resources"]["resource4"]["lowest_value"]) {
        it = "die_resource4_low";
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
    resource1 = j["resources"]["resource1"]["start_value"];
    resource2 = j["resources"]["resource2"]["start_value"];
    resource3 = j["resources"]["resource3"]["start_value"];
    resource4 = j["resources"]["resource4"]["start_value"];
    it = "event1";
    return j["declaring_character"];
}

std::string Game::get_story() {
    return j["events"][it]["text"];
}
