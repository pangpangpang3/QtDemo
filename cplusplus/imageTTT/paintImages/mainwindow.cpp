#include "mainwindow.h"

#include <QShortcut>
#include <QDir>
#include <QFileDialog>
#include <QDirIterator>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QEventLoop>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QFrame(parent)
    , m_drawingImages(false)
    , m_historyImageExist(false)
    , m_pressed(false)
    , m_ownActive(false)
    , m_grabImageNum(-1)
    , m_activeOrder(-1)
    , m_hoverOrder(-1)
    , m_hoverRect(QRect(0, 0, 0, 0))
{
    setMinimumSize(800, 600);
    setMouseTracking(true);

    QShortcut* sc = new  QShortcut(QKeySequence("Ctrl+o"), this);
    m_startPos = QPoint(0, 0);
    connect(sc, &QShortcut::activated, this, [=]{
        qDebug() << "QShortcut ....." << "ctrl+o";
        QDir dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                   "/home",
                                                   QFileDialog::ShowDirsOnly
                                                   | QFileDialog::DontResolveSymlinks);

        QDirIterator it(dir, QDirIterator::Subdirectories);
        m_paths.clear();
        m_imagesRect.clear();
        while (it.hasNext()) {
            it.next();

            if (!QPixmap(it.filePath()).isNull()) {
                m_paths.append(it.filePath());
                m_allPaths.append(it.filePath());
                qDebug() << "MainWindow:" << it.filePath();

                QRect currentRect = QRect(m_startPos.x(), m_startPos.y(),
                    QPixmap(it.filePath()).width(),
                    QPixmap(it.filePath()).height());
                m_imagesRect.append(currentRect);
                m_allImagesRect.append(currentRect);

                m_startPos = QPoint(m_startPos.x() + 10, m_startPos.y() + 10);
            }
            qDebug() << "MainWindow:" << m_paths.length();
        }
        m_drawingImages = true;

        update();
    });
    connect(this, &MainWindow::clicked, this, &MainWindow::popActiveItem);

    m_timer = new QTimer(this);
    m_timer->setSingleShot(false);
    m_timer->setInterval(60);
    connect(m_timer, &QTimer::timeout, this,[=](){
        update();
    });
    m_timer->start();
    layerImage();

}

void MainWindow::layerImage()
{
    m_drawingImages = true;
    m_backgroundPixmap = QPixmap(":/image/DeepinDraw_20170825105346.png");
    m_maskPixmap = QPixmap(":/image/th (3).jpg");

    m_allImagesRect.append(QRect(0, 0, m_backgroundPixmap.width(), m_backgroundPixmap.height()));
    m_allImagesRect.append(QRect(15, 15, m_maskPixmap.width(), m_maskPixmap.height()));

    QPainter::CompositionMode mode = QPainter::CompositionMode_SourceIn;
    QImage resultImage = QImage(this->size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(resultImage.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

    painter.drawImage(0, 0, m_backgroundPixmap.toImage());
    painter.setCompositionMode(mode);
    painter.drawImage(0, 0, m_maskPixmap.toImage());
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.end();

    m_backgroundPixmap = QPixmap::fromImage(resultImage);

    m_backgroundPixmap.save("/tmp/bg.png", "PNG");
    setStyleSheet(QString("background-image: url(%1);").arg("/tmp/bg.png"));
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    qDebug() <<"init draw pixmap...";
    QPainter painter(this);

    if (m_drawingImages) {
        auto drawPoint = m_pressedPoint - m_clickOffset;
        painter.drawPixmap(m_topOrigin,
        test_topPixmap);
    }
    qDebug() << "finised draw active item..." << m_drawingImages << m_historyImageExist;
}

void MainWindow::drawActiveItem(QPainter &painter)
{
    qDebug() << "drawActiveItem:" << m_activeOrder
                      << m_drawingImages << m_historyImageExist;

    if (m_activeOrder == -1 || m_activeOrder > m_allImagesRect.length()) {
        qDebug() << "drawActive Item return";
        return;
    }

    if (m_activeOrder != -1 && m_ownActive) {
        if (!QPixmap(m_allPaths[m_activeOrder]).isNull()) {
            painter.drawPixmap(m_allImagesRect[m_activeOrder],
            QPixmap(m_allPaths[m_activeOrder]));

            QPen pen;
            pen.setColor(Qt::green);
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawRect(m_allImagesRect[m_activeOrder]);
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QFrame::mouseMoveEvent(event);

    QPoint pos = event->pos();
    m_movingPoint = pos;

    if (m_pressed) {
        m_topOrigin =  m_pressedPoint - m_clickOffset;
        m_allImagesRect[m_allImagesRect.length() -1] = QRect(
                    m_allImagesRect[m_allImagesRect.length() - 1].x() + (m_movingPoint.x() - m_pressedPoint.x())/200,
                    m_allImagesRect[m_allImagesRect.length() - 1].y() + (m_movingPoint.y() - m_pressedPoint.y())/200,
                    m_allImagesRect[m_allImagesRect.length() - 1].width(),
                    m_allImagesRect[m_allImagesRect.length() - 1].height()
                    );
    }

    m_pressedPoint = pos;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_pressed = true;
    m_pressedPoint = event->pos();
    m_clickOffset = m_pressedPoint - m_topOrigin;

    qDebug() << "mousePressEvent:" << m_activeOrder;
    QFrame::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_pressed) {
        m_pressed = false;
        m_topOrigin = m_pressedPoint - m_clickOffset;
        emit clicked();
    }

     qDebug() << "mouseReleaseEvent:" << m_activeOrder;
    QFrame::mouseReleaseEvent(event);
}

void MainWindow::popActiveItem()
{
    m_ownActive = true;
}

void MainWindow::grabHistroyImage()
{
//    if (m_activeOrder == -1)
//        return;

//    QImage img(this->size(), QImage::Format_ARGB32);
//    QPainter painter(&img);
//    this->render(&painter);
////    QPixmap img(this->size());
////    img = this->grab(this->rect());
//    img.save("/tmp/bg.png", "PNG");

//    m_backgroundImage = QPixmap::fromImage(img);
//    m_grabImageNum += 1;

//    qDebug() << "grabHistroyImage:" << m_grabImageNum
//                      << m_drawingImages << m_historyImageExist;

//    m_historyImageExist = true;
//    m_drawingImages = false;

//    if (m_activeOrder != -1) {
//        m_updateActiveItem = true;
//    } else {
//        m_updateActiveItem = false;
//    }
}

MainWindow::~MainWindow()
{
}
