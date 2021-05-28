#pragma once

#include <QColor>
#include <QMouseEvent>
#include <QToolButton>

class sapper;

class Button : public QToolButton {
  Q_OBJECT
  int status = 0;
  int status_for_player = 0;
  int x = 0;
  int y = 0;
  bool revealed = false;
  sapper *win = nullptr;
  QColor num_colors[10];

protected:
  void mousePressEvent(QMouseEvent *e) override;
  QString enumNameFromValue(const Qt::MouseButton button);

public:
  explicit Button(int st = 0, int x_ = 0, int y_ = 0, sapper *par_win = nullptr,
                  QWidget *parent = nullptr)
      : QToolButton(parent), win(par_win) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    status = st;
    x = x_;
    y = y_;
  }

  QSize sizeHint() const override;
  void changeStatus(int new_st);
  int get_status();
  int get_status_for_player();
  bool get_rev();
public slots:
  void oncellClicked();
  void mineCheck();
  void cellClickedforrecursion();
};
