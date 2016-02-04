#include <QPushButton>

#include "widget.h"
#include <libdui/darrowrectangle.h>

DUI_USE_NAMESPACE

Widget::Widget(QWidget *parent)
    : QFrame(parent)
{
    arrowRect = new DArrowRectangle(DArrowRectangle::ArrowTop, this);
    arrowRect->setArrowX(25);
    arrowRect->setArrowWidth(30);
    arrowRect->setArrowHeight(10);
    setFixedSize(1440, 900);
    QPushButton *button = new QPushButton("DArrowRectangle PH", this);
    button->setFixedSize(200, 30);
    arrowRect->setContent(button);
    arrowRect->move(0, 0);
//    arrowRect->show(600, 200);
    arrowRect->raise();

    QHBoxLayout* m_Layout = new QHBoxLayout;
    m_Layout->setMargin(0);
    m_Layout->setSpacing(0);
    m_Layout->addWidget(arrowRect);
    setLayout(m_Layout);

    setFixedWidth(arrowRect->width());
    setFixedHeight(arrowRect->height());

    QTimer* m_control = new QTimer(this);
    m_control->setInterval(600);
    connect(m_control, SIGNAL(timeout()), this, SLOT(controlArrow()));
    m_control->start();
}

void Widget::controlArrow() {
    if (arrowRect->isHidden()) {
        arrowRect->show(400, 500);
        update();
    } else {
        arrowRect->hide();
        update();
    }
}

Widget::~Widget()
{

}
