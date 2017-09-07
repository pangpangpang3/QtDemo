#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QPaintEvent>
#include <QMap>

class MainWindow : public QFrame
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *e);

private:
    QStringList m_imageList;
    QRect m_historyRect;
    QRect m_currentRect;

    QList<QRect> m_imageRects;
    QRect m_hoverRect;
};

#endif // MAINWINDOW_H
