#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFrame>
#include <QPaintEvent>
#include <QMouseEvent>

class MainWindow : public QFrame
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void drawActiveItem(QPainter &painter);

public slots:
    void grabHistroyImage();
    void popActiveItem();

signals:
    void grabImage();
    void clicked();

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QStringList m_allPaths;
    QStringList m_paths;

    bool m_drawingImages;
    bool m_historyImageExist;
    bool m_pressed;
    bool m_ownActive;
    bool m_updateActiveItem;

    int m_activeOrder;
    int m_hoverOrder;
    int m_grabImageNum;
    QList<QRect> m_allImagesRect;
    QList<QRect> m_imagesRect;

    QRect m_hoverRect;
    QRect m_activeRect;

    QPoint m_startPos;
    QPoint m_pressedPoint;
    QPoint m_movingPoint;

    QTimer* m_timer;

    QPixmap m_backgroundImage;
};

#endif // MAINWINDOW_H
