#include "mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_settings = new QSettings(":/current_default.conf", QSettings::NativeFormat, this);
    qDebug() << "value" << value("Image Viewing", "Start slide show").toString();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setValue(const QString &group, const QString &key,
                            const QVariant &value)
{
    m_settings->beginGroup(group);
    m_settings->setValue(key, value);
    m_settings->endGroup();

    emit valueChanged(group, key, value);
}

QVariant MainWindow::value(const QString &group, const QString &key,
                             const QVariant &defaultValue)
{
    QVariant value;
    m_settings->beginGroup(group);
    value = m_settings->value(key, defaultValue);
    m_settings->endGroup();

    return value;
}

QStringList MainWindow::keys(const QString &group)
{
    QStringList v;
    m_settings->beginGroup(group);
    v = m_settings->childKeys();
    m_settings->endGroup();

    return v;
}
