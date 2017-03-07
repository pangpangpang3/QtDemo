#include "imagescene.h"


#include <QPainter>
#include <QPixmap>

const QColor LIGHT_CHECKER_COLOR = QColor("#353535");
const QColor DARK_CHECKER_COLOR = QColor("#050505");


ImageScene::ImageScene(QObject *parent) {

    m_image.load(":/adapt_screen_hover.png");
    QPixmap pm(12, 12);
    QPainter pmp(&pm);
    pmp.fillRect(0, 0, 6, 6, LIGHT_CHECKER_COLOR);
    pmp.fillRect(6, 6, 6, 6, LIGHT_CHECKER_COLOR);
    pmp.fillRect(0, 6, 6, 6, DARK_CHECKER_COLOR);
    pmp.fillRect(6, 0, 6, 6, DARK_CHECKER_COLOR);
    pmp.end();
    setBackgroundBrush(QBrush(pm));
    setSceneRect(m_image.rect());
    addPixmap(m_image);
}

QRect ImageScene::imageSize() {
    return m_image.rect();
}

ImageScene::~ImageScene() {}
