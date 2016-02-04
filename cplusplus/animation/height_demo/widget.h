#ifndef WIDGET_H
#define WIDGET_H

#include "widget.h"
#include <QtCore>
#include <QtWidgets>

#include <QFrame>

class Widget : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(int width READ width WRITE setWidth)// NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight)// NOTIFY heightChanged)
public:
    Widget(QFrame *parent = 0);
    ~Widget();
    bool expand = false;
    void setExpand(bool expand);
//    void setSize(int width, int Height);
    int ex_width = 200;
    int ex_height = 60;

    void setWidth(int ex_width);
    void setHeight(int ex_height);
signals:
    void setAnimation();
private:
    QPropertyAnimation* m_animation;

};

#endif // WIDGET_H
