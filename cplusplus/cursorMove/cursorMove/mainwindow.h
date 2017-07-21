#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QMouseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showPos();

protected:
    void mouseMoveEvent(QMouseEvent* e);
    void keyPressEvent(QKeyEvent* e);

private:
    QLabel* m_zoomLabel;
};

#endif // MAINWINDOW_H
