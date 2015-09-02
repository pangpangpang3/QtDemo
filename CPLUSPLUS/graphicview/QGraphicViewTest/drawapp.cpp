#include <QtGui/QPainter>

#include "drawapp.h"

DrawApp::DrawApp(QWidget *parent)
    : QWidget(parent)
{
}
void DrawApp::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawLine(10, 10, 150, 300);
}
DrawApp::~DrawApp()
{

}
