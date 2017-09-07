#include "widget.h"

#include <QColorDialog>
#include <QPushButton>
#include <QLinearGradient>

#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(340, 340);

    QPushButton* button = new QPushButton(this);
    button->move(0, 0);
    QObject::connect(button, &QPushButton::clicked, this, [=]{
         QColorDialog::getColor(Qt::white, this);
    });

    QPushButton* colButton = new QPushButton(this);
    colButton->setIconSize(QSize(222, 10));
    colButton->setIcon(QIcon(":/resource/color_line.png"));

    QVBoxLayout* vLayout = new QVBoxLayout(this);
    vLayout->setMargin(0);
    vLayout->setSpacing(20);
    vLayout->addWidget(button);
    vLayout->addWidget(colButton);
    vLayout->addStretch();
    setLayout(vLayout);
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

//    QLinearGradient linearGradient1;
//    linearGradient1.setStart(this->width(), this->y());
//    linearGradient1.setColorAt(0, QColor(255, 0, 0, 255));
//    linearGradient1.setFinalStop(QPoint(this->x(), this->height()));
//    linearGradient1.setColorAt(1, QColor(0, 0, 0, 255));

//    painter.setBrush(QBrush(linearGradient1));
//    painter.drawRect(this->rect());

//    QLinearGradient linearGradient2;
//    linearGradient2.setStart(0, this->y());
//    linearGradient2.setColorAt(0, QColor(255, 255, 255));
//    linearGradient2.setFinalStop(QPoint(0, this->height()));
//    linearGradient2.setColorAt(1, QColor(0, 0, 0, 255));

//    painter.setBrush(QBrush(linearGradient2));
//    painter.drawRect(this->rect());

    QRect bgRect = QRect(this->x(), this->y() + 40, this->width(), this->height() - 40);
    QLinearGradient linearGradient1;
    linearGradient1.setStart(this->width(), this->y());
    linearGradient1.setColorAt(0, QColor(255, 0, 0, 255));
    linearGradient1.setFinalStop(QPoint(this->x(), this->height()));
    linearGradient1.setColorAt(1, QColor(0, 0, 0, 255));

    painter.setBrush(QBrush(linearGradient1));
    painter.drawRect(bgRect);
}

Widget::~Widget()
{

}
