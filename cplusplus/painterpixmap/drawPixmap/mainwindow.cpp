#include "mainwindow.h"

#include <QPainter>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(728, 400);



}

void MainWindow::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    QPixmap image1(":/img/google-chrome.png");
    QPixmap image2(":/img/skype.png");
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);


    QPixmap tmpPix = image1.scaled(256, 256, Qt::IgnoreAspectRatio);
    painter.drawPixmap(QPoint(0, 0),  tmpPix);

    painter.drawPixmap(300, 0, 64, 64, image1);
    painter.drawPixmap(QPoint(400, 0),   image1.scaled(64, 64, Qt::IgnoreAspectRatio));
    painter.drawPixmap(QPoint(300, 300), image2.scaled(48, 48, Qt::IgnoreAspectRatio));
}

MainWindow::~MainWindow()
{

}
