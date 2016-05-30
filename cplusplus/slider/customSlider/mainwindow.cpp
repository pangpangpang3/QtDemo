#include "mainwindow.h"

#include <QSlider>
#include <QHBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSlider* a = new QSlider(Qt::Vertical);
    a->setMinimum(0);
    a->setMaximum(100);
    a->setValue(50);
    a->setFixedWidth(20);
    a->setStyleSheet("QSlider {"
                     "background: transparent;"
                     "}"
                "QSlider::handle:vertical {"
                     "height: 8px;"
                     "background: white;"
                     "margin: 0 -8px;"
                     "border: 1px solid rgba(0, 0, 0, .3);"
                     "width:10px;}"
                     "QSlider::groove:vertical {"
                     "background: rgba(255, 255, 255, .3);"
                     "position: absolute;"
                     "left: 8px; right: 8px;}"

                 "QSlider::add-page:vertical {"
                     "background: rgba(255, 255, 255, .3);"
                     "border: 1px solid rgba(0, 0, 0, .3);"
                     "}"
                 "QSlider::sub-page:vertical {"
                      "border: 1px solid rgba(0, 0, 0, .3);"
                     "border-radius: 3px;"
                     "background: white;}");
    setCentralWidget(a);
}

MainWindow::~MainWindow()
{

}
