#include "mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{
    QLabel* imagesLabel = new QLabel(this);
    QImage img;
    img.load(":/358157.jpg");
    QPixmap pix = QPixmap::fromImage(img);
    imagesLabel->setPixmap(pix);
    setCentralWidget(imagesLabel);
}

MainWindow::~MainWindow()
{

}
