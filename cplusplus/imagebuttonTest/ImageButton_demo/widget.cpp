#include "widget.h"
#include "imagebutton.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
    QFile f(":/resources/dark/qss/view.qss");
    if (f.open(QIODevice::ReadOnly)) {
        setStyleSheet(f.readAll());
        f.close();
    }
    else {
        qDebug() << "Set style sheet for ImageButton failed";
    }

//    QWidget* mainW = new QWidget(this);
    setObjectName("MainWidget");

    setFixedSize(600, 400);
//    QHBoxLayout* layout = new QHBoxLayout();
//    layout->setContentsMargins(100, 0, 0, 0);


    ImageButton* m_adaptBtn = new ImageButton(this);
    m_adaptBtn->setFixedSize(48, 40);
    m_adaptBtn->setObjectName("AdaptBtn");
    m_adaptBtn->move(148, 0);
    m_adaptBtn->setDisabled(true);
    ImageButton* m_adaptScreenBtn = new ImageButton(this);
    m_adaptScreenBtn->setObjectName("AdaptScreenBtn");
    m_adaptScreenBtn->move(196, 0);
    ImageButton* m_collectBtn = new ImageButton(this);
    m_collectBtn->setObjectName("CollectBtn");
    m_collectBtn->move(220, 0);

    connect(m_collectBtn, &ImageButton::clicked, [=]{
        m_collectBtn->setCheckable(true);
        m_collectBtn->setChecked(true);
//        m_collectBtn->setDisabled(true);
    });

    ImageButton* m_rotateBtn = new ImageButton(this);
    m_rotateBtn->setObjectName("RotateBtn");
    m_rotateBtn->move(270, 0);
    ImageButton* m_rotateCounterBtn = new ImageButton(this);
    m_rotateCounterBtn->setObjectName("RotateCounterBtn");
    m_rotateCounterBtn->move(320, 0);
//    layout->addWidget(m_adaptBtn);
//    layout->addWidget(m_adaptScreenBtn);
//    layout->addWidget(m_collectBtn);
//    layout->addWidget(m_rotateBtn);
//    layout->addWidget(m_rotateCounterBtn);
//    mainW->setLayout(layout);

//    setCentralWidget(mainW);

    QPushButton* testButton = new QPushButton(this);
    testButton->setFixedSize(80, 80);
    testButton->move(0, 0);
    connect(testButton, &QPushButton::clicked, this, [=]{
        m_count++;

        if (m_count%2==1) {
            QFile f(":/resources/dark/qss/view.qss");
            if (f.open(QIODevice::ReadOnly)) {
                setStyleSheet(f.readAll());
                f.close();
            }
            else {
                qDebug() << "Set style sheet for ImageButton failed";
            }

        } else {
            QFile f(":/resources/light/qss/view.qss");
            if (f.open(QIODevice::ReadOnly)) {
                setStyleSheet(f.readAll());
                f.close();
            }
            else {
                qDebug() << "Set style sheet for ImageButton failed";
            }
        }
    });
}

Widget::~Widget()
{

}
