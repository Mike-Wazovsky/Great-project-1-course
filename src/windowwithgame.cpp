#include "include/windowwithgame.h"
#include "ui_windowwithgame.h"
#include "include/resultwindow.h"
#include "include/mainwindow.h"
#include "include/second_main.h"
#include "include/arithmetic_problem.h"
#include "include/game.h"
#include "include/controller.h"
#include "include/view.h"
#include "include/uml.h"
#include <cstdlib>
#include <iostream>
#include <QMessageBox>
#include "include/minigame.h"

extern bool result_mini_game;
//extern const int the_number_of_plots;

namespace p{
    int get_the_number_plot(int k) {
        return std::rand() % k;
    }

    const int the_number_of_plots = 3;
    int number_plot = 0;
    bool selection = true;
    bool prepare_for_game = false;
    bool resource_check = false;
    Game select_plot(-1);
    Game game;
    View view;
    Controller controller;
}
windowwithgame::windowwithgame(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::windowwithgame)
{
    ui->setupUi(this);
    //p::game.to_uml(p::number_plot);
    p::view.start_move("Хотите ли вы сами выбрать сюжет?");

    //p::game.start_game();
    //std::string str = p::view.start_game(p::game.start_game());
    ui->label->setText(QString::fromStdString("Хотите ли вы сами выбрать сюжет?"));
}

windowwithgame::~windowwithgame()
{
    delete ui;
}

void windowwithgame::on_Yes_Button_clicked()
{
    if (p::selection) {
        p::selection = false;
        p::prepare_for_game = true;
        part_of_selection(true);
        //p::view.start_move(p::select_plot.get_story());
        //std::string new_question = p::view.start_move(p::select_plot.get_story());
        //ui->label->setText(QString::fromStdString(new_question));
    }
    else if (p::prepare_for_game) {
        part_of_selection(true);
    }
    else {
        on_Button_clicked(true);
    }
}

void windowwithgame::on_No_Button_clicked()
{
    if (p::selection) {
        p::selection = false;
        p::prepare_for_game = false;
        p::number_plot = p::get_the_number_plot(p::the_number_of_plots);
        p::game.change_plot(p::number_plot);

        p::game.start_game();
        std::string str = p::view.start_game(p::game.start_game());
        ui->label->setText(QString::fromStdString(str));
    }
    else if (p::prepare_for_game) {
        part_of_selection(false);
    }
    else {
        on_Button_clicked(false);
    }
}

void windowwithgame::on_Button_clicked(bool choice) {
    if (p::resource_check) {
        p::game.change_resources(choice);
        p::resource_check = false;
        p::game.check_end();
        std::string new_move = p::view.start_move(p::game.get_story());
        ui->label->setText(QString::fromStdString(new_move));
    }
    else {
        p::game.change_resources(choice); //!!!!!!!!!!!!!!!!!!!!!
        p::game.move(choice);
        p::game.check_end();
        if (p::game.is_game_ended()) {
            this->close();
            //resultwindow result;
            //result.setModal(true);
            //result.exec();
            // TODO better to make a window with result
            std::string result_of_game = p::view.end_game(p::game.get_story());
            QMessageBox::about(this, "result of story", QString::fromStdString(result_of_game));
            MainWindow main;
            main.resize(800, 750);
            main.show();
        }
        else {
            //p::game.mini_game();
            if (p::game.mini_game() != 0) {
                if (p::game.mini_game() == p::game.arithmetic_problem) {
                    GameArithmeticProblem mini_game(std::rand());
                    mini_game.start_game();
                } else if (p::game.mini_game() == p::game.saper) {
                    Minigame wind;
                    wind.setModal(true);
                    wind.exec();
                }
                if (!result_mini_game) {
                    p::game.loss_in_mini_game(p::game.mini_game());
                    result_mini_game = true;
                }
            }
            if (p::game.is_game_ended()) {
                this->close();
                //resultwindow result;
                //result.setModal(true);
                //result.exec();
                // TODO better to make a window with result
                std::string result_of_game = p::view.end_game(p::game.get_story());
                QMessageBox::about(this, "result of story", QString::fromStdString(result_of_game));
                MainWindow main;
                main.resize(800, 750);
                main.show();
            }

            if (!p::game.check_resources()) {
                std::string check = p::view.start_move(p::game.get_story());
                ui->label->setText(QString::fromStdString(check));
                p::resource_check = true;
            } else {
                std::string new_move = p::view.start_move(p::game.get_story());
                ui->label->setText(QString::fromStdString(new_move));
            }
        }
    }
}

void windowwithgame::part_of_selection(bool choice) {
    p::select_plot.move(choice);
    if (p::select_plot.is_game_ended()) {
        p::prepare_for_game = false;
        p::number_plot = atoi(p::select_plot.get_story().c_str());
        Game g(p::number_plot);
        p::game.change_plot(p::number_plot);

        p::game.start_game();
        std::string str = p::view.start_game(p::game.start_game());
        ui->label->setText(QString::fromStdString(str));
    }
    else {
        std::string new_question = p::view.start_move(p::select_plot.get_story());
        ui->label->setText(QString::fromStdString(new_question));
    }
}



/*
#include "include/windowwithgame.h"
#include "ui_windowwithgame.h"
#include "include/resultwindow.h"
#include "include/mainwindow.h"
#include "include/second_main.h"
#include "include/arithmetic_problem.h"
#include "include/game.h"
#include "include/controller.h"
#include "include/view.h"
#include "include/uml.h"
#include <cstdlib>
#include <iostream>
#include <QMessageBox>
#include "include/minigame.h"

namespace p{
int get_the_number_plot(int k) {
    return std::rand() % k;
}

extern const int the_number_of_plots = 2;
int number_plot = 0;
bool selection = true;
bool prepare_for_game = false;
bool resource_check = false;
Game select_plot(-1);

extern Game game;
View view;
extern Controller controller;
}
windowwithgame::windowwithgame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowwithgame)
{
    ui->setupUi(this);
    //p::game.to_uml(p::number_plot);
    p::view.start_move("Хотите ли вы сами выбрать сюжет?");

    //p::game.start_game();
    //std::string str = p::view.start_game(p::game.start_game());
    ui->label->setText(QString::fromStdString("Хотите ли вы сами выбрать сюжет?"));
}

windowwithgame::~windowwithgame()
{
    delete ui;
}

void windowwithgame::on_Yes_Button_clicked()
{
    if (p::selection) {
        p::selection = false;
        p::prepare_for_game = true;
        part_of_selection(true);
        //p::view.start_move(p::select_plot.get_story());
        //std::string new_question = p::view.start_move(p::select_plot.get_story());
        //ui->label->setText(QString::fromStdString(new_question));
    }
    else if (p::prepare_for_game) {
        part_of_selection(true);
    }
    else {
        on_Button_clicked(true);
    }
}

void windowwithgame::on_No_Button_clicked()
{
    if (p::selection) {
        p::selection = false;
        p::prepare_for_game = false;
        p::number_plot = p::get_the_number_plot(p::the_number_of_plots);
        p::game.change_plot(p::number_plot);

        p::game.start_game();
        std::string str = p::view.start_game(p::game.start_game());
        ui->label->setText(QString::fromStdString(str));
    }
    else if (p::prepare_for_game) {
        part_of_selection(false);
    }
    else {
    on_Button_clicked(false);
    }
}

void windowwithgame::on_Button_clicked(bool choice) {
    if (p::resource_check) {
        p::game.change_resources(choice);
        p::resource_check = false;
        p::game.check_end();
        std::string new_move = p::view.start_move(p::game.get_story());
        ui->label->setText(QString::fromStdString(new_move));
    }
    else {
        p::game.change_resources(choice); //!!!!!!!!!!!!!!!!!!!!!
        p::game.move(choice);
        p::game.check_end();
        if (p::game.is_game_ended()) {
            this->close();
            //resultwindow result;
            //result.setModal(true);
            //result.exec();
            // TODO better to make a window with result
            std::string result_of_game = p::view.end_game(p::game.get_story());
            QMessageBox::about(this, "result of story", QString::fromStdString(result_of_game));
            MainWindow main;
            main.resize(800, 750);
            main.show();
        }
        else {
            //p::game.mini_game();
            if (*/
/*p::game.mini_game() == p::game.arithmetic_problem*//*
 true) {
                GameArithmeticProblem mini_game(1);
                if(!mini_game.start_game()) {
                    p::game.loss_in_mini_game(p::game.arithmetic_problem);
                }
            }
            else if (*/
/*p::game.mini_game() == p::game.saper*//*
 true) {
                Minigame wind;
                wind.setModal(true);
                wind.exec();
            }
            if (p::game.is_game_ended()) {
                //break;
            }

            if (!p::game.check_resources()) {
                std::string check = p::view.start_move(p::game.get_story());
                ui->label->setText(QString::fromStdString(check));
                p::resource_check = true;
            } else {
            std::string new_move = p::view.start_move(p::game.get_story());
            ui->label->setText(QString::fromStdString(new_move));
            }
        }
    }
}

void windowwithgame::part_of_selection(bool choice) {
    p::select_plot.move(choice);
    if (p::select_plot.is_game_ended()) {
        p::prepare_for_game = false;
        p::number_plot = atoi(p::select_plot.get_story().c_str());
        Game g(p::number_plot);
        p::game.change_plot(p::number_plot);

        p::game.start_game();
        std::string str = p::view.start_game(p::game.start_game());
        ui->label->setText(QString::fromStdString(str));
    }
    else {
        std::string new_question = p::view.start_move(p::select_plot.get_story());
        ui->label->setText(QString::fromStdString(new_question));
    }
}
*/
