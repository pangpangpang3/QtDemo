#include "textedit.h"

#include <QPainter>
#include <QAbstractTextDocumentLayout>

TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent) {}

TextEdit::~TextEdit(){}

void TextEdit::paintEvent(QPaintEvent *e) {
//    QPainter painter(viewport());

//    painter.translate(viewport()->width()/2, viewport()->height()/2);
//    painter.rotate(90);
////    painter.translate(-viewport()->rect().height(),0);

//    QAbstractTextDocumentLayout::Selection selection;
//    selection.cursor = textCursor();
//    selection.format = textCursor().charFormat();

//    QAbstractTextDocumentLayout::PaintContext ctx;
//    ctx.cursorPosition = textCursor().position();
//    ctx.selections.append(selection);

//    document()->documentLayout()->draw(&painter,ctx);
}
