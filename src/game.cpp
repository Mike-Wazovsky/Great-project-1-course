#include "include/game.h"

void Game::to_uml(int k) {
    std::string path = "../diagram_uml/myth_" + std::to_string(k) + ".txt";
    translation_from_json_to_uml(j, path);
}

void Game::change_resources(bool f) {
    if (it.empty() || j["events"][it]["is_end"]){
        return;
    }
    /*std::string b;
    if (f) {
        b = "yes";
    }
    else {
        b = "no";
    }
    for (auto i = 0; i < resource[0]) {
        resource[i] += static_cast<int>(j["events"][it]["routes"][b]["resource_change"]["resource" + std::to_string(i + 1)]);
    }*/
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
    /*for (auto i = 1; i <= resource[0]) {
        if (resource[i] > resource_high || resource[i] < resource_low) {
            resource1 = j["resources"]["resource + std::to_string(i + 1)"]["start_value"];
        }
    }*/

    if (resource1 > resource_high || resource1 < resource_low) {
        resource1 = j["resources"]["resource1"]["start_value"];
    }
    if (resource2 > resource_high || resource2 < resource_low) {
        resource2 = j["resources"]["resource2"]["start_value"];
    }
    if (resource3 > resource_high || resource3 < resource_low) {
        resource3 = j["resources"]["resource3"]["start_value"];
    }
    if (resource4 > resource_high || resource4 < resource_low) {
        resource4 = j["resources"]["resource4"]["start_value"];
    }
}

bool Game::check_resources() {
    if (resource1 >= j["resources"]["resource1"]["highest_value"]) {
        copy_it = it;
        it = "chance_to_change_resource1_high";
        return false;
    }
    if (resource1 <= j["resources"]["resource1"]["lowest_value"]) {
        copy_it = it;
        it = "chance_to_change_resource1_low";
        return false;
    }

    if (resource2 >= j["resources"]["resource2"]["highest_value"]) {
        copy_it = it;
        it = "chance_to_change_resource2_high";
        return false;
    }
    if (resource2 <= j["resources"]["resource2"]["lowest_value"]) {
        copy_it = it;
        it = "chance_to_change_resource2_low";
        return false;
    }

    if (resource3 >= j["resources"]["resource3"]["highest_value"]) {
        copy_it = it;
        it = "chance_to_change_resource3_high";
        return false;
    }
    if (resource3 <= j["resources"]["resource3"]["lowest_value"]) {
        copy_it = it;
        it = "chance_to_change_resource3_low";
        return false;
    }

    if (resource4 >= j["resources"]["resource4"]["highest_value"]) {
        copy_it = it;
        it = "chance_to_change_resource4_high";
        return false;
    }
    if (resource4 <= j["resources"]["resource4"]["lowest_value"]) {
        copy_it = it;
        it = "chance_to_change_resource4_low";
        return false;
    }
    return true;
}

void Game::check_end() {
    if (resource1 >= j["resources"]["resource1"]["highest_value"]) {
        it = "die_resource1_high";
        return;
    }
    if (resource1 <= j["resources"]["resource1"]["lowest_value"]) {
        it = "die_resource1_low";
        return;
    }

    if (resource2 >= j["resources"]["resource2"]["highest_value"]) {
        it = "die_resource2_high";
        return;
    }
    if (resource2 <= j["resources"]["resource2"]["lowest_value"]) {
        it = "die_resource2_low";
        return;
    }

    if (resource3 >= j["resources"]["resource3"]["highest_value"]) {
        it = "die_resource3_high";
        return;
    }
    if (resource3 <= j["resources"]["resource3"]["lowest_value"]) {
        it = "die_resource3_low";
        return;
    }

    if (resource4 >= j["resources"]["resource4"]["highest_value"]) {
        it = "die_resource4_high";
        return;
    }
    if (resource4 <= j["resources"]["resource4"]["lowest_value"]) {
        it = "die_resource4_low";
        return;
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

int Game::mini_game() {
    return j["events"][it]["mini_game"];
}

void Game::loss_in_mini_game(int k) {
    if (k == arithmetic_problem) {
        it = "die_arithmetic_problem";
    }
    else if (k == saper) {
        it = "die_saper";
    }
}