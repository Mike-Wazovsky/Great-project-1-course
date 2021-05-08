#include "settingswindow.h"
#include "ui_settingswindow.h"

settingswindow::settingswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingswindow)
{
    ui->setupUi(this);
}

settingswindow::~settingswindow()
{
    delete ui;
}

void settingswindow::on_pushButton_clicked()
{

}
