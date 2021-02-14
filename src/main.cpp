#include <iostream>
#include "game.h"
#include "controller.h"
#include "view.h"

int main() {
    macaftc::Game game(50);
    macaftc::View view;
    macaftc::Controller controller;
    macaftc::Plot plot;
    macaftc::Base base;
    macaftc::Event first("Are yore ready to become a king today", 20, -20, 0);
    plot.add_event(first);
    base.add_plot(plot);

    view.Start_game();
    while (!game.give_end_of_game()) {
        game.event = base.give_a_story();
        view.Start_move(game.event.s);
        bool f = controller.Move();
        game.Move(f);
        game.Check_end();
    }
    view.End_game(game.end_of_story);
    return 0;
}