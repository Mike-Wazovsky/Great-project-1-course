#include <QPropertyAnimation>
#include "arithmeticwindow.h"
#include "ui_arithmeticwindow.h"
#include "arithmetic_problem.h"

GameArithmeticProblem problem(rand());

ArithmeticWindow::ArithmeticWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArithmeticWindow)
{
    ui->setupUi(this);
    ui->label_2->setText(QString::fromStdString(problem.start_game()));
    //ui->progressBar->setValue(55);
    //ui->progressBar->setMinimum(0);
    //ui->progressBar->setMaximum(100);
    //QPropertyAnimation animation(ui->progressBar, "value");
    //animation.setDuration(2000);
    //animation.setStartValue(0);
    //animation.setEndValue(100);
}

ArithmeticWindow::~ArithmeticWindow()
{
    delete ui;
}


void ArithmeticWindow::on_pushButton_clicked()
{
    std::string answ = ui->lineEdit->text().toStdString();
    problem.check_answer(stoi(answ)); //Падает
    this->close();
}
