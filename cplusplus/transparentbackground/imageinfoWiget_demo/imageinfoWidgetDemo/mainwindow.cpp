#include "mainwindow.h"

ImageInfoWidget::ImageInfoWidget(QWidget *parent)
    : QScrollArea(parent) {
    setStyleSheet("ImageInfoWidget {\
                  background: rgba(255, 255, 255, .7);\
              }\
");
}

ImageInfoWidget::~ImageInfoWidget() {

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setStyleSheet("background: white;");
    ImageInfoWidget* w = new ImageInfoWidget(this);
    w->setFixedSize(100, 100);
    setCentralWidget(w);
    setFixedSize(600, 400);
}

MainWindow::~MainWindow()
{

}
