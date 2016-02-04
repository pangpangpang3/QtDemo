#ifndef ITEMBUTTON
#define ITEMBUTTON
#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QDebug>

class ItemButton: public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QString normalIcon MEMBER m_normalIcon DESIGNABLE true NOTIFY iconChanged)
    Q_PROPERTY(QString hoverIcon MEMBER m_hoverIcon DESIGNABLE true NOTIFY iconChanged)
    Q_PROPERTY(QString pressedIcon MEMBER m_pressedIcon DESIGNABLE true NOTIFY iconChanged)
    Q_PROPERTY(bool disabled READ isDisabled WRITE setDisabled NOTIFY stateChanged)

public:
    ItemButton(QWidget* parent=0);
    ~ItemButton();

    enum State {Default, Normal, Hover, Checked, Pressed, Disabled};

    void setDisabled(bool disabled);
    inline bool isDisabled() const {return m_state == Disabled;}
    void setChecked(bool checked);
    inline bool isChecked() const {return m_state == Checked;}
    inline State state() const {return m_state;}
    void updateState(const State state);
signals:
    void stateChanged(const State state);
    void clicked();
    void iconChanged();

private slots:
    void updateIcon();
    inline void setState(const State state) {updateState(state);}
protected:
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* e);

private:
    void initUI();
    void initConnect();

    State m_state = Normal;

    QLabel *m_itemIcon;
    QString m_normalIcon;
    QString m_hoverIcon;
    QString m_pressedIcon;
};
#endif // ITEMBUTTON

