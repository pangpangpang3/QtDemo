#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

#include <QDialog>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QPushButton* controlButton;
    QDialog* mainDialog;
};

#endif // WIDGET_H
