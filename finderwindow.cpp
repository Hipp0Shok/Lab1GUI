#include "finderwindow.h"
#include "ui_finderwindow.h"


FinderWindow::FinderWindow(const Dish* existing, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FinderWindow)
{
    ui->setupUi(this);
    ui->nameLabel->setText(existing->getName());
    ui->fatsL->setText(QString::number((existing->getFats())));
    ui->protL->setText(QString::number(existing->getProteins()));
    ui->carboL->setText(QString::number(existing->getCarbohydrates()));
    ui->fibersL->setText(QString::number(existing->getAlimentaryFibers()));
    ui->acidsL->setText(QString::number(existing->getOrganicAcids()));
    ui->weightL->setText(QString::number(existing->getWeight()));
    ui->energyL->setText(QString::number(existing->getEnergyValueTotal()));
}

FinderWindow::~FinderWindow()
{
    delete ui;
}
