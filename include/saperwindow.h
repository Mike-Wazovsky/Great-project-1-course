#pragma once

#include <QDialog>

namespace Ui {
class SaperWindow;
}

class SaperWindow : public QDialog {
  Q_OBJECT

public:
  explicit SaperWindow(QWidget *parent = nullptr);
  ~SaperWindow();

private:
  Ui::SaperWindow *ui;
};