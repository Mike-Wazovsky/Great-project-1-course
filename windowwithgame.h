#ifndef WINDOWWITHGAME_H
#define WINDOWWITHGAME_H

#include <QDialog>

namespace Ui {
class windowwithgame;
}

class windowwithgame : public QDialog
{
    Q_OBJECT

public:
    explicit windowwithgame(QWidget *parent = nullptr);
    ~windowwithgame();

private slots:

    void on_Yes_Button_clicked();

    void on_No_Button_clicked();

    void windowwithgame::on_Button_clicked(bool choice);
private:
    Ui::windowwithgame *ui;
};

#endif // WINDOWWITHGAME_H
