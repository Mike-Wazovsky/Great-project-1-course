#pragma once

#include <QDialog>

namespace Ui {
class resultwindow;
}

class resultwindow : public QDialog {
  Q_OBJECT

public:
  explicit resultwindow(QWidget *parent = nullptr);
  ~resultwindow();

private:
  Ui::resultwindow *ui;
};