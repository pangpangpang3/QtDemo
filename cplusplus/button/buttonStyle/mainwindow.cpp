#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(600, 600);
    m_test1Button = new ItemButton(this);
    m_test1Button->setProperty("normalIcon", ":/img/Deepin_indicator_normal.png");
    m_test1Button->setProperty("hoverIcon", ":/img/Deepin_indicator_hover.png");
    m_test1Button->setProperty("checkedIcon", ":/img/Deepin_indicator_press.png");

    m_test1Button->setFixedSize(40, 40);

    setStyleSheet(QString("QMainWindow{border-image: url(%1);no-repeat;}").arg(":/img/games.jpg"));




    m_test2Button = new QPushButton(this);
    m_test2Button->setIcon(QPixmap(":/img/Deepin_indicator_normal.png"));
    m_test2Button->setFixedSize(40, 40);
    m_test2Button->setIconSize(QSize(40, 40));
    m_test2Button->move(200, 200);
}

MainWindow::~MainWindow()
{

}
