#pragma once

#include <QDialog>

namespace Ui {
class ArithmeticWindow;
}

class ArithmeticWindow : public QDialog {
  Q_OBJECT

public:
  explicit ArithmeticWindow(QWidget *parent = nullptr);
  ~ArithmeticWindow();

private slots:
  void on_pushButton_clicked();

private:
  Ui::ArithmeticWindow *ui;
};