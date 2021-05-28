#include "include/windowwithgame.h"
#include "include/arithmetic_problem.h"
#include "include/arithmeticwindow.h"
#include "include/controller.h"
#include "include/game.h"
#include "include/mainwindow.h"
#include "include/resultwindow.h"
#include "include/sapper.h"
#include "include/uml.h"
#include "include/view.h"
#include "ui_windowwithgame.h"
#include <QMessageBox>
#include <cstdlib>
#include <iostream>

extern bool result_mini_game;

namespace p {
int get_the_number_plot(int k) { return std::rand() % k; }

const int the_number_of_plots = 3;
int number_plot = 0;
bool selection = true;
bool prepare_for_game = false;
bool resource_check = false;
Game select_plot(-1);
Game game;
View view;
Controller controller;
} // namespace p

windowwithgame::windowwithgame(QWidget *parent)
    : QDialog(parent), ui(new Ui::windowwithgame) {
  ui->setupUi(this);
  p::view.start_move("Хотите ли вы сами выбрать сюжет?");
  ui->label->setText(
      QString::fromStdString("Хотите ли вы сами выбрать сюжет?"));
  ui->toolButton->setText(
      QString::fromStdString("Хотите ли вы сами выбрать сюжет?"));
}

windowwithgame::~windowwithgame() { delete ui; }

void windowwithgame::on_Yes_Button_clicked() {
  if (p::selection) {
    p::selection = false;
    p::prepare_for_game = true;
    part_of_selection(true);
  } else if (p::prepare_for_game) {
    part_of_selection(true);
  } else {
    on_Button_clicked(true);
  }
}

void windowwithgame::on_No_Button_clicked() {
  if (p::selection) {
    p::selection = false;
    p::prepare_for_game = false;
    p::number_plot = p::get_the_number_plot(p::the_number_of_plots);
    p::game.change_plot(p::number_plot);

    p::game.start_game();
    std::string str =
        p::view.start_game(p::game.start_game() + '\n' + p::game.get_story());
    ui->label->setText(QString::fromStdString(str));
    ui->toolButton->setText(QString::fromStdString(str));
  } else if (p::prepare_for_game) {
    part_of_selection(false);
  } else {
    on_Button_clicked(false);
  }
}

void windowwithgame::on_Button_clicked(bool choice) {
  if (p::resource_check) {
    p::game.change_resources(choice);
    new_resources();

    p::resource_check = false;
    p::game.check_end();
    if (p::game.is_game_ended()) {
      this->close();
      std::string result_of_game = p::view.end_game(p::game.get_story());
      QMessageBox::about(this, "result of story",
                         QString::fromStdString(result_of_game));
      MainWindow main;
      main.resize(800, 750);
      main.show();
    }
    std::string new_move = p::view.start_move(p::game.get_story());
    ui->toolButton->setText(QString::fromStdString(new_move));
    ui->label->setText(QString::fromStdString(new_move));
  } else {
    p::game.change_resources(choice);
    new_resources();
    p::game.move(choice);
    if (p::game.is_game_ended()) {
      this->close();
      std::string result_of_game = p::view.end_game(p::game.get_story());
      QMessageBox::about(this, "result of story",
                         QString::fromStdString(result_of_game));
      MainWindow main;
      main.resize(800, 750);
      main.show();
    } else {
      if (p::game.mini_game() != 0) {
        if (p::game.mini_game() == p::game.arithmetic_problem) {
          ArithmeticWindow arwind;
          arwind.setModal(true);
          arwind.exec();
        } else if (p::game.mini_game() == p::game.saper) {
          sapper sapwind;
          sapwind.setModal(true);
          sapwind.exec();
        }
        if (!result_mini_game) {
          p::game.loss_in_mini_game(p::game.mini_game());
          result_mini_game = true;
        }
      }
      if (p::game.is_game_ended()) {
        this->close();
        std::string result_of_game = p::view.end_game(p::game.get_story());
        QMessageBox::about(this, "result of story",
                           QString::fromStdString(result_of_game));
        MainWindow main;
        main.resize(800, 750);
        main.show();
      }

      if (!p::game.check_resources()) {
        std::string check = p::view.start_move(p::game.get_story());
        ui->label->setText(QString::fromStdString(check));
        ui->toolButton->setText(QString::fromStdString(check));
        p::resource_check = true;
      } else {
        std::string new_move = p::view.start_move(p::game.get_story());
        ui->label->setText(QString::fromStdString(new_move));
        ui->toolButton->setText(QString::fromStdString(new_move));
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
    std::string str =
        p::view.start_game(p::game.start_game() + '\n' + p::game.get_story());
    ui->label->setText(QString::fromStdString(str));
    ui->toolButton->setText(QString::fromStdString(str));
  } else {
    std::string new_question = p::view.start_move(p::select_plot.get_story());
    ui->label->setText(QString::fromStdString(new_question));
    ui->toolButton->setText(QString::fromStdString(new_question));
  }
}

void windowwithgame::new_resources() {
  std::vector<int> num;
  std::vector<std::string> names;
  num = p::game.resources();
  names = p::game.name_resources();
  ui->num1->setText(QString::fromStdString(std::to_string(num[0])));
  ui->num2->setText(QString::fromStdString(std::to_string(num[1])));
  ui->num3->setText(QString::fromStdString(std::to_string(num[2])));
  ui->num4->setText(QString::fromStdString(std::to_string(num[3])));
  ui->res1->setText(QString::fromStdString(names[0]));
  ui->res2->setText(QString::fromStdString(names[1]));
  ui->res3->setText(QString::fromStdString(names[2]));
  ui->res4->setText(QString::fromStdString(names[3]));
}