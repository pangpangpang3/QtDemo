#include <QLineEdit>
#include <QFont>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(640, 480);

    QLineEdit* lineEdit = new QLineEdit(this);
    lineEdit->setText("密码错误，密码错误，wrong password!");
    lineEdit->setFixedSize(640, 40);
    QFont myfont;
    myfont.setPixelSize(30);

    lineEdit->setFont(myfont);
}

MainWindow::~MainWindow()
{

}
