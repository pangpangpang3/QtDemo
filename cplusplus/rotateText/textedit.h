#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QTextEdit>
#include <QPaintEvent>

class TextEdit : public QTextEdit {
    Q_OBJECT
public:
    TextEdit(QWidget* parent);
    ~TextEdit();
protected:
    void paintEvent(QPaintEvent *e);

};
#endif // TEXTEDIT_H
