#include "mainwindow.h"

#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QClipboard* cb = qApp->clipboard();
    cb->setPixmap(screenShotPix, QClipboard::Clipboard);
}

MainWindow::~MainWindow()
{

}
