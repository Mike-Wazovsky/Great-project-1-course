#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H

#include "game_fwd.h"
#include "plot.h"
#include "view.h" //?

namespace macaftc {
    struct Game {
        bool end_of_game = false; //1 - game over
        int determination = 50; // resources
        std::string end_of_story;
        Event event = {"", 0, 0, 0};

    public:
        Game(int determination_) : determination(determination_) {
        }
        void Move(bool f);
        void Check_end();
        bool give_end_of_game() const;
    };
}

#endif //PROJECT_GAME_H
