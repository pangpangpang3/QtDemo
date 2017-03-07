#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QMainWindow>

class MainWidget : public QMainWindow {
    Q_OBJECT
public:
    MainWidget(QMainWindow* parent = 0);
    ~MainWidget();
};
#endif // MAINWIDGET_H
