#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore/QTimer>
#include "dbreathinglabel.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    DBreathingLabel* breathing_label;
};

#endif // WIDGET_H
