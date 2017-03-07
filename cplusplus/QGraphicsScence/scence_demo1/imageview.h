#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QGraphicsView>

class ImageView : public QGraphicsView {
    Q_OBJECT
public:
    ImageView(QGraphicsScene *scene, QWidget* parent = 0);
    ~ImageView();

private:
    QPixmap m_image;
};
#endif // IMAGEVIEW_H
