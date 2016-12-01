#include "volumemonitor.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VolumeMonitor volumeMonitor;
    volumeMonitor.start();

    QObject::connect(&volumeMonitor, &VolumeMonitor::deviceAdded, [](const QString& path){
        qDebug() << "device added:" << path;
    });

    QObject::connect(&volumeMonitor, &VolumeMonitor::deviceRemoved, [](const QString& path){
        qDebug() << "device removed:" << path;
    });

    return a.exec();
}
