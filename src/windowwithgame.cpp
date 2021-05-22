#include "include/windowwithgame.h"
#include "include/ui_windowwithgame.h"
#include "include/resultwindow.h"
#include "include/mainwindow.h"
#include "include/second_main.h"
#include "include/game.h"
#include "include/controller.h"
#include "include/view.h"
#include "include/uml.h"
#include <cstdlib>
#include <iostream>
#include <QMessageBox>

const int the_number_of_plots = 2;
int number_plot = std::rand() % the_number_of_plots;

Game game(number_plot);
View view;
Controller controller;

windowwithgame::windowwithgame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowwithgame)
{
    ui->setupUi(this);
    game.to_uml(number_plot);
    std::string str = view.start_game(game.start_game());
    // QString qstr(str[0]);
    ui->label->setText(QString::fromStdString(str));
}

windowwithgame::~windowwithgame()
{
    delete ui;
}

void windowwithgame::on_Yes_Button_clicked()
{
    game.change_resourses(true);
    game.move(true);
    game.check_end();
    if (game.is_game_ended()) {
        this->close();
        //resultwindow result;
        //result.setModal(true);
        //result.exec();
        // TODO better to make a window with result
        std::string result_of_game = view.end_game(game.get_story());
        QMessageBox::about(this, "result of story", QString::fromStdString(result_of_game));
	MainWindow main;
        main.resize(800, 750);
        main.show();
    }
    else {
        std::string new_move = view.start_move(game.get_story());
        ui->label->setText(QString::fromStdString(new_move));
    }
}

void windowwithgame::on_No_Button_clicked()
{
    ui->label->setText("no" /*qst*/);
    game.change_resourses(false);
    game.move(false);
    game.check_end();
    if (game.is_game_ended()) {
        this->close();
        //resultwindow result;
        //result.setModal(true);
        //result.exec();
        // TODO better to make a window with result
        std::string result_of_game = view.end_game(game.get_story());
        QMessageBox::about(this, "result of story", QString::fromStdString(result_of_game));
        MainWindow main;
        main.resize(800, 750);
        main.show();
    }
    else {
        std::string new_move = view.start_move(game.get_story());
        ui->label->setText(QString::fromStdString(new_move));
    }
}

void windowwithgame::on_Button_clicked(bool choice) {

}
