#include "widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//#ifdef SUPPORT_INOTIFY
    m_watcher = new InotifyEngine;
    connect(m_watcher, &InotifyEngine::fileRemoved,
            this, &Widget::fileRemoved);
//#endif

    m_watcher->addPath("/home/ph/图片/");
}

void Widget::fileRemoved(const QString &filepath) {
    qDebug() << "fileRemoved:" << filepath;
}

Widget::~Widget()
{

}
