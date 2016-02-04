#ifndef DESKTOPFRAME_H
#define DESKTOPFRAME_H

#endif // DESKTOPFRAME
#include "item.h"
#include "arrowrectangle.h"

#include <QtWidgets>
#include <QtCore>
#include <QtGui>

class desktopframe: public QFrame
{
    Q_OBJECT

public:
    desktopframe(QWidget *parent = 0);
    ~desktopframe();
private:
    Item* item;
    QLabel* label;


};
