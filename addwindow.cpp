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
    QPalette warningPalette, defaultPalette;
    warningPalette.setColor(QPalette::Base, Qt::red);
    float fats, prots, carbo, acids, fibers, weight;
        fats = ui->fatsEdit->text().toFloat();
        if(ui->nameEdit->text().toStdString().empty())
        {
            ui->nameEdit->setPalette(warningPalette);
            flag = true;
        }
        else
        {
            ui->nameEdit->setPalette(defaultPalette);
        }
        if(fats <= 0.0F || fats > 100.0F)
        {
        ui->fatsEdit->setPalette(warningPalette);
        flag = true;
        }
        else
        {
            ui->fatsEdit->setPalette(defaultPalette);
        }
        prots = ui->protEdit->text().toFloat();
        if(prots <= 0.0F || prots > 100.0F)
        {
        ui->protEdit->setPalette(warningPalette);
        flag = true;
        }
        else
        {
            ui->protEdit->setPalette(defaultPalette);
        }
        carbo = ui->carboEdit->text().toFloat();
        if(carbo <= 0.0F || carbo > 100.0F)
        {
        ui->carboEdit->setPalette(warningPalette);
        flag = true;
        }
        else
        {
            ui->carboEdit->setPalette(defaultPalette);
        }
        acids = ui->acidsEdit->text().toFloat();
        if(acids <= 0.0F || acids > 100.0F)
        {
        ui->acidsEdit->setPalette(warningPalette);
        flag = true;
        }
        else
        {
            ui->acidsEdit->setPalette(defaultPalette);
        }
        fibers = ui->fibersEdit->text().toFloat();
        if(fibers <= 0.0F || fibers > 100.0F)
        {
        ui->fibersEdit->setPalette(warningPalette);
        flag = true;
        }else
        {
            ui->fibersEdit->setPalette(defaultPalette);
        }
        weight = ui->weightEdit->text().toFloat();
        if(weight <= 0.0F || weight > 100.0F)
        {
        ui->weightEdit->setPalette(warningPalette);
        flag = true;
        }
        else
        {
            ui->weightEdit->setPalette(defaultPalette);
        }
        if(!flag)
        {
            Dish temp(ui->nameEdit->text().toStdString(),
                      fats, prots, carbo, acids, fibers, weight);
            editList->addNode(temp);
            dynamic_cast<MainWindow*>(this->parent())->setTable();
            ui->nameEdit->clear();
            ui->fatsEdit->clear();
            ui->protEdit->clear();
            ui->acidsEdit->clear();
            ui->carboEdit->clear();
            ui->fibersEdit->clear();
            ui->weightEdit->clear();
        }
}