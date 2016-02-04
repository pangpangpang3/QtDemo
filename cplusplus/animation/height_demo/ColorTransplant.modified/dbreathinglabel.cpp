#include <QtDebug>
#include "dbreathinglabel.h"

DBreathingLabel::DBreathingLabel(QWidget *parent,Qt::WindowFlags f)
    : alpha_(255), QLabel(parent, f)
{
}
DBreathingLabel::DBreathingLabel (const QString &text, QWidget *parent, Qt::WindowFlags f)
    : alpha_(255), QLabel(text, parent,f)
{
}
DBreathingLabel::~DBreathingLabel()
{
    delete m_showAnimation;
    delete m_hideAnimation;
}
void DBreathingLabel::setColor(QColor color) {
    m_palette.setColor(QPalette::WindowText, color);
    this->setPalette(m_palette);
}
void DBreathingLabel::setAlpha(int opa) {
    alpha_ = opa;
    QColor color =m_palette.color(QPalette::WindowText);
    color = QColor(color.red(), color.green(), color.blue(), opa);
    m_palette.setColor(QPalette::Foreground, color);
    setPalette(m_palette);
}


void DBreathingLabel::hideLabel() {
    m_showAnimation = new QPropertyAnimation(this, "alpha");
    m_showAnimation->setStartValue(255);
    m_showAnimation->setEndValue(0);
    m_showAnimation->setDuration(1000);
    m_showAnimation->start();
}

void DBreathingLabel::showLabel() {
    m_hideAnimation = new QPropertyAnimation(this, "alpha");
    m_hideAnimation->setStartValue(0);
    m_hideAnimation->setEndValue(255);
    m_hideAnimation->setDuration(2000);
    m_hideAnimation->start();
}
