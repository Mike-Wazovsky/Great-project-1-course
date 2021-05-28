#pragma once

#include "Button.h"
#include <QDialog>

namespace Ui {
class sapper;
}

class sapper : public QDialog {
  Q_OBJECT
  int x = 6;
  int y = 6;
  int mines = 5;
  int left;

public:
  explicit sapper(QWidget *parent = nullptr);
  ~sapper();
private slots:
  Button *createButton(int k, int i, int j);
  void create_cells();
  void settings_of_grid();
  void calculate_grid();
  void add_mines(int num_of_m);
public slots:
  void waiting_end();
  void check_zero(int i, int j);
  void check_win();
  void left_decr();
  void left_incr();

private:
  Ui::sapper *ui;
};