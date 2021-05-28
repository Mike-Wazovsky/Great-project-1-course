#include "include/arithmeticwindow.h"
#include "include/arithmetic_problem.h"
#include "ui_arithmeticwindow.h"
#include <QPropertyAnimation>

GameArithmeticProblem problem(rand());

ArithmeticWindow::ArithmeticWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::ArithmeticWindow) {
  ui->setupUi(this);
  ui->label_2->setText(QString::fromStdString(problem.start_game()));
}

ArithmeticWindow::~ArithmeticWindow() { delete ui; }

void ArithmeticWindow::on_pushButton_clicked() {
  std::string answ = ui->lineEdit->text().toStdString();
  problem.check_answer(stoi(answ)); //Падает
  this->close();
}
