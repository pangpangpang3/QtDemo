#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QObject>
class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    int m_count = 1;
};

#endif // WIDGET_H
