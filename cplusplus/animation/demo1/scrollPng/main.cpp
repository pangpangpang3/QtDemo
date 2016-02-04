#include "mainwindow.h"
#include <QApplication>
#include "animationlabel.h"
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
    AnimatedLabel bt(":/img/LoginSpinner_40.png", 8);

    bt.show();
    return a.exec();
}
