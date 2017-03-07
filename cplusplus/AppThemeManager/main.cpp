#include "mainwindow.h"
#include <QApplication>

#include "appthememanager.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AppThemeManager* themeManager = AppThemeManager::instance();
    themeManager->setTheme("dark");
    MainWindow w;

    w.show();

    return a.exec();
}
