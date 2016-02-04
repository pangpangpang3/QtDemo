#include "widget.h"
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *w = new Widget();
    w->setWidth(400);
    w->setHeight(0);
    w->setWindowFlags(Qt::FramelessWindowHint);
    w->move(100, 0);
    w->show();

        QTimer::singleShot(2000, [=] {
               // w->expand = !w->expand;
               emit w->setExpand(true);});

    return a.exec();
}
