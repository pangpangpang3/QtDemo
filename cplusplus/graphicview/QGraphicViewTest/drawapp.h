#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui/QPaintEvent>
class DrawApp : public QWidget
{
    Q_OBJECT

public:
    DrawApp(QWidget *parent = 0);
    ~DrawApp();
protected:
    void paintEvent(QPaintEvent* event);
};

#endif // WIDGET_H
