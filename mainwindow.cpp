#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "settingswindow.h"
//#include "gamewindow.h"
#include "windowwithgame.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/settings_button.png");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    settingswindow settings;
    settings.setModal(true);
    settings.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    windowwithgame game_window;
    this->close();
    game_window.setModal(true);
    game_window.exec();
}
