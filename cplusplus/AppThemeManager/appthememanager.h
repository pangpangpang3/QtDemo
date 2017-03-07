#ifndef APPTHEMEMANAGER_H
#define APPTHEMEMANAGER_H

#include <QObject>
#include <QString>
#include <QGlobalStatic>


class AppThemeManager : public QObject
{
    Q_OBJECT

public:
    static AppThemeManager * instance();
    QString theme() const;
    void setTheme(const QString theme);
    QString getQssForWidget(const QString className,
                            const QString &theme = "");
public slots:
    void updateQss();

signals:
    void themeChanged(QString theme);

private:
    static AppThemeManager* m_appThemeManager;
    QString m_theme = "light";
};

#endif // APPTHEMEMANAGER_H
