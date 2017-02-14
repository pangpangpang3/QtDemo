#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    scene.addText("Hello, world!");

    QGraphicsView view(&scene);
    view.show();

    scene.setBackgroundBrush(Qt::blue);

     // a gradient background
     QRadialGradient gradient(0, 0, 10);
     gradient.setSpread(QGradient::RepeatSpread);
     scene.setBackgroundBrush(gradient);
//     scene.setForegroundBrush(QColor(255, 255, 255, 127));

//     // a grid foreground
//     scene.setForegroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));
    return a.exec();
}
