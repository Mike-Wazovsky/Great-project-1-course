/*#ifndef MINIGAME_H
#define MINIGAME_H

#include <QMainWindow>
#include <QDialog>
#include <thread>
#include "Button.h"

//QT_BEGIN_NAMESPACE
namespace Ui { class Minigame; }
//QT_END_NAMESPACE

class Minigame : public QDialog
{
    Q_OBJECT
    int x = 5;
    int y = 5;
    int mines = 3;
    int left;

public:
    explicit Minigame(QWidget *parent = nullptr);
    ~Minigame();

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
    Ui::Minigame *ui;
};
#endif // MINIGAME_H
*/

/*#ifndef MINIGAME_H
#define MINIGAME_H

#include <QDialog>
#include "Button.h"

namespace Ui {
class Minigame;
}

class Minigame : public QDialog
{
    Q_OBJECT
    int x = 10;
    int y = 10;

public:
    explicit Minigame(QWidget *parent = nullptr);
    ~Minigame();
private slots:
    Button *createButton(int k, int i, int j);
    void create_cells();
    void settings_of_grid();
    void calculate_grid();
    void add_mines(int num_of_m);
public slots:
    void waiting_end();
    void check_zero(int i, int j);

private:
    Ui::Minigame *ui;
};*/

//#endif  MINIGAME_H
