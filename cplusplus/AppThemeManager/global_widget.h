#ifndef GLOBAL_WIDGET_H
#define GLOBAL_WIDGET_H

#include "appthememanager.h"
#include <QtCore/QMetaMethod>

#include <QDebug>

#define D_THEME_INIT_WIDGET(className, ...) do{\
    AppThemeManager * manager =  AppThemeManager::instance(); \
    this->setStyleSheet(this->styleSheet() + manager->getQssForWidget(#className)); \
    connect(manager, &AppThemeManager::themeChanged, this, [this, manager] (QString) { \
        this->setStyleSheet(manager->getQssForWidget(#className)); \
    });\
    QStringList list = QString(#__VA_ARGS__).replace(" ", "").split(",");\
    const QMetaObject *self = metaObject();\
    foreach (const QString &str, list) {\
        if(str.isEmpty())\
            continue;\
        connect(this, self->property(self->indexOfProperty(str.toLatin1().data())).notifySignal(),\
        manager, manager->metaObject()->method(manager->metaObject()->indexOfMethod("updateQss()")));\
    } \
} while (0);

#endif // GLOBAL_WIDGET_H
