#include "addwindow.h"
#include "ui_addwindow.h"
#include "mainwindow.h"

AddWindow::AddWindow(List *list, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddWindow),
    editList(list)
{
    ui->setupUi(this);
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addDish()));
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::addDish()
{
    bool flag = false;
    QPalette warning;
    warning.setColor(QPalette::Base, Qt::red);
    float fats, prots, carbo, acids, fibers, weight;
        fats = ui->fatsEdit->text().toFloat();
        if(fats == 0.0F)
        {
        ui->fatsEdit->setPalette(warning);
        flag = true;
        }
        else
        {
        }
        prots = ui->protEdit->text().toFloat();
        if(prots == 0.0F)
        {
        ui->protEdit->setPalette(warning);
        flag = true;
        }
        carbo = ui->carboEdit->text().toFloat();
        if(carbo == 0.0F)
        {
        ui->carboEdit->setPalette(warning);
        flag = true;
        }
        acids = ui->acidsEdit->text().toFloat();
        if(acids == 0.0F)
        {
        ui->acidsEdit->setPalette(warning);
        flag = true;
        }
        fibers = ui->fibersEdit->text().toFloat();
        if(fibers == 0.0F)
        {
        ui->fibersEdit->setPalette(warning);
        flag = true;
        }
        weight = ui->weightEdit->text().toFloat();
        if(weight == 0.0F)
        {
        ui->weightEdit->setPalette(warning);
        flag = true;
        }
        if(!flag)
        {
        Dish temp(ui->nameEdit->text().toStdString(), fats, prots, carbo, acids, fibers, weight);
        editList->addNode(&temp);
        dynamic_cast<MainWindow*>(this->parent())->setTable();
        }
}