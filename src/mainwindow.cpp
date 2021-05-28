#include "include/mainwindow.h"
#include "include/settingswindow.h"
#include "include/windowwithgame.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QPixmap pix2("../images/city.png");
  int w = ui->label->width();
  int h = ui->label->height();
  ui->label->setPixmap(pix2.scaled(w, h));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_2_clicked() {
  settingswindow settings;
  settings.setModal(true);
  settings.exec();
}

void MainWindow::on_pushButton_clicked() {
  windowwithgame game_window;
  this->close();
  game_window.setModal(true);
  game_window.exec();
}
