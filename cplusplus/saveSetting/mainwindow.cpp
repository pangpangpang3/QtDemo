#include <QSettings>
#include <QFile>
#include <QTimer>
#include <QPushButton>
#include <QDebug>

#include "mainwindow.h"

#define DDESESSIONCC_CONFIG_GREETER "/tmp/greeter.ini"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    testBool = true;
    setUserListExpandFlag(testBool);

    QPushButton* testButton = new QPushButton(this);
    testButton->setText("testButton");
    testButton->move(0, 0);
    connect(testButton, &QPushButton::clicked, [this] {
        testBool = !testBool;
        setUserListExpandFlag(testBool);});
}

MainWindow::~MainWindow()
{

}
bool MainWindow::getUserListExpandFlag() {
    QSettings settings(DDESESSIONCC_CONFIG_GREETER, QSettings::IniFormat);

    const QString item = "UserListExpand";
    bool result = settings.value(item + "/expandFlag").toBool();
    qDebug() << "Get UserList value:" << result;
    return result;
}

void MainWindow::setUserListExpandFlag(bool ex) {
    QFile file(DDESESSIONCC_CONFIG_GREETER);

    if (!file.exists()) {
        qDebug() << "file not exist SETLOGIN" << file.open(QIODevice::ReadWrite);

        file.setPermissions(DDESESSIONCC_CONFIG_GREETER, QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner
              |QFile::ReadGroup|QFile::WriteGroup|QFile::ExeGroup|QFile::ReadOther|QFile::WriteOther|QFile::ExeOther
              |QFile::ReadUser|QFile::WriteUser|QFile::ExeUser);
    } else {
        qDebug() << "file exist SETLOGIN" << file.open(QIODevice::ReadWrite);

    }
    QSettings settings(DDESESSIONCC_CONFIG_GREETER, QSettings::IniFormat);

    const QString item = "UserListExpand";

    settings.beginGroup(item);
    settings.setValue("expandFlag", ex);
    qDebug() << "UserList  set result:" << ex;
    settings.endGroup();
    settings.sync();
    settings.setPath(QSettings::IniFormat, QSettings::SystemScope, DDESESSIONCC_CONFIG_GREETER);
}
