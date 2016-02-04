#include "item.h"
#include <QtWidgets>
#include <QtCore>
#include <QtGui>

Item::Item(QWidget *parent)
    : QFrame(parent)
{
    resize(160, 160);
    iconlabel_a = new QLabel;
    iconlabel_b = new QLabel;
    iconlabel_c = new QLabel;
    iconlabel_d = new QLabel;

    QPixmap pixmap_a(QString(":/icon/clock.png"));
    QPixmap pixmap_b(QString(":/icon/cloud.png"));
    QPixmap pixmap_c(QString(":/icon/folder.png"));
    QPixmap pixmap_d(QString(":/icon/media.png"));
    QGridLayout *gridlayout = new QGridLayout();
    iconlabel_a->setPixmap(pixmap_a);
    iconlabel_b->setPixmap(pixmap_b);
    iconlabel_c->setPixmap(pixmap_c);
    iconlabel_d->setPixmap(pixmap_d);
    gridlayout->addWidget(iconlabel_a, 0, 0, 1, 1);
    gridlayout->addWidget(iconlabel_b, 0, 1, 1, 1);
    gridlayout->addWidget(iconlabel_c, 1, 0, 1, 1);
    gridlayout->addWidget(iconlabel_d, 1, 1, 1, 1);
    gridlayout->setSpacing(15);
    setLayout(gridlayout);
    this->setObjectName("Item");

    QFile qssFile(":Item.qss");
    QString qss;
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
     }
}
Item::~Item()
{
}
void Item::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::RightButton) {
        pos = e->globalPos();
        qDebug()<<"right button press"<< pos<<pos.x()<<pos.y();
        arrowrectangle = new ArrowRectangle();
        arrowrectangle->setArrorDirection(ArrowRectangle::ArrowTop);
        tablewidget = new QTableWidget(2, 2);
        tablewidget->resize(300, 600);
        iconItem_a = new QTableWidgetItem(QIcon(":/icon/clock.png"), "");
        iconItem_b = new QTableWidgetItem(QIcon(":/icon/cloud.png"), "");
        iconItem_c = new QTableWidgetItem(QIcon(":/icon/folder.png"), "");
        iconItem_d = new QTableWidgetItem(QIcon(":/icon/media.png"), "");

        tablewidget->setItem(0,0, iconItem_a);
        tablewidget->setItem(0,1, iconItem_b);
        tablewidget->setItem(1,0, iconItem_c);
        tablewidget->setItem(1,1, iconItem_d);

        arrowrectangle->setContent(tablewidget);
        arrowrectangle->showAtTop(pos.x(), pos.y());
    }

}
void Item::mouseReleaseEvent(QMouseEvent *e) {
    Q_UNUSED(e);
}
