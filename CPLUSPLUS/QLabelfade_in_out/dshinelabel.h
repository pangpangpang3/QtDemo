#ifndef DSHINELABEL
#define DSHINELABEL
#include <QtWidgets/QLabel>
#include <QtGui/QPainter>
#include <QtGui/QPalette>
#include <QtCore/QTimer>
#include <QtWidgets/QGraphicsOpacityEffect>
#include <QObject>
class DShineLabel:public QLabel
{
    Q_OBJECT
public:
    double opacity = 0.0;
    DShineLabel(QWidget *parent=0);
    ~DShineLabel();
    QGraphicsOpacityEffect* label_effect;
    QTimer* timer_fadeIn;
    QTimer* timer_fadeOut;
public slots:
    void fadeIn(double velocity=0.05);
    void fadeOut(double velocity=0.05);
    void showLabel();
    void hideLabel();
};
#endif // DSHINELABEL

