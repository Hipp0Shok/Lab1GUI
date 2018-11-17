#ifndef ADDLUNCHWINDOW_H
#define ADDLUNCHWINDOW_H

#include <QMainWindow>
#include "D:\study\info\lab1\list.h"

namespace Ui {
class AddLunchWindow;
}

class AddLunchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddLunchWindow(List* list, QWidget *parent = nullptr);
    ~AddLunchWindow();


private:
    Ui::AddLunchWindow *ui;
    List* editList;

public slots:
    void setCombo();
};

#endif // ADDLUNCHWINDOW_H
