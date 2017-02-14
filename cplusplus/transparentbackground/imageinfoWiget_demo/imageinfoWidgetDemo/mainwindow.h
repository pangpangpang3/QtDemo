#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
class ImageInfoWidget : public QScrollArea {
    Q_OBJECT
public:
    ImageInfoWidget(QWidget* parent = 0);
    ~ImageInfoWidget();
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
