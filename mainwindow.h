#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtGui>
#include <QTableWidget>
#include "D:\study\info\lab1\list.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTable();
    List list;

private:
    Ui::MainWindow *ui;


public slots:
    void openFile();
    void saveFile();
    void deleteRow();
    void addWindow();
    void addLunchWindow();

};

#endif // MAINWINDOW_H
