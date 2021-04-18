#include "game.h"
#include "controller.h"
#include "view.h"
#include <cstdlib>

const int the_number_of_plots = 2;

int get_the_number_plot(int k) {
    return std::rand() % k;
}

int main() {
    int number_plot = get_the_number_plot(the_number_of_plots);

    Game game(number_plot);
    View view;
    Controller controller;

    view.start_game(game.start_game());
    while (!game.is_game_ended()) {
        view.start_move(game.get_story());
        bool choice = controller.move();
        game.change_resourses(choice);
        game.move(choice);
        game.check_end();
    }
    view.end_game(game.get_story());
    return 0;
}