#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "second_main.h"
#include "game.h"
#include "controller.h"
#include "view.h"
#include "uml.h"
#include <cstdlib>
#include <iostream>

//extern const int the_number_of_plots;
//extern int number_plot;

//extern Game game;
//extern View view;
//extern Controller controller;

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //game.to_uml(number_plot);
    //std::string str = view.start_game(game.start_game());
    //std::cout << str;
    //QString("Welcome %1").arg(str);
    //QString qstr(str[0]);
    ui->label->setText("Started" /*qst*/);
}

GameWindow::~GameWindow()
{
    delete ui;
}

