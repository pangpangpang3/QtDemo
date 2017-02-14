#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "inotifyengine.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void fileRemoved(const QString &filepath);
private:
    InotifyEngine* m_watcher;
};

#endif // WIDGET_H
