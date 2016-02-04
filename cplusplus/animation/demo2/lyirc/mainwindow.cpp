#include <QPainter>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setMinimumSize(300, 50);
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
        p.setBrush((Qt::red));//给文字填充红色
        p.setPen(Qt::red); //文字边框也是红色
        QFont font("黑体",30); //字体决定整句歌词的Rect大小
        QRegion left(0,0,150,50);//左边唱过的部分,这里的值我是随便弄的作效果
        QRegion right(151,0,300,50);//右边未唱过的部分
        QPainterPath path;
        path.addText(0,30,font,"今天天气非常好，蓝天白云，杨柳飘拂．．．．");//歌词文字作为路径
        p.setClipRegion(left);       //设置栽剪区域,Painter只在其中绘图
        p.drawPath(path);            //画出左边歌词
        p.setBrush(Qt::blue);       //改变填充字体颜色为绿色
        p.setPen(Qt::black);         //改变字体边框为绿色
        p.setClipRegion(right);      //设置栽剪区域为右边未唱过的部分
        p.drawPath(path);            //画右边未唱过的歌词
}
MainWindow::~MainWindow()
{

}
