#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    controlButton = new QPushButton(this);
    controlButton->move(0, 0);

    mainDialog = new QDialog;

    connect(controlButton, &QPushButton::clicked, [=]{
       mainDialog->setModal(true);
//       mainDialog->setWindowModality(Qt::WindowModal);
       mainDialog->show();
       mainDialog->exec();

    });
}

Widget::~Widget()
{
    mainDialog->deleteLater();
}
