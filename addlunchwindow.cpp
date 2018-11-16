#include "addlunchwindow.h"
#include "ui_addlunchwindow.h"

AddLunchWindow::AddLunchWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddLunchWindow)
{
    ui->setupUi(this);
}

AddLunchWindow::~AddLunchWindow()
{
    delete ui;
}
