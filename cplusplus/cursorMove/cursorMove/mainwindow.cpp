#include "mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    m_zoomLabel = new QLabel(this);
    m_zoomLabel->setStyleSheet("background-color: green;");
    m_zoomLabel->setFixedSize(100, 100);
    m_zoomLabel->hide();

}

void MainWindow::showPos() {
//    this->show();
    this->setStyleSheet("background: rgba(255, 100, 100, 100)");
    this->showFullScreen();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    QPoint pos = e->pos();
    this->activateWindow();

    m_zoomLabel->show();
    m_zoomLabel->move(pos.x() + 15, pos.y() + 15);
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape) {
        qApp->quit();
    }
}

MainWindow::~MainWindow()
{

}
