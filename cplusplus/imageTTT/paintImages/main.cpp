#include "mainwindow.h"
#include <QApplication>

#include <DLog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dtk::Core::DLogManager::registerConsoleAppender();

    MainWindow w;
    w.show();

    return a.exec();
}
