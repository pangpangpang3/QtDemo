#include "widget.h"
#include <QtCore>
#include <QtWidgets>
#include <QtGui>

Widget::Widget(QFrame *parent)
    : QFrame(parent)
{

    qDebug() << "before" << this->geometry();
    m_animation = new QPropertyAnimation(this, "height");
    m_animation->setDuration(1000);


    QObject::connect(m_animation, &QPropertyAnimation::finished, [=]{
        qWarning() << "----" << this->geometry();
    });

    this->setStyleSheet("background-color: green");

}

Widget::~Widget()
{
}
void Widget::setWidth(int ex_width) {
    setFixedWidth(ex_width);
}
void Widget::setHeight(int ex_height) {
    setFixedHeight(ex_height);
}

void Widget::setExpand(bool expand) {
    if (expand) {
        setHeight(200);
        m_animation->setStartValue(0);
        m_animation->setEndValue(this->height());

    } else {

        qDebug() << "false expand:" ;
        m_animation->setStartValue(this->height());
        m_animation->setEndValue(2);
    }
    m_animation->stop();
    m_animation->start();
}
