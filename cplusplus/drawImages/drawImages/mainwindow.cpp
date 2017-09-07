#include "mainwindow.h"

#include <QPushButton>
#include <QDirIterator>
#include <QFileDialog>
#include <QPainter>
#include <QMapIterator>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QFrame(parent)
{
    setMouseTracking(true);
    setMinimumSize(800, 700);
    m_historyRect = QRect(0, 0, 0, 0);
    m_currentRect = QRect(0, 0, 0, 0);
    m_hoverRect = QRect(0, 0, 0, 0);

    QPushButton* loadImageBtn = new QPushButton(this);
    loadImageBtn->setText("Load images dir");

    connect(loadImageBtn, &QPushButton::clicked, this, [=]{
        QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                        "/home",
                                                        QFileDialog::ShowDirsOnly
                                                        | QFileDialog::DontResolveSymlinks);
        QPoint startPos = QPoint(40, 30);

        QDirIterator dirIterator(dir);
        while (dirIterator.hasNext()) {
            dirIterator.next();
            m_imageList.append(dirIterator.filePath());
            QString filePath = dirIterator.filePath();
            m_imageList.append(filePath);
            m_imageRects.append(QRect(startPos.x(), startPos.y(),
                                      QPixmap(filePath).width(),
                                      QPixmap(filePath).height()));

            startPos = QPoint(startPos.x() + 5, startPos.y() + 5);
            qDebug() << "dirIterator path:" << dirIterator.filePath();
        }

        update();
        qDebug() << "m_imageList:" << m_imageList.length() << m_imageMap.count();
    });
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for (int i = 0; i < m_imageList.length(); i++) {
        QPixmap pixmap = QPixmap(i.key());

        if (!pixmap.isNull()) {
            m_currentRect = QRect(i.value());
            m_imageRects.append(m_currentRect);

            painter.drawPixmap(i.value().x(), i.value().y(), pixmap);
            m_historyRect = m_currentRect;
        }
    }

    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setWidth(2);
    painter.setPen(pen);

    if (m_hoverRect != QRect(0, 0, 0, 0))
    {
        qDebug() << "m_hoverRect" << m_hoverRect;
        painter.drawRect(m_hoverRect);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    for(int i = 0; i < m_imageRects.length(); i++)
    {
        if (m_imageRects[i].contains(e->pos()))
        {
            m_hoverRect = m_imageRects[i];

            update();
            break;
        } else {
            continue;
        }
    }

    QFrame::mouseMoveEvent(e);
}

MainWindow::~MainWindow()
{
}
