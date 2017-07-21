#include "widget.h"
#include <QtWidgets/QPushButton>

#include <QDebug>

#include "iconbutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QPushButton* abutton = new QPushButton(/*QIcon(QPixmap(":/img/lock_press.png")), "Lock",*/ this);
    abutton->setIcon(QIcon(QPixmap(":/img/lock_press.png")));
    abutton->setText("Lock");
    abutton->setFixedHeight(120);
    abutton->setIconSize(QSize(120, 120));

    IconButton* bbutton = new IconButton(":/img/oval_normal.png", ":/img/oval_hover.png", ":/img/oval_active.png", ":/img/oval_active.png","Oval", this);
    qDebug() << bbutton->getNormalPic();
    bbutton->setCheckable(true);
    bbutton->move(100, 100);
}

Widget::~Widget()
{

}
