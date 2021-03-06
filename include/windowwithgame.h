#pragma once

#include <QDialog>

namespace Ui {
class windowwithgame;
}

class windowwithgame : public QDialog {
  Q_OBJECT

public:
  explicit windowwithgame(QWidget *parent = nullptr);
  ~windowwithgame();

private slots:

  void on_Yes_Button_clicked();

  void on_No_Button_clicked();

  void on_Button_clicked(bool choice);

  void part_of_selection(bool choice);

  void new_resources();

private:
  Ui::windowwithgame *ui;
};