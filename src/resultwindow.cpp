#include "include/resultwindow.h"
#include "include/windowwithgame.h"
#include "ui_resultwindow.h"

resultwindow::resultwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultwindow)
{
    ui->setupUi(this);
    ui->label->setText("result");
}

resultwindow::~resultwindow()
{
    delete ui;
}
