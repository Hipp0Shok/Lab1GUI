#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QMainWindow>
#include "D:\study\info\lab1\list.h"

namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWindow(List *list, QWidget *parent = nullptr);
    ~AddWindow();

private:
    Ui::AddWindow *ui;
    List* editList;

private slots:
    void addDish();
};

#endif // ADDWINDOW_H
