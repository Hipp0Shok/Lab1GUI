#include "addlunchwindow.h"
#include "ui_addlunchwindow.h"
#include "mainwindow.h"

AddLunchWindow::AddLunchWindow(List* list, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddLunchWindow),
    editList(list)
{
    ui->setupUi(this);
    connect(ui->addLunchButton, SIGNAL(clicked()), this, SLOT(setCombo()));
    QString text;
    List::Iterator iter;
    iter = editList->begin();
    for( ; iter != nullptr; iter++)
    {
        if((*iter)->getKind() == DISH)
        {
            text = dynamic_cast< const Dish*>(*iter)->getName();
            ui->soupCombo->addItem(text);
            ui->mainCombo->addItem(text);
            ui->dessertCombo->addItem(text);
        }
    }
}

AddLunchWindow::~AddLunchWindow()
{
    delete ui;
}

void AddLunchWindow::setCombo()
{
    const Base *soup, *mainCourse, *dessert;
    soup = editList->findDishByName(ui->soupCombo->currentText());
    mainCourse = editList->findDishByName(ui->mainCombo->currentText());
    dessert = editList->findDishByName(ui->dessertCombo->currentText());
    if(!soup || !mainCourse || !dessert)
    {
        return;
    }
    SetLunch LunchNew(*dynamic_cast<const Dish*>(soup),
                      *dynamic_cast<const Dish*>(mainCourse),
                      *dynamic_cast<const Dish*>(dessert));
    editList->addNode(LunchNew);
    dynamic_cast<MainWindow *>(this->parent())->setTable();
    this->close();
}
