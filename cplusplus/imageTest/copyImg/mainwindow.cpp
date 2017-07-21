#include "mainwindow.h"

#include <QLabel>
#include <QDebug>
#include <QTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPixmap backgroundImg(":/1.jpg");

    QLabel* cutImageLabel = new QLabel(this);
    QPixmap cutImg;
    QTransform transform;
    transform.translate(0, 0);
     cutImg = backgroundImg.transformed(transform, Qt::FastTransformation);
     cutImg.copy(-15, -15,  15, 15);
     cutImageLabel->setPixmap(cutImg);
    cutImageLabel->setFixedSize(cutImg.size());
//    setFixedSize(cutImg.size());
     qDebug() << cutImg.size() << cutImageLabel->size();
     cutImageLabel->setStyleSheet("background-color: rgba(255, 0, 0, 0.2)");
}

MainWindow::~MainWindow()
{

}
