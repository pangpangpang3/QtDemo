#ifndef DSHINELABEL
#define DSHINELABEL
#include <QtWidgets/QLabel>
#include <QtGui/QPalette>
#include <QtCore/QPropertyAnimation>
#include <QtCore/QTimer>
//this label can just control the alpha of text
class DBreathingLabel: public QLabel
{
    Q_OBJECT
    Q_PROPERTY(int alpha WRITE setAlpha)

public:
    DBreathingLabel(QWidget *parent=0, Qt::WindowFlags f = 0);
    DBreathingLabel(const QString & text, QWidget * parent = 0,
                    Qt::WindowFlags f = 0);
    ~DBreathingLabel();
    void setColor(QColor color);

public slots:
    void showLabel();
    void hideLabel();

private:
    int alpha_;
    void setAlpha(int alpha);
    QPropertyAnimation* m_showAnimation;
    QPropertyAnimation* m_hideAnimation;
    QPalette m_palette;
};
#endif // DSHINELABEL

