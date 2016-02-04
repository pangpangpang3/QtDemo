#ifndef ANIMATIONLABEL
#define ANIMATIONLABEL
#ifndef ANIM_H
#define ANIM_H
#include <QWidget>
#include <QString>
#include <QTimer>
#include <QLabel>
#include <QList>
#include <QPixmap>

class AnimatedLabel : public QLabel
{
Q_OBJECT

public:
    AnimatedLabel(const QString & image, const int imageCount,  QWidget* parent = 0);

private slots:
    void changeImage();

private:
    QList<QPixmap> pixmaps;
    int currentPixmap;
    QTimer timer;
};

#endif // ANIM_H
#endif // ANIMATIONLABEL

