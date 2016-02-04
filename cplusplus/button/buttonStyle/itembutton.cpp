
#include <QEvent>
#include <QDebug>
#include <QFile>
#include <QGraphicsDropShadowEffect>

#include "itembutton.h"

ItemButton::ItemButton(QWidget* parent)
    : QPushButton(parent),
      m_itemIcon(new QLabel(this))
{
    initUI();
    initConnect();
    this->setStyleSheet("QPushButton {border:none;}");
//    setFlat(false);
}

ItemButton::~ItemButton()
{
}

void ItemButton::setDisabled(bool disabled)
{
    if (!disabled)
        updateState(Normal);
    else
        updateState(Disabled);

    QAbstractButton::setDisabled(disabled);

    // update qss
//    setStyleSheet(styleSheet());

    // update opacity
}

void ItemButton::setChecked(bool checked)
{
    if (checked)
        updateState(Checked);
    else
        updateState(Normal);
}

void ItemButton::initConnect()
{
    connect(this, &ItemButton::stateChanged, this, &ItemButton::setState, Qt::DirectConnection);
    connect(this, &ItemButton::stateChanged, this, &ItemButton::updateIcon);
    connect(this, &ItemButton::stateChanged, this, static_cast<void (ItemButton::*)()>(&ItemButton::update));
    connect(this, &ItemButton::iconChanged, this, &ItemButton::updateIcon);
    connect(this, &ItemButton::toggled, this, &ItemButton::setChecked);
//    connect(signalManager, &SignalManager::setButtonHover, [this] (const QString &text) {
//        if (m_itemText->text() != text && !isChecked() && !isDisabled()) {
//            updateState(Normal);
//        }
//    })
}

void ItemButton::initUI() {
    m_itemIcon->setFocusPolicy(Qt::NoFocus);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->addSpacing(0);
    mainLayout->addWidget(m_itemIcon);
    mainLayout->setAlignment(m_itemIcon, Qt::AlignCenter);

    setFocusPolicy(Qt::NoFocus);
    setFocusPolicy(Qt::StrongFocus);
    setLayout(mainLayout);

//    setCheckable(true);
}

void ItemButton::enterEvent(QEvent* event)
{
    Q_UNUSED(event)
    qDebug() << "EnterEvent:" << m_state;
    if (m_state == Disabled)
        return;

    if (m_state == Normal)
        updateState(Hover);

//    emit signalManager->setButtonHover(m_itemText->text());
}

void ItemButton::leaveEvent(QEvent* event)
{
    Q_UNUSED(event)

    if (m_state == Disabled)
        return;

    if (m_state == Checked)
        return;

    updateState(Normal);
}

void ItemButton::mousePressEvent(QMouseEvent* event)
{
    Q_UNUSED(event);

    updateState(Pressed);
}

void ItemButton::mouseReleaseEvent(QMouseEvent* e)
{
    Q_UNUSED(e);

    if (m_state == Checked)
        updateState(Hover);
    else
        updateState(Pressed);

    if (m_state != Disabled)
        emit clicked();
}

void ItemButton::updateIcon()
{
    QPixmap pixmap;
    switch (m_state)
    {
    case Disabled:  /* show normal pic */
    case Normal:    pixmap.load(m_normalIcon);      break;
    case Default:
    case Hover:     pixmap.load(m_hoverIcon);       break;
    case Checked:   pixmap.load(m_normalIcon);      break;
    case Pressed:   pixmap.load(m_pressedIcon);     break;
    default:;
    }

    if (!pixmap.isNull()) {
        qDebug() << "item Icon:" << m_normalIcon;
        m_itemIcon->setPixmap(pixmap);
        update();
    }
}

void ItemButton::updateState(const ItemButton::State state)
{
    qDebug() << "updateState:" << state << m_state;
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }

    QAbstractButton::setChecked(m_state == Checked);
    return updateIcon();
}
