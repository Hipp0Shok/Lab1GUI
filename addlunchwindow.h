#ifndef ADDLUNCHWINDOW_H
#define ADDLUNCHWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddLunchWindow;
}

class AddLunchWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddLunchWindow(QWidget *parent = nullptr);
    ~AddLunchWindow();

private:
    Ui::AddLunchWindow *ui;
};

#endif // ADDLUNCHWINDOW_H
