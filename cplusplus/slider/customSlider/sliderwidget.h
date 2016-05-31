#ifndef IMAGESLIDER_H
#define IMAGESLIDER_H

#include <QSlider>
#include <QVBoxLayout>

#include <dimagebutton.h>

using namespace Dtk::Widget;

class ImageSlider : public QSlider {
    Q_OBJECT
public:
    ImageSlider(QWidget* parent = 0);
    ImageSlider(Qt::Orientation orientation, QWidget * parent = 0);
    ~ImageSlider();
protected:
    void wheelEvent(QWheelEvent *e);
public slots:
    void showTooltip();
    void hideTooltip();
private:
    QWidget* m_tooltip;
};

class SliderWidget : public QWidget {
    Q_OBJECT
public:
    SliderWidget(QWidget* parent = 0);
    ~SliderWidget();
public slots:
    int getValue();

private slots:
    void addValue();
    void minusValue();
private:
    DImageButton* m_addBtn;
    DImageButton* m_minusBtn;
    ImageSlider* m_slider;
    QVBoxLayout* m_layout;
};
#endif // IMAGESLIDER_H
