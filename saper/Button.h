#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>
//#include "mainwindow.h"

class MainWindow;

class Button : public QToolButton
{
    Q_OBJECT
    int status = 0;
    int x = 0;
    int y = 0;
    bool revealed = false;
    MainWindow* win =nullptr;

public:
    explicit Button(int st = 0, int x_ = 0, int y_ = 0, MainWindow *par_win = nullptr, QWidget *parent = nullptr)
        : QToolButton(parent), win(par_win)
    {
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        status = st;
        x = x_;
        y = y_;
        //setText(text);
    }

    QSize sizeHint() const override;
    void changeStatus(int new_st);
    int get_status();
    bool get_rev();
public slots:
    void oncellClicked();
    void cellClickedforrecursion();
};

#endif // BUTTON_H
