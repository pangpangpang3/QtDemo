#include <QApplication>

class RootImageApp : public QApplication
{
    Q_OBJECT
public:
    RootImageApp(int &argc, char **argv);
private slots:
    void setBackground();
private:
};