#ifndef WIDGET_H
#define WIDGET_H

#include <QFrame>
#include <libdui/darrowrectangle.h>

DUI_USE_NAMESPACE

class Widget : public QFrame
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    DArrowRectangle* arrowRect;
public slots:
    void controlArrow();
};

#endif // WIDGET_H
