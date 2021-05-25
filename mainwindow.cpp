#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowwithgame.h"
#include "settingswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    settingswindow settings;
    settings.setModal(true);
    settings.exec();
}

void MainWindow::on_pushButton_clicked()
{
    windowwithgame game_window;
    this->close();
    game_window.setModal(true);
    game_window.exec();
}
