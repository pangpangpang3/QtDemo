#include "mainwindow.h"

#include  <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);

    QTextEdit *button = new QTextEdit();
    button->setText("My cool buttonTTTTTTTTTTTT");
    scene->addWidget(button);

   QGraphicsView* view = new QGraphicsView(this);
   view->setFixedSize(200, 200);
   view->setScene(scene);
   view->move(100, 100);
   view->translate(view->width(), 0);
   view->rotate(45);
   view->show();
}

MainWindow::~MainWindow()
{

}
