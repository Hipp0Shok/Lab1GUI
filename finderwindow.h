#ifndef FINDERWINDOW_H
#define FINDERWINDOW_H
#include <QMainWindow>
#include "D:\study\info\lab1\list.h"
namespace Ui {
class FinderWindow;
}

class FinderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FinderWindow(const Dish*, QWidget *parent = nullptr);
    ~FinderWindow();

private:
    Ui::FinderWindow *ui;
};

#endif // FINDERWINDOW_H
