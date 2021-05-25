#include "windowwithgame.h"
#include "ui_windowwithgame.h"
#include "resultwindow.h"
#include "mainwindow.h"
#include "second_main.h"
#include "game.h"
#include "controller.h"
#include "view.h"
#include "uml.h"
#include <cstdlib>
#include <iostream>
#include <QMessageBox>

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

extern Game game(0);
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
            std::string new_move = p::view.start_move(p::game.get_story());
            ui->label->setText(QString::fromStdString(new_move));
            if (!p::game.check_resources()) {
                std::string check = p::view.start_move(p::game.get_story());
                ui->label->setText(QString::fromStdString(check));
                p::resource_check = true;
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
