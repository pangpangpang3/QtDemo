#include "sliderwidget.h"

#include <QWheelEvent>
#include <QDebug>

const int WHEEL_VALUE = 50;
ImageSlider::ImageSlider(Qt::Orientation orientation, QWidget *parent)
    : QSlider(parent) {
}


ImageSlider::ImageSlider(QWidget *parent)
    : QSlider(parent) {

    m_tooltip = new QWidget(this);
    m_tooltip->isHidden();
    m_tooltip->setFixedSize(74, 38);
    m_tooltip->setStyleSheet("border-image: url(:/images/tooltip.png);");
}


ImageSlider::~ImageSlider() {

}

void ImageSlider::wheelEvent(QWheelEvent *e) {
    int scrollValue = this->value();

    if (e->angleDelta().y() > 0) {
        if (scrollValue >= this->minimum() + WHEEL_VALUE) {
            this->setValue(scrollValue - WHEEL_VALUE);
        }
    } else {
        if (scrollValue <= this->maximum() - WHEEL_VALUE) {
            this->setValue(scrollValue + WHEEL_VALUE);
        }
    }

}

SliderWidget::SliderWidget(QWidget *parent)
    : QWidget(parent) {
    setFixedSize(30, 300);
    m_addBtn = new DImageButton(this);
    m_addBtn->setNormalPic(":/images/Shape Copy.png");

    m_slider = new ImageSlider(Qt::Vertical);
    m_slider->setMinimum(50);
    m_slider->setMaximum(3000);
    m_slider->setValue(100);
    m_slider->setFixedWidth(20);

    m_slider->setToolTip(QString("%1%").arg(m_slider->value()));

    m_slider->setStyleSheet("QSlider::handle:vertical {\
                        width:18px;\
                        border-image: url(:/images/Rectangle 1472 Copy 2.png);}\
                        QTooltip {\
                        background-color:red;\
                        border-image:url(:/images/tooltip.png);}");

    connect(m_slider, &QSlider::valueChanged, [=]{
        qDebug() << "m_slider:" << m_slider->value();
        m_slider->setToolTip(QString("%1%").arg(m_slider->value()));

    });

    m_minusBtn = new DImageButton(this);
    m_minusBtn->setNormalPic(":/images/Shape.png");
    QHBoxLayout* addBtnHLayout = new QHBoxLayout;
    addBtnHLayout->setMargin(0);
    addBtnHLayout->setSpacing(0);
    addBtnHLayout->addStretch(1);
    addBtnHLayout->addWidget(m_addBtn);
    addBtnHLayout->addStretch(1);


    QHBoxLayout* sliderHLayout = new QHBoxLayout;
    sliderHLayout->setMargin(0);
    sliderHLayout->setSpacing(0);
    sliderHLayout->addStretch(1);
    sliderHLayout->addWidget(m_slider);
    sliderHLayout->addStretch(1);

    QHBoxLayout* minusBtnHLayout = new QHBoxLayout;
    minusBtnHLayout->setMargin(0);
    minusBtnHLayout->setSpacing(0);
    minusBtnHLayout->addStretch(1);
    minusBtnHLayout->addWidget(m_minusBtn);
    minusBtnHLayout->addStretch(1);

    m_layout = new QVBoxLayout(this);
    m_layout->setMargin(0);
    m_layout->setSpacing(0);
    m_layout->addLayout(addBtnHLayout);
    m_layout->addLayout(sliderHLayout);
    m_layout->addLayout(minusBtnHLayout);

    setLayout(m_layout);

    connect(m_addBtn, &DImageButton::clicked, this, &SliderWidget::addValue);
    connect(m_minusBtn, &DImageButton::clicked, this, &SliderWidget::minusValue);
}

int SliderWidget::getValue() {
    return m_slider->value();
}

void SliderWidget::addValue() {
    int currentValue = m_slider->value();
    if (currentValue <= m_slider->maximum() - WHEEL_VALUE) {
        m_slider->setValue(currentValue + WHEEL_VALUE);
    }
}

void SliderWidget::minusValue() {
    int currentValue = m_slider->value();
    if (currentValue >= m_slider->minimum() + WHEEL_VALUE) {
        m_slider->setValue(currentValue - WHEEL_VALUE);
    }
}

SliderWidget::~SliderWidget() {

}


