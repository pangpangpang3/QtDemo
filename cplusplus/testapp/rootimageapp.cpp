
#include <QApplication>
#include <QPixmap>
#include <QX11Info>
#include <QDesktopWidget>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QDebug>
#include <X11/Xlib.h>

#include "rootimageapp.h"

RootImageApp::RootImageApp(int &argc, char **argv):
    QApplication(argc, argv)
{
    XDefineCursor(QX11Info::display(), QX11Info::appRootWindow(), QCursor(Qt::ArrowCursor).shape());

    QTimer::singleShot(5000, this, SLOT(setBackground()));
}

void RootImageApp::setBackground()
{
    QFile stdIn;
    stdIn.open(0, QIODevice::ReadOnly);

    QImage image;
    qDebug() << "image load:" << image.load(&stdIn, "xpm");

    QPalette palette;
    palette.setBrush(desktop()->backgroundRole(), QBrush(image));
    desktop()->setPalette(palette);
    XClearWindow(QX11Info::display(), desktop()->winId());

    quit();
}
