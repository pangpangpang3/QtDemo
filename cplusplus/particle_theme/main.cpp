#include "themeframe.h"
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ThemeFrame w("../theme/qml/sky.qml");
    w.show();


    return a.exec();
}
