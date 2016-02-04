#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool testBool;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool getUserListExpandFlag();
    void setUserListExpandFlag(bool ex);
};

#endif // MAINWINDOW_H
