#include "include/second_main.h"
#include "include/game.h"
#include "include/controller.h"
#include "include/view.h"
///////////////////////////////////// new!
#include "include/arithmetic_problem.h"
#include <cstdlib>
#include <iostream>

///////////////////////////////////
extern bool result_mini_game;

int MainOfGame::get_the_number_plot(int k) {
    return std::rand() % k;
}

int MainOfGame::second_main() {
    Controller controller;
    View view;

    view.start_move("Хотите ли вы сами выбрать сюжет?");
    bool is_select = controller.move();

    int number_plot = 0;

    if (is_select) {
        Game select_plot(-1);
        while (!select_plot.is_game_ended()) {
            view.start_move(select_plot.get_story());
            bool choice = controller.move();
            select_plot.move(choice);
        }
        number_plot = atoi(select_plot.get_story().c_str());
    }
    else {
        number_plot = get_the_number_plot(the_number_of_plots);
    }

    Game game(number_plot);

    game.to_uml(number_plot);

    view.start_game(game.start_game());
    while (!game.is_game_ended()) {
        view.start_move(game.get_story());
        bool choice = controller.move();
        game.change_resources(choice);
        game.move(choice);

        //////////////////////////////////////////////////////////////new ->
        if (game.mini_game() != 0) {
            if (game.mini_game() == game.arithmetic_problem) {
                GameArithmeticProblem mini_game(std::rand());
                mini_game.start_game();
            } else if (game.mini_game() == game.saper) {
                /* Saper mini_game; // ?*/
            }
            if (!result_mini_game) {
                game.loss_in_mini_game(game.mini_game());
                result_mini_game = true;
            }
        }
        if (game.is_game_ended()) {
            break;
        }
        //////////////////////////////////////////////////////////////new <-

        if (!game.check_resources()) {
            view.start_move(game.get_story());
            bool choice = controller.move();
            game.change_resources(choice);
        }
        game.check_end();
    }
    view.end_game(game.get_story());
    return 0;
}
