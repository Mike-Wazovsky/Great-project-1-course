#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "game_fwd.h"
#include "plot.h"
// TODO: an important question, not sure which though?
#include "view.h"

namespace macaftc {
    struct Game {
	// TODO: hide internal fields, convert to class for simplicity
        bool end_of_game = false; //1 - game over
	// TODO: checkout Stroustrup's way of initializing
        int determination {50}; // resources
        std::string end_of_story;
        Event event = {"", 0, 0, 0};

    public:
        Game(int determination_) : determination(determination_) {
        }

	// snake_case: give_end_of_game
	// camelCase: giveEndOfGame
	// PascalCase: GiveEndOfGame
	// SCREAMING_SNAKE_CASE: GIVE_END_OF_GAME
        void Move(bool f);
        void Check_end();
        bool give_end_of_game() const;
    };
}

#endif //PROJECT_GAME_H
