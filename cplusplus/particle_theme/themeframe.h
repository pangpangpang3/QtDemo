#ifndef THEMEFRAME_H
#define THEMEFRAME_H

#include <QFrame>
#include <QtQuick>

class ThemeFrame : public QFrame
{
    Q_OBJECT

public:
    ThemeFrame(QString url, QWidget *parent = 0);
    ~ThemeFrame();
public slots:
    void setTheme(QString url);
};

#endif // THEMEFRAME_H
