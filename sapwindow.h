#ifndef SAPWINDOW_H
#define SAPWINDOW_H

#include <QMainWindow>
#include <thread>
#include "Button.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SapWindow; }
QT_END_NAMESPACE

class SapWindow : public QDialog
{
    Q_OBJECT
    int x = 10;
    int y = 10;

public:
    explicit SapWindow(QWidget *parent = nullptr);
    ~SapWindow();

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
    Ui::SapWindow *ui;
};
#endif // SAPWINDOW_H
