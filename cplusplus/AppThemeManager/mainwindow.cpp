#include "mainwindow.h"

#include "global_widget.h"

#include <QPushButton>

#include "appthememanager.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(640, 480);
    D_THEME_INIT_WIDGET(MainWindow);
    QPushButton* changeThemeBtn = new QPushButton(this);
    changeThemeBtn->setFixedSize(100, 50);
    changeThemeBtn->setText("ChangeBtn");

    connect(changeThemeBtn, &QPushButton::clicked, this, [=]{
        if (AppThemeManager::instance()->theme() == "dark")
            AppThemeManager::instance()->setTheme("light");
        else
            AppThemeManager::instance()->setTheme("dark");
    });
}

MainWindow::~MainWindow()
{

}
