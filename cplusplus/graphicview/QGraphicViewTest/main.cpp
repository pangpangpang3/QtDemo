#include "drawapp.h"

#include <QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene* scense = new QGraphicsScene;
    scense->addLine(10, 10, 150, 300);
    QGraphicsView* view = new QGraphicsView(scense);
    view->resize(500, 500);
    view->setWindowTitle("QGraphicView");
    view->move(20, 20);
    view->show();

    DrawApp w;
    w.resize(500, 500);
    w.setWindowTitle("QWidget");
    w.move(400, 400);
    w.show();

    return a.exec();
}
