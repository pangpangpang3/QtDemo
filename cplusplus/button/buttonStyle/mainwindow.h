#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "itembutton.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ItemButton* m_test1Button = NULL;

    QPushButton* m_test2Button = NULL;
};

#endif // MAINWINDOW_H
