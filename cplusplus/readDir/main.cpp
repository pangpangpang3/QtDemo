#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QDir dir(QDir("/home/hui/图片/Wallpapers/only").absolutePath());
    qDebug() << "dir:" << dir;
    dir.setFilter(QDir::Files);
    QStringList list = dir.entryList();
    qDebug() << "list:" << list.length();
    for(int i = 0; i < list.length(); i++) {
        qDebug() << "dir:" << i << list.at(i);
    }

    return a.exec();
}
