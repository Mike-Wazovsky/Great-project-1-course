#include "sapper.h"
#include "ui_sapper.h"

extern bool result_mini_game;
Button *Cell[100][100];

sapper::sapper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sapper)
{
    ui->setupUi(this);
    //QGridLayout self();
    settings_of_grid();
    create_cells();
    add_mines(mines);
    calculate_grid();
    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->display(mines);
}

sapper::~sapper()
{
    delete ui;
}

Button *sapper::createButton(int k, int i, int j)
{
    Button *button = new Button(k, i, j, this);
    //button->oncellClicked(1, 1);
    //connect(button, SIGNAL(clicked()), button, SLOT(oncellClicked()));
    return button;
}

void sapper::create_cells() {
    for (int i = 0; i <x; i++) {
        for (int j = 0; j < y; j++) {
            Cell[i][j] = createButton(0, i, j);
            ui->gridLayout_2->addWidget(Cell[i][j], i, j);
            Cell[i][j]->setFixedSize(30, 30);
        }
    }
}

void sapper::settings_of_grid() {
    //ui->gridLayout_2->setSpacing(5);
    ui->gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
    ui->gridLayout_2->setHorizontalSpacing(0);
    ui->gridLayout_2->setVerticalSpacing(0);
}

void sapper::add_mines(int num_of_m) {
    while (num_of_m > 0) {
        int i = rand() % x;
        int j = rand() % y;
        if (Cell[i][j]->get_status() != -1) {
            Cell[i][j]->changeStatus(-1);
            num_of_m--;
        }
    }
    left = mines;
}

void sapper::calculate_grid() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (Cell[i][j]->get_status() != -1) {
                int mines = 0;
                int li = i, ri = i, lj = j, rj = j;
                if (i > 0)
                    li = i - 1;
                if (i < x - 1)
                    ri = i + 1;
                if (j > 0)
                    lj = j - 1;
                if (j < y - 1)
                    rj = j + 1;
                for (int f = li; f<=ri;f++) {
                    for (int s = lj; s<=rj;s++) {
                        if (Cell[f][s]->get_status() == -1)
                            mines++;
                    }
                }
                Cell[i][j]->changeStatus(mines);
            }
        }
    }
}

void sapper::waiting_end() {
    ui->label->setText("Проигрышш"); //TODO delete this
    result_mini_game = false;
    this->close();
}

void sapper::check_zero(int i, int j) {
   Cell[i][j]->cellClickedforrecursion();
   if (i > 0)
        if (Cell[i - 1][j]->get_status() == 0 && !Cell[i - 1][j]->get_rev())
            check_zero(i - 1, j);
    if (i < x - 1)
        if (Cell[i + 1][j]->get_status() == 0 && !Cell[i + 1][j]->get_rev())
            check_zero(i + 1, j);
    if (j > 0)
        if (Cell[i][j - 1]->get_status() == 0 && !Cell[i][j - 1]->get_rev())
            check_zero(i, j - 1);
    if (j < y - 1)
        if (Cell[i][j + 1]->get_status() == 0 && !Cell[i][j + 1]->get_rev())
            check_zero(i, j + 1);
    int li = i, ri = i, lj = j, rj = j;
    if (i > 0)
        li = i - 1;
    if (i < x - 1)
        ri = i + 1;
    if (j > 0)
        lj = j - 1;
    if (j < y - 1)
        rj = j + 1;
    for (int f = li; f<=ri;f++) {
        for (int s = lj; s<=rj;s++) {
            if (!Cell[f][s]->get_rev() && Cell[f][s]->get_status() != 0)
                Cell[f][s]->cellClickedforrecursion();
        }
    }
}

void sapper::check_win() {
    if (left != 0)
        return;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (Cell[i][j]->get_status() != Cell[i][j]->get_status_for_player()) {
                return;
            }
        }
    }
    ui->label->setText("Побэда");
    this->close();
}

void sapper::left_decr() {
    left--;
    ui->lcdNumber->display(left);
}

void sapper::left_incr() {
    left++;
    ui->lcdNumber->display(left);
}
