#include "include/saperwindow.h"
#include "ui_saperwindow.h"

SaperWindow::SaperWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaperWindow)
{
    ui->setupUi(this);
}

SaperWindow::~SaperWindow()
{
    delete ui;
}
