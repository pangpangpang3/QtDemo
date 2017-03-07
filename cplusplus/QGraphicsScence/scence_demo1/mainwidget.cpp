#include "mainwidget.h"

#include "imagescene.h"
#include "imageview.h"
#include <QDebug>

MainWidget::MainWidget(QMainWindow *parent)
    : QMainWindow(parent) {
    ImageScene* imageScene = new ImageScene(NULL);
    ImageView* imageView = new ImageView(imageScene, this);
//    imageView->setStyleSheet("background:red;");
    qDebug() << imageView->geometry();
    setCentralWidget(imageView);
}

MainWidget::~MainWidget() {}
