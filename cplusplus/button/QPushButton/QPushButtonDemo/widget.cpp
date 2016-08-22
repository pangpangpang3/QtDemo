#include "widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button1 = new QPushButton(this);
    button1->setText("Button1");


    QPushButton* button2 = new QPushButton(this);
    button2->setText("Button2");
    button2->move(100, 0);

}

Widget::~Widget()
{

}
