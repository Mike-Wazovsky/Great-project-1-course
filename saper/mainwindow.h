#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include "Button.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int x = 10;
    int y = 10;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
