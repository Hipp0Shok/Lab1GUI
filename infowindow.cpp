#include "infowindow.h"
#include "ui_infowindow.h"

InfoWindow::InfoWindow(const Dish* selected, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
    ui->nameLabel->setText(selected->getName());
    ui->fatEdit->setText(QString::number(selected->getFats()));
    ui->protEdit->setText(QString::number(selected->getProteins()));
    ui->carboEdit->setText(QString::number(selected->getCarbohydrates()));
    ui->acidEdit->setText(QString::number(selected->getOrganicAcids()));
    ui->fiberEdit->setText(QString::number(selected->getAlimentaryFibers()));
    ui->weightEdit->setText(QString::number(selected->getWeight()));
}

InfoWindow::~InfoWindow()
{
    delete ui;
}
