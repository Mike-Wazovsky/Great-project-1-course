#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "second_main.h"
#include "game.h"
#include "controller.h"
#include "view.h"
#include "uml.h"
#include <cstdlib>
#include <iostream>

const int the_number_of_plots = 2;
int number_plot = std::rand() % the_number_of_plots;

Game game(number_plot);
View view;
Controller controller;

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    game.to_uml(number_plot);
    std::string str = view.start_game(game.start_game());
    std::cout << str;
    //QString("Welcome %1").arg(str);
    QString qstr(str[0]);
    ui->label->setText("Started" /*qst*/);
}

GameWindow::~GameWindow()
{
    delete ui;
}

