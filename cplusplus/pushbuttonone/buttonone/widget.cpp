#include "widget.h"
#include <QtWidgets/QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    QPushButton* abutton = new QPushButton(QIcon(QPixmap(":/img/lock_press.png")), "Lock", this);
    abutton->setFixedHeight(120);
    abutton->setIconSize(QSize(120, 120));
}

Widget::~Widget()
{

}
