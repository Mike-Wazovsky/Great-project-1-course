#include "game.h"

void Game::change_resourses(bool f) {
    if (f) {
        determination += event.determination_if_yes;
    } else {
        determination += event.determination_if_no;
    }
}

void Game::check_end() {
    if (determination >= 100) {
        end_of_story = "You full of determination to start your way";
        end_of_game = true;
    }
    if (determination <= 0) {
        end_of_story = "You are not enough determined for adventure";
        end_of_game = true;
    }
    if (event.is_it_the_end) {
        end_of_story = event.s;
        end_of_game = true;
    }
}

bool Game::is_game_ended() const {
    return end_of_game;
}

std::string Game::get_end_of_story() {
    return end_of_story;
}


