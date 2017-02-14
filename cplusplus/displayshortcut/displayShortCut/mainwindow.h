#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void valueChanged(const QString &group, const QString &key, const QVariant &value);
public slots:
    void setValue(const QString &group, const QString &key,
                                const QVariant &value);
    QVariant value(const QString &group, const QString &key,
               const QVariant &defaultValue = QVariant());
    QStringList keys(const QString &group);
private:
    QSettings *m_settings;
};

#endif // MAINWINDOW_H
