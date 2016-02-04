#ifndef ITEM_H
#define ITEM_H
#include "arrowrectangle.h"

#include <QtWidgets>
#include <QtCore>
#include <QtGui>
class Item : public QFrame
{
    Q_OBJECT

public:
    Item(QWidget *parent = 0);
    ~Item();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    ArrowRectangle* arrowrectangle;
    QTableWidget* tablewidget;
    QPoint  pos;


    QTableWidgetItem* iconItem_a;
    QTableWidgetItem* iconItem_b;
    QTableWidgetItem* iconItem_c;
    QTableWidgetItem* iconItem_d ;

private:
    QLabel* iconlabel_a;
    QLabel* iconlabel_b;
    QLabel* iconlabel_c;
    QLabel* iconlabel_d;
    QPixmap* pixmap_a;
    QPixmap* pixmap_b;
    QPixmap* pixmap_c;
    QPixmap* pixmap_d;


};

#endif // WIDGET_H
