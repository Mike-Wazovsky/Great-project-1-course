#ifndef SAPPER_H
#define SAPPER_H

#include <QDialog>
#include "Button.h"

namespace Ui {
class sapper;
}

class sapper : public QDialog
{
    Q_OBJECT
    int x = 14;
    int y = 14;
    int mines = 50;
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

#endif // SAPPER_H
