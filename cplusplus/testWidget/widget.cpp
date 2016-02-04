#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("color: transparent; background-color: rgba(255, 255, 255, 0)");
}

Widget::~Widget()
{

}
