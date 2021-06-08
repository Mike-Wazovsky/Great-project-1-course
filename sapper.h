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
    int x = 6;
    int y = 6;
    int mines = 3;
    int left;
    bool first_move = true;

public:
    explicit sapper(QWidget *parent = nullptr);
    ~sapper();
private slots:
    Button *createButton(int k, int i, int j);
    void create_cells();
    void settings_of_grid();
    void calculate_grid();
public slots:
    void add_mines(int num_of_m, int coord_x, int coord_y);
    void waiting_end();
    void check_zero(int i, int j);
    void check_win();
    void left_decr();
    void left_incr();
    bool get_first_move();
    int get_mines();
    void false_first_move();


private:
    Ui::sapper *ui;
};

#endif // SAPPER_H
