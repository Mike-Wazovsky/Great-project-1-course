#ifndef PROJECT_VIEW_H
#define PROJECT_VIEW_H

#include <string>

namespace macaftc {
    struct View {
    public:
        void Start_game();
        void Start_move(std::string move);
        void Result_move(std::string result);
        void End_game(std::string end);
    };
}

#endif //PROJECT_VIEW_H