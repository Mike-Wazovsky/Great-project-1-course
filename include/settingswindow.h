#pragma once

#include <QDialog>

namespace Ui {
class settingswindow;
}

class settingswindow : public QDialog {
  Q_OBJECT

public:
  explicit settingswindow(QWidget *parent = nullptr);
  ~settingswindow();

private slots:
  void on_pushButton_clicked();

private:
  Ui::settingswindow *ui;
};