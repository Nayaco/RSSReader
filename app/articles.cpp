#include "articles.h"

Articles::Articles(QObject *parent) : QStyledItemDelegate(parent) {

}

void Articles::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {

}

QSize Articles::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(index)
    return QSize(option.rect.width(), 100);
}
