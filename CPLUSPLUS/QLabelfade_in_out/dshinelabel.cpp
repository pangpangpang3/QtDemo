#include <QtDebug>
#include "dshinelabel.h"

DShineLabel::DShineLabel(QWidget *parent)
    : QLabel(parent)
{
    label_effect = new QGraphicsOpacityEffect(this);
    label_effect->setOpacity(opacity);
    this->setGraphicsEffect(label_effect);
    timer_fadeIn = new QTimer;
    timer_fadeOut = new QTimer;

    connect(timer_fadeIn, SIGNAL(timeout()), this, SLOT(fadeIn()));
    connect(timer_fadeOut, SIGNAL(timeout()), this, SLOT(fadeOut()));
}
DShineLabel::~DShineLabel()
{

}
void DShineLabel::fadeIn(double velocity) {
    if(opacity>=1.0) {
        timer_fadeIn->stop();
     } else {
        label_effect->setOpacity(opacity);
        this->setGraphicsEffect(label_effect);
        opacity+=velocity;
     }
}
void DShineLabel::fadeOut(double velocity) {
    if(opacity<=-0.05) {
        timer_fadeOut->stop();
     } else {
         label_effect->setOpacity(opacity);
         this->setGraphicsEffect(label_effect);
         opacity-=velocity;
     }
}
void DShineLabel::showLabel() {
    timer_fadeOut->stop();
    timer_fadeIn->start(30);
}
void DShineLabel::hideLabel() {
    timer_fadeIn->stop();
    timer_fadeOut->start(30);
}
