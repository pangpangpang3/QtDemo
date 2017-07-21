#include "mainwindow.h"
#include "dbusnotify.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(200, 300);
    DBusNotify* notify = new DBusNotify(this);
    QString summary = QString("Screenshot send notify NNNNNNNNNNNN");
    QVariantMap emptyMap;



    QPushButton* sendNotifyBtn = new QPushButton("发送通知", this);
    sendNotifyBtn->setStyleSheet("background-color: pink;");
    sendNotifyBtn->move(0, 0);
    connect(sendNotifyBtn, &QPushButton::clicked, this, [=]{
        notify->Notify("Deepin Screenshot", 0,  "deepin-screenshot", "",
                       summary,  QStringList(), emptyMap, 0);
    });


    QPushButton* hideNotifyBtn = new QPushButton("隐藏通知", this);
    hideNotifyBtn->setStyleSheet("background-color: green;");
    hideNotifyBtn->move(0, 100);
    connect(hideNotifyBtn, &QPushButton::clicked, this, [=]{
        notify->CloseNotification(0);
    });
}

MainWindow::~MainWindow()
{

}
