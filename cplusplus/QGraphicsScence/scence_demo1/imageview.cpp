#include "imageview.h"

#include <QGraphicsScene>
#include <QDebug>



ImageView::ImageView(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(parent) {
    setScene(scene);
    setSceneRect(0, 0, 48, 40);
//    setStyleSheet("background: green;");
    set
}

ImageView::~ImageView(){}
