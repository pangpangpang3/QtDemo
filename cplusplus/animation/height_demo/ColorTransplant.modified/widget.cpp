#include <QtDebug>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    breathing_label = new DBreathingLabel("GOOD",this);
    breathing_label->setFixedSize(900, 400);
//    breathing_label->setPixmap(QPixmap(":img/blueberry.jpg"));
    breathing_label->setColor(Qt::blue);
    QTimer::singleShot(1000, [=]{
        qDebug() << "hide";
//        qDebug() << "opacity:" << breathing_label->opacity();

        breathing_label->hideLabel();
    });
    QTimer::singleShot(2000, [=]{
//        qDebug() << "show";
//        qDebug() << "opacity:" << shine_label->opacity();
        breathing_label->showLabel();
    });
}

Widget::~Widget()
{

}
