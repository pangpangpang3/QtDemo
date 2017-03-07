#ifndef IMAGESCENE_H
#define IMAGESCENE_H

#include <QGraphicsScene>

class ImageScene : public QGraphicsScene {
    Q_OBJECT
public:
    ImageScene(QObject* parent = 0);
    ~ImageScene();
    QRect imageSize();
private:
    QPixmap m_image;
};
#endif // IMAGESCENE_H
