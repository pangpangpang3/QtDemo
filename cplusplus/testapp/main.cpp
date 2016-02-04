#include <QApplication>
#include <QPixmap>
#include <QX11Info>
#include <QDesktopWidget>
#include <QTimer>
#include <QDebug>
#include <QFile>

#include <X11/Xlib.h>

#include "rootimageapp.h"

int main(int argc, char *argv[])
{
    RootImageApp app(argc, argv);
    XSetCloseDownMode(QX11Info::display(), RetainTemporary);

//    app.flush();
    qDebug() << "app running";
    return app.exec();
}
