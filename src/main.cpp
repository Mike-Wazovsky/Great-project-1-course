#include "game.h"
#include "controller.h"
#include "view.h"
#include "story.h"

int main() {
    Game game(50);
    View view;
    Controller controller;
    Base base = first_myth();

    view.Start_game();
    game.event = base.give_a_story(); // игра получает событие
    while (!game.is_game_ended()) {
        view.Start_move(game.event.get_story()); // выводит событие
        bool desicion = controller.Move(); // получает ответ игрока
        game.change_resourses(desicion); // меняет ресурсы
        base.count_a_conclusion(desicion); // смещает историю в нужном направлении
        game.event = base.give_a_story(); // игра получает событие
        game.check_end(); // проверяет на концвоку
    }
    view.End_game(game.get_end_of_story());
    return 0;
}