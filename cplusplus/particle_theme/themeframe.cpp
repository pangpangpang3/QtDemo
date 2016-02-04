#include "themeframe.h"
#include <QPushButton>

#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickWidget>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QFrame>

ThemeFrame::ThemeFrame(QString url, QWidget *parent)
    : QFrame(parent)
{
    this->setFixedSize(1400, 900);

    setTheme(url);

    QPushButton* testButton = new QPushButton(this);
    testButton->setFixedSize(40, 40);
    testButton->setText("Test");
    testButton->move(0, 0);

}

void ThemeFrame::setTheme(QString url) {
    QQuickWidget* view = new QQuickWidget(this);
    view->setResizeMode(QQuickWidget::SizeRootObjectToView);
    view->setSource(QUrl::fromLocalFile(url));
    view->setFixedSize(size());
}

ThemeFrame::~ThemeFrame()
{

}
