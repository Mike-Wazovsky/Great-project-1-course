#pragma once

#include "plot.h"


struct Game {
    // TODO: hide internal fields, convert to class for simplicity
private:
    bool end_of_game = false; //1 - game over
    int determination{50}; // resources
    std::string end_of_story;
public:
    Event event = {"If you see this, something goes wrong", 0, 0, false};
    Game(int determination_) : determination(determination_) {
    }

    void change_resourses(bool f);
    void check_end();
    bool is_game_ended() const;
    std::string get_end_of_story();
};

