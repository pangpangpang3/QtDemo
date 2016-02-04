#include "desktopframe.h"


desktopframe::desktopframe(QWidget *parent)
    : QFrame(parent)
{
    resize(300, 600);
    item = new Item;
    label = new QLabel;
    QVBoxLayout *vblayout = new QVBoxLayout();
    vblayout->addWidget(item);
    vblayout->addWidget(label);
    setLayout(vblayout);

}
desktopframe::~desktopframe()
{
}
