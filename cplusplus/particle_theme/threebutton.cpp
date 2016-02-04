#include "threebutton.h"

ThreeButton::ThreeButton(QWidget *parent)
    :QFrame(parent)
{
    setStyleSheet("background-color: rgba(255, 255, 0, 255);");

    QPushButton* atest = new QPushButton;
    atest->setText("TestA");
    QPushButton* btest = new QPushButton;
    btest->setText("TestB");
    QPushButton* ctest = new QPushButton;
    ctest->setText("TestC");
    m_Layout = new QHBoxLayout;
    m_Layout->setMargin(0);
    m_Layout->addSpacing(20);
    m_Layout->addStretch(0);
    m_Layout->addWidget(atest);
    m_Layout->addWidget(btest);
    m_Layout->addWidget(ctest);
    m_Layout->addStretch(0);

    setLayout(m_Layout);

}

ThreeButton::~ThreeButton() {

}
