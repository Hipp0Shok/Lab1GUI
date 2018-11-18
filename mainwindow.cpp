#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include <string>
#include "QFileDialog"
#include "addwindow.h"
#include "addlunchwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->chooseFile, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(ui->saveFile, SIGNAL(clicked()), this, SLOT(saveFile()));
    connect(ui->selectButton, SIGNAL(clicked()), this, SLOT(deleteRow()));
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addWindow()));
    connect(ui->lunchButton, SIGNAL(clicked()), this, SLOT(addLunchWindow()));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //ui->tableWidget->horizontalHeader()->resizeSection(0, 120);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    //ui->tableWidget->horizontalHeader()->resizeSection(2, 60);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("*.dat"));
    if(fileName != "")
    {
        list.readFromFile(fileName);
        setTable();
    }
}

void MainWindow::saveFile()
{
    if(list.getLength() != 0)
    {
        QString fileName;
        fileName = QFileDialog::getSaveFileName(this, "Сохранить файл как", "", "*.dat");
        list.writeInFile(fileName);
    }
}

void MainWindow::setTable()
{
    QTableWidgetItem *item;
    ui->tableWidget->setRowCount(list.getLength());
    List::Iterator iter;
    iter = list.begin();
    const Dish *dish;
    const SetLunch *lunch;
    for(int row = 0; row < list.getLength(); row++, iter++)
    {
        switch((*iter)->getKind())
        {
        case(DISH):
            dish = dynamic_cast<const Dish*>(*iter);
            item = new QTableWidgetItem;
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            item->setText(dish->getName());
            ui->tableWidget->setItem(row, 0, item);
            item = new QTableWidgetItem;
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            item->setText(QString::number(dish->getEnergyValueTotal()));
            ui->tableWidget->setItem(row, 2, item);
            item = new QTableWidgetItem;
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            item->setText(QString::number(dish->getWeight()));
            ui->tableWidget->setItem(row, 1, item);
            break;
        case(SETLUNCH):
            lunch = dynamic_cast<const SetLunch*>(*iter);
            item = new QTableWidgetItem;
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            item->setText(lunch->getNameTotal());
            ui->tableWidget->setItem(row, 0, item);
            item = new QTableWidgetItem;
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            item->setText(QString::number(lunch->getEnergyValueTotal()));
            ui->tableWidget->setItem(row, 2, item);
            item = new QTableWidgetItem;
            item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            item->setText(lunch->getWeightTotal());
            ui->tableWidget->setItem(row, 1, item);
        }
    }
}

void MainWindow::deleteRow()
{
    if(!ui->tableWidget->selectedItems().empty())
    {
        const Base* temp = list.findByNameAndEnergy(ui->tableWidget->selectedItems().last()->text().toFloat(),
                                                    ui->tableWidget->selectedItems().first()->text());
        list.deleteNode(temp);
        setTable();
    }
}

void MainWindow::addWindow()
{
    AddWindow *win = new AddWindow(&list, this);

    win->show();
}

void MainWindow::addLunchWindow()
{
    AddLunchWindow *addLunchWin = new AddLunchWindow(&list, this);
    addLunchWin->show();
}
