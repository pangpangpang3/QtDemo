#include "mainwindow.h"

#include <QShortcut>
#include <QDir>
#include <QFileDialog>
#include <QDirIterator>
#include <QPainter>
#include <QTimer>
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
    m_timer->setSingleShot(true);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (m_drawingImages) {
        qDebug() << "paintEvent activing..............................++++++++++++++++";
        if (m_historyImageExist) {
            painter.drawPixmap(0, 0, m_backgroundImage);

            for(int i = 0; i < m_paths.length(); i++) {
                painter.drawPixmap(m_imagesRect[i], QPixmap(m_paths[i]));
            }
        } else {
            for(int i = 0; i < m_allPaths.length(); i++) {
                qDebug() << "paint all images" << i << m_activeOrder;
                if (i != m_activeOrder) {
                    painter.drawPixmap(m_allImagesRect[i], QPixmap(m_allPaths[i]));
                }

                if (!m_ownActive) {
                    if (m_allImagesRect[i] == m_hoverRect) {
                        QPen pen;
                        pen.setColor(Qt::red);
                        pen.setWidth(2);
                        painter.setPen(pen);
                        painter.drawRect(m_allImagesRect[i]);
                    }
                }
            }

            grabHistroyImage();

//            QEventLoop eventLoop;
//            QTimer::singleShot(1000, &eventLoop, SLOT(quit()));
//            eventLoop.exec();
//            painter.drawPixmap(0, 0, m_backgroundImage);
            drawActiveItem(painter);
        }
    } else {
        qDebug() << "pppppppppp";

        QPainter pp(this);
        pp.drawPixmap(0, 0, m_backgroundImage);

        if (m_ownActive) {
            painter.drawPixmap(m_allImagesRect[m_activeOrder],
                                                    QPixmap(m_allPaths[m_activeOrder]));
        }
    }

    QFrame::paintEvent(event);
}

void MainWindow::drawActiveItem(QPainter &painter)
{
    qDebug() << "drawActiveItem:" << this->paintingActive() << m_activeOrder;
    if (m_activeOrder == -1) {
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
    QPoint pos = event->pos();
    m_movingPoint = pos;

    if (m_ownActive && m_pressed) {
        m_updateActiveItem = true;

//        QPoint originPos = QPoint(m_allImagesRect[m_activeOrder].x(),
//                                                         m_allImagesRect[m_activeOrder].y());

        m_allImagesRect[m_activeOrder] = QRect(
                    m_allImagesRect[m_activeOrder].x() + (m_movingPoint.x() - m_pressedPoint.x())/10,
                    m_allImagesRect[m_activeOrder].y() + (m_movingPoint.y() - m_pressedPoint.y())/10,
                    m_allImagesRect[m_activeOrder].width(),
                    m_allImagesRect[m_activeOrder].height());

        m_updateActiveItem = true;
        update();

    } else {
        m_updateActiveItem = false;
    }

    qDebug() << "mouseMoveEvent:" << pos;

    for(int j = m_allImagesRect.length() - 1; j >= 0; j--) {
        if (m_allImagesRect[j].contains(pos)) {
            qDebug() << "inside Rect num:" << j;
            m_hoverRect = m_allImagesRect[j];
            m_hoverOrder = j;

            m_drawingImages = true;
            m_historyImageExist = false;
            update();
            break;
        } else {
            qDebug() << "outside Rect num:" << j;
            m_hoverRect = QRect(0, 0, 0, 0);
            m_hoverOrder = -1;
            continue;
        }
    }

    QFrame::mouseMoveEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_pressed = true;
    m_pressedPoint = event->pos();

    QFrame::mousePressEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_pressed) {
        m_pressed = false;
        emit clicked();
    }

    QFrame::mouseReleaseEvent(event);
}

void MainWindow::popActiveItem()
{
    m_activeRect = m_hoverRect;
    m_activeOrder = m_hoverOrder;

    if (m_activeRect != QRect(0, 0, 0, 0)) {
        m_ownActive = true;
        m_drawingImages = true;
        m_historyImageExist = false;

        update();
    } else {
        m_ownActive = false;
    }
}

void MainWindow::grabHistroyImage()
{
    QImage img(this->size(), QImage::Format_ARGB32);
    QPainter painter(&img);
    this->render(&painter);
    img.save("/tmp/bg.png", "PNG");

    m_backgroundImage = QPixmap("/tmp/bg.png", "PNG");
    m_grabImageNum += 1;

    qDebug() << "grabHistroyImage:" << m_grabImageNum
                      << m_drawingImages << m_historyImageExist;

    m_historyImageExist = true;
    m_drawingImages = false;
}

MainWindow::~MainWindow()
{

}
