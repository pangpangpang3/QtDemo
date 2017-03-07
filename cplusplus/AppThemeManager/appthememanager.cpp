#include "appthememanager.h"

#include <QFile>
#include <QWidget>
#include <QStyle>
#include <QStyleFactory>

#include <QDebug>

AppThemeManager *AppThemeManager::m_appThemeManager = NULL;
AppThemeManager *AppThemeManager::instance()
{
    if (!m_appThemeManager) {
        m_appThemeManager = new AppThemeManager();
    }

    return m_appThemeManager;
}


QString AppThemeManager::theme() const
{
    return m_theme;
}

void AppThemeManager::setTheme(const QString theme)
{
    if (m_theme != theme) {
        m_theme = theme;
        emit themeChanged(m_theme);
    }
}

QString AppThemeManager::getQssForWidget(const QString className, const QString &theme)
{
    QString qss;

    QString themeName = theme.isEmpty() ? m_theme : theme;
    QFile themeFile(QString(":/resources/%1/%2.qss").arg(themeName).arg(className));


    if (themeFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qss = themeFile.readAll();

        themeFile.close();
    }

    return qss;
}

void AppThemeManager::updateQss()
{
    QWidget *w = qobject_cast<QWidget*>(sender());
    if(w){
        w->setStyleSheet(w->styleSheet());
    }
}
