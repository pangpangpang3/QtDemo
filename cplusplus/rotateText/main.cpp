#include "mainwindow.h"
#include <QApplication>

#include  <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene;

    QTextEdit *button = new QTextEdit;
    button->setText("My cool buttonTTTTTTTTTTTT");
    scene->addWidget(button);

   QGraphicsView* view = new QGraphicsView;
   view->setStyleSheet("background-color:red;");
   view->setMinimumSize(button->size());
   view->setScene(scene);
   view->move(100, 100);
//   view->translate(view->width(), view->height());
//   view->rotate(45);
   QTransform form;
   form.rotate(60);
   view->setTransform(form);
   view->show();
    return a.exec();
}
