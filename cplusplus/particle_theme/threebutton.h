#ifndef THREEBUTTON
#define THREEBUTTON

#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>

class ThreeButton : public QFrame {
    Q_OBJECT
public:
    ThreeButton(QWidget* parent = 0);
    ~ThreeButton();

    QHBoxLayout* m_Layout;
};
#endif // THREEBUTTON

